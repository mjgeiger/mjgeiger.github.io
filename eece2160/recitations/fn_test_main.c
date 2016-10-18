//
//  fn_test_main.c
//
//  Created by Michael Geiger on 10/17/16.
//  Main program to test recitation exercises related to functions
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "fn_test_functions.h"

int main() {
	int hr1, hr2, hr3;		// Hours for split_time() test
	int min1, min2, min3;	// Minutes for split_time() test
	int sec1, sec2, sec3;	// Seconds for split_time() test
	
	int num1, num2, num3;	// Numerators for reduceFraction() test
	int den1, den2, den3;	// Denominators for reduceFraction() test
	
	// Testing check_val() function
	printf("check_val(4, 5, 6) should print 1: %d\n", check_val(4, 5, 6));
	printf("check_val(4, 6, 5) should print 0: %d\n", check_val(4, 6, 5));
	printf("check_val(6, 4, 5) should print 0: %d\n\n", check_val(6, 4, 5));
	
	// Testing num_digits() function
	printf("num_digits(1234) should print 4: %d\n", num_digits(1234));
	printf("num_digits(5) should print 1: %d\n", num_digits(5));
	printf("num_digits(67890) should print 5: %d\n\n", num_digits(67890));
	
	// Testing digit() function
	printf("digit(2160, 1) should print 0: %d\n", digit(2160, 1));
	printf("digit(2160, 2) should print 6: %d\n", digit(2160, 2));
	printf("digit(2160, 3) should print 1: %d\n", digit(2160, 3));
	printf("digit(2160, 4) should print 2: %d\n", digit(2160, 4));
	printf("digit(2160, 5) should print 0: %d\n\n", digit(2160, 5));
	
	// Testing split_time() function
	split_time(51105, &hr1, &min1, &sec1);
	split_time(25217, &hr2, &min2, &sec2);
	split_time(7199, &hr3, &min3, &sec3);
	
	printf("sec = 51105 --> H/M/S should be 14:11:45: %d:%d:%d\n", hr1, min1, sec1);
	printf("sec = 25217 --> H/M/S should be 7:0:17: %d:%d:%d\n", hr2, min2, sec2);
	printf("sec = 7199 --> H/M/S should be 1:59:59: %d:%d:%d\n\n", hr3, min3, sec3);
	
	// Testing reduceFraction() function
	reduceFraction(15, 60, &num1, &den1);
	reduceFraction(1000, 750, &num2, &den2);
	reduceFraction(7, 17, &num3, &den3);
	
	printf("15/60 reduces to 1/4: %d/%d\n", num1, den1);
	printf("1000/750 reduces to 4/3: %d/%d\n", num2, den2);
	printf("7/17 reduces to 7/17: %d/%d\n", num3, den3);
	
	
	return 0;
}
