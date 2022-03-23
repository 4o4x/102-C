/*
** hw2_io.h:
**
** The header file declaring library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.11.15.45
** 
*/


int find_WeekDayOfDate(int* day, int* month, int* year);


int count_DayBetweenDates(int* starting_date, int* ending_date, int* date_of_year, int* day_of_week);


double find_angle(double a0, double a1, double a);


char* string_matching(char* filename, char* searched_word, int* number_of_sentences);


char* decrypt(char* encoded);
