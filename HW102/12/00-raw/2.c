#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct antonyms{
    
    char *name;
    int number_of_words;
    char ** words;
    double chance;
    struct antonyms * next;
    
};

typedef struct antonyms antonyms;


struct snonyms{
    
    char *name;
    char ** words;
    int number_of_words;
    double chance;
    struct snonyms * next;
    
};

typedef struct snonyms snonyms;

int get_string(FILE *fp,char **str);
int get_ar_str(FILE *fp,char ***str);

int login(char *str);

void fill_an(antonyms ** list);
void fill_sn(snonyms ** list);

antonyms* new_input_an();
snonyms * new_input_sn();

void insert_an(antonyms **list,antonyms*input);
void insert_sn(snonyms **list,snonyms*input);

void update_from_userdata(char * user_fname,antonyms *list_an,snonyms *list_sn);

void quest_an(antonyms **list);
void quest_sn(snonyms **list);

void add_word(char *** strar,char ** str,int * n);

void save_and_exit(antonyms *list_an,snonyms *list_sn,char * fusername);

double rd(double min,double max);

void add_entry_an(antonyms **list);
void add_entry_sn(snonyms**list);

void fix(char ** str);


void print_an(antonyms *element){
    int i;
    while(element!=NULL){
        printf("%s <>",element->name);

        for(i=0;i<element->number_of_words;i++){
            printf(" %s",element->words[i]);
            
        }

        printf("\nchance %lf nm %d",element->chance,element->number_of_words);
        printf("\n\n");
        element=element->next;
    }
}

void print_sn(snonyms *element){

    while(element!=NULL){
        printf("%s =",element->name);

        for(int i=0;i<element->number_of_words;i++){
            printf(" %s",element->words[i]);
        }

        printf("\nchance %lf nm %d",element->chance,element->number_of_words);
        printf("\n\n");
        element=element->next;
    }
}

int main(){
    
    char * user_name,*user_fname; 
    int check,menu,check_menu;
    char q_menu;

    srand(time(NULL));
        
    antonyms * list_an = NULL;
    snonyms * list_sn = NULL;

    printf("User Name: ");
    get_string(stdin,&user_name);
    strcpy(user_fname,user_name);
    strcat(user_fname,".worddat");
    check = login(user_fname);
    
    printf("Welcome %s\n\n",user_name);

    

    fill_an(&list_an);
    fill_sn(&list_sn);

    
    if(check){
        update_from_userdata(user_fname,list_an,list_sn);
        
    }
    
    //print_an(list_an);
    //print_sn(list_sn);

    while(1){
        
        printf("\n1.Question\n2.Add New\n3.Save and Exit\n\nSelect:");
        
        check_menu = scanf("%d",&menu);
        

        if(!check_menu || menu > 3 || menu<1){
            
            printf("Try Again\n");
            while(getchar() != '\n');
            continue;
        }

        if(menu == 3){
            save_and_exit(list_an,list_sn,user_fname);
            return 0;
        }
        
        while(getchar() != '\n');  
           
            
        if(menu == 1){
            printf("\n1.Antonyms\n2.Snonyms\nSelect: ");
            scanf("%c",&q_menu);
            while(getchar() != '\n');
            
            if(q_menu == '1')
                quest_an(&list_an);
            
            else if(q_menu == '2')
                quest_sn(&list_sn);

        }

        else if(menu == 2){
            printf("\n1.Antonyms\n2.Snonyms\nSelect: ");
            scanf("%c",&q_menu);
            while(getchar() != '\n');

            if(q_menu == '1')
                add_entry_an(&list_an);
            
            else if(q_menu == '2')
                add_entry_sn(&list_sn);
        }

        //print_an(list_an);
        //print_sn(list_sn); 
   
    }


        
}

/*-------------------------------------------------------*/

