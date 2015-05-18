/*
 * 16.216: ECE Application Programming, University of Massachusetts Lowell
 * Instructor: Dr. Michael Geiger
 *
 * 9/23/11: Programming Exercise 1
 * Program is intended to give students practice with output formatting
 *   as well as experience using debugger
 *
 * Given: a simple resistive DC voltage divider consisting of a 10V source and two 
 *   resistors, one of which is known to be 1000 ohms.
 * Program should read four possible values for the second resistor (max: 5000 ohms)
 *   and calculate what the following quantities would be if each value was used in the divider:
 *      --> The voltage drop across the second resistor
 *      --> The current flowing through the second resistor
 *      --> The power dissipated by the second resistor
 * Program should prompt user to enter desired precision for all data, then print data in tabular form.
 */

#include <stdio.h>
#define R1 1000.0		// First resistor in divider
#define V_in 10.0		// Input voltage

/* EACH COMMENT IN THE MAIN PROGRAM BELOW DESCRIBES A CODE SNIPPET THAT 
   STUDENTS MUST WRITE IN ORDER TO COMPLETE THE PROGRAM BELOW. */
int main() {

	/* VARIABLE DECLARATIONS */
	double res1, res2, res3, res4;		// Four possible R2 values
	double vout1, vout2, vout3, vout4;	// Four possible V_out values
	int precision;						// Desired precision for output
	int field_width;					// Desired field width

	/* PROMPT USER TO ENTER FOUR VALUES THAT REPRESENT FOUR 
	   POSSIBLE RESISTORS TO BE USED IN DIVIDER AND READ THESE VALUES 
	   ASSUME MAXIMUM RESISTANCE IS 5000 OHMS */
	printf("Enter four resistance values: ");
	scanf("%lf%lf%lf%lf", &res1, &res2, &res3, &res4);

	/* CALCULATE VALUES FOR V_OUT */
	vout1 = V_in * res1 / (res1 + R1);
	vout2 = V_in * res2 / (res2 + R1);
	vout3 = V_in * res3 / (res3 + R1);
	vout4 = V_in * res4 / (res4 + R1);

	/* PROMPT USER TO ENTER A DESIRED PRECISION FOR VOLTAGE, CURRENT, 
	   AND POWER (USE SAME PRECISION FOR ALL THREE) AND READ THIS VALUE */
	printf("Enter desired precision: ");
	scanf("%d", &precision);

	field_width = 5 + precision;		// Calculate field width

	/* PRINT A TABLE WITH FOUR ROWS:
	    --FIRST ROW: FOUR RESISTANCE VALUES
	    --SECOND ROW: VOLTAGE DROP ACROSS RESISTOR, GIVEN EACH VALUE
	    --THIRD ROW: CURRENT FLOWING THROUGH RESISTOR, GIVEN EACH VALUE
	    --FOURTH ROW: POWER DISSIPATED BY RESISTOR, GIVEN EACH VALUE
	   ENSURE THERE ARE AT LEAST 2 SPACES BETWEEN ALL VALUES IN ROW */
	printf("Resistance (ohms):  %*.*lf  %*.*lf  %*.*lf  %*.*lf\n", 
		   field_width, precision, res1,
		   field_width, precision, res2,
		   field_width, precision, res3,
		   field_width, precision, res4);
	printf("Voltage drop (V):   %*.*lf  %*.*lf  %*.*lf  %*.*lf\n", 
		   field_width, precision, vout1,
		   field_width, precision, vout2,
		   field_width, precision, vout3,
		   field_width, precision, vout4);
	printf("Current (A):        %*.*lf  %*.*lf  %*.*lf  %*.*lf\n", 
		   field_width, precision, vout1 / res1,
		   field_width, precision, vout2 / res2,
		   field_width, precision, vout3 / res3,
		   field_width, precision, vout4 / res4);
	printf("Power (W):          %*.*lf  %*.*lf  %*.*lf  %*.*lf\n", 
		   field_width, precision, vout1 * vout1 / res1,
		   field_width, precision, vout2 * vout2 / res2,
		   field_width, precision, vout3 * vout3 / res3,
		   field_width, precision, vout4 * vout4 / res4);
	return 0;
}