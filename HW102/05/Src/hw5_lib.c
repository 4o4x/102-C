/*
** hw5_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.02.23.55
** 
*/

#include <stdio.h>
#include <math.h>
#include "hw5_lib.h"

int which_quadrant(double x ,double y,double origin_x,double origin_y);
void replace_coordinates(double*x1,double *y1,double *x2 ,double *y2);

void operate_polynomials  (double* a3, double* a2, double* a1, double* a0, double* b3, double* b2, double* b1, double* b0, char op)
{
	
	int c0,c1,c2,c3,c4,c5,c6; /*for multiplication*/

	switch(op){

		case '+':
			*a3=*a3+*b3;
			*a2=*a2+*b2;
			*a1=*a1+*b1;
			*a0=*a0+*b0;
			break;
		
		case '-':
			*a3=*a3-*b3;
			*a2=*a2-*b2;
			*a1=*a1-*b1;
			*a0=*a0-*b0;
			break;
		
		case '*':
			c6 = (*a3 * *b3);
			c5 = (*a3 * *b2) + (*a2 * *b3);
			c4 = (*a3 * *b1) + (*a1 * *b3) + (*a2 * *b2);
			c3 = (*a3 * *b0) + (*a0 * *b3) + (*a2 * *b1) + (*a1 * *b2);
			c2 = (*a2 * *b0) + (*a0 * *b2) + (*a1 * *b1);
			c1 = (*a1 * *b0) + (*a0 * *b1);
			c0 = (*a0 * *b0);

			*a3 = c6;
			*a2 = c5;
			*a1 = c4;
			*a0 = c3;
			*b3 = c2;
			*b2 = c1;
			*b1 = c0;
			break;



	}

}


void four_d_vectors (double* mean_a0, double* mean_a1, double* mean_a2, double* mean_a3, double* longest_distance, int N)
{
	double x0,x1,x2,x3,d0, d1, d2, d3, euclidian_distance=0,i;

	printf("Please enter vector 1: ");
	scanf("%lf %lf %lf %lf",&d0,&d1,&d2,&d3);
	if(d0==-1 && d1 ==-1 && d2==-1 && d3 ==-1)
		return;
	
	*mean_a0 += d0;
	*mean_a1 += d1;
	*mean_a2 += d2;
	*mean_a3 += d3;
	
	
	

	for(i=2;i<=N;i++){
		printf("Please enter vector %.lf: ",i);
		scanf("%lf %lf %lf %lf",&x0,&x1,&x2,&x3);
		
		if(x0==-1 && x1 ==-1 && x2==-1 && x3 ==-1){
			i--;
			break;}
		
		d0=d0-x0;
		d1=d1-x1;     /*the difference of the coordinates of the two vectors*/
		d2=d2-x2;
		d3=d3-x3;
		

		distance_between_4d_points (d0, d1, d2, d3, &euclidian_distance);

		if(euclidian_distance > *longest_distance)
			*longest_distance = euclidian_distance;


		d0=x0;
		d1=x1;
		d2=x2;
		d3=x3;
	

		*mean_a0 += d0;
		*mean_a1 += d1;           /*    sum of cordinates    */
		*mean_a2 += d2;
		*mean_a3 += d3;
		


	}

	*mean_a0 /=i-1;
	*mean_a1 /=i-1;        /* mean coordinates of vectors */
	*mean_a2 /=i-1;
	*mean_a3 /=i-1;
	

}


void distance_between_4d_points (double d0, double d1, double d2, double d3, double* euclidian_distance)
{
    /*eucliad distance formula */
	*euclidian_distance = sqrt(   sqrt( d0*d0 + d1*d1 )*sqrt( d0*d0 + d1*d1 )    +     sqrt( d2*d2 + d3*d3 )*sqrt( d2*d2 + d3*d3 )  );
}


