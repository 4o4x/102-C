/*
** hw8_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.04.22.19.55
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include "hw8_lib.h"

#define WORDSIZE 50





#define WORDSIZE 50

int stcmp(char* x, char* y,int z){/* recursive string compare*/
    
    
    if(z==0){        
        return 1;   /*if the strings are the euqal return 1*/

       
    }          
    
	else{
        
        if(x[z-1] != y[z-1]){
            return 0;  
        } 
        return stcmp(x,y,z-1);  
    }

}

int stlen(char *str,int n){ /*recursive lenght of string*/
    if(str[0] == '\0')
        return n;
    
    else
        return stlen(&str[1],n+1);
}

void substring_and_delete(char* str, char *sub){/* Checks if there is a sub in the str string*/
    

    if(stlen(str,0)<stlen(sub,0)){
        
        return;
    }

          
            
    else{
        
        if(stcmp(sub,str,stlen(sub,0))  == 1){    
            
            
            sprintf(&(str[0]),"%s",&str[stlen(sub,0)]);   /*if there is , prints data which is after x on to x address*/
        }
        
        substring_and_delete(&str[1],sub);

        
        
    }
}


void cmp(char* str,char* words_to_delete[WORDSIZE],  int number_of_words){ 

    if(number_of_words == 0)
        return;
    
    else{
        
        substring_and_delete(str,words_to_delete[number_of_words-1]);
        cmp(str,words_to_delete,number_of_words-1);
        
    }
}



void delete_words (FILE* infid, FILE* outfid, char* words_to_delete[WORDSIZE],  int number_of_words)
{
	char str[500];
    
    
    if(feof(infid))
        return;
    
    else{
        
        fgets(str,200,infid);
        

        cmp(str,words_to_delete,number_of_words);

        fprintf(outfid,"%s",str);

        delete_words(infid, outfid, words_to_delete, number_of_words);

        

    }
}


void clean_file(char* infile, char * outfile, char *words_to_delete[WORDSIZE], int number_of_words)
{
	FILE* infid;
	FILE* outfid;

    infid = fopen(infile,"rt");
    outfid = fopen(outfile,"wt");


	delete_words (infid, outfid, words_to_delete, number_of_words);
	fclose(infid);
    fclose(outfid);
}


/* ---------------------------------------------------------------------------------------------------------*/


void find_location_on_maze(cell_type (*maze)[8],cell_type player,int* x,int* y){/*Finds where the player is*/
    
    if(maze[*x][*y] == player )
        return;
    
    else{
        
       

        if(*y<8){
            *y=*y+1;
            
        }
        else{
            *x=*x+1;
            *y=0;
        }

        find_location_on_maze(maze,player,x,y);

    }

    return;

    
}

int maze_move(cell_type maze[][8], cell_type player, move_type move)
{
	int x=0,y=0;
    
    find_location_on_maze(maze,player,&x,&y);

    
    

    switch(move){

        case move_left: /*Left*/
            
            
            if(maze[x][y-1]==cell_target)
                return 1;
            
            else if(maze[x][y-1]==cell_free){
                maze[x][y-1] = player;
                maze[x][y] = cell_free;
                return 0;
            }
            
            else return 0;

        case move_right: /*Right*/
            
            if(maze[x][y+1]==cell_target)
                return 1;
            
            else if(maze[x][y+1]==cell_free){
                maze[x][y+1] = player;
                maze[x][y] = cell_free;
                return 0;
            }
            
            else return 0;
        
        case move_up: /*up*/
            
            if(maze[x-1][y]==cell_target)
                return 1;
                
            
            else if(maze[x-1][y]==cell_free){
                maze[x-1][y] = player;
                maze[x][y] = cell_free;
                return 0;
            }
            
            else return 0;

        case move_down: /*down*/
            
            if(maze[x+1][y]==cell_target)
                return 1;
            
            else if(maze[x+1][y]==cell_free){
                maze[x+1][y] = player;
                maze[x][y] = cell_free;
                return 0;
            }
            
            else return 0;
    }


    

    
}










void towers_of_hanoi(char start_peg, char end_peg, char aux_peg, int n)
{
   
}
