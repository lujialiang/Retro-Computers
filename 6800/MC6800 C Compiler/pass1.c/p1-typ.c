/*
* routines to do type checking, setting, and conversions
*/

#include "il.h"
#include "pass1.h"

extern char qopt;
extern char matlev, nocomf;
extern short ptrcnt, opcount;
extern struct symtab **tos;
extern struct express *nxtmat;
extern struct classo *op1;
extern struct classo *op2;
extern struct classo classes[];
extern char thisop;
extern char strnum;
extern short namsize;
extern struct express emat[];
extern int *cursubs;
extern short strloc;
extern struct symtab pszsym;
extern struct symtab *funnam;
extern struct symtab *symloc;

/* process type info */

prctyp() {
  typechk();
}

/* classify both operands of current entry */

classops() {
  register struct express *p;
  register struct symtab *s;
  int *cp;

  p = nxtmat-1;
  ptrcnt = 0;
  thisop = p->moprtr;
  op1 = &classes[0];
  op2 = &classes[1];
  op1->otype = op2->otype = 0;
  op1->onode = op2->onode = 0;
  op1->ocflag = op2->ocflag = 0;
  if (s = p->mo1loc) {
    if ((unsigned) s > 255) {
      op1->onode = 0;
      op1->oloc.sym = s;
      if (!(op1->otype = s->stype))
        rptero(75, op1);
    }
    else {
      op1->onode = (unsigned) s;
      op1->oloc.exp = &emat[(unsigned) s - 1];
      if (!(op1->otype=op1->oloc.exp->mttype) && (op1->oloc.exp->moprtr==CAL))
        rptero(78, op1);
    }
    if (s = p->mo2loc) {
      if ((unsigned) s > 255) {
        op2->onode = 0;
        op2->oloc.sym = s;
        if (!(op2->otype = s->stype))
          rptero(75, op2);
      }
      else {
        op2->onode = (unsigned) s;
        op2->oloc.exp = &emat[(unsigned) s - 1];
        if (!(op2->otype=op2->oloc.exp->mttype) && (op2->oloc.exp->moprtr==CAL))
          rptero(78, op2);
      }
    }
  }
  if ((op1->otype & 0x0f) == CONST) {
    op1->otype >>= 8;
    op1->ocflag++;
  }
  if ((op2->otype & 0x0f) == CONST) {
    op2->otype >>= 8;
    op2->ocflag++;
  }
  if (op1->otype & 0x30)
    ptrcnt |= 1;
  if (op2->otype & 0x30)
    ptrcnt |= 2;
}

/* check if operand is an lvalue */

chlvalu(op)
struct classo *op;
{
  short t;
  struct express *tptr;
  char rv = 0;

  if (t = (op->otype & 0x30))
    if (t != (PTR<<4))
      return(rptern(73));
  if (op->ocflag)
    return(rptern(73));
  if (op->onode) {
    if (op->oloc.exp->moprtr == CVC) {
      tptr = nxtmat;
      nxtmat = op->oloc.exp + 1;
      classops();
      rv = chlvalu(op1);
      nxtmat = tptr;
      classops();
      return(rv);
    }
    if (op->oloc.exp->moprtr==IND || op->oloc.exp->moprtr==DOT
         || op->oloc.exp->moprtr==BEX)
      return(TRUE);
    else
      return(rptern(73));
  }
  return(TRUE);
}

/* remove highest type level */

remvlev(typ)
unsigned typ;
{
  return(((typ>>2) & 0xfff0) | (typ & 0x0f));
}

/* change type X to pointer to X */

makeptr(typ)
unsigned typ;
{
  return(((typ&0xfff0)<<2) | (typ&0x0f) | (PTR<<4));
}

/* do type checking on entry */

