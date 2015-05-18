/* 
 * 16.317: Microprocessors I
 * UMass Lowell
 * Instructor: M. Geiger
 * Source file for HW 2, Problem #2
 * 2/8/2014
 */

#include <stdio.h>

char  blist[] = {0x16, 0x31, 0x72, 0x01, 0xEC, 0xE2, 0x08};
short wlist[] = {0x1234, 0xAABB, 0x7183, 0x4599};
int   dlist[] = {0xDEADBEEF, 0xAF021131, 0x7819A3B2};

void main() {
	
	_asm {
		// Parts a-d: Initializing registers using constants
		mov eax, 0
		mov ebx, -1
		mov ecx, 0xDEADBEEF
		mov edx, 0xFF

		mov ax, 0xFFFF
		mov ah, 0xAA

		// Part e: Copying values between registers
		mov edx, eax
		mov bx, cx
		mov ah, al

		// Parts f-h: Memory transfers
		mov	  al, [blist]
		mov	  ah, [blist+6]
		movsx bx, [blist+5]
		movzx cx, [blist+5]

		mov   bx, [wlist]
		movsx ecx, [wlist+2]
		mov   [wlist+4], cx

		mov   esi, 0
	L:
		mov   eax, [dlist + 4*esi]
		inc   esi
		cmp   esi, 3
		jl    L
	}
}