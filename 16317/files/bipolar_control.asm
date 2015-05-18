 title  "asmStepper - PIC16F684 Bipolar Stepper Motor Control"
;
;  This Program Outputs a new Bipolar Stepper Motor Sequence
;   once every 250 ms.  
;
;  Hardware Notes:
;   PIC16F684 running at 4 MHz Using the Internal Clock
;   Internal Reset is Used
;   RC5:RC2 - L293D Stepper Motor Control
;
;
;  Myke Predko
;  05.01.14
;
  LIST R=DEC
 INCLUDE "p16f684.inc"

 __CONFIG _FCMEN_OFF & _IESO_OFF & _BOD_OFF & _CPD_OFF & _CP_OFF & _MCLRE_OFF & _PWRTE_ON & _WDT_OFF & _INTOSCIO

;  Variables
 CBLOCK 0x20
Dlay, i
 ENDC

  PAGE
;  Mainline

 org     0

  nop                           ;  For ICD Debug

  movlw   1 << 2                ;  Start with Bit 2 Active
  movwf   PORTC
  movlw   7                     ;  Turn off Comparators
  movwf   CMCON0
  bsf     STATUS, RP0           ;  Execute out of Bank 1
  clrf    ANSEL ^ 0x080         ;  All Bits are Digital
  movlw   b'000011'             ;  RC5:RC2 are Outputs
  movwf   TRISC ^ 0x080
  bcf     STATUS, RP0           ;  Return Execution to Bank 0

  clrf    i

Loop:                           ;  Return Here for Next Value
  movlw   HIGH ((250000 / 5) + 256)
  movwf   Dlay
  movlw   LOW ((250000 / 5) + 256)
  addlw   -1                    ;  
  btfsc   STATUS, Z
   decfsz Dlay, f
    goto  $ - 3

  movf    i, w
  call    SwitchRead
  movwf   PORTC

  incf    i, f                  ;  i = (i + 1) % 8;
  bcf     i, 3

  goto    Loop

SwitchRead:
  addwf   PCL, f                ;  Staying in First 256 Instructions
 dt       b'011100', b'010100', b'000100', b'100100'
 dt       b'100000', b'101000', b'111000', b'011000'


  end                           
