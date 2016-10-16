/** Z80: portable Z80 emulator *******************************/
/**                                                         **/
/**                           Z80.h                         **/
/**                                                         **/
/** This file contains declarations relevant to emulation   **/
/** of Z80 CPU.                                             **/
/**                                                         **/
/** Copyright (C) Marat Fayzullin 1994,1995,1996            **/
/**     You are not allowed to distribute this software     **/
/**     commercially. Please, notify me, if you make any    **/   
/**     changes to this file.                               **/
/*************************************************************/

#ifndef _Z80_H_
#define _Z80_H_

#define INTERRUPTS             /* Compile interrupts code    */
/*#define DEBUG */           /* Compile debugging version  */
/*#define LSB_FIRST */                     /* Compile for low-endian CPU */

#define S_FLAG      0x80
#define Z_FLAG      0x40
#define H_FLAG      0x10
#define P_FLAG      0x04
#define V_FLAG      0x04
#define N_FLAG      0x02
#define C_FLAG      0x01

/**********************************************************/
/*** NOTICE: sizeof(byte)=1 and sizeof(word)=2          ***/
/**********************************************************/
//typedef unsigned char byte;
//typedef unsigned short word;
//typedef signed char offset;

/**********************************************************/
/*** #define LSB_FIRST for machines where least         ***/
/*** signifcant byte goes first.                        ***/
/**********************************************************/
/*typedef union
{
#ifdef LSB_FIRST
  struct { byte l,h; } B;
#else
  struct { byte h,l; } B;
#endif
  word W;
} pair;

typedef struct
{
  pair AF,BC,DE,HL,IX,IY,PC,SP;
  pair AF1,BC1,DE1,HL1;
  byte IFF,I;
} reg;
*/
/*** Interrupts *******************************************/
/*** Interrupt-related variables.                       ***/
/**********************************************************/
#ifdef INTERRUPTS
extern int  IPeriod;  /* Number of commands between internal interrupts */
extern byte IntSync;  /* Generate internal interrupts if IntSync==1     */
//extern volatile byte IFlag;    /* If IFlag==1, generate interrupt and set to 0   */
extern byte IFlag;
#endif

/*** Trace and Trap ***************************************/         
/*** Switches to turn tracing on and off in DEBUG mode. ***/
/**********************************************************/
#ifdef DEBUG
extern byte Trace;  /* Tracing is on if Trace==1  */
extern word Trap;   /* When PC==Trap, set Trace=1 */
#endif

/*** TrapBadOps *******************************************/
/*** When 1, print warnings of illegal Z80 instructions.***/
/**********************************************************/
extern byte TrapBadOps;

/*** CPURunning *******************************************/
/*** When 0, execution terminates.                      ***/
/**********************************************************/
extern byte CPURunning;

/*** Reset Z80 registers: *********************************/
/*** This function can be used to reset the register    ***/
/*** file before starting execution with Z80(). It sets ***/
/*** the registers to their initial values.             ***/
/**********************************************************/
void ResetZ80(reg *Regs);

/*** Interpret Z80 code: **********************************/
/*** Registers have initial values from Regs. PC value  ***/
/*** at which emulation stopped is returned by this     ***/
/*** function.                                          ***/
/**********************************************************/
word Z80(reg Regs);

/*** Memory access: ***************************************/
/*** These functions are called when read or write to   ***/
/*** RAM occurs. They perform actual reads abd writes.  ***/
/**********************************************************/
void M_WRMEM(word A,byte V);
byte M_RDMEM(word A);

/*** Input/Output values from/to ports: *******************/
/*** These are called on IN and OUT commands and should ***/
/*** supplied by machine-dependent part of the code.    ***/
/**********************************************************/
byte DoIn(byte Port);
void DoOut(byte Port,byte Value);

/**********************************************************/
/*** Emulate BIOS calls. This function is called on the ***/
/*** ED FE instruction to emulate disk/tape access, etc.***/
/*** Replace it with an empty macro for now patching.   ***/
/**********************************************************/
void Patch(reg *R);

#ifdef DEBUG
/*** Single-step debugger *********************************/
/*** This function should exist if DEBUG is #defined.   ***/
/*** If Trace==1 it is called after each command        ***/
/*** executed by the CPU and given a pointer to the     ***/
/*** register file.                                     ***/
/**********************************************************/
void ZDebug(reg *R);
#endif

#ifdef INTERRUPTS
/*** Interrupt handler ************************************/
/*** This function should exist if INTERRUPTS is        ***/
/*** #defined. It is called on each attempted interrupt ***/
/*** and should return an interrupt address to proceed  ***/
/*** with interrupt or 0xFFFF to continue execution.    ***/ 
/**********************************************************/
word Interrupt(void);
#endif

#endif /* _Z80_H_ */
