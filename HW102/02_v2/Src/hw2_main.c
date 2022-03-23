/*
** main.c:
**
** The test/driver program for the homework.
**
*/


#include <stdio.h>
#include "hw2_lib.h"


void test_find_weekday_of_data() 
{
	int date_day = 5 ,date_month= 2, date_year= 2000, dayno;
	printf("\n--------------------------------------------------------------------------\n");
	printf("| --> Testing test_find_weekday_of_data...                               |\n");
	printf("--------------------------------------------------------------------------\n");
	dayno = find_weekday_of_data(date_day, date_month, date_year);
	printf("%02d-%02d-%04d is the %dth day of the week!\n",date_day, date_month, date_year, dayno);
}


void test_count_day_between_dates() 
{
	int start_day = 25, start_month=8, start_year=2000;
	int end_day = 23, end_month=3, end_year=2005;
	int numdays;
	printf("\n--------------------------------------------------------------------------\n");
	printf("| --> Testing test_count_day_between_dates...                            |\n");
	printf("--------------------------------------------------------------------------\n");
	numdays = count_day_between_dates(start_day, start_month, start_year, end_day, end_month, end_year);

	printf("The number of days between %02d-%02d-%04d and ",start_day, start_month, start_year);
	printf("%02d-%02d-%04d is %d.\n",end_day, end_month, end_year, numdays);
}


void test_find_angle() 
{
	double a = 1, b = 2, c = 3, alpha;
	printf("\n--------------------------------------------------------------------------\n");
	printf("| --> Testing test_find_angle...                                         |\n");
	printf("--------------------------------------------------------------------------\n");
	alpha = find_angle(a, b, c);
	printf("The angle for a=%f, b=%f and c=%f is %f.\n",a, b, c, alpha);
}


void test_print_tabulated() {
	printf("\n--------------------------------------------------------------------------\n");
	printf("| --> Testing test_print_tabulated...                                    |\n");
	printf("--------------------------------------------------------------------------\n");
	print_tabulated(145, 11.1510, -1, 7146, -2, 2, 175944, 3.010, -37889, '*');
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	
	test_find_weekday_of_data();
	test_count_day_between_dates();
	test_find_angle();
	test_print_tabulated();
	
	
} /* end main */
