/*
 * 16.216: ECE Application Programming, University of Massachusetts Lowell
 * Instructor: Dr. Michael Geiger
 *
 * 9/30/11: Programming Exercise 2
 * Program is intended to give students practice with if and switch statements
 *
 * Given: a (fictional) schedule of classes for each day of the week, as
 *   well as a list of holidays during the semester, prompt the user to enter
 *   a day and date, and then print the appropriate schedule for that day.
 */

/* Constant definitions */
// Daily class schedules
#define MonSchedule "Monday Schedule: 16.201, 92.231\n"
#define WedFriSchedule "Wednesday/Friday Schedule: 16.201, 92.231, 16.216\n"
#define TueSchedule "Tuesday Schedule: 16.207, 99.999\n"
#define ThuSchedule "Thursday Schedule: 99.999\n"

// Day of week
#define Monday 'M'
#define Tuesday 'T'
#define Wednesday 'W'
#define Thursday 'R'
#define Friday 'F'

// Month number
#define Sep 9
#define Oct 10
#define Nov 11
#define Dec 12

// Holidays
#define LaborDay 5
#define LaborSchedule "Labor Day -- no classes\n"
#define ColumbusDay 10
#define ColumbusSchedule "Columbus Day -- no classes\n"
#define VeteransDay 11
#define VeteransSchedule "Veterans Day -- no classes\n"
#define ThanksgivingDay 24
#define ThanksgivingSchedule "Thanksgiving Recess -- no classes\n"

#include <stdio.h>

/* EACH COMMENT IN THE MAIN PROGRAM BELOW DESCRIBES A CODE SNIPPET THAT 
   STUDENTS MUST WRITE IN ORDER TO COMPLETE THE PROGRAM BELOW. */
int main() {

	/* VARIABLE DECLARATIONS */
	char dayOfWeek;				// Character to hold day of week
	int month, dayOfMonth;		// Month and day of month

	/* PROMPT USER TO ENTER THE FOLLOWING:
	   --A SINGLE CHARACTER REPRESENTING THE DAY OF THE WEEK
	   --AN INTEGER REPRESENTING THE MONTH
	   --AN INTEGER REPRESENTING THE DAY OF THE MONTH */
	printf("Enter day of week (M/T/W/R/F): ");
	scanf("%c", &dayOfWeek);
	printf("Enter month (1-12): ");
	scanf("%d", &month);
	printf("Enter day of month: ");
	scanf("%d", &dayOfMonth);

	/* PRINT THE APPROPRIATE SCHEDULE FOR THE DAY ENTERED,
	   INCLUDING EACH HOLIDAY'S SCHEDULE WHEN APPROPRIATE */
	switch (dayOfWeek) {
	case 'M':
		if ((month == 9) && (dayOfMonth == LaborDay))
			printf(LaborSchedule);
		else if ((month == 10) && (dayOfMonth == ColumbusDay))
			printf(ColumbusSchedule);
		else
			printf(MonSchedule);
		break;
	case 'T':
		printf(TueSchedule);
		break;
	case 'W':
	case 'F':
		if ((month == 11) && (dayOfMonth == VeteransDay))
			printf(VeteransSchedule);
		else if ((month == 11) && (dayOfMonth == ThanksgivingDay + 1))
			printf(ThanksgivingSchedule);
		else
			printf(WedFriSchedule);
		break;
	case 'R':
		if ((month == 11) && (dayOfMonth == ThanksgivingDay))
			printf(ThanksgivingSchedule);
		else
			printf(ThuSchedule);
		break;
	}

	// Added to allow this to look like a stand-alone executable
	printf("Press enter to continue ... ");
	getchar();  // Reads the return from previous input
	getchar();  // Reads "enter"

	return 0;
}	