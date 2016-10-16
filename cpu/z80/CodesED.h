/** Z80: portable Z80 emulator *******************************/
/**                                                         **/
/**                         CodesED.h                       **/
/**                                                         **/
/** This file contains implementation for the ED table of   **/
/** Z80 commands. It is included from Z80.c.                **/
/**                                                         **/
/** Copyright (C) Marat Fayzullin 1994,1995,1996            **/
/**     You are not allowed to distribute this software     **/
/**     commercially. Please, notify me, if you make any    **/
/**     changes to this file.                               **/
/*************************************************************/

/*** This is a special patch for emulating BIOS calls: *******/
case DB_FE:     driver.patch(&R);break;
/*************************************************************/

case ADC_HL_BC: M_ADCW(BC);break;
case ADC_HL_DE: M_ADCW(DE);break;
case ADC_HL_HL: M_ADCW(HL);break;
case ADC_HL_SP: M_ADCW(SP);break;

case SBC_HL_BC: M_SBCW(BC);break;
case SBC_HL_DE: M_SBCW(DE);break;
case SBC_HL_HL: M_SBCW(HL);break;
case SBC_HL_SP: M_SBCW(SP);break;

case LD_xWORDe_HL:
  J.B.l=driver.rdmem(R.PC.W++);
  J.B.h=driver.rdmem(R.PC.W++);
  driver.wrmem(J.W++,R.HL.B.l);
  driver.wrmem(J.W,R.HL.B.h);
  break;
case LD_xWORDe_DE:
  J.B.l=driver.rdmem(R.PC.W++);
  J.B.h=driver.rdmem(R.PC.W++);
  driver.wrmem(J.W++,R.DE.B.l);
  driver.wrmem(J.W,R.DE.B.h);
  break;
case LD_xWORDe_BC:
  J.B.l=driver.rdmem(R.PC.W++);
  J.B.h=driver.rdmem(R.PC.W++);
  driver.wrmem(J.W++,R.BC.B.l);
  driver.wrmem(J.W,R.BC.B.h);
  break;
case LD_xWORDe_SP:
  J.B.l=driver.rdmem(R.PC.W++);
  J.B.h=driver.rdmem(R.PC.W++);
  driver.wrmem(J.W++,R.SP.B.l);
  driver.wrmem(J.W,R.SP.B.h);
  break;

case LD_HL_xWORDe:
  J.B.l=driver.rdmem(R.PC.W++);
  J.B.h=driver.rdmem(R.PC.W++);
  R.HL.B.l=driver.rdmem(J.W++);
  R.HL.B.h=driver.rdmem(J.W);
  break;
case LD_DE_xWORDe:
  J.B.l=driver.rdmem(R.PC.W++);
  J.B.h=driver.rdmem(R.PC.W++);
  R.DE.B.l=driver.rdmem(J.W++);
  R.DE.B.h=driver.rdmem(J.W);
  break;
case LD_BC_xWORDe:
  J.B.l=driver.rdmem(R.PC.W++);
  J.B.h=driver.rdmem(R.PC.W++);
  R.BC.B.l=driver.rdmem(J.W++);
  R.BC.B.h=driver.rdmem(J.W);
  break;
case LD_SP_xWORDe:
  J.B.l=driver.rdmem(R.PC.W++);
  J.B.h=driver.rdmem(R.PC.W++);
  R.SP.B.l=driver.rdmem(J.W++);
  R.SP.B.h=driver.rdmem(J.W);
  break;

case RRD:
  I=driver.rdmem(R.HL.W);
  J.B.l=(I>>4)|(R.AF.B.h<<4);
  driver.wrmem(R.HL.W,J.B.l);
  R.AF.B.h=(I&0x0F)|(R.AF.B.h&0xF0);
  R.AF.B.l=PZSTable[R.AF.B.h]|(R.AF.B.l&C_FLAG);
  break;
