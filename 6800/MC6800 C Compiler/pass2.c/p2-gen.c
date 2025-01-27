/*
* This file contains the general code production routines
* such as generation of addresses.
*/

#include "pass2.h"
#include "il.h"

#define LSREF 6

extern struct addreg adregs[];
extern struct express exptbl[];
extern struct express *dcont;
extern struct addreg *xcont;
extern int stklev, stksiz, explev, lstlev;
extern char ccok, dvalid;
extern int incloc, curopr, locop2, locop1;
extern char notdone;
extern char opalong;
extern struct dstruct dloc;

/* Generate an address for the op at loc */

genadr(loc)
int loc;
{
  int i, type;
  int indc, offset;
  char ns[9];
  register struct addreg *aptr;

  aptr = &adregs[loc];
  type = aptr->ar_ref;
  indc = aptr->ar_ind;
  if ((indc < 0) && (!(type & ADRREG)))
    putchar('#');
  else if (indc > 0)
    putchar('[');
  if ((type & 0xf0) == 0) {
    switch(type) {
      case NREF:
        for (i=0; i<8; i++) {
          ns[i] = aptr->ar_data.ad_nam[i];
          aptr->ar_data.ad_nam[i] = '\0';
        }
        ns[8] = '\0';
        outcode("%s", ns);
        break;
      case CREF:
        outcode("%d", *aptr->ar_con + aptr->ar_off);
        aptr->ar_off = 0;
        aptr->ar_con = NULL;
        break;
      case LREF:
        outcode("L%u", aptr->ar_data.ad_val);
        aptr->ar_data.ad_val = 0;
        break;
      case TREF:
        if (!notdone) {
          outcode("0,s++");
          stksiz -= 2;
          --stklev;
          break;
        }
      case BREF:
        outcode("0,s");
        if (!notdone)
          --stklev;
        else
          notdone = 0;
        break;
      default:
        badfile();
    }
    if (aptr->ar_off != 0) {
      outcode("+%d", aptr->ar_off);
      aptr->ar_off = 0;
    }
  }
  else
    switch(type & 0xf0) {
      case ADRREG:
        offset = 0;
        if (aptr->ar_ofr != 0) {
          if (aptr->ar_ofr == OFFB)
            putchar('b');
          else
            putchar('d');
          aptr->ar_ofr = 0;
          dcont = NULL;
        }
        else {
          if (aptr->ar_off != 0) {
            offset = aptr->ar_off;
            aptr->ar_off = 0;
          }
          outcode("%d", aptr->ar_data.ad_val + offset);
        }
        putchar(',');
        if ((i = aptr->ar_inc) < 0)
          do {
            putchar('-');
          } while (++i);
        switch(type & 0x7) {
          case XREG:
            putchar('x');
            xcont = 0;
            break;
          case YREG:
            putchar('y');
            aptr->ar_data.ad_val = 0;
            break;
          case UREG:
            putchar('u');
            break;
        }
        if ((i = aptr->ar_inc) > 0)
          do {
           putchar('+');
          } while (--i);
    }
  if (indc > 0) {
    putchar(']');
    --aptr->ar_ind;
  }
  putchar('\n');
  aptr->ar_ref = 0;
  if (aptr->ar_inc) {
    aptr->ar_inc = 0;
    if ((type & 0x07) == XREG) {
      outcode(" stx ");
      dvalid = '\0';
      if (adregs[incloc & (NUMADR-1)].ar_ref == BREF)
        ++stklev;
      genadr(incloc & (NUMADR-1));
      adregs[incloc & (NUMADR-1)].ar_ref = 0;
    }
    ccok = 0;
  }
}

/* Generate special address for the 'increment' ops.
*  The code to be generated is in opst. */

spcladr(loc, opst)
int loc;
char *opst;
{
  int i;
  struct addreg *temp;
  register struct addreg *p;

  p = &adregs[loc & (NUMADR-1)];
  if ((p->ar_ofr) || (p->ar_ind>0)) {
    --p->ar_ind;
    loadx(loc & (NUMADR-1));
    ++p->ar_ind;
  }
  i = dupop(loc) & (NUMADR-1);
  temp = xcont;
  if (xcont == p)
    xcont = &adregs[i];
  adregs[i].ar_ind--;
  setoff(1, i);
  adregs[i].ar_ind++;
  outcode(opst);
  genadr(i);
  xcont = temp;
}

