   10 PRINT"SEAWOLFE
   20 PRINT"COPYRYGHT 1978 BY RODGER OLSEN
   30 INPUT"DO YOU WANT INSTRUCTIONS";A$:IFA$="YES"THEN700 
   40 IFA$<>"NO"THEN30
   50 GP=53247:GI=3:LC=64:W=32:K1=5:K2=3:K3=65:K4=33:P=1
   60 VB=600:IFPEEK(57088)<129THENVB=540:GOTO90
   70 IFVB<>600THEN60 
   80 P=254:LC=32
   90 G1=INT(GP+26*LC+.5*W):T=G1+1:T2=T:MP=GP+21*LC
   100 FORX=1TO5:READG(X),ID(X):D(X)=ID(X):NEXT
   110 S1=GP+15*LC:S3=GP+11*LC+W:S(1)=S1:S(2)=S1+1:S(3)=S3:S(4)=S3-1
   120 INPUT"REGULAR(1) OR MASTER'S (2) GAME";G:POKE530,1:POKE57088,P
   130 MN=MP:POKE56900,0:SD=GP+6*LC+8:S5=GP+7*LC+W+6:S(5)=S5:FM=-2
   140 FORX=1TO32:PRINT:NEXT:FORX=1TO32:POKEGP+3*LX+X,233
   150 POKEGP+29*LC+X,233
   160 IFVB=540THENPOKEGP+X*LC,233:POKEGP+32+X*LC,233
   170 POKEGP+X+13*LC,191:POKEGP+X+32*LC,233:NEXT
   180 POKEGP+14*LC+20,193:POKEGP+14*LC+21,193:POKEGP+13*LC+21,13
   190 P=PEEK(57088):IFVB=600THENP=255-P
   200 IFP=K1ANDGI<5THENGI=GI+1
   210 TURN=TURN+1:IFTURNS>300THEN660 
   220 IFP=K2ANDGI>1THENGI=GI-1
   230 S$=STR$(300-TU)
   240 FORX=2TOLEN(S$):POKESD+10+X,ASC(MID$(S$,X,1))
   250 NEXT
   260 POKESD+10+X,32
   270 POKEG1,G(GI):POKEG1+2,G(GI)
   280 IFP=K3ANDT=G1+1THENPOKET,32:MF=2*LC-3+GI:T=T-MF:POKET,16:GOTO300
   290 IFP=K3ANDT2=G1+1THENPOKET2,32:M2=2*LC-3+GI:T2=T2-M2:POKET2,16
   300 IFP=K4THENPOKE530,0:POKE56900,1:GOTO120
   310 IFG=1THENFORX=1TO75:NEXT
   320 POKES(1),32:POKES(3),32:POKES(5),32:S(1)=S(1)+1:S(5)=S(5)+FM
   330 IFS(1)=S1+WTHENS(1)=S1:D(1)=ID(1):D(2)=ID(2)
   340 S(2)=S(1)+1:S(3)=S(3)-1
   350 IFS(3)=S3-WTHENS(3)=S3:D(3)=ID(3):D(4)=ID(4)
   360 MC=MC+1:IFMC=5THENMC=1:GOSUB510
   370 IFS(5)=S5ORS(5)=(S5-W-6)THENFM=-FM:D(5)=ID(5)
   380 S(4)=S(3)-1:FORX=1TO5:POKES(X),D(X):NEXT
   390 IFT=G1+1THENFORX=1TO50:NEXT:GOTO450
   400 P=PEEK(T-LC):IFP<10THENGOSUB550 :GOTO450
   410 IFG=1THENP=PEEK(T-LC-1):IFP<10THENGOSUB550 
   420 IFP=127THENGOSUB550 :GOTO450
   430 IFT<GP+3*LCTHENPOKET,32:T=G1+1:POKET,16:GOTO450
   440 POKET,32:T=T-MF:POKET,29
   450 IFT2=G1+1THENFORX=1TO50:NEXT:GOTO190
   460 P=PEEK(T2-LC):IFP<10THENGOSUB560 :GOTO190
   470 IFG=1THENP=PEEK(T2-LC-1):IFP<10THENGOSUB560 :GOTO450
   480 IFP=127THENGOSUB560 :GOTO190
   490 IFT2<GP+3*LCTHENPOKET2,32:T2=G1+1:POKET2,16:GOTO190
   500 POKET2,32:T2=T2-M2:POKET2,29:GOTO190
   510 POKEMN,32:POKEMN+8,32:POKEMN+16,32:MN=MN+1
   520 IFMN=MP+W+8THENMN=MP
   530 POKEMN,127:IFSC>10THENPOKEMN+8,127:IFSC>30THENPOKEMN+16,127:RETURN
   540 RETURN
   550 POKET,32:Q=T-LC-3:T=G1+1:POKET,16:GOTO570 
   560 POKET2,32:Q=T2-LC-3:T2=G1+1:POKET2,16
   570 D=42
   580 FORX=1TO5:POKEQ+X,D:NEXT:IFD=42THEND=32:GOTO580 
   590 IFP=7ORP=8THEND(1)=32:D(2)=32
   600 IFP=5ORP=6THEND(3)=32:D(4)=32
   610 IFP=4THEND(5)=32:SC=SC+5
   620 IFP=127THENRETURN
   630 SC=SC+1:POKEG1+1,16:PS=SC:OS=0
   640 IFSC>9THENOS=INT(SC/10):PS=(SC-10*OS)
   650 POKESD,OS+48:POKESD+1,PS+48:POKESD+2,48:POKESD+3,48:RETURN
   660 PRINT"FINAL SCORE "SC*100:A$="DROWNER'":IFSC>9THENA$="AMATEURS"
   670 IFSC>15THENA$="MASTERS":IFSC>20THENA$="CAPTAIN'S"
   680 IFSC>25THENA$="COMMODORE'S":IFSC>30THENA$="ADMIRALS"
   690 PRINT"YOU EARNED YOUR "A$ "STRIPES":SC=0:TU=0:GOTO120
   700 PRINT:PRINT:PRINT:PRINT"THE LEFT SHIFT AIMS THE TUBE TO THE LEFT
   710 PRINT"THE RIGHT SHIFT AIMS THE TUBE RIGHT
   720 PRINT"THE CTRL KEY FIRES A TORPEDOE-YOU CAN FIRE 
   730 PRINT"UP TOO 2 TORPEDOES AT A TIME
   740 PRINT"THE SMALL SHIP IS 500 POINTS":PRINT"ALL OTHER SHIPS ARE 100
   750 PRINT"HIT ESC TO END THE GAME EARLY
   760 INPUT"READY TO START";A$
   765 PRINT:PRINT:PRINT:GOTO50
   770 DATA189,7,201,8,140,6,200,5,190,4
