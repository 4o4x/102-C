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

int fill_list(movie**list);

int fii_char(char**str);

int main(){
    int x,z;
    char y;
    char *str;
    int er,zer,ker;
    movie *list = (movie*) calloc(5,sizeof(movie));
    
    //fill_list(&(list));

    //printf("%p\n%p\n%p\n%p",list,&list,list->name,(&(list->name)));

    //printf("List %s",(list[0].name));

   
    int tut;

    char *arr;

    //printf("%p\n%p",&arr[3],(arr+3));

    tut = fii_char(&str);

    
    printf("\ntut %d\n",tut);
    

    list[3].name = (char*) calloc(tut,sizeof(char));
    
    strncpy(list[3].name,str,tut);

    printf("%s",list[3].name);

   // printf("%p\n%p",arr[3],(arr+3));

    
    
   /* {er = scanf("%d",&x);

    if(er == EOF)
        return;
    
    else if(!er)
        x = -1;
        

    while(getchar()!= ',');

    ker = scanf("%d",&z);
    

    printf("%d %d-- -- %d %d",er,x,ker,z);}*/
}

int fill_list(movie**list){
    int i=0,j;
    char vaule;
    char * temp1;
    char * temp2 = NULL;
    

    
    

    //printf("temp1 %p",(temp1));

    do{
        
        i++;
        temp1 = (char*)calloc(i,sizeof(char));

        //printf("Yes");

        for(j=0;j<i-1;j++) temp1[j] = temp2[j];
        scanf("%c",&vaule);

        temp1[i-1] = vaule;

        if(temp2 != NULL) free(temp2);
            temp2 = temp1;
    }while(vaule!=',');

    temp1 = NULL;
     

    ((*list)->name) = temp2;

    

    

    printf("\n%p----%p\n",(*list)->name,(*list[0]).name);

    temp2 = NULL;

    
    
    
    
    
    
}

int fii_char(char**str){
    int i=0,j;
    char vaule;
    char * temp1;
    char * temp2 = NULL;
    
    //printf("temp1 %p",(temp1));

    do{
        
        i++;
        temp1 = (char*)calloc(i,sizeof(char));

        printf("Yes");

        for(j=0;j<i-1;j++) temp1[j] = temp2[j];
        scanf("%c",&vaule);

        temp1[i-1] = vaule;

        if(temp2 != NULL) free(temp2);
            temp2 = temp1;
    }while(vaule!=',');

    temp1 = NULL;
     

    *str = temp2;
    return i;

    

    

   // printf("\n%p----%p\n",(*list)->name,(*list[0]).name);

    temp2 = NULL;
}

    