case RLD:
  I=driver.rdmem(R.HL.W);
  J.B.l=(I<<4)|(R.AF.B.h&0x0F);
  driver.wrmem(R.HL.W,J.B.l);
  R.AF.B.h=(I>>4)|(R.AF.B.h&0xF0);
  R.AF.B.l=PZSTable[R.AF.B.h]|(R.AF.B.l&C_FLAG);
  break;

case LD_A_I:
  R.AF.B.h=R.I;
  R.AF.B.l=(R.AF.B.l&C_FLAG)|(R.IFF&1? P_FLAG:0)|ZSTable[R.AF.B.h];
  break;

case LD_A_R:
#ifdef INTERRUPTS
  R.AF.B.h=(byte)(-ICount&0xFF);
#endif
  R.AF.B.l=(R.AF.B.l&C_FLAG)|(R.IFF&1? P_FLAG:0)|ZSTable[R.AF.B.h];
  break;

case LD_I_A:   R.I=R.AF.B.h;break;
case LD_R_A:   break;

case IM_0:     R.IFF&=0xF9;break;
case IM_1:     R.IFF=(R.IFF&0xF9)|2;break;
case IM_2:     R.IFF=(R.IFF&0xF9)|4;break;

case RETI:     M_RET;break;
case RETN:     if(R.IFF&0x40) R.IFF|=0x01; else R.IFF&=0xFE;
               M_RET;break;

case NEG:      I=R.AF.B.h;R.AF.B.h=0;M_SUB(I);break;

case IN_B_xC:  M_IN(R.BC.B.h);break;
case IN_C_xC:  M_IN(R.BC.B.l);break;
case IN_D_xC:  M_IN(R.DE.B.h);break;
case IN_E_xC:  M_IN(R.DE.B.l);break;
case IN_H_xC:  M_IN(R.HL.B.h);break;
case IN_L_xC:  M_IN(R.HL.B.l);break;
case IN_A_xC:  M_IN(R.AF.B.h);break;
case IN_F_xC:  M_IN(J.B.l);break;

case OUT_xC_B: driver.doout(R.BC.B.l,R.BC.B.h);break;
case OUT_xC_C: driver.doout(R.BC.B.l,R.BC.B.l);break;
case OUT_xC_D: driver.doout(R.BC.B.l,R.DE.B.h);break;
case OUT_xC_E: driver.doout(R.BC.B.l,R.DE.B.l);break;
case OUT_xC_H: driver.doout(R.BC.B.l,R.HL.B.h);break;
case OUT_xC_L: driver.doout(R.BC.B.l,R.HL.B.l);break;
case OUT_xC_A: driver.doout(R.BC.B.l,R.AF.B.h);break;

case INI:
  driver.wrmem(R.HL.W++,driver.doin(R.BC.B.l));R.BC.B.h--;
  R.AF.B.l=N_FLAG|(R.BC.B.h? 0:Z_FLAG);
  break;

case INIR:
#ifdef INTERRUPTS
  ICount=(ICount>R.BC.B.h)? ICount-R.BC.B.h:1;
#endif
  do
  { driver.wrmem(R.HL.W++,driver.doin(R.BC.B.l));R.BC.B.h--; }
  while(R.BC.B.h);
  R.AF.B.l=Z_FLAG|N_FLAG;break;

case IND:
  driver.wrmem(R.HL.W--,driver.doin(R.BC.B.l));R.BC.B.h--;
  R.AF.B.l=N_FLAG|(R.BC.B.h? 0:Z_FLAG);
  break;

case INDR:
#ifdef INTERRUPTS
  ICount=(ICount>R.BC.B.h)? ICount-R.BC.B.h:1;
#endif
  do
  { driver.wrmem(R.HL.W--,driver.doin(R.BC.B.l));R.BC.B.h--; }
  while(R.BC.B.h);
  R.AF.B.l=Z_FLAG|N_FLAG;break;

case OUTI:
  driver.doout(R.BC.B.l,driver.rdmem(R.HL.W++));R.BC.B.h--;
  R.AF.B.l=N_FLAG|(R.BC.B.h? 0:Z_FLAG);
  break;

