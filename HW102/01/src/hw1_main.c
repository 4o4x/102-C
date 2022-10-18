/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
** 
*/


#include <stdio.h>


#include "hw1_lib.h"
#include "hw1_io.h"



/*
** Testing root finding..
**
*/
void test_root_finder3() 
{
	double root_known = 1.0;
	double root_found;
	root_found = root3(1.2, 1.0, -1.0, -1.2, root_known-0.1, root_known+0.1);
	printf("Ground truth root: %f vs found root: %f\n", root_known, root_found);
}

void test1(){
	write_polynomial3(5,4,3,2);
}

/*
** main function for testing the functions...
**
*/
int main(void) {
	 double a0=1,a1=1,a2=1,a3=1,a4=0,xs=2,xe=6,delta=0.000000001;
	printf("%lf",integral3(a0,a1,a2,a3,xs,xe,delta));


} /* end main */
