/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/


#include <stdio.h>
#include <math.h>
#include "hw5_lib.h"


void test_operate_polynomials () 
{	
	char operant;
	int which_coefficients,i;
	double coefficient,a3,a2,a1,a0,b3,b2,b1,b0;
	printf("Enter coefficients of first polynomial: ");
	for(i=0;i<4;i++){
		scanf(" (%d,%lf)",&which_coefficients,&coefficient);
		switch(which_coefficients){

			case 0: a0 = coefficient; break;
			case 1: a1 = coefficient; break;
			case 2: a2 = coefficient; break;
			case 3: a3 = coefficient; break;
		}
	}
	
	printf("Enter coefficients of second polynomial: ");

	for(i=0;i<4;i++){
		scanf(" (%d,%lf)",&which_coefficients,&coefficient);
		switch(which_coefficients){

			case 0: b0 = coefficient; break;
			case 1: b1 = coefficient; break;
			case 2: b2 = coefficient; break;
			case 3: b3 = coefficient; break;
		}
	}

	printf("\nWhich operation would you like to do\nAddition(+)\nSubtraction(-)\nMultiplication(*)\nEnter: ");
	scanf(" %c",&operant);

	operate_polynomials (&a3, &a2, &a1, &a0, &b3, &b2, &b1, &b0, operant);

	if(operant =='*'){
		printf("\b1st coefficient: %lf\n2nd coefficient: %lf\n3rd coefficient: %lf\n4th coefficient: %lf\n5th coefficient: %lf\n6th coefficient: %lf\n7th coefficient: %lf\n",a3,a2,a1,a0,b3,b2,b1);
	}

	else{
		printf("\b1st coefficient: %lf\n2nd coefficient: %lf\n3rd coefficient: %lf\n4th coefficient: %lf\n",a3,a2,a1,a0);
	}

	printf("\n\n\n");
}


void test_four_d_vectors ()
{
	double mean_a0=0.0, mean_a1=0.0, mean_a2=0.0, mean_a3=0.0, longest_distance=0.0;
	int N=5;
	four_d_vectors (&mean_a0, &mean_a1, &mean_a2, &mean_a3, &longest_distance, N);
	printf("Mean a0: %f\nMean a1: %f\nMean a2: %f\nMean a3: %f\nThe longest distance between two points: %f\n\n\n", mean_a0, mean_a1, mean_a2, mean_a3, longest_distance);
}


void test_dhondt_method ()
{
	int partyA=2, partyB=2, partyC=2, partyD=2, partyE=2, numberOfSeats=100;
	dhondt_method (&partyA, &partyB, &partyC, &partyD, &partyE, numberOfSeats);
	printf("Party A: %d seat(s).\nParty B: %d seat(s).\nParty C: %d seat(s).\nParty D: %d seat(s).\nParty E: %d seat(s).\n\n\n", partyA, partyB, partyC, partyD, partyE);
}


void test_order_2d_points_cc ()
{
	double x1=-21, y1=12, x2=1, y2=100, x3=100, y3=1;
	order_2d_points_cc (&x1, &y1, &x2, &y2, &x3, &y3);
	printf("Counter-Clockwise Order: (%f,%f) - (%f,%f) - (%f,%f)\n\n\n", x1, y1, x2, y2, x3, y3);
}


void test_number_encrypt ()
{
	unsigned char number=217;
	number_encrypt (&number);
	printf("Encrypted number: %d\n\n\n", number);
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_operate_polynomials ();
	test_four_d_vectors ();
	test_dhondt_method ();
	test_order_2d_points_cc ();
	test_number_encrypt ();
	return (0);
} /* end main */