case OTIR:
#ifdef INTERRUPTS
  ICount=(ICount>R.BC.B.h)? ICount-R.BC.B.h:1;
#endif
  do
  { driver.doout(R.BC.B.l,driver.rdmem(R.HL.W++));R.BC.B.h--; }
  while(R.BC.B.h);
  R.AF.B.l=Z_FLAG|N_FLAG;break;

case OUTD:
  driver.doout(R.BC.B.l,driver.rdmem(R.HL.W--));R.BC.B.h--;
  R.AF.B.l=N_FLAG|(R.BC.B.h? 0:Z_FLAG);
  break;

case OTDR:
#ifdef INTERRUPTS
  ICount=(ICount>R.BC.B.h)? ICount-R.BC.B.h:1;
#endif
  do
  { driver.doout(R.BC.B.l,driver.rdmem(R.HL.W--));R.BC.B.h--; }
  while(R.BC.B.h);
  R.AF.B.l=Z_FLAG|N_FLAG;break;

case LDI:
  driver.wrmem(R.DE.W++,driver.rdmem(R.HL.W++));R.BC.W--;
  R.AF.B.l=(R.AF.B.l&~(N_FLAG|H_FLAG|P_FLAG))|(R.BC.W? P_FLAG:0);
  break;

case LDIR:
#ifdef INTERRUPTS
  ICount=(ICount>R.BC.W)? ICount-R.BC.W:1;
#endif
  do
  { driver.wrmem(R.DE.W++,driver.rdmem(R.HL.W++));R.BC.W--; }
  while(R.BC.W);
  R.AF.B.l&=~(N_FLAG|H_FLAG|P_FLAG);break;

case LDD:
  driver.wrmem(R.DE.W--,driver.rdmem(R.HL.W--));R.BC.W--;
  R.AF.B.l=(R.AF.B.l&~(N_FLAG|H_FLAG|P_FLAG))|(R.BC.W? P_FLAG:0);
  break;

case LDDR:
#ifdef INTERRUPTS
  ICount=(ICount>R.BC.W)? ICount-R.BC.W:1;
#endif
  do
  { driver.wrmem(R.DE.W--,driver.rdmem(R.HL.W--));R.BC.W--; }
  while(R.BC.W);
  R.AF.B.l&=~(N_FLAG|H_FLAG|P_FLAG);break;

case CPI:
  I=driver.rdmem(R.HL.W++);J.B.l=R.AF.B.h-I;R.BC.W--;
  R.AF.B.l=
    N_FLAG|(R.AF.B.l&C_FLAG)|ZSTable[J.B.l]|
    ((R.AF.B.h^I^J.B.l)&H_FLAG)|(R.BC.W? P_FLAG:0);
  break;

case CPIR:
  do
  { I=driver.rdmem(R.HL.W++);J.B.l=R.AF.B.h-I;R.BC.W--; }  
  while(R.BC.W&&J.B.l);
  R.AF.B.l=
    N_FLAG|(R.AF.B.l&C_FLAG)|ZSTable[J.B.l]|
    ((R.AF.B.h^I^J.B.l)&H_FLAG)|(R.BC.W? P_FLAG:0);
  break;  

case CPD:
  I=driver.rdmem(R.HL.W--);J.B.l=R.AF.B.h-I;R.BC.W--;
  R.AF.B.l=
    N_FLAG|(R.AF.B.l&C_FLAG)|ZSTable[J.B.l]|
    ((R.AF.B.h^I^J.B.l)&H_FLAG)|(R.BC.W? P_FLAG:0);
  break;

case CPDR:
  do
  { I=driver.rdmem(R.HL.W--);J.B.l=R.AF.B.h-I;R.BC.W--; }
  while(R.BC.W&&J.B.l);
  R.AF.B.l=
    N_FLAG|(R.AF.B.l&C_FLAG)|ZSTable[J.B.l]|
    ((R.AF.B.h^I^J.B.l)&H_FLAG)|(R.BC.W? P_FLAG:0);
  break;