int login(char *str){
    
    FILE * fp;
    fp = fopen(str,"rb");

    if(!fp){
        printf("--new user created--\n");
        fp = fopen(str,"wb");
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;



}

/*-------------------------------------------------------*/

void fill_an(antonyms ** list){
    
    antonyms *element;
    int check;

    FILE * fp;
    
    fp = fopen("antonyms_example.txt","rt");

    if(fp==0){
        printf("error");
    }

    while(1){
        
        element = new_input_an();
        
        check = get_string(fp,&element->name);
        
        if(check == -1)
            break;

        while(getc(fp)!= '>'); while(getc(fp)!= ' ');
        
        element->number_of_words = get_ar_str(fp,&element->words);
        element->chance = 1;

        //fix(&element->words[element->number_of_words-1]);

        element->words[element->number_of_words-1][strlen(element->words[element->number_of_words-1])-1] = '\0';

        //printf("\n---%d %s---\n",strlen(element->words[element->number_of_words-1]),element->words[element->number_of_words-1]);


        insert_an(list,element);
                    
    }

    fclose(fp);

}

void fill_sn(snonyms ** list){
    
    snonyms *element;
    int check;

    FILE * fp;
    
    fp = fopen("out.txt","rt");

    if(fp==0){
        printf("error");
    }

    while(1){
        
        element = new_input_sn();
        
        check = get_string(fp,&element->name);
        
        if(check == -1)
            break;
        
        while(getc(fp)!= '='); while(getc(fp)!= ' ');
        
        element->number_of_words = get_ar_str(fp,&element->words);
        element->chance = 1;

        //fix(&element->words[element->number_of_words-1]);

        //element->words[element->number_of_words-1][strlen(element->words[element->number_of_words-1])-1] = '\0';
        printf("\n---%d %s---\n",strlen(element->words[element->number_of_words-1]),element->words[element->number_of_words-1]);
        
        insert_sn(list,element);
        
    }

    fclose(fp);
}

/*-------------------------------------------------------*/

int get_ar_str(FILE *fp,char ***str){
    
    int number_of_words = 0,j,check;
    char ** temp1;
    char ** temp2=NULL;
    
    while(1){
        
        number_of_words++;
        
        temp1 = (char**)calloc(number_of_words,sizeof(char*));

        for(j=0;j<number_of_words-1;j++) temp1[j] = temp2[j];
    
        check = get_string(fp,&temp1[number_of_words-1]);

        if(temp2 != NULL) free(temp2);
        temp2 = temp1;

        if(check==0){
            break;
        }
    }

    *str = temp2;
    return number_of_words;


}

int get_string(FILE *fp,char **str){
    
    int i=0,j;
    char vaule;
    char * temp1;
    char * temp2 = NULL;
    
    while((vaule=getc(fp)) != ' '){
        
        
        if(vaule == '\n')
            break;
        
        if(vaule == EOF)
            break;
        
        if(vaule == '?')
            break;

        i++;
        temp1 = (char*)calloc(i,sizeof(char));

        for(j=0;j<i-1;j++) temp1[j] = temp2[j];
    
        temp1[i-1] = vaule;

        if(temp2 != NULL) free(temp2);
        temp2 = temp1;
    }

    i++;
    temp1 = (char*)calloc(i,sizeof(char));

    for(j=0;j<i-1;j++) temp1[j] = temp2[j];

    temp1[i-1] = '\0';

    if(temp2 != NULL) free(temp2);
    temp2 = temp1;

    temp1 = NULL;
    *str = temp2;

    if(vaule == ' ')
        return 1;

    else if (vaule == '\n')
        return 0;
    else if(vaule == EOF)
        return -1;
    else if(vaule == '?')
        return -2;
    

}

/*-------------------------------------------------------*/

antonyms* new_input_an(){

    antonyms* list;

    list = (antonyms*) malloc(sizeof(antonyms));
    list->next = NULL;

    return list;

}

snonyms * new_input_sn(){
    
    snonyms* list;

    list = (snonyms*) malloc(sizeof(snonyms));
    list->next = NULL;

    return list;
}


/*-------------------------------------------------------*/
void insert_an(antonyms **list,antonyms*input){
    
    antonyms * first;

    first = *list;

    if(first == NULL){
        *list = input;
        return ;
    }

    
    
    while(first->next!=NULL){
        first = first->next;}
    
    first->next = input;
    input->next = NULL;
    
}


void insert_sn(snonyms **list,snonyms*input){
    
    snonyms * first;

    first = *list;

    if(first == NULL){
        *list = input;
        return ;
    }

    
    
    while(first->next!=NULL){
        first = first->next;}
    
    first->next = input;
    input->next = NULL;
    
}

/*-------------------------------------------------------*/
void update_from_userdata(char * user_fname,antonyms *list_an,snonyms *list_sn){
    
    FILE * fp;
    antonyms * head_an ,*temp_an;
    snonyms * head_sn ,*temp_sn;
    char * str;
    double rt;

    int check;

    temp_an = head_an = list_an;
    temp_sn = head_sn = list_sn;

    fp = fopen(user_fname,"rb");

    while(1){
        
        check = get_string(fp,&str);

        //printf("chechk%d\n",check);

        if(check == -2){
            
            break;}
        
        fscanf(fp,"%lf",&rt);

        while(getc(fp)!= '\n');

        //printf("%s-%lf\n",str,rt);



        while(temp_an!=NULL){
            
            if(!strcmp(str,temp_an->name)){
                temp_an->chance = rt;
                break;
            }

            temp_an = temp_an->next;
        }

        temp_an = head_an;       
    }

    while(getc(fp)!= '\n');
    
    

    while(1){
        
        check = get_string(fp,&str);

        if(check == -2)
            break;
        
        fscanf(fp,"%lf",&rt);

        //printf("%s-%lf-%s\n",str,rt,temp_sn->name);
        
        while(getc(fp)!= '\n');

        while(temp_sn!=NULL){
            
            if(!strcmp(str,temp_sn->name)){
                temp_sn->chance = rt;
                break;
            }

            temp_sn = temp_sn->next;
        }

        temp_sn = head_sn;        
    }

    fclose(fp);    

}

/*-------------------------------------------------------*/

void quest_an(antonyms **list){
    
    antonyms * temp_list,*header;
    double total_chance = 0,critic,sum_chance=0;
    char *str;
    int i,check;

    
    temp_list = header = *list;

    while(temp_list!=NULL){
        total_chance += temp_list->chance;
        temp_list = temp_list->next;
    }
    
    temp_list = header;

    critic = rd(0,total_chance);

    //printf("\nCritic: %lf Chance: %lf\n",critic,total_chance);

    while(temp_list!=NULL){
        sum_chance += temp_list->chance;

        //printf("\nname:%s %lf\n",temp_list->name,sum_chance);
        
        if(sum_chance >=critic)
            break;
        
        temp_list = temp_list->next;
    }

    printf("What is the antonym of %s:",temp_list->name);

    
    
    get_string(stdin,&str);

    

    for(i=0;i<temp_list->number_of_words;i++){
            
        if(!strcmp(str,temp_list->words[i])){
            
            
            printf("\n----Correct-----\n");

            temp_list->chance = temp_list->chance*0.5*0.999;
            return;
        }
    }
    
    printf("\n---Incorret-----\n");

    printf("\nIf you want to add your answer to the list, enter 1; otherwise, 0  : ");

    scanf("%d",&check);
    

    if(check){
        
        add_word(&temp_list->words,&str,&temp_list->number_of_words);
        temp_list->chance = temp_list->chance*0.5*0.999;
        
    }

    else{
        temp_list->chance = temp_list->chance*0.5*0.999999;
    }

}

void quest_sn(snonyms **list){
    snonyms * temp_list,*header;
    double total_chance = 0,critic,sum_chance=0;
    char *str;
    int i,check;

    
    temp_list = header = *list;

    while(temp_list!=NULL){
        total_chance += temp_list->chance;
        temp_list = temp_list->next;
    }
    
    temp_list = header;

    critic = rd(0,total_chance);

    //printf("\nCritic: %lf Chance: %lf\n",critic,total_chance);

    while(temp_list!=NULL){
        sum_chance += temp_list->chance;

        //printf("\nname:%s %lf\n",temp_list->name,sum_chance);
        
        if(sum_chance >=critic)
            break;
        
        temp_list = temp_list->next;
    }

    printf("What is the snonyms of %s:",temp_list->name);

    
    
    get_string(stdin,&str);

    

    for(i=0;i<temp_list->number_of_words;i++){
            
        if(!strcmp(str,temp_list->words[i])){
            
            
            printf("\n----Correct-----\n");

            temp_list->chance = temp_list->chance*0.5*0.999;
            return;
        }
    }
    
    printf("\n---Incorret-----\n");

    printf("\nIf you want to add your answer to the list, enter 1; otherwise, 0  : ");

    scanf("%d",&check);
    

    if(check){
        
        add_word(&temp_list->words,&str,&temp_list->number_of_words);
        temp_list->chance = temp_list->chance*0.5*0.999;
        
    }

    else{
        temp_list->chance = temp_list->chance*0.5*0.999999;
    }

}

void add_word(char *** strar,char**str,int * n){
    
    int number_of_words =*n,j,check;
    
    char ** temp1;
    char ** temp2 = *strar;
    
    
        
    number_of_words++;
    
    temp1 = (char**)calloc(number_of_words,sizeof(char*));

    for(j=0;j<number_of_words-1;j++) temp1[j] = temp2[j];

    temp1[number_of_words-1] = *str;

    if(temp2 != NULL) free(temp2);
    temp2 = temp1;

        
    

    *strar = temp2;
    *n = number_of_words;
    

}

void save_and_exit(antonyms *list_an,snonyms *list_sn,char * fusername){
    
    FILE *fp_an,*fp_sn,*fp_user;

    fp_user = fopen(fusername,"wb");

    fp_an = fopen("an.txt","wt");

    while(list_an!=NULL){
        
        if(list_an->chance < 1){
            fprintf(fp_user,"%s %lf\n",list_an->name,list_an->chance);
        }


        fprintf(fp_an,"%s <>",list_an->name);

        for(int i=0;i<list_an->number_of_words;i++){
            fprintf(fp_an," %s",list_an->words[i]);
        }
        fprintf(fp_an,"\n");

        list_an = list_an->next;
    }

    fprintf(fp_user,"?\n");

    fclose(fp_an);

    fp_sn = fopen("sn.txt","wt");

    while(list_sn!=NULL){

        if(list_sn->chance < 1){
            fprintf(fp_user,"%s %lf\n",list_sn->name,list_sn->chance);
        }
        
        fprintf(fp_sn,"%s =",list_sn->name);

        for(int i=0;i<list_sn->number_of_words;i++){
            fprintf(fp_sn," %s",list_sn->words[i]);
        }
        fprintf(fp_sn,"\n");

        list_sn = list_sn->next;
    }

    fprintf(fp_user,"?\n");

    fclose(fp_an);

    fclose(fp_user);


}

double rd(double min,double max){
    
    return (double)rand() * (max-min) /(double)RAND_MAX + min;
}

void add_entry_an(antonyms **list){
    
    antonyms * element;
    
    printf("Enter new entry: ( format: word <> antonyms_1 antonyms_2 antonyms_3 ....... antonyms_n)\n");
    
    element = new_input_an();
    
    get_string(stdin,&element->name);
    
    while(getc(stdin)!= '>'); while(getc(stdin)!= ' ');
        
    element->number_of_words = get_ar_str(stdin,&element->words);
    
    element->chance = 1;

    insert_an(list,element);
}


void add_entry_sn(snonyms**list){

    snonyms * element;

    printf("Enter new entry: ( format: word = snonyms_1 snonyms_2 snonyms_3 ....... snonyms_n)\n");
    
    element = new_input_sn();
    
    get_string(stdin,&element->name);
    
    while(getc(stdin)!= '>'); while(getc(stdin)!= ' ');
        
    element->number_of_words = get_ar_str(stdin,&element->words);
    
    element->chance = 1;

    insert_sn(list,element);
}

void fix(char ** str){
    char *x;
    int i;

    x = (char*)malloc(strlen(*str)-1*sizeof(char));
    
    for(i=0;i<strlen(*str)-1;i++){
        x[i] = (*str)[i];
    }

    free(*str);
    *str = x;
}