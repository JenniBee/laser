#ifndef _OSILINE_H_
#define _OSILINE_H_

typedef union {
#ifdef LSB_FIRST
  struct { byte l,h; } B;
#else
  struct { byte h,l; } B;
#endif
  word W;
} pair;

/* WARNING! Z80 specific code */
typedef struct {
  pair AF,BC,DE,HL,IX,IY,PC,SP;
  pair AF1,BC1,DE1,HL1;
  byte IFF,I;
} reg;

void ResetZ80(reg *Regs);
word Z80(reg Regs);


/* WARNING! 6502 specific code */
typedef struct {
  byte A,P,X,Y,S;     /* CPU registers and program counter   */
  pair PC;

  int IPeriod,ICount; /* Set IPeriod to number of CPU cycles */
                      /* between calls to driver->loop()         */
  byte IRequest;      /* Set to the INT_IRQ when pending IRQ */
  byte AfterCLI;      /* Private, don't touch                */
  int IBackup;        /* Private, don't touch                */
  void *User;         /* Arbitrary user data (ID,RAM*,etc.)  */
  byte TrapBadOps;    /* Set to 1 to warn of illegal opcodes */
  word Trap;          /* Set Trap to address to trace from   */
  byte Trace;         /* Set Trace=1 to start tracing        */
} M6502;

void Reset6502(register M6502 *R);
word Exec6502(register M6502 *R);

#endif