typechk() {
  register struct express *p;
  int t;
  char saveop;
  int *cp;
  register struct symtab *sp;
  struct symtab *findnam();

  if (nxtmat == emat)
    return;
  classops();
  if (op1->onode)
    if (onzcheck(op1->oloc.exp)) {
      op1->oloc.exp++;
      op1->otype = INT;
      op1->onode++;
      p = nxtmat-1;
      t = p->mo1loc;
      p->mo1loc = ++t;
    }
  if (op2->onode)
    if (onzcheck(op2->oloc.exp)) {
      op2->oloc.exp++;
      op2->otype = INT;
      op2->onode++;
      p = nxtmat-1;
      t = p->mo2loc;
      p->mo2loc = ++t;
    }
  p = nxtmat-1;
  if (thisop < FPP) return;
  if (thisop < ADD) {
    switch (thisop) {
      case FPP:
      case FMM:
      case BPP:
      case BMM:
        if (!chlvalu(op1))
          return(FALSE);
        if (t = (op1->otype & 0x30))
          if (t==(PTR<<4))
            return(ptradd(p));
          else
            rptern(76);
        break;
      case NOT:
        p->mttype = INT;
        if (op1->otype > DUBLE)
          if ((op1->otype&0x30) != (PTR<<4))
            return(rptero(79, op1));
        return;
      case ADR:
        if ((op1->otype&0x30) != (FNCT<<4))
          chlvalu(op1);
        p->mttype = makeptr(op1->otype);
        if (!(op1->onode)) {
          if (op1->oloc.sym->sclass == REG)
            return(rptern(87));
        }
        else {
          if (op1->oloc.exp->moprtr == BEX)
            return(rptero(105, op1));
        }
        return;
      case IND:
        if (t = (op1->otype & 0x30)) {
          if (t == (FNCT<<4))
            rptern(67);
          p->mttype = remvlev(op1->otype);
          if (p->mttype==STRUCT || p->mttype==UNION) {
            sp = findnam(op1);
            strnum = sp->sstrnum;
            strloc = sp->sstrct;
          }
          if ((t==(ARAY<<4)) && ((p->mttype&0x30)==(ARAY<<4)))
            p->moprtr = NOP;
          return;
        }
        rptero(70, op1);
        break;
      case UNM:
        if (op1->otype > DUBLE)
          rptero(71, op1);
        break;
      case COM:
        if (op1->otype > LONG)
          rptero(72, op1);
        break;
    }
    if (!(p->mttype = op1->otype))
      p->mttype = INT;
    return;
  }
  else if (thisop < EQU) {
    switch (thisop) {
      case ADD:
        if (ptrcnt) {
          if (ptrcnt == 3)
            return(rptern(80));
          ptradd(p);
        }
        else {
          docomut(p);
          if (chktyps(0))
            cvtrslt(0,0);
        }
        break;
      case SUB:
        if (op2->ocflag) {
          cp = p->mo2loc;
          cp += (SIZINT/2);
          *cp = -(*cp);
          p->moprtr = thisop = ADD;
        }
        if (ptrcnt) {
          if (ptrcnt == 2)
            return(rptern(82));
          if (ptrcnt == 1)
            ptradd(p);
          else {
            if (op1->otype != op2->otype) {
              if ((op1->otype&0x30)==FNCT || (op2->otype&0x30)==FNCT)
                return(rptern(84));
              if ((op1->otype&0xffcf) != (op2->otype&0xffcf))
                return(rptern(84));
            }
            t = patsize(remvlev(op1->otype));
            p->mttype = INT;
            p++;
            p->moprtr = DIV;
            p->mo1loc = (p - &emat[0]);
            cp = makone();
            *(cp+1+(SIZINT/4)) = t;
            p->mo2loc = cp;
            p++;
            p->moprtr = 0;
            nxtmat = p;
            matlev++;
            t = *(tos-1);
            *(tos-1) = ++t;
            typechk();
          }
        }
        else {
          if (chktyps(0))
            cvtrslt(0,0);
        }
        break;
      case MUL:
        docomut(p);
      case DIV:
        if (op2->ocflag)
          if (opmd(p))
            return(TRUE);
        if (chktyps(0))
          cvtrslt(5,0);
        break;
      case MOD:
        if (chktyps(1))
          cvtrslt(5,0);
        break;
      case SHR:
      case SHL:
        if (chktyps(1))
          cvtrslt(3,1);
        break;
      case AND:
      case BOR:
      case XOR:
        docomut(p);
        if (chktyps(1))
          cvtrslt(0,0);
        break;
    }
  }
  else if (thisop < ADA) {
    if (ptrcnt == 1) {
      if (op2->otype >= FLOAT)
        return(rptero(88, op2));
    }
    else {
      if (ptrcnt == 2)
        if (op1->otype >= FLOAT)
          return(rptero(88, op1));
    }
    if (docomut(p))
      if (thisop > NEQ) {
        thisop += 2;
        if (thisop > GRT)
          thisop -= 4;
        p->moprtr = thisop;
      }
    if (chktyps(3))
      cvtrslt(6, 2);
  }
  else if (thisop <= ASN) {
    if (!chlvalu(op1))
      return(FALSE);
    if (thisop != ASN) {
      if (ptrcnt == 3)
        return(rptern(85));
      if (ptrcnt==0 || ptrcnt==2)
        cvtrslt(4,9);
      p = nxtmat-1;
      saveop = thisop;
      p->moprtr -= (ADA-ADD);
      nocomf++;
      if (!typechk()) {
        p = nxtmat-1;
        p->moprtr = saveop;
        return(FALSE);
      }
      p = nxtmat-1;
      p->moprtr = saveop;
      classops();
    }
    if (thisop == ASN) {
      namsize = 0;
      if (chktyps(4)) {
        cvtrslt(7,1);
        if (namsize) {
          entern(SIZ);
          putsize(namsize, &((p+1)->mo1loc));
        }
      }
    }
    else
      cvtrslt(15,1);
    if (op1->onode)
      if (op1->oloc.exp->moprtr == BEX)
        if (thisop == ASN)
          op1->oloc.exp->moprtr = BCL;
        else
          op1->oloc.exp->moprtr = BXC;
  }
  else {
    switch (thisop) {
      case CXB:
      case CBR:
      case CEN:
        cvtrslt(15,1);
        break;
      case DOT:
        p->mttype = op2->otype;
        if (op2->oloc.sym->sflags & FFIELD) {
          enteru(BEX);
          cp = makone();
          *cp = (SHORT<<8) | CONST;
          *(cp+1+(SIZINT/4)) = op2->oloc.sym->sstrct;
          (p+1)->mo2loc = cp;
        }
        break;
      case CAL:
        if ((op1->otype & 0x30) != (FNCT<<4))
          return(rptero(86, op1));
        p->mttype = remvlev(op1->otype);
        break;
      case PRM:
        if (op1->otype < INT)
          cvop1(INT);
        cvtrslt(15,1);
        if (p->mttype==STRUCT || p->mttype==UNION) {
          findnam(op1);
          putsize(namsize, &p->mo2loc);
        }
        break;
      case LOD:
      case ENC:
        if (!(op1->otype & 0x30))
          if (op1->otype > DUBLE)
            return(rptero(89, op1));
        cvtrslt(15,1);
        break;
      case SPL:
        p->mttype = remvlev(symloc->stype);
        if (p->mttype==STRUCT || p->mttype==UNION)
          putsize(patsize(p->mttype), &p->mo1loc);
        break;
      case RET:
        t = remvlev(funnam->stype);
        if (op1->otype != t)
          cvop1(t);
        cvtrslt(15,1);
        if (t==STRUCT || t==UNION)
          putsize(patsize(t), &p->mo2loc);
        break;
      case SWT:
        if (op1->otype >= FLOAT)
          return(rptern(90));
        if (op1->otype != INT)
          cvop1(INT);
        cvtrslt(15,1);
        break;
      case SIZ:
        p->mttype = (p-1)->mttype;
        break;
      case BEX:
        p->mttype = UNSND;
        break;
    }
  }
}

