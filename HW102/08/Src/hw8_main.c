/*
** main.c:
**
** The test/driver program for the homework.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.22.19.55
** 
*/


#include <stdio.h>
#include "hw8_lib.h"

#define WORDSIZE 50




void test_clean_file () 
{
	int number_of_words = 2;
    char *words_to_delete[WORDSIZE] = {"mediocrite","partout"};

    

    char infile[] = "input.txt";
    char outfile[] = "output.txt";

    clean_file(infile,outfile,words_to_delete,number_of_words);
}



void test_maze_move ()
{


	
}


void test_towers_of_hanoi ()
{
	
}


/*
** main function for testing the functions...
**
*/
int main(void) {
	test_clean_file ();
	test_maze_move ();
	test_towers_of_hanoi ();
	return (0);
} /* end main */
