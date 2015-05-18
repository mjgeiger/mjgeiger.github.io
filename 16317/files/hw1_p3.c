#include <stdio.h>

char *buffer = "Enter a number between 0 and 1000: ";
char *buffer1 = "Base: ";
int a, b = 0;

void disps(int base, int data);

void main() {
	int i;

	printf(buffer);
	a = getchar();

	while ((a >= '0') && (a <= '9')) {

		_asm sub a, 30h;
		b = b * 10 + a;
		a = getchar();
	}

	putchar(10);
	putchar(10);
	putchar(13);
	for (i = 2; i < 17; i++) {
		printf(buffer1);
		disps(10, i);
		putchar(' ');
		putchar('=');
		putchar(' ');
		disps(i, b);
		putchar(10);
		putchar(13);
	}
	getchar();
}

void disps(int base, int data) {

	int temp;
	_asm
	{
		mov		eax, data
		mov		ebx, base
		push	ebx
	disps1:
		mov		edx, 0
		div		ebx
		push	edx
		cmp		eax, 0
		jne		disps1
	disps2:
		pop		edx
		cmp		ebx, edx
		je		disps4
		add		dl, 30h
		cmp		dl, 39h
		jbe		disps3
		add		dl, 7
	disps3:
		mov		temp, edx
	}
	putchar(temp);
	_asm jmp disps2;
	
	disps4:;
}