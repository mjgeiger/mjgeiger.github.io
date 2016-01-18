;Software License Agreement                                         
;                                                                    
;The software supplied herewith by Microchip Technology             
;Incorporated (the "Company") is intended and supplied to you, the  
;Company’s customer, for use solely and exclusively on Microchip    
;products. The software is owned by the Company and/or its supplier,
;and is protected under applicable copyright laws. All rights are   
;reserved. Any use in violation of the foregoing restrictions may   
;subject the user to criminal sanctions under applicable laws, as   
;well as to civil liability for the breach of the terms and         
;conditions of this license.                                        
;                                                                    
;THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,  
;WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED  
;TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A       
;PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,  
;IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR         
;CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.       
;****************************************************************************
;File Name:	Debounce.asm
;Author:	w.r.brown	
;Date:  	2 December 2002
;Version:	1.01	
;Description:	Single pole, single throw switch debounce  
;
;Modified:	1.01 1/27/03 w.r.brown 
;			Changed processor to PIC12F675. Added initialization 
;			code to change analog inputs to digital I/O.
;
;Modified:  1.16F in 2009-4-10 by Piti
;           Changed processor to PIC16F684.  Changed some lines.
;           (For Microprocessor 1 at ECE, UMassLowell, Spring 2009)
;
;******************************************************************************
;Notes:
;******************************************************************************
;    Each button push toggles LED D0.
;
;    This program demonstrates a simple brute force polled switch
;    debounce routine. Toggle action is initiated immediately on switch 
;    closure. Further action is inhibited until the switch is    
;    released and fully debounced.                               
;
;******************************************************************************
  
	list      p=16F684    ; list directive to define processor
	#include <p16f684.inc> ; processor specific variable definitions

	__CONFIG  _CP_OFF & _WDT_OFF & _BOD_ON & _PWRTE_ON & _INTRC_OSC_NOCLKOUT & _MCLRE_OFF & _CPD_OFF

; '__CONFIG' directive is used to embed configuration word within .asm file.
; The labels following the directive are located in the respective .inc file.
; See data sheet for additional information on configuration word settings.

;******************************************************************************
;Defines
;******************************************************************************

#define Bank0		0x00
#define	Bank1		0x80
#define SWITCH		PORTA,3
#define D0_1Tris	B'11001111'
#define D0On		B'00010000'
#define D0Off		B'00000000'
#define LEDOn		Flags,0

;******************************************************************************
;General Purpose Registers (GPR's) 
;******************************************************************************

	cblock	0x20
	Flags			; LED flags
	CountH			; debounce counter - MS Byte
	CountL			; debounce counter - LS Byte
	endc

;******************************************************************************
;Reset Vector 
;******************************************************************************
	ORG     0x000         	; processor reset vector
	nop			; required by in circuit debugger  
	goto    Init            ; go to beginning of program

;******************************************************************************
;Interrupt Vector     
;******************************************************************************
	ORG	0x004
	return			; interrupt trap - returns without re-enabling
;******************************************************************************
;Initialization
;******************************************************************************
Init
	;call    0x3FF      ; retrieve factory calibration value
						; comment instruction if using simulator, ICD2, or ICE2000
	BANKSEL	Bank1		; BANK1
	movwf   OSCTUNE          ; update register with factory cal value 
	movlw	D0_1Tris	; set direction so LEDs D0 & D1 are outputs
	movwf	TRISA		; all others are inputs (high-z)
	clrf	ANSEL		; configure A/D I/O as digital
	banksel	Bank0		; change back to PORT memory bank
	movlw	CM2 | CM1 | CM0 ; configure comparator inputs as digital I/O
	movwf	CMCON0		;
	clrf	Flags		; set initial LED state as off
	call	ToggleLED	; light initial LED

;******************************************************************************
;Main 
;******************************************************************************
Main
	btfsc	SWITCH		; wait in loop until SWITCH closure is sensed
	goto	Main		; SWITCH closure grounds input pin
	
	call	ToggleLED	; SWITCH closure sensed - toggle LED
	call	SwitchDebounce	; wait for switch to release and settle
	goto	Main

;******************************************************************************
;Subroutines & Functions
;******************************************************************************

;******************************************************************************
;ToggleLED - Toggles D0 on and off
;******************************************************************************
ToggleLED
	btfss	LEDOn		; test flag of present LED condition
	goto	TurnLedOn	; the LED is presently off - go turn it on
	
TurnLedOff
	bcf	LEDOn		; clear flag to indicate LED is off
	movlw	D0Off		; data for all LED outputs low
	movwf	PORTA		; send data to PORTA port
	return			; return to calling routine
	
TurnLedOn
	bsf	LEDOn		; set flag to indicate LED is on
	movlw	D0On		; data to forward bias LED0 and reverse bias LED1
	movwf	PORTA		; send data to PORTA port
	return			; return to calling routine

;******************************************************************************
;SwitchDebounce - Waits for switch to release and settle
;******************************************************************************
SwitchDebounce
; The SWITCH must be a steady high for 10 milliseconds to be considered  
; released and debounced. The debounce routine sets a 10 mSec timer and looks 
; for a high SWITCH input. The timer is reset to 10 mSec for every occurance of
; a low SWITCH input.
;
; Debounce timer constants (TenMSH and TenMSL) are a function of the 
; instruction execution time and number of instructions in each loop. Debounce
; time for this example is:
; Timer overhead + TenMSH * [outer loop time + (TenMSL * inner loop time)]
; or [2 + TenMSH * (5 + (TenMSL * 5))]*(4/fosc)= .010
;
; Arbitrarily choosing 99 for TenMSL we solve for TenMSH
; 2 + TenMSH * (5 + (99 * 5)) = 10,000
; TenMSH = 9998/500 ~ 20

#define TenMSH 		D'20'
#define TenMSL		D'99'

	movlw	TenMSH		; set outer timer loop count
	movwf	CountH		; outer loop overhead is 2 instructions

;========== outer loop [TenMSH * 5 instruction cycles*(Inner loop time)] ======
SD10
	movlw	TenMSL		; set inner timer loop
	movwf	CountL
;----------------- inner loop (TenMSL * 5 instruction cycles) -----------------
SD20
	btfss	SWITCH		; test SWITCH input
	goto	SwitchDebounce	; SWITCH was low - reset timer
	
	decfsz	CountL,f	; inner loop countdown
	goto	SD20		; test SWITCH while counting

;-------------------------------- inner loop ----------------------------------
	
	decfsz	CountH,f	; outer loop countdown
	goto	SD10		; reset inner loop after each outer loop count

;================================ outer loop ==================================

	return			; full countdown and no bounces achieved - exit
	
	END			; directive 'end of program'