ptradd(p)
struct express *p;
{
  int size, *cp;
  struct classo *temp;
  int top1, top2, ttyp;
  char topr;
  struct express *p2;

  if (!(op1->otype & 0x30)) {
    temp = p->mo1loc;
    p->mo1loc = p->mo2loc;
    p->mo2loc = temp;
    temp = op1;
    op1 = op2;
    op2 = temp;
  }
  size = patsize(remvlev(op1->otype));
  p->mttype = op1->otype;
  if ((op1->otype&0x30) == (FNCT<<4))
    return(rptero(77, op1));
  if (op2->ocflag && (op2->otype<=UNSND)) {
    cp = (int *)op2->oloc.sym;
    cp += (SIZINT/2);
    *cp *= size;
  }
  else {
    if (op2->otype >= FLOAT)
      return(rptero(96, op2));
    topr = p->moprtr;
    ttyp = op1->otype;
    top1 = p->mo1loc;
    p->mo1loc = p->mo2loc;
    p->moprtr = MUL;
    cp = makone();
    *(cp+1+(SIZINT/4)) = size;
    p->mo2loc = cp;
    typechk();
    p2 = nxtmat++;
    p2->moprtr = topr;
    p2->mttype = ttyp;
    p2->mo1loc = top1;
    p2->mo2loc = (nxtmat-emat)-1;
    (p2+1)->moprtr = 0;
    *(tos-1) = (struct symtab *) ++matlev;
  }
}

