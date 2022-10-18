#include <stdio.h>
#include <string.h>

void fix_spelling_error(char ar_text[],char ar_dictionary[]);
void find_best_correction(char *word,char file_dictionary[]);
char comparison(char c1,char c2);
int control(char str[],char dic[]);

int main(){

    char text[] = "text.txt";
    char dictionary[] = "dictionary.txt";
    
    fix_spelling_error(text,dictionary);

    

}

char comparison(char c1,char c2){

    int i;
    int flag; /* if flag = 0 >>> draw   if flag =1  >>>> win c1    if flag = -1 >>>>> win c2*/
    char vowel[5] = {'a','e','i','o','u'};

    for(i=0;i<5;i++){
        
        if(vowel[i]==c1)
            flag = 1;
        
        if(vowel[i]==c2)
            flag = -1;
    }


    if(flag==1){
        return c1;

    }

    else
        return c2;
}


void fix_spelling_error(char ar_text[],char ar_dictionary[]){
    
    char str[20];
    FILE *text;
    /*FILE *dictionary;
    dictionary = fopen(ar_dictionary,"rt");*/

    text = fopen(ar_text,"r+");
    

    while(fscanf(text,"%s",&str)!= EOF){

        find_best_correction(str,ar_dictionary);

        fseek(text, -(strlen(str)), SEEK_CUR);

        fprintf(text,"%s",str);
    }
    fclose(text);
}

void find_best_correction(char *word, char file_dictionary[]){

    FILE *dictionary;
    int i,number_of_error,which;
    char error1 = 124,error2;
    char str[20];
    
    

    if(control(word,file_dictionary)) return;
    
    
    
    dictionary = fopen(file_dictionary,"rt");

    while(fscanf(dictionary,"%s",&str)!= EOF){
        
        
        number_of_error = 0;
        
        /*printf("-%d-",strlen(str));*/
        
        if(!(strlen(word) >= strlen(str)) ) continue;
        
        for(i=0;i<strlen(word);i++){
            
            if(word[i]>=97 && word[i]<=122 ){
               
                if(str[i] != word[i]){

                    number_of_error++;
                    error2 = str[i];
                    which = i;
                }

                if(number_of_error>1) break;
            }
        }

        
        
        if(number_of_error==1){
            
            word[which] = comparison(error1,error2);
            error1 = error2;
            /*printf("-%d-",strlen(str));*/
            
        }
        
    }
    fclose(dictionary);
    
    
    

    
}

int control(char str[],char dic[]){
    char check[20];
    FILE *dictionary;
    
    dictionary = fopen(dic,"rt");

    while(fscanf(dictionary,"%s",&check)!= EOF){
        if(!(strcmp(str,check))){  return 1;}

    }

    fclose(dictionary);
    return 0;
}