/* Generate code and addresses for the bit wise operators */

bitadr(code)
char *code;
{
  struct addreg *p, *temp;
  int loc, ref, i;
  
  loc = locop2 & (NUMADR-1);
  p = &adregs[loc];
  if (p->ar_ofr || p->ar_ind>0) {
    --p->ar_ind;
    loadx(loc);
    ++p->ar_ind;
  }
  ref = p->ar_ref;
  if (ref==NREF || ref==LREF || ref==(ADRREG|YREG) ||
      ((ref==(ADRREG|XREG) || ref==(ADRREG|UREG)) && (!p->ar_inc))) {
    i = dupop(locop2) & (NUMADR-1);
    temp = xcont;
    adregs[i].ar_ind--;
    setoff(1, i);
    adregs[i].ar_ind++;
    outcode(" %sa ", code);
    genadr(loc);
    if (xcont==p)
      xcont = &adregs[i];
    outcode(" %sb ", code);
    genadr(i);
    xcont = temp;
  } else if (ref==BREF) {
    outcode(" %sa 0,s\n %sb 1,s\n", code, code);
    --stklev;
  } else if (ref==TREF) {
    outcode(" %sa 0,s+\n %sb 0,s+\n", code, code);
    --stklev;
    stksiz -= 2;
  } else if (ref==(ADRREG|XREG)) {
    xcont = NULL;
    outcode(" %sa 0,x+\n %sb 0,x+\n stx ", code, code);
    genadr(incloc & (NUMADR-1));
    adregs[incloc & (NUMADR-1)].ar_ref = 0;
  } else {
    outcode(" %sa 0,u+\n %sb 0,u+\n", code, code);
  }
  ccok = dvalid = '\0';
}

/* Generate code for an integer load of a data register */

