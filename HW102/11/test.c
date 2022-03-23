#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    char *name;
    struct node *next;
}node;

char * fill_name();

int get_int();

int main(){
    int i;
    node * root ;
    node * l;

    char **str;

    str = (char**) malloc(sizeof(char*));
    
    root = (node*)malloc(sizeof(node));
    root->next = NULL;

    str[0] = fill_name();
    root->data = get_int();


    printf("%s %d",str[0],root->data);

}


char * fill_name(){
    
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
    return temp2;
    temp2 = NULL;
}

int get_int(){
    
    int bdgt,check_bdgt;
    char f_check;
    check_bdgt = scanf("%d",&bdgt);

    if(check_bdgt == EOF)
        return EOF;
    
    else if(!check_bdgt)
         bdgt = -2;
        
    while(1){
        f_check = getchar();
        if (f_check == '\n' || f_check == ',')
            break;
    }
    return bdgt;
}
