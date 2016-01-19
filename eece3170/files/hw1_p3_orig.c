#include <conio.h>

char *buffer = "Enter a number between 0 and 1000: ";
char *buffer1 = "Base: ";
int a, b = 0;

void disps(int base, int data);

void main() {
	int i;

	_cputs(buffer);
	a = _getche();
	while ((a >= '0') && (a <= '9')) {

		_asm sub a, 30h;
		b = b * 10 + a;
		a = _getche();
	}

	_putch(10);
	_putch(10);
	_putch(13);
	for (i = 2; i < 17; i++) {
		_cputs(buffer1);
		disps(10, i);
		_putch(' ');
		_putch('=');
		_putch(' ');
		disps(i, b);
		_putch(10);
		_putch(13);
	}
	_getche();
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
	_putch(temp);
	_asm jmp disps2;
	
	disps4:;
}