/* find pointed at object size */

patsize(t) {
  pszsym.stype = t;
  if ((t&0x0f)==STRUCT || (t&0x0f)==UNION)
    pszsym.sstrct = strloc;
  pszsym.ssubs = cursubs;
  return(sizeit(&pszsym));
}

/* check for valid types - three rules as follows:
*
* 0 -> any type (char to double) - no pointers
* 1 -> integral types only - no pointers
* 2 -> any type - including pointers
* 3 -> any type - except cant mix pointers and floats
*/

chktyps(rule) {
  struct symtab *findnam();

  switch (rule) {
    case 0:
      if (op1->otype > DUBLE)
        return(rptero(89, op1));
      if (op2->otype > DUBLE)
        return(rptero(89, op2));
      break;
    case 1:
      if (op1->otype >= FLOAT)
        return(rptero(92, op1));
      if (op2->otype >= FLOAT)
        return(rptero(92, op2));
      break;
    case 2:
      if (!(op1->otype&0x30))
        if (op1->otype > DUBLE)
          return(rptero(89, op1));
      if (!(op2->otype&0x30))
        if (op2->otype > DUBLE)
          return(rptero(89, op2));
      break;
    case 4:
      if (op1->otype==STRUCT || op1->otype==UNION) {
        if (findnam(op1)->sstrct == findnam(op2)->sstrct)
          return(TRUE);
        namsize = 0;
        return(rptern(95));
      }
    case 3:
      if (!ptrcnt) {
        if (op1->otype > DUBLE)
          return(rptero(89, op1));
        if (op2->otype > DUBLE)
         return(rptero(89, op2));
        break;
      }
      else {
        if (ptrcnt == 1) {
          if (op2->otype >= FLOAT)
            return(rptero(96, op2));
        }
        else {
          if (ptrcnt==2 && op1->otype>=FLOAT)
            return(rptero(96, op1));
        }
      }
      break;
  }
  return(TRUE);
}

/* do type conversions and set result type
*    There are 5 conversion rules as follows:
*     0 -> usual with +q option
*     1 -> usual without +q option
*     2 -> usual but allow small types
*     3 -> right operand to CHAR, left to INT unless +q
*     4 -> convert right operand to type of left
*     5 -> usual with +q but smallest type is short
*     6 -> special cases for relationals and pur assignment
*
*   Result rules:
*     0 -> usual
*     1 -> type of left operand
*     2 -> integer
*/

