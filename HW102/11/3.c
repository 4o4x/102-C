#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{

    double budget;
    int genre;
    char* name;
    double score;
    int year;

}movie;


int fill_list(movie **list,char* file);

int fill_name(char** str,FILE *fp);

double myatoi(char *str);






int main(int argc,char *argv[]){
    printf("yes ");
    movie *list;
    int lenght_of_list;
    char ** genre;
    
    lenght_of_list = fill_list(&list,argv[1]);

    //printf("\nhey %.0lf,%s,%.1f,%d,%d",list->budget,list->name,list->score,list->year,lenght_of_list);

    printf("\n Lenght Of List: %d",lenght_of_list);
    printf("\n%s",list[1].name);

}


int fill_list(movie **list,char* file){

    FILE * fp;

    movie *temp_list_x;
    movie *temp_list_y = NULL;
    
    int counter_list=0,k;

    int deneme=0;
    
    char** arr_genre;
    char * str;

    
    double bdgt,scr; 
    int gint,yint;

    int check_bdgt,check_yint,check_scr;
    int stlen;



    fp = fopen(file,"r");

    if(fp==NULL){
        printf("Dosya acilmadi\n");
        return -1;
    }
    
    while(getc(fp) != '\n');
    

    while(1){
        
        check_bdgt = fscanf(fp,"%lf",&bdgt);

        if(check_bdgt == EOF)
            break;
    
        else if(!check_bdgt)
            bdgt = -1;
        
        while(getc(fp)!= ',');

        
        counter_list++;

        temp_list_x = (movie*)calloc(counter_list,sizeof(movie));
        
        for(k=0;k<counter_list-1;k++) temp_list_x[k] = temp_list_y[k];

        temp_list_x[counter_list-1].budget = bdgt;

        


        
        while(getc(fp)!= ',');
        
        
        
        

        stlen = fill_name(&str,fp);
        

        temp_list_x[counter_list-1].name = (char*) calloc(stlen,sizeof(char));

        strncpy(temp_list_x[counter_list-1].name,str,stlen);

        
        

        fscanf(fp,"%lf",&scr);
        while(getc(fp)!= ',');
        temp_list_x[counter_list-1].score = scr;

        fscanf(fp,"%d",&yint);
        while(getc(fp)!= '\n');
        temp_list_x[counter_list-1].year = yint;
        

        if(temp_list_y != NULL) free(temp_list_y);
        temp_list_y = temp_list_x;


        

        
    }

    *list = temp_list_y;

    //printf("\n%s",temp_list_y[0].name);

    
    printf("bitirdim: %d\n",deneme);

    fclose(fp);
    
    return counter_list;

    

}

int fill_name(char** str,FILE *fp){
    
    int i=0,j;
    char vaule;
    char * temp1;
    char * temp2 = NULL;
    
    
    

    while((vaule=getc(fp)) != ','){
           
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




double myatoi(char *str){

    int i;
    double number=0;

    for(i=0;i<strlen(str);i++){

        number *= 10;
        
        if(str[i] < '0' || str[i] > '9' )
            return -1;       
        number += str[i] - '0'; 

    }

    return number;

}