/*
* 16.216 ECE Application Programming
* Fall 2011
* prog3_bits.c: Instructor solution to third programming assignment
*   by Dr. Michael Geiger
* Tests bitwise operations, both for a single bit and a range of bits
*/

#include <stdio.h>

int main() {
	unsigned int input1, input2;		// Input values
	int single_bit;						// Single bit to be changed
	int range_low, range_high;			// Ends of range to be changed
	int rot_arith_amt;					// EXTRA CREDIT: # of bits
										//   to use in rotate left/
										//   arithmetic shift right ops
	unsigned int mask;					// Bit mask to be used for multi-bit changes

	// Read input values in hex
	printf("Enter two values in hexadecimal: ");
	scanf("%x%x", &input1, &input2);

	// Read bit numbers to be changed
	printf("Enter single bit position to be changed: ");
	scanf("%d", &single_bit);
	printf("Enter lowest and highest bits to be changed: ");
	scanf("%d%d", &range_low, &range_high);
	 
	// Set mask so that bits between (and including) positions range_low -- range_high are 1
	mask = 0xFFFFFFFF >> (31 - range_high);
	mask = mask & (0xFFFFFFFF << range_low);

	/* NOTE: My code originally used the following method, which works ... unless range_high == 31.
	
	   mask = 0xFFFFFFFF << (range_high + 1);
	   mask = mask ^ (0xFFFFFFFF << range_low);

	   What I found through a quick online search is that bit shift operations are undefined if the shift
	     amount is greater than or equal to the number of bits in the number--it's up to the compiler to 
	     determine how to handle that case.

	   What Visual Studio does is modulo arithmetic on the bit shift amount--any time you use a shift, it
	     determines the shift amount by doing (shift_amount % 32). So, if you try to shift a number by
		 32 bits, code compiled in Visual Studio will shift it by (32 % 32), or 0.
	   
	   Another solution that uses only bit shift operations is shown below. Consider:

	   1. The total # of ones in your bit mask is (range_high - range_low + 1)
	   2. To generate the correct number of ones, you can shift by (32 - # of ones), or:
	       (32 - (range_high - range_low + 1)) = (31 - range_high + range_low)
		  It doesn't matter if you left shift or right shift by this amount.
	   3. To get those ones in the correct position:
	      --If you left shifted in step 2, you have to right shift until the most significant one (which is 
		    currently in position 31) is in position range_high--your shift amount is (31 - range_high).
		  --If you right shifted in step 2, you have to left shift until the least significant one (which is
		    currently in position 0) is in position range_low--your shift amount is range_low.

	   Therefore, to determine your bit mask in this way, you can use:

	   mask = (0xFFFFFFFF << (31 - range_high + range_low)) >> (31-range_high);
	*/

	// Output values for single bit changes
	printf("\nSINGLE BIT CHANGES\n");
	printf("   Input    Bit %2d set   Bit %2d cleared  Bit %2d flipped\n", single_bit, single_bit, single_bit);
	printf("%#010x  %#010x     %#010x      %#010x\n", input1, 
			input1 | (1 << single_bit),
			input1 & ~(1 << single_bit), 
			input1 ^ (1 << single_bit));
	printf("%#010x  %#010x     %#010x      %#010x\n", input2, 
			input2 | (1 << single_bit),
			input2 & ~(1 << single_bit), 
			input2 ^ (1 << single_bit));

	// Output values for multi-bit changes
	printf("\nMULTI-BIT CHANGES\n");
	printf("   Input    %2d-%2d set    %2d-%2d cleared   %2d-%2d flipped\n", 
			range_low, range_high, range_low,
			range_high, range_low, range_high);
	printf("%#010x  %#010x     %#010x      %#010x\n", input1, 
			input1 | mask,
			input1 & ~mask, 
			input1 ^ mask);
	printf("%#010x  %#010x     %#010x      %#010x\n\n", input2, 
			input2 | mask,
			input2 & ~mask, 
			input2 ^ mask);

	// Output values for extra credit changes
	printf("EXTRA CREDIT\n");
	printf("Amount to use in rotate/arithmetic shift: ");
	scanf("%d", &rot_arith_amt);
	printf("Rotates: %#010x %#010x\n",
		(input1 << rot_arith_amt) | (input1 >> (32-rot_arith_amt)),
		(input2 << rot_arith_amt) | (input2 >> (32-rot_arith_amt)));
	printf("Arithmetic shifts: %#010x %#010x\n\n",
		(input1 >> rot_arith_amt) | ((0xFFFFFFFF << (32-rot_arith_amt)) * (input1 >> 31)),
		(input2 >> rot_arith_amt) | ((0xFFFFFFFF << (32-rot_arith_amt)) * (input2 >> 31)));
	return 0;
}