void dhondt_method (int* partyA, int* partyB, int* partyC, int* partyD, int* partyE, int numberOfSeats)
{
	int max = 0,i,j;
	int seatA=0,seatB=0,seatC=0,seatD=0,seatE=0;
	int flag;
	
	for(i=0;i<numberOfSeats;i++){
		max = 0;

		if(*partyA/(seatA+1)>max){
			max = *partyA/(seatA+1);
			flag = 1;
		}
		if(*partyB/(seatB+1)>max){
			max = *partyB/(seatB+1);
			flag = 2;
		}
		if(*partyC/(seatC+1)>max){                         /*   Finding the party with the most votes */
			max = *partyC/(seatC+1);
			flag = 3;
		}
		if(*partyD/(seatD+1)>max){
			max = *partyD/(seatD+1);
			flag = 4;
		}
		if(*partyE/(seatE+1)>max){
			max = *partyE/(seatE+1);
			flag = 5;
		}
		
		switch(flag){

			case 1:
				seatA++;
				break;
			
			case 2:
				seatB++;
				break;
			
			case 3:                           
				seatC++;
				break;
			case 4:
				seatD++;
				break;
			case 5:
				seatE++;
				break;
		
		}
		



	}

	*partyA = seatA;
	*partyB = seatB;
	*partyC = seatC;
	*partyD = seatD;
	*partyE = seatE;
}


void order_2d_points_cc (double* x1, double* y1, double* x2, double* y2, double* x3, double* y3)
{
	int quad1,quad2,quad3,temp;
	double center_of_gravity_x,center_of_gravity_y;

	center_of_gravity_x = (*x1+*x2+*x3)/3;  /* New origin*/
	center_of_gravity_y = (*y1+*y2+*y3)/3;

	quad1 = which_quadrant(*x1,*y1,center_of_gravity_x,center_of_gravity_y);
	quad2 = which_quadrant(*x2,*y2,center_of_gravity_x,center_of_gravity_y);      
	quad3 = which_quadrant(*x3,*y3,center_of_gravity_x,center_of_gravity_y);

	

	if(quad1>quad2){
        replace_coordinates(x1,y1,x2,y2);
		
		temp = quad2;
		quad2 = quad1;
		quad1 = temp;
    }
	
	if(quad1>quad3){
        
		replace_coordinates(x1,y1,x3,y3);

		temp = quad3;
		quad3 = quad1;
		quad1 = temp;	
    }

    if(quad2>quad3){
      	
		replace_coordinates(x2,y2,x3,y3);	
    }

}


int which_quadrant(double x ,double y,double origin_x,double origin_y){   /*find out in which quadrant the coordinate is*/

	if(x>origin_x && y>origin_y)
		return 1;
	else if(x<origin_x && y>origin_y)
		return 2;
	else if(x<origin_x && y<origin_y)
		return 3;
	else if(x>origin_x && y<origin_y)
		return 4;
}

void replace_coordinates(double*x1,double *y1,double *x2 ,double *y2){

	double temp;
	
	temp = *x1;
    *x1 = *x2;
    *x2 = temp;

	temp = *y1;
    *y1 = *y2;
	*y2 = temp;

}

void number_encrypt (unsigned char* number)
{
	char b7='0', b6='0', b5='0', b4='0', b3='0', b2='0', b1='0', b0='0';
	get_number_components (*number, &b7, &b6, &b5, &b4, &b3, &b2, &b1, &b0);
	reconstruct_components (number, b7, b6, b5, b4, b3, b2, b1, b0);
	
}


void get_number_components (unsigned char number, char* b7, char* b6, char* b5, char* b4, char* b3, char* b2, char* b1, char* b0)
{
	int real_number = number;

	if(real_number%2 == 1)
		*b0 = '1';
	
	real_number = real_number/2;
	
	if(real_number%2 == 1)
		*b1 = '1';
	
	real_number = real_number/2;

	if(real_number%2 == 1)
		*b2 = '1';
	
	real_number = real_number/2;

	if(real_number%2 == 1)
		*b3 = '1';
	
	real_number = real_number/2;

	if(real_number%2 == 1)
		*b4 = '1';
	
	real_number = real_number/2;

	if(real_number%2 == 1)
		*b5 = '1';
	
	real_number = real_number/2;

	if(real_number%2 == 1)
		*b6 = '1';
	
	real_number = real_number/2;

	if(real_number%2 == 1)
		*b7 = '1';
	
	real_number = real_number/2;

		
}


void reconstruct_components (unsigned char* number, char b7, char b6, char b5, char b4, char b3, char b2, char b1, char b0)
{	
	*number = (b3 - '0')*1 + (b2 - '0')*2 + (b5 - '0')*4 + (b4 - '0')*8 + (b7 - '0')*16 + (b6 - '0')*32 + (b1 - '0')*64 + (b0 - '0')*128;
}
