/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.11.15.45
** 
*/


#include <stdio.h>


#include "hw2_lib.h"
#include "hw2_io.h"



/*
** Testing angle finding..
**
*/
void test_find_angle() 
{
	double angle;
	
	angle = find_angle(1, 1,1);
	printf("Found angle: %f\n", angle);
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_find_angle();
	return (0);
} /* end main */