loadi(loc)
int loc;
{
  if (loc & ARREF) {
    if (!(dvalid && dmatch(loc & (NUMADR-1)))) {
      if (dcont && ((dcont != loc) || (curopr >= ADA && curopr <= XOA)))
        freed();
      finar(loc);
      ccok++;
      setdloc(loc & (NUMADR-1));
      if (iszcon(loc & (NUMADR (@.� $.��g< -`< +H�H�/ N�  2�X�R�.�N�  2�, �   l.� t0/N�  2�X�R�S�m.� H�H�/N�  2�X�R�`�` �*- lzA���.�Hn��//.��/.��N�  +�O� (@ f"A���.�Hn��z//.��/.��N�  +�O� (@(.��o$ԅ&`$R�&$.��f- f- gR�J�f- gp`p -@��gR�$- ��,S�m.� t /N�  2�X�R�`�$.��g.� t-/N�  2�X�R�`2- g.� t+/N�  2�X�R�`- g.� t /N�  2�X�R�J�oRS�m.� H�H�/N�  2�X�R�`�$.��g..� t./N�  2�X�R�S�m.� H�H�/N�  2�X�R�`�``.� t0/N�  2�X�R�$.��g.� t./N�  2�X�R�R�nS�.� t0/N�  2�X�R�`�S�m.� H�H�/N�  2�X�R�`�` 4*- nzA���.�Hn��//.��/.��N�  0O� (@ f"A���.�Hn��z//.��/.��N�  0O� (@G���J���gt-�`- gt+�`
- gt �,.�������m  n��mhJ�nt0�t.�R�nt0�`��f�`(��oS�m�`�t.��f�`�f�- gt.B��B����o- fS�# 0g� .gR�B`  ��t.��f�S�- f# 0g� .gR�- H�H�U��$.��S�,mt+�`
$D�,t-��   dm&td.�/N�  0�X��   0�td.�/N�  1�X�, t
.�/N�  0�X��   0�t
.�/N�  1�X��   0�BA���.�N�  2�D�Э , o- fS�m.� t /N�  2�X�R�`�G���g.� H�H�/N�  2�X�R�`�S�m.� t /N�  2�X�R�`�`2�   eg �6�   Eg �,�   fg �0�   gg ���   Gg �� L�8���N^NuNV��H�<���*n &n  n P� P-h����-h����- H�H� ` 2,- l|A���.�Hn��$R�//.��/.��N�  0O� (@ f&A���.�Hn��|$R�//.��/.��N�  0O� (@.���/.��B�B�N�  "6O� gS���$Z�(.���N�  C4�   coR�$.��f- f- gR�J�f- gp`p -@��gR�$- ��.S�mt �`�$.��gt-�`- gt+�`
- gt ��$.��gt.�S�m�`�� A���.�/<  UGt
//.��N�  G O� (@$.��g< -`< +�.�N�  2�. �   lt0�S�m�`�` ,- l|A���.�Hn��//.��/.��N�  +�O� (@ f"A���.�Hn��|//.��/.��N�  +�O� (@*.��o$Ԇ(`$R�($.��f- f- gR�J�f- gp`p -@��gR�$- ��.S�mt �`�$.��gt-�`- gt+�`
- gt �J�oS�m�`�$.��gt.�S�m�`�`"t0�$.��gt.�R�nS�t0�`�S�m�`�` ,- n|A���.�Hn��//.��/.��N�  0O� (@ f"A���.�Hn��|//.��/.��N�  0O� (@E���J���gt-�`- gt+�`
- gt �..�������m  n��mhJ�nt0�t.�R�nt0�`��f�`(��oS�m�`�t.��f�`�f�- gt.B��B����o- fS�" 0g� .gR�B`  ��t.��f�S�- f" 0g� .g-inc, xcont - adregs);
    xcont->ar_pre = 0;
  }
  if (xcont->ar_ind>0 || xcont->ar_off!=0 || xcont->ar_ofr!=0) {
    --xcont->ar_ind;
    loadx(xcont - adregs);
    ++xcont->ar_ind;
  }
  if (curopr==PRM || xtype() != LONG) {
    if (dcont)
      freed();
    xcont->ar_ref = xpush();
    xcont->ar_ind++;
    xcont = NULL;
  }
  else {
    outcode(" jsr pshlong\n");
    xcont->ar_ref = LSREF;
    xcont = 0;
  }
}

/* Generate code to push an address register onto the stack */

xpush() {
  if (stklev++) {
    stksiz += 2;
    outcode(" pshs x\n");
    return(TREF);
  }
  else {
    outcode(" stx 0,s\n");
    return(BREF);
  }
}

/* Generate code to push the U register onto the stack */

stacku(loc) {
  register struct addreg *p;

  p = &adregs[loc & (NUMADR-1)];
  if (p->ar_ind>0 || p->ar_off!=0 || p->ar_ofr!=0) {
    p->ar_ind--;
    loadx(loc & (NUMADR-1));
    p->ar_ind++;
  }
  if (p->ar_ref == (ADRREG|XREG))
    freex();
  else {
    p->ar_ref = upush();
    p->ar_ind++;
  }
}

upush() {
  if (stklev++) `p, g |  20x H�H� f�`  �$g�   .gp `p* gj�.�N�  3P. �����fp `p, *gJ |  20x H�H��   *g2�.�N�  3P. �����fp `p, g |  20x H�H� f�$g  �$g  �.�N�  A0�   Ef  ��t-B��.�N�  3P. �����fp `p, g2�   -g�   +f"�t-B��.�N�  3P. �����fp `p, $gH |  20x H�H� g4�.�N�  3P. �����fp `p, g |  20x H�H� f�`����`z ` \$g TJ�o N�   -g�   +f*�.�N�  3P. �����fp `p, gS�np `p* $g  �J�o  � |  20x H�H� g  ��.�N�  3P. �����fp `p, gS�o |  20x H�H� f�$gBJ�o>�   .f6�.�N�  3P. �����fp `p, gS�o |  20x H�H� f�`  �$gJ�o�   .gp `p* g  |�.�N�  3P. �����fp `p, *gZS�o |  20x H�H��   fp `p* g6�.�N�  3P. �����fp `p, gS�o |  20x H�H� f�$g  �$g  �J�o  �.�N�  A0�   Ef  ��t-B��.�N�  3P. �����fp `p, g8S�o4�   -g�   +f$�t-B��.�N�  3P. �����fp `p, S�$gPJ�oL |  20x H�H� g8�.�N�  3P. �����fp `p, gS�o |  20x H�H� f�`����`z $gH, fBB, gA�� .�N�  "n "�#h  ` A�� .�N�  .�utcode ��nextc   �	��outcode ���nextc   �	��outcode ��فnextc   �	��outcode �nextw   	�outcode "%�nextw   *	/�outcode FIQ�nextc   ^�nextw   n	s�outcode ��nextw   �	��outcode ���nextw   �	��outcode ��فnextw   �	�outcode �nextc   �	��outcode 	!�outcode &.	3�outcode HKNQTW	\�outcode a�nextc   n�nextc   sv�nextw   |�nextw   �	��outcode �	��outcode ���nextw   �	��outcode ���nextw   ��namebuf ��nexts   �	́outcode �	ENDBLK: /* End block */
        number = nextw();
        value = nextw() + 2;
        byte = nextc();
        if (number == 0)
          break;
        outcode("L%u equ %u\n", number, value);
        break;
      case ENDMOD: /* End module */
        outcode(" end\n");
        break;
      case STVAR: /* String variable description */
        number = nextw();
        outcode("* Static %s L%u\n", nexts(namebuf), number);
        break;
      case AUTVAR: /* Auto variable description */
        number = nextw();
        outcode("* Auto %d %s\n", number, nexts(namebuf));
        break;
      case REGVAR: /* Register variable description */
        number = nextw();
        outcode("* Register %d %s\n", number, nexts(namebuf));
        break;
      case SSPACE: /* Save space */
        outcode(" rmb %u\n", nextw());
        break;
      case DNAME: /* Data name */
        outcode("%s", nexts(namebuf));
        break;
      case BRANCH: /* Branch (GOTO) */
        outcode(" lbra L%u\n", nextw());
        break;


p2-basic.c                    14:18:23 Tue Jun 25 1985     Page     3 

 
      case CBRNCH: /* Conditional branch */
        if (nextc() != 0)
          byte = BTRUE;
        else
          byte = BFALSE;
        brntyp = REGLAB;
        gbrnch(byte, nextw());
        break;
      case LABEL: /* Generate label */
        outcode("L%u\n", nextw());
        dvalid = '\0';
        break;
      case BYTES: /* Data bytes */
        value = 0;
        for(number = nextc(); number > 0; number--) {
          if ((value & 0xF) == 0)
            outcode(" fcb ");
          if (((value & 0xF) == 0xF) || (number == 1))
            outcode("%u\n", nextc());
          else
            outcode("%u,", nextc());
          value++;
        }
        break;
      case WORDS: /* Data words */
        value = 0;
        for(number = nextc(); number > 0; number--) {
          if ((value & 0xF) == 0)
            outcode(" fdb ");
          if (((value & 0xF) == 0xF) || (number == 1))
            outcode("%u\n", nextw());
          else
            outcode("%u,", nextw());
          value++;
        }
        break;
      case LONGS: /* Data longs */
        value = 0;
        for(number = nextc(); number > 0; number--) {
          number2 = nextw();
          if ((value & 0x7) == 0)
            outcode(" fdb ");
          if (((value & 0x7) == 0x7) || (number == 1))
            outcode("%u,%u\n", number2, nextw());
          else
            outcode("%u,%u,", number2, nextw());
          value++;
        }
        break;
      case STRNG: /* String data */
        value = 0;


p2-basic.c                    14:18:23 Tue Jun 25 1985     Page     4 

 
        outcode("L%u", nextw());
        while(1) {
          number = nextc();
          if ((value & 0xF) == 0)
            outcode(" fcb ");
          if (((value & 0xF) == 0xF) || (number == 0))
            ou$yO�2�O�����3@1	� � �@� � 	� 1	�	�� ?�a����>8��0��������� ��2 �� �2a��pO�2���rÏ��8qb8@�>	
'&V�����'&V���66Rde("%s pshs u,y\n leay 2,s\n", namebuf);
        dvalid = '\0';
        lretlab = retlab = 0;
        break;
      case ENDFNT: /* End function */
        value = nextw();
        nextw();
        if (value & 0x30)
          outcode(" tfr x,d\n");
        outcode(" leas -2,y\n puls y,u,pc\n");
        if (lretlab)
          outcode(" bss\nL%u rmb 4\n text\n", lretlab);
        break;


p2-basic.c                    14:18:22 Tue Jun 25 1985     Page     2 

 
      case TEXT: /* Text segment */
        outc        .�                                   /#    '  p.c                                                                                                                             source/cc/pass2.c                                                                                                                ��   t    �p   u   u   u   �, �@  -z                 ��   v   v   v   �\ �@ �l  0(  -z  -z                   w    ӌ �@ Ӝ  0( ��   w    �T           � Ӵ �@  B����c   "int *p1, *p2;
main() {
  int a;
  a = p1-p2;
}
    �� 
 '   symtab.r                                                                                                                        source/cc/pa