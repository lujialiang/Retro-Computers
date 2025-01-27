;
;	32bit unsigned divide. Used as the core for the actual C library
;	division routines. It expects to be called with the parameters
;	offsets from X, and uses tmp/tmp2/tmp3.
;
;	tmp2/tmp3 end up holding the remainder
;
;	On entry the stack frame referenced by X looks like this
;
;	7-11	32bit dividend (C compiler TOS)
;	5,6	A return address
;	1-4	32bit divisor
;

DIVID		.equ	0
;		4/5,x are a return address and it's easier to just leave
;		the gap
DIVIS		.equ	6

		.export div32x32
		.code

div32x32:
		ldab #32		; 32 iterations for 32 bits
		stab @tmp
		clra
		clrb
		; Clear the working register (tmp2/tmp3)
		staa @tmp2
		stab @tmp2+1
		staa @tmp3
		stab @tmp3+1
loop:		; Shift the dividend left and set bit 0
		sec
		rol DIVID+3,x			; Shift 32bits left
		rol DIVID+2,x
		rol DIVID+1,x
		rol DIVID,x
		; Capture into the working register
		rol @tmp3+1		; capturing low bit into scratch
		rol @tmp3
		rol @tmp2+1
		rol @tmp2
		; Do a 32bit subtract but skip writing the high 16bits
		; back until we know the comparison
		ldaa @tmp3
		ldab @tmp3+1
		subb DIVIS+3,x
		sbca DIVIS+2,x
		staa @tmp3
		stab @tmp3+1
		ldaa @tmp2
		ldab @tmp2+1
		sbcb DIVIS+1,x
		sbca DIVIS,x
		; Want to subtract
		bcc skip
		; No subtract, so put back the low 16bits we mushed
		ldaa @tmp3
		ldab @tmp3+1
		addb DIVIS+3,x
		adca DIVIS+2
		andb #0xFE
		staa @tmp3
		stab @tmp3+1
done:
		dec tmp
		bne loop
		rts
		; We do want to subtract - write back the other bits
skip:
		staa @tmp2
		stab @tmp2+1
		dec tmp
		bne loop
		rts
