//
//  fn_test_functions.h
//
//  Created by Michael Geiger on 10/17/16.
//  Header file to hold function prototypes for recitation exercise
//

#ifndef fn_test_functions_h
#define fn_test_functions_h

// Returns 1 if both x and y fall between 0 and n - 1, inclusive
int check_val(int x, int y, int n);

// Returns number of digits in n
int num_digits(int n);

// Returns kth digit from the right in n
int digit(int n, int k);

// Given time in seconds since midnight (total_sec), divide
//   time into hours, minutes, and seconds
void split_time(int total_sec, int *hr, int *min, int *sec);

// Given fraction defined by num/den, calculate GCD and
//   use GCD to reduce fraction, storing reduced numerator
//   and denominator in locations indicated by rNum & rDen
void reduceFraction(int num, int den, int *rNum, int *rDen);

#endif /* fn_test_functions_h */