cvtrslt(crule, rrule) {
  short op1less, min;
  register struct express *p;

  if (op1->otype == op2->otype) {
    switch(crule) {
      case 0:
        if (qopt)
          break;
      case 1:
        if (op1->otype < INT) {
          cvop1(INT);
          cvop2(INT);
        }
      case 2:
      case 6:
      case 7:
        break;
      case 3:
        if (op2->otype != CHR)
          cvop2(CHR);
        if (!qopt)
          if (op1->otype < INT)
            cvop1(INT);
      case 4:
        break;
      case 5:
        if (qopt) {
          if (op1->otype < SHORT) {
            cvop1(SHORT);
            cvop2(SHORT);
          }
          break;
        }
        if (op1->otype < INT) {
          cvop1(INT);
          cvop2(INT);
        }
        break;
    }
  }
  else {
    op1less = 0;
    if (op1->otype < op2->otype)
      op1less++;
    min = INT;
    if (qopt)
      if (crule == 0)
        min = CHR;
      else
        if (crule == 5)
          min = SHORT;
    if (crule==2 || crule==6 || crule==7)
      min = CHR;
    switch (crule) {
      case 6:
      case 7:
        if (ptrcnt==3)
          break;
        if (op1->ocflag && op1->otype!=op2->otype)
          if (op1->otype<LONG && op2->otype<LONG) {
            cvcon(op1->otype, op2->otype, op1->oloc.sym);
            op1->otype = op2->otype;
            break;
          }
        if (op2->ocflag && op2->otype!=op1->otype)
          if (op1->otype<LONG && op2->otype<LONG) {
            cvcon(op2->otype, op1->otype, op2->oloc.sym);
            op2->otype = op1->otype;
            break;
          }
      case 0:
      case 1:
      case 2:
      case 5:
        if (crule != 7) {
          if (op1less) {
            if (op2->otype < min) {
              cvop1(min);
              cvop2(min);
              break;
            }
            cvop1(op2->otype);
            break;
          }
          if (op1->otype < min) {
            cvop1(min);
            cvop2(min);
            break;
          }
        }
        if (crule==6 || crule==7) {
          if (op2->ocflag && ptrcnt==1) {
            if (op2->otype != INT)
              cvop2(INT);
            break;
          }
        }
        cvop2(op1->otype);
        break;
      case 3:
        if (!qopt)
          if (op1->otype < INT)
            cvop1(INT);
        if (op2->otype != CHR)
          cvop2(CHR);
        break;
      case 4:
        cvop2(op1->otype);
        break;
    }
  }
  p = nxtmat-1;
  switch (rrule) {
    case 0:
    case 1:
      p->mttype = op1->otype;
      break;
    case 2:
      p->mttype = INT;
      break;
  }
}

/* convert operand one to type specified */

cvop1(ctype) {
  register struct express *p;
  unsigned noden;
  int *cp;

  p = nxtmat-1;
  p->mttype = ctype;
  if (op1->onode)
    nodecvt(ctype, op1->oloc.exp);
  else {
    if (op1->ocflag && op1->otype<MAXCON && ctype<MAXCON) {
      cvcon(op1->otype, ctype, p->mo1loc);
      op1->otype = ctype;
      return;
    }
    else {
      (p+1)->mo2loc = p->mo2loc;
      p->mo2loc = 0;
      (p+1)->moprtr = p->moprtr;
      p->moprtr = CVC;
      (p+1)->mo1loc = (p-emat) + 1;
    }
  }
  op1->otype = ctype;
  (p+2)->moprtr = 0;
  nxtmat = p+2;
  matlev++;
  noden = (unsigned) (*(tos-1));
  if (thisop != PRM)
    *(tos-1) = (struct symtab *) ++noden;
}

/* convert operand two to type specified */

cvop2(ctype) {
  register struct express *p;
  unsigned noden;
  int *cp;

  p = nxtmat-1;
  p->mttype = ctype;
  if (op2->onode)
    nodecvt(ctype, op2->oloc.exp);
  else {
    if (op2->ocflag && op2->otype<MAXCON && ctype<MAXCON) {
      cvcon(op2->otype, ctype, p->mo2loc);
      op2->otype = ctype;
      return;
    }
    else {
      (p+1)->mo1loc = p->mo1loc;
      p->mo1loc = p->mo2loc;
      p->mo2loc = 0;
      (p+1)->moprtr = p->moprtr;
      p->moprtr = CVC;
      (p+1)->mo2loc = (p-emat) + 1;
    }
  }
  op2->otype = ctype;
  (p+2)->moprtr = 0;
  nxtmat = p+2;
  matlev++;
  noden = (unsigned) (*(tos-1));
  *(tos-1) = (struct symtab *) ++noden;
}

