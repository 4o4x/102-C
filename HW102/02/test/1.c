#include <stdio.h>
#include <stdlib.h>

void word_prediction(char* start_letter, char* end_letter, int* length_of_word, int* number_of_guess)
{
    char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; /* letter table*/
    int i,j,g;
    int first;
    int last;
    char *xword;
    char *fword;
    char finder;
    
        for(i=0;i<26;i++){                          /* finds which order the letter is in alphabet  */
        if(alpha[i] == *start_letter){
            first = i;
            break;
        }
    }

    for(i=0;i<26;i++){                              /* finds which order the letter is in alphabet  */
        if(alpha[i] == *end_letter){
            last = i;
            break;
        }
    }
   
   
    
    xword = (char*) malloc(sizeof(*length_of_word));    /*  adjusts size of array    */
    fword = (char*) malloc(sizeof(*length_of_word));

    for(i=0;i<(*length_of_word);i++){
        fword[i] = '*';
    }

    for(i=0;i<(*length_of_word);i++){
        
        xword[i] = alpha[first+(rand()%(last+1-first))]; /* puts random letters in array */
        /*printf("\n%d",x);*/
    } 
    /*printf("%s",xword);*/
    
    i=0;
    g=0;
   
    while(i != *length_of_word && g != *number_of_guess){
        printf("\nPlease Input a letter:");
        scanf(" %c",&finder);
        for(j=0;j<*length_of_word;j++){
            if(finder == xword[j]){
                fword[j] = xword[j];
                i++;
                
            }
        }
    printf("The word is: %s\n",fword);
    g++;
    }
    
   
    if(i== *length_of_word)
        printf("Congrats! You find the word.\n");
    else
        printf("You Failed\n");
}

int main(){
    
    char a = 'a';
    char b = 'c';
    int lenght = 5;
    int gues = 3;
    
    word_prediction(&a,&b,&lenght,&gues);

}