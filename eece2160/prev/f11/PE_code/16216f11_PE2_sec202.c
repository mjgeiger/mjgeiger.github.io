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
// TYPOS IN HANDOUT--SHOULD NOT BE EXTRA SPACES
//    IN LaborDay, ColumbusDay, and VeteransDay
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
	char dayOfWeek;			// Day of week (M/T/W/R/F)
	int month;				// Month (9-12)
	int dayOfMonth;			// Day of month

	/* PROMPT USER TO ENTER THE FOLLOWING:
	   --A SINGLE CHARACTER REPRESENTING THE DAY OF THE WEEK
	   --AN INTEGER REPRESENTING THE MONTH
	   --AN INTEGER REPRESENTING THE DAY OF THE MONTH */
	printf("Enter day of week (M/T/W/R/F): ");
	scanf("%c", &dayOfWeek);
	printf("Enter month (9-12): ");
	scanf("%d", &month);
	printf("Enter day of month: ");
	scanf("%d", &dayOfMonth);

	/* PRINT THE APPROPRIATE SCHEDULE FOR THE DAY ENTERED,
	   INCLUDING EACH HOLIDAY'S SCHEDULE WHEN APPROPRIATE */

	switch(dayOfWeek) {
	case Monday:
		if ((dayOfMonth == LaborDay) && (month == Sep))
			printf(LaborSchedule);
		else if ((dayOfMonth == ColumbusDay) && (month == Oct))
			printf(ColumbusSchedule);
		else
			printf(MonSchedule);
		break;
	case Tuesday:
		printf(TueSchedule);
		break;
	case Wednesday:
	case Friday:
		if ((dayOfMonth == VeteransDay) && (month == Nov))
			printf(VeteransSchedule);
		else if ((dayOfMonth == ThanksgivingDay + 1) && (month == Nov))
			printf(ThanksgivingSchedule);
		else
			printf(WedFriSchedule);
		break;
	case Thursday:
		if ((dayOfMonth == ThanksgivingDay) && (month == Nov))
			printf(ThanksgivingSchedule);
		else
			printf(ThuSchedule);
		break;
	default:
		printf("Invalid day entered\n");
	}
	return 0;
}