/* convert the node referenced to the type specified */

nodecvt(ctype, ep)
int ctype;
struct express *ep;
{
  register struct express *p;
  unsigned nodnum;
  unsigned mynode;

  for (p=nxtmat-1; p>ep; p--) {
    (p+1)->moprtr = p->moprtr;
    (p+1)->mttype = p->mttype;
    (p+1)->mo1loc = p->mo1loc;
    (p+1)->mo2loc = p->mo2loc;
  }
  p = ep+1;
  p->moprtr = CVC;
  p->mttype = ctype;
  p->mo1loc = (ep-&emat[0]) + 1;
  p->mo2loc = 0;
  mynode = (unsigned) (p->mo1loc);
  for (p=ep+2; p<=nxtmat; p++) {
    nodnum = (unsigned) (p->mo1loc);
    if (nodnum && (nodnum < 255) && (nodnum >= mynode))
      p->mo1loc = ++nodnum;
    nodnum = (unsigned) (p->mo2loc);
    if (nodnum && (nodnum < 255) && (nodnum >= mynode))
      p->mo2loc = ++nodnum;
  }
}

/* test for commute conditions and do it */

docomut(p)
register struct express *p;
{
  struct express *temp;

  if (nocomf) {
    nocomf=0;
    return(FALSE);
  }
  if (op1->onode)
    return(FALSE);
  if (!op2->onode && !op1->ocflag)
    return(FALSE);
  temp = p->mo1loc;
  p->mo1loc = p->mo2loc;
  p->mo2loc = temp;
  classops();
  return(TRUE);
}

/* optimize MUL & DIV if constants */

opmd(p)
register struct express *p;
{
  char flag;
  int con, *cp;

  if (op1->otype > UNSND)
    return(FALSE);
  flag = 0;
  cp = p->mo2loc;
  cp += (SIZINT/2);
  con = *cp;
  switch (con) {
    case 2:
      flag++;
      *cp = 1;
      break;
    case 4:
      flag++;
      *cp = 2;
      break;
    case 1:
      if (op1->onode)
        p->moprtr = NOP;
      else
        p->moprtr = LOD;
      p->mo2loc = 0;
      break;
    case 256:
      flag++;
      *cp = 8;
      break;
    case 512:
      flag++;
      *cp = 9;
      break;
    case 8:
      flag++;
      *cp = 3;
      break;
    case 16:
      flag++;
      *cp = 4;
      break;
    case -1:
      p->moprtr = UNM;
      p->mo2loc = 0;
      break;
    case 0:
      p->moprtr = LOD;
      *cp = 0;
      p->mo1loc = p->mo2loc;
      p->mo2loc = 0;
      break;
  }
  if (flag)
    if (thisop == MUL)
      p->moprtr = SHL;
    else
      p->moprtr = SHR;
  if (p->moprtr == SHL || p->moprtr == SHR) {
    typechk();
    return(TRUE);
  }
  return(FALSE);
}

/* convert constant in place */

cvcon(oldt, newt, cp)
register int *cp;
{
  int value;

#ifdef ALIGN
  if (oldt==CHR && newt>=SHORT) {
    if (*(cp+2) > 127) {
      *(cp+2) |= 0xff00;
      *(cp+1) = 0xffff;
    }
  }
  else if (oldt==SHORT && newt>=INT) {
    if (*(cp+2) < 0)
      *(cp+1) = 0xffff;
  }
  else if (oldt>=SHORT && newt<SHORT) {
    *(cp+1) = 0;
    *(cp+2) &= 0xff;
  }
  else if (oldt>=INT && newt<INT)
    *(cp+1) = 0;
  *cp = (newt<<8) | CONST;
#else
  value = *(cp+1);
  if (oldt==CHR && newt>=SHORT) {
    if (value > 127)
      value |= 0xff00;
  }
  else if (oldt>=SHORT && newt<SHORT)
    value &= 0xff;
  *cp = (newt<<8) | CONST;
  *(cp+1) = value;
#endif
}

