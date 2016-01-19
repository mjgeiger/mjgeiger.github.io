	;; Student Name:
	;; Student ID:
	;; Partner:
	;;
	;; By submitting this source code,
	;; I (We) certify that the following code is my (our) own work, and
	;; I (We) understand and accept that I am (We are) subject to administrative penalty
	;; if the code submitted here is found to be a result of plagiarism.
	;; 
; UMass Lowell 16.317 Microprocessors I 
;
; Lab 3: input, calculate and ouput
; 
; Skeleton code
;
;
; For use in UMass Lowell 16.317 Microprocessor I only.
; Please contact Prof. Michael Geiger (Michael_Geiger@uml.edu) if you'd like to distribute it.
;  
; In this lab, you will need to write your assembly
; language program to :  
;
; (1) let user input three hexdecimal numbers from keyboard 
; (2) sort the numbers in ascending order
; (3) print out the sorted numbers in hexdecimal
;   


;========== Stack ==============================================
stack_seg       segment		stack 'stack'
		db		1024 dup(?)
stack_seg       ends

;========== Data ===============================================
data_seg        segment         'data'
msg1 		db "Enter the first number:  $"
msg2 		db "Enter the second number:  $"
msg3            db "I am in the subroutine call $"
newline 	db 0Dh, 0Ah, "$"
data_seg	ends


code_seg        segment         'input_calculate_output'

;;===============================================================
;; Lab3 Main
;;----------------------------------------------
Lab3		proc		far
		assume cs:code_seg, ss:stack_seg, ds:data_seg

		push ds                 ;proper return to DOS 
		push ax
		mov ax, data_seg        ;set up DS
		mov ds, ax

; now print out prompt string
       mov dx, offset msg1
       mov ah, 9
       int 21h

       ; read a character in al:
       mov ah, 1 
       int 21h
           
       ; first number is copied to BL,
       ; NOTE: you need to convert ASCII to real number !!!     
       mov bl, al

; now print out new line
       mov dx, offset newline
       mov ah, 9
       int 21h

       
; now print out prompt string
       mov dx, offset msg2
       mov ah, 9
       int 21h

       ; read a character in al:
       mov ah, 1 
       int 21h

; now print out new line
       mov dx, offset newline
       mov ah, 9
       int 21h

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Now you have two "numbers" in AL and BL, respectively. 
; (NOTE: REMEMBER, YOU NEED THREE NUMBERS FOR THIS PROGRAM)
; However, they are NOT really numbers.  
; For example, when the user type '9' from keyboard, the
; value 39H, the ASCII code of character '9', is stored in AL. 
;
; You need to sort the numbers using actual numeric values.
; Thus, it is necessary to "convert" them to real numbers
; We suggest performing the conversion in a subroutine that
; can be called to convert each input value.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; example of a subroutine call
       call mysubroutine

; We are done here. Stop the program.
       stop: ret  ; stop

Lab3            endp

; mysubroutine is an example subroutine
; it simply prints out a message
; You should modify this code so that
;  this subroutine converts an ASCII
;  value to a hexadecimal integer 

mysubroutine   proc
                mov dx, offset msg3
                mov ah,9
                int 21h
                ret
mysubroutine   endp

code_seg        ends
		end	Lab3