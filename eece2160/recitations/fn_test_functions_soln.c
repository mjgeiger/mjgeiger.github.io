//
//  fn_test_functions.c
//
//  Created by Michael Geiger on 10/17/16.
//  Source file to hold function definitions for recitation exercise
//  **** SOLUTION ****
//

#include "fn_test_functions.h"

// Returns 1 if both x and y fall between 0 and n - 1, inclusive
int check_val(int x, int y, int n) {
	if (x >= 0 && x <= n-1 && y >= 0 && y <= n-1)
		return 1;
	else
		return 0;
}

// Returns number of digits in n
int num_digits(int n) {
	int ndig = 0;	// Number of digits
	
	// Repeatedly divide n by 10 until result is 0
	// Each time you divide by 10, count one digit
	while (n > 0) {
		n = n / 10;
		ndig++;
	}
	
	return ndig;
}

// Returns kth digit from the right in n
int digit(int n, int k) {
	int cur_digit =	0;	// Current digit
	int ndig = 0;		// Number of digits found so far
	
	// Repeat as long as (1) haven't divided out all digits, and
	//   (2) digit position is < k (once positions match, found
	//   desired digit)
	while (n > 0 && ndig < k) {
		cur_digit = n % 10;			// Remainder of dividing by 10 = rightmost digit
		// For example, 123 % 10 = 3; 95 % 10 = 5
		n = n / 10;					// Dividing by 10 removes rightmost digit
		ndig++;
	}
	
	// If ndig < k, must have exited because n > 0
	// Implies number has fewer than k digits --> return 0
	if (ndig < k)
		return 0;
	
	// Otherwise, cur_digit holds kth digit from right
	else
		return cur_digit;
}

// Given time in seconds since midnight (total_sec), divide
//   time into hours, minutes, and seconds
void split_time(int total_sec, int *hr, int *min, int *sec) {
	
	// 1 hour = 3600 sec --> # hours = total_sec / 3600
	*hr = total_sec / 3600;
	
	// Remove hours using modulus, and you're left with minutes/seconds
	total_sec = total_sec % 3600;
	
	// 1 minute = 60 sec --> # minutes = total_sec / 60, # seconds = total_sec % 60
	*min = total_sec / 60;
	*sec = total_sec % 60;
}

// Given fraction defined by num/den, calculate GCD and
//   use GCD to reduce fraction, storing reduced numerator
//   and denominator in locations indicated by rNum & rDen
void reduceFraction(int num, int den, int *rNum, int *rDen) {
	int gcd;    // Greatest common divisor
	int rem;    // Remainder
	int temp;	// Temporary value
	
	/* GCD calculation via Euclid's algorithm:
	 If temp == 0, then gcd == greatest common divisor
	 Otherwise, set temp = gcd % temp, and
	 gcd = old value of temp */
	gcd = den;
	temp = num;
	
	while (temp != 0) {
		rem = gcd % temp;
		gcd = temp;
		temp = rem;
	}
	
	// Divide num and den by gcd to get reduced
	//   numerator and denominator
	*rNum = num / gcd;
	*rDen = den / gcd;
}