/* do type conversions for question mark operator */

cvtqum(p2, p1)
register struct express *p1, *p2;
{
  int t1, t2;
  char pc;

  t1 = p1->mttype;
  t2 = p2->mttype;
  pc = 0;
  if (t1 & 0x30)
    pc |= 1;
  if (t2 & 0x30)
    pc |= 2;
  if (pc) {
    if (pc==3) {
      if ((t1&0xffcf) != (t2&0xffcf))
        return(rptern(93));
    }
    else if (pc == 1) {
      chkzero(p2, t1);
    }
    else
      chkzero(p1, t2);
  }
  else {
    if (t1>DUBLE || t2>DUBLE)
      return(rptern(94));
    if (t1 == t2)
      return(TRUE);
    if (t1 > t2)
      nodecvt(t1, p2);
    else {
      nodecvt(t2, p1);
      (p1+2)->mttype = t2;
    }
    nxtmat++;
    matlev++;
    t1 = *(tos-1);
    *(tos-1) = ++t1;
  }
  return(TRUE);
}

/* check if node is a LOD zero */

chkzero(p, t)
register struct express *p;
{
  int *ip;

  if (p->moprtr != ENC)
    return(rptern(98));
  if ((unsigned)(p->mo1loc) < 256)
    return(rptern(98));
  if (!isconst(p->mo1loc->stype))
    return(rptern(98));
  ip = p->mo1loc;
  if (*(ip + (SIZINT/2)))
    return(rptern(98));
  p->mttype = t;
  return(TRUE);
}

/* check for generation of 'one-zero' result */

onzcheck(ep)
register struct express *ep;
{
  char op;
  unsigned noden;

  if (thisop==ANC || thisop==ORC || thisop==ORB || thisop==ANB)
    return(FALSE);
  if (thisop==CXB)
    return(FALSE);
  op = (ep+1)->moprtr;
  if (op == ANE || op == ORE) {
    ep++;
    ep->moprtr -= (ORE-OZF);
    ep->mttype = INT;
    return(TRUE);
  }
  else {
    op = ep->moprtr;
    if (op==NOT || (op>=EQU && op<=GRT)) {
      nodecvt(INT, ep);
      ep++;
      ep->moprtr = OZR;
      ep = nxtmat + 1;
      ep->moprtr = 0;
      nxtmat = ep;
      matlev++;
      if (thisop!=PRM && thisop!=CBR) {
        noden = (unsigned) (*(tos-1));
        *(tos-1) = ++noden;
      }
      classops();
    }
  }
  return(FALSE);
}

/* find symbol name referenced by op */

struct symtab *findnam(op)
struct classo *op;
{
  register struct express *ep;
  register struct symtab *sp;

  if (op->onode) {
    ep = &emat[op->onode-1];
    while (1) {
      if (ep->moprtr == DOT) {
        break;
      }
      else {
        if ((unsigned)(ep->mo1loc) < 256)
          ep = &emat[(unsigned)(ep->mo1loc)-1];
        else
          break;
      }
    }
    if (ep->moprtr == DOT)
      sp = ep->mo2loc;
    else
      sp = ep->mo1loc;
  }
  else
    sp = op->oloc.sym;
  pszsym.stype = op->otype;
  pszsym.sstrct = sp->sstrct;
  pszsym.ssubs = 0;
  namsize = sizeit(&pszsym);
  return(sp);
}

/* put size of structure in expression */

putsize(siz, loc)
int siz, *loc;
{
  int *cp;

  cp = makone();
  *(cp+1+(SIZINT/4)) = siz;
  *loc = cp;
}
