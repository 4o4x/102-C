#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *typ;

}genre;

int fill_name(char** str);

int x(genre** hmm,int (*number_of_genre)){

    int i,k,j,stlen,flag;
    genre *temp_genre2=NULL,*temp_genre1;
    char *str;


    for(j=0;j<3;j++){


        flag =0;

        stlen = fill_name(&str);
        
        for(i=0;i<(*number_of_genre);i++){
            
            if(!strncmp(temp_genre2[i].typ,str,stlen)){
                flag = 1;
                
                break;
            }
        }

        printf("%s %d",str,flag);

        if(!flag){
            
            (*number_of_genre)++;
            
            temp_genre1 = (genre*)calloc((*number_of_genre),sizeof(genre));
        
            for(k=0;k<(*number_of_genre)-1;k++) temp_genre1[k] = temp_genre2[k];

            printf("Yes;");
            
            temp_genre1[(*number_of_genre)-1].typ = (char*) calloc(stlen,sizeof(char));
            strncpy(temp_genre1[(*number_of_genre)-1].typ,str,stlen);

            if(temp_genre2 != NULL) free(temp_genre2);
            temp_genre2 = temp_genre1;
            

        }

        
        
    }
}

int main(){
    int lenght_of_genre=0;
    genre * hmm;
    
    
    x(&hmm,&lenght_of_genre);

    

    

}



int fill_name(char** str){
    
    int i=0,j;
    char vaule;
    char * temp1;
    char * temp2 = NULL;
    
    while((vaule=getchar()) != ','){
           
        i++;
        temp1 = (char*)calloc(i,sizeof(char));

        for(j=0;j<i-1;j++) temp1[j] = temp2[j];
    
        temp1[i-1] = vaule;

        if(temp2 != NULL) free(temp2);
        temp2 = temp1;
    }

    temp1 = NULL;
    *str = temp2;
    return i;
    temp2 = NULL;
}