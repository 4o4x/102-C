/*
** hw2_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.11.15.45
**
*/
#include <math.h>
#include <stdio.h>
#include "hw2_lib.h"
#define pi 3.14159265


int find_WeekDayOfDate(int* day, int* month, int* year)
{
    printf("TO BE IMPLEMENTED\n");
    return 0;
}


int count_DayBetweenDates(int* starting_date, int* ending_date, int* date_of_year, int* day_of_week)
{
    printf("TO BE IMPLEMENTED\n");
    return 0;
}


double find_angle(double a0, double a1, double a)
{
    double inscribed_angle,center_angle; 


    inscribed_angle = acos( ((a*a)-(a0*a0)-(a1*a1))/ (-2*a0*a1)); /* Law of cosines > c^2 = a^2 + b^2 - 2ab.cos(x)*/
    inscribed_angle *= 180/pi; /* acos() return radian > degree = radian*(180/pi) */
    center_angle = inscribed_angle*2;
    

    return center_angle;
}


char* string_matching(char* filename, char* searched_word, int* number_of_sentences)
{
    return "TO BE IMPLEMENTED\n";
}


char* decrypt(char* encoded)
{
	return "TO BE IMPLEMENTED\n";
}
//int main(){printf("%lf",find_angle(9,9,9));}
