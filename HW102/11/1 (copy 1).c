#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Movie_Budget{
    
    int budget;
    int year;
    char *name;
    struct Movie_Budget * next;
    
};

typedef struct Movie_Budget Movie_Budget;


struct Movie_Name{
    
    double score;
    char *genre;
    char *name;
    struct Movie_Name * next;
    
};

typedef struct Movie_Name Movie_Name;

/*---------------------------------------------------------------------------------------*/

int fill_list(Movie_Budget **list_bdg,Movie_Name **list_nm,char* file);

/*------------------------------------- Insert functions -------------------------------------------------*/

int insert_budget(Movie_Budget **list,Movie_Budget*input);
int insert_name(Movie_Name **list,Movie_Name*input);

/*------------------------------------- New Input -------------------------------------------------*/

Movie_Name* new_input_name();
Movie_Budget* new_input_bdg();


/*------------------------------------- Update functions -------------------------------------------------*/

int update_bdg(Movie_Budget ** temp_list_bdg,Movie_Budget * input_bdg);
int update_name(Movie_Name ** temp_list_nm,Movie_Name *input_name);

/*-----------------------------------------Read functions----------------------------------------------*/

char * get_string(FILE *fp);
int get_int(FILE *fp);
double get_double(FILE *fp);

/*---------------------------------------Menu functions------------------------------------------------*/
void menu_1(Movie_Name **list_nm, Movie_Budget **list_bdg);

void menu_2(Movie_Name *list);

void menu_3(Movie_Budget *list);

void menu_4(Movie_Name *list);

void menu_5(Movie_Name *list_nm, Movie_Budget *list_bdg);

void menu_6(Movie_Name *list);

void menu_7(Movie_Name *list);

/*----------------------------------------Sort Function-----------------------------------------------*/

Movie_Budget * sort_budget(Movie_Budget *list);
Movie_Budget * sort_year(Movie_Budget *list);
Movie_Name * sort_genre(Movie_Name *list);
Movie_Name * sort_name(Movie_Name *list);
Movie_Name * sort_score(Movie_Name *list);


/*---------------------------------------print functions for menu 1-----------------------------------*/

void print_bdg(Movie_Name *list_nm, Movie_Budget *list_bdg,int start,int end);
void print_nm(Movie_Name *list_nm, Movie_Budget *list_bdg,int start,int end);



/*void print_list_1(Movie_Name*l){
    
    while(l!=NULL){
        printf("%s\n",l->name);
        l = l->next;

    }
}


void print_list_2(Movie_Budget*l){
    int i=0;
    while(l!=NULL){
        printf("%-50s %-4d\n",l->name,l->year);
        l = l->next;
        i++;

    }
    printf("%d",i);
}*/

int main(int argc,char *argv[]){
    
    int i;
    
    Movie_Budget *list_bdg = NULL;
    Movie_Name *list_nm = NULL;
 
    int menu;
    int check_menu;
    
    fill_list(&list_bdg,&list_nm,argv[1]);

    while(1){
        
        printf("\n1.Listed of the Sorted Data\n2.List of the Genres\n3.List of Movie Through the years\n4.List of Movie Through the Scores\n5.All information of a Single movie\n6.Average of the IMDB score\n7.Frequence of the Genres\n8.EXIT\n\nSelect:");
        
        check_menu = scanf("%d",&menu);

        if(!check_menu || menu > 8 || menu<1){
            
            printf("Try Again\n");
            while(getchar() != '\n');
            continue;
        }

        if(menu == 8){
            return 0;
        }
        
        while(getchar() != '\n');     
            
        switch(menu){

            case 1:
                menu_1(&list_nm,&list_bdg);                
                break;
            case 2:
                menu_2(list_nm);              
                break;

            case 3:
                menu_3(list_bdg);
                break;

            case 4:
                menu_4(list_nm);
                break;
            
            case 5:
                menu_5(list_nm,list_bdg);                               
                break;
            
            case 6:
                menu_6(list_nm);           
                break;

            case 7:
                menu_7(list_nm);
                break;
            
        }
   
    }

}


int fill_list(Movie_Budget **list_bdg,Movie_Name **list_nm,char* file){

    FILE * fp;

    Movie_Budget *input_bdg;
    Movie_Name * input_name;
 
    int temp_int,flag=0,i=0;

    

    /*--------------- FILE -----------*/

    fp = fopen(file,"r");

    if(fp==NULL){
        printf("Dosya acilmadi\n");
        return -1;
    }
    
    /*--------------- Skip first row -----------*/
    while(getc(fp) != '\n');
    
    
    /*--------------- Read and Insert -----------*/

    for(;;){
        flag = 0;
        /*--------------- Budget and checking EOF -----------*/
        
        temp_int = get_int(fp);

        if(temp_int == EOF){
            break;
        }

        input_bdg = new_input_bdg();
        input_name = new_input_name();

        input_bdg->budget = temp_int;

        /*--------------------- Genre ---------------------*/

        input_name->genre = get_string(fp);
   
        /*--------------------- Name ---------------------*/
        
        input_bdg->name = input_name->name = get_string(fp);
        
        /*--------------------- Score ---------------------*/

        input_name->score = get_double(fp);

        /*--------------------- Year ---------------------*/

        input_bdg->year = get_int(fp);

        /*if(input_bdg->budget >0 || input_bdg->budget<2025 ){
            return 0;
        
        }*/

        //printf("%-10d  %-10s  %-50s  %.1lf  %-4d\n",input_bdg->budget,input_name->genre,input_name->name,input_name->score,input_bdg->year);
        

        /*--------------------- Update ---------------------*/
        
        //update_bdg(list_bdg,input_bdg);
        //flag = update_name(list_nm,input_name);
        
         
        
        /*--------------------- Insert ---------------------*/
        //if(!flag){
        insert_budget(list_bdg,input_bdg);
        insert_name(list_nm,input_name);//}
        
        i++;
             
    }
    //print_list_2(*list_bdg);
    
    


    /**list_bdg = temp_list_bdg;
    *list_nm = temp_list_nm;*/
    
    fclose(fp);  

}

/*-----------------------------------------Read functions----------------------------------------------*/

int get_int(FILE *fp){
    
    int bdgt,check_bdgt;
    char f_check;

    check_bdgt = fscanf(fp,"%d",&bdgt);

    if(check_bdgt == EOF)
        return EOF;
    
    else if(!check_bdgt)
        bdgt = -2;

    while(1){
        f_check = getc(fp);
        if (f_check == '\n' || f_check == ',')
            break;
    }
       
    return bdgt;
}

char * get_string(FILE *fp){
    
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
    return temp2;
    
}

double get_double(FILE *fp){
    
    double vaule;

    fscanf(fp,"%lf",&vaule);
    
    while(getc(fp)!= ',');

    return vaule;
}

/*------------------------------------- Update functions -------------------------------------------------*/

int update_bdg(Movie_Budget ** temp_list_bdg,Movie_Budget * input_bdg){
    
    /* checks if there is the same movie in the list. 
    If there is, it updates and returns 1, otherwise it returns 0. */
    
    Movie_Budget * r;

    r = *temp_list_bdg;

    if(r == NULL)
        return 0;

    while(r!=NULL){
        
        if(!strcmp(r->name,input_bdg->name)){
            
            r->budget = input_bdg->budget;
            r->year = input_bdg->year;

            return 1;
        }
        
        r = r->next;
    }

    return 0;

}


int update_name(Movie_Name ** temp_list_nm,Movie_Name *input_name){
    
    /* checks if there is the same movie in the list. 
    If there is, it updates and returns 1, otherwise it returns 0. */
    
    Movie_Name * r;

    r = *temp_list_nm;
    

    if(r == NULL)
        return 0;

    

    while(r!=NULL){
        
        if(!strcmp(r->name,input_name->name)){
            //printf("%s\n",r->name);
            r->score = input_name->score;
            r->genre = input_name->genre;
            
            return 1;
        }
        
        r = r->next;
    }

    return 0;
}

/*------------------------------------- New Input -------------------------------------------------*/
Movie_Budget* new_input_bdg(){
    /* allocate node */

    Movie_Budget* list;

    list = (Movie_Budget*) malloc(sizeof(Movie_Budget));
    list->next = NULL;

    return list;

}

Movie_Name* new_input_name(){
    /* allocate node */

    Movie_Name* list;

    list = (Movie_Name*) malloc(sizeof(Movie_Name));

    list->next = NULL;

    return list;

}
/*------------------------------------- Insert functions -------------------------------------------------*/
int insert_budget(Movie_Budget **list,Movie_Budget*input){
    
    Movie_Budget *first,*second;

    first = second = *list;

    

    if(first == NULL){
        *list = input;
        return 0;
    }

    while(first!=NULL){
                
        if(input->year == second->year){
            
            if(input->budget >= first->budget){
                
                if(first == second){
                    input->next = *list;
                    *list = input;
                    return 0;
                }
                
                second->next = input;
                input->next = first;

                return 0;
                
            }

            else{
                
                second = first;
                first = first->next;

                second->next = input;
                input->next = first;

                return 0;
            }

            
        }

        else if(input->year > first->year){
            
            if(first == second){
                    input->next = *list;
                    *list = input;
                    return 0;
                }

            second->next = input;
            input->next = first;
            return 0;

        }

        second = first;
        first = first->next;

    }

    second->next = input;
    input->next = NULL;

    return 0;


}


int insert_name(Movie_Name **list,Movie_Name*input){
    
    Movie_Name * first;

    first = *list;

    if(first == NULL){
        *list = input;
        return 0;
    }

    
    
    while(first->next!=NULL){
        first = first->next;}
    
    first->next = input;
    input->next = NULL;
    
}

/*---------------------------------------Menu functions------------------------------------------------*/


void menu_1(Movie_Name **list_nm, Movie_Budget **list_bdg){

    

    int op1,op2,under,upper;
   
    int check_menu;

    while(1){
        
        printf("\n1.Budget\n2.Genre\n3.Name\n4.Score\n5.Year\n\nSelect:");
        
        check_menu = scanf("%d",&op1);

        if(!check_menu || op1 >5 || op1<1){
            
            printf("Try Again\n");
            while(getchar() != '\n');
            continue;
        }

        printf("1.Single Selection\n2.Multiple Selection\n\nSelect: ");

        check_menu = scanf("%d",&op2);

        if(!check_menu || op2 >2 || op2<1){
            
            printf("Try Again\n");
            while(getchar() != '\n');
            continue;
        }


        if(op2 == 1){
            printf("\nEnter Vaule: ");
            scanf("%d",&upper);
            under == upper;
        }

        else if(op2==2){
            printf("\nEnter Start Vaule: ");
            scanf("%d",&under);
            
            printf("\nEnter End Vaule: ");
            scanf("%d",&upper);
            
            
        }

        
        switch(op1){

            case 1:
                
                (*list_bdg) = sort_budget(*list_bdg);
                print_bdg(*list_nm,*list_bdg,under,upper);
                return;
            case 2:
                *list_nm = sort_genre(*list_nm);
                print_nm(*list_nm,*list_bdg,under,upper);            
                return;
            case 3:
                *list_nm = sort_name(*list_nm);
                print_nm(*list_nm,*list_bdg,under,upper);           
                return;
            case 4:
                *list_nm = sort_score(*list_nm);
                print_nm(*list_nm,*list_bdg,under,upper);                
                return;
            case 5:
                (*list_bdg) = sort_year(*list_bdg);
                print_bdg(*list_nm,*list_bdg,under,upper);             
                return;
        }
    }
}


void menu_2(Movie_Name *list){
    
    

    int number_of_genre=0,k,j,flag;
    char **arr_genre=NULL,**temp1;
    Movie_Name *header;

    header = list;

    

    while(list!=NULL){ /*Creates an array holding the genres in the list*/   
        
        flag = 0;
        
        for(k=0;k<number_of_genre;k++){
            
            if(!strcmp(arr_genre[k],list->genre)){
                flag = 1;
                break;
            }
              
        }
        
        if(!flag){
            /* dynamic memory allocation*/ 
            number_of_genre++;
            temp1 = (char**)calloc(number_of_genre,sizeof(char*));

            for(j=0;j<number_of_genre-1;j++) temp1[j] = arr_genre[j];
        
            temp1[number_of_genre-1] = list->genre;

            if(arr_genre != NULL) free(arr_genre);
            arr_genre = temp1;
        
        }

        list = list->next;

    }

    for(k=0;k<number_of_genre;k++){ /*Prints all genres*/
        printf("%s\n",arr_genre[k]);
    }
}


void menu_3(Movie_Budget *list){
    
    int critic, way,flag = 0;

    Movie_Budget * header = list;

   
    
    while(1){

        list = header;
        flag = 0;

        printf("Enter Year: ");
        scanf("%d",&critic);

        printf("Less(0) or Greater(1) than %d: ",critic);
        scanf("%d",&way);

        switch(way){
            
            case 1:
                /* Finds and prints the greater than the entered year*/
                while(list!=NULL){
                    
                    if(list->year>critic){
                        flag = 1;
                        printf("\n%s",list->name);
                    }
                    list= list->next;
                }

                break;
            
            case 0:
                /* Finds and prints the less than the entered year*/
                while(list!=NULL){
                    
                    if(list->year<critic){
                        flag = 1;
                        printf("\n%s",list->name);
                    }
                    list= list->next;
                }
                break;
        }
        
        printf("\n");

        if(flag ==1)
            break;
        else if(flag == 0) /* if there is no movie in the entered values, gives error and requests new value*/
            printf("\nTRY AGAIN\n\n");
   
    }
}


void menu_4(Movie_Name *list){
    
    int way,flag = 0;

    double critic;
    
    Movie_Name *header;

    while(1){

        list = header;

        flag = 0;

        printf("Enter Score: ");
        scanf("%lf",&critic);

        printf("Less(0) or Greater(1) than %lf: ",critic);
        scanf("%d",&way);

        switch(way){
            
            case 1:
                /* Finds and prints the greater than the entered score */
                while(list!=NULL){
                    
                    if(list->score>critic){
                        flag = 1;
                        printf("\n%s",list->name);
                    }
                    list= list->next;
                }

                break;
            
            case 0:
                /* Finds and prints the less than the entered score */
                while(list!=NULL){
                    
                    if(list->score<critic){
                        flag = 1;
                        printf("\n%s",list->name);
                    }
                    list= list->next;
                }
                break;
        }
        
        printf("\n");

        if(flag ==1)
            break;
        else if(flag == 0) /* if there is no movie in the entered values, gives error and requests new value*/
            printf("\nTRY AGAIN\n\n");
   
    }
}

void menu_5(Movie_Name *list_nm, Movie_Budget *list_bdg){

    int i=0,j,flag;
    char vaule;
    char * temp1;
    char * temp2 = NULL;
    
    while(1){
        /* Dynamic Memory for string*/
        flag=0;
        printf("Enter the name of the movie: \n");
        
        while((vaule=getchar()) != '\n'){
            
            i++;
            temp1 = (char*)calloc(i,sizeof(char));

            for(j=0;j<i-1;j++) temp1[j] = temp2[j];
        
            temp1[i-1] = vaule;

            if(temp2 != NULL) free(temp2);
            temp2 = temp1;
        }
        
        while(list_nm!=NULL){ /*finds movie in linked-list*/
            
            if(!strcmp(temp2,list_nm->name)){ 
                flag = 1;
                break;
            }

            list_nm = list_nm->next;
        }

        while(list_bdg!=NULL){ /*finds movie in linked-list*/
            
            if(!strcmp(temp2,list_bdg->name)){ 
                flag = 1;
                break;
            }
            
            list_bdg = list_bdg->next;
        }



        if(flag == 1){ /*prints information about the movie if the movie is in the list and exits the loop*/
            
            printf("\nBudget: ");

            if(list_bdg->budget == -2)
                printf("Unknown");
            else
                printf("%d",list_bdg->budget);
            
            printf("\nGenre : %s",list_nm->genre);
            printf("\nName  : %s",list_bdg->name);
            printf("\nScore : %.1lf",list_nm->score);
            printf("\nYear  : %d\n",list_bdg->year);
            break;
        }

    }

}


void menu_6(Movie_Name *list){
    
    int i=0;
    double result=0;

    while(list!=NULL){
        result +=list->score;
        i++;
        list = list->next;
    }

    printf("\nAverage:%lf\n",result/(double)i);
}

void menu_7(Movie_Name *list){
        
    int number_of_genre=0,k,j,flag,counter;
    char **arr_genre=NULL,**temp1;
    Movie_Name *header;

    header = list;

    printf("\n");
    
    while(list!=NULL){    /*Creates an array holding the genres in the list*/
        
        flag = 0;

        for(k=0;k<number_of_genre;k++){
            
            if(!strcmp(arr_genre[k],list->genre)){
                flag = 1;
                break;
            }
              
        }
        
        if(!flag){

            /* dynamic memory allocation*/ 
            number_of_genre++;
            temp1 = (char**)calloc(number_of_genre,sizeof(char*));

            for(j=0;j<number_of_genre-1;j++) temp1[j] = arr_genre[j];
        
            temp1[number_of_genre-1] = list->genre;

            if(arr_genre != NULL) free(arr_genre);
            arr_genre = temp1;
        
        }

        list = list->next;

    }

    
    for(k=0;k<number_of_genre;k++){ /*finds how many of which genre are in the list and print*/
        
        printf("%s ",arr_genre[k]);
        list=header;
        counter = 0;
        
        while(list!=NULL){
            
            if(!strcmp(arr_genre[k],list->genre))
                counter++;
            
            list=list->next;
        }

        printf("%d\n",counter);

    }

    
}

    


/*----------------------------------------Sort Function-----------------------------------------------*/

Movie_Budget * sort_budget(Movie_Budget *list){
    
    Movie_Budget *header,*a,*b,*c,*temp; /*a b and c hold consecutive addresses*/

    int i,j,length_of_list=0,flag;

    header = list; /*header holds root address*/

    while((list)!=NULL){ /* finds the length of the linked-list*/
        (list) = (list)->next;
        length_of_list++;
    }

    

    
    for(i=1;i<length_of_list;i++){

        
        
        flag = 1;

        a = b = header;
        c = header->next;

        
        if(b->budget > c->budget){ 
                
            

            /*swap*/

            flag = 0;
            b->next = c->next;
            c->next = b;
            
            header = c;

            /* make a b and c consecutive again -D.Trump*/
            temp = b;
            b = c;
            c = temp;
            
        }

        
        a = b;
        b = b->next;
        c = c->next;




    for(j=i+1;j<length_of_list;j++){

        

        if(b->budget > c->budget){
            
            /*swap*/
            flag = 0;
            b->next = c->next;
            c->next = b;
            a->next = c;

            /* make a b and c consecutive again -D.Trump*/
            temp = b;
            b = c;
            c = temp; 
        }

        a = b;
        b = b->next;
        c = c->next;

        }

        

        if(flag) break; /*if flag is not 0 the linked-list is sorted*/
        

    }

    return header;

}

Movie_Budget * sort_year(Movie_Budget *list){
    
    Movie_Budget *header,*a,*b,*c,*temp; /*a b and c hold consecutive addresses*/

    int i,j,length_of_list=0,flag;

    header = list; /*header holds root address*/

    while((list)!=NULL){ /* finds the length of the linked-list*/
        (list) = (list)->next;
        length_of_list++;
    }

    

    
    for(i=1;i<length_of_list;i++){

        
        
        flag = 1;

        a = b = header;
        c = header->next;

        
        if(b->year > c->year){ 
                
            

            /*swap*/

            flag = 0;
            b->next = c->next;
            c->next = b;
            
            header = c;

            /* make a b and c consecutive again -D.Trump*/
            temp = b;
            b = c;
            c = temp;
            
        }

        
        a = b;
        b = b->next;
        c = c->next;




    for(j=i+1;j<length_of_list;j++){

        

        if(b->year > c->year){
            
            /*swap*/
            flag = 0;
            b->next = c->next;
            c->next = b;
            a->next = c;

            /* make a b and c consecutive again -D.Trump*/
            temp = b;
            b = c;
            c = temp; 
        }

        a = b;
        b = b->next;
        c = c->next;

        }

        

        if(flag) break; /*if flag is not 0 the linked-list is sorted*/
        

    }

    return header;

}

Movie_Name * sort_genre(Movie_Name *list){
    
    Movie_Name *header,*a,*b,*c,*temp; /*a b and c hold consecutive addresses*/

    int i,j,length_of_list=0,flag;

    header = list; /*header holds root address*/

    while((list)!=NULL){ /* finds the length of the linked-list*/
        (list) = (list)->next;
        length_of_list++;
    }

    

    
    for(i=1;i<length_of_list;i++){

        
        
        flag = 1;

        a = b = header;
        c = header->next;

        
        if(strcmp(b->genre,c->genre)>0){ 
                
            

            /*swap*/

            flag = 0;
            b->next = c->next;
            c->next = b;
            
            header = c;

            /* make a b and c consecutive again -D.Trump*/
            temp = b;
            b = c;
            c = temp;
            
        }

        
        a = b;
        b = b->next;
        c = c->next;




    for(j=i+1;j<length_of_list;j++){

        

        if(strcmp(b->genre,c->genre)>0){
            
            /*swap*/
            flag = 0;
            b->next = c->next;
            c->next = b;
            a->next = c;

            /* make a b and c consecutive again -D.Trump*/
            temp = b;
            b = c;
            c = temp; 
        }

        a = b;
        b = b->next;
        c = c->next;

        }

        

        if(flag) break; /*if flag is not 0 the linked-list is sorted*/
        

    }

    return header;

}

Movie_Name * sort_name(Movie_Name *list){

    Movie_Name *header,*a,*b,*c,*temp; /*a b and c hold consecutive addresses*/

    int i,j,length_of_list=0,flag;

    header = list; /*header holds root address*/

    while((list)!=NULL){ /* finds the length of the linked-list*/
        (list) = (list)->next;
        length_of_list++;
    }

    

    
    for(i=1;i<length_of_list;i++){

        
        
        flag = 1;

        a = b = header;
        c = header->next;

        
        if(strcmp(b->name,c->name)>0){ 
                
            

            /*swap*/

            flag = 0;
            b->next = c->next;
            c->next = b;
            
            header = c;

            /* make a b and c consecutive again -D.Trump*/
            temp = b;
            b = c;
            c = temp;
            
        }

        
        a = b;
        b = b->next;
        c = c->next;




    for(j=i+1;j<length_of_list;j++){

        

        if(strcmp(b->name,c->name)>0){
            
            /*swap*/
            flag = 0;
            b->next = c->next;
            c->next = b;
            a->next = c;

            /* make a b and c consecutive again -D.Trump*/
            temp = b;
            b = c;
            c = temp; 
        }

        a = b;
        b = b->next;
        c = c->next;

        }

        

        if(flag) break; /*if flag is not 0 the linked-list is sorted*/
        

    }

    return header;
}

Movie_Name * sort_score(Movie_Name *list){
    
    Movie_Name *header,*a,*b,*c,*temp; /*a b and c hold consecutive addresses*/

    int i,j,length_of_list=0,flag;

    header = list; /*header holds root address*/

    while((list)!=NULL){ /* finds the length of the linked-list*/
        (list) = (list)->next;
        length_of_list++;
    }

    

    
    for(i=1;i<length_of_list;i++){

        
        
        flag = 1;

        a = b = header;
        c = header->next;

        
        if(b->score > c->score){ 
                
            

            /*swap*/

            flag = 0;
            b->next = c->next;
            c->next = b;
            
            header = c;

            /* make a b and c consecutive again -D.Trump*/
            temp = b;
            b = c;
            c = temp;
            
        }

        
        a = b;
        b = b->next;
        c = c->next;




    for(j=i+1;j<length_of_list;j++){

        

        if(b->score > c->score){
            
            /*swap*/
            flag = 0;
            b->next = c->next;
            c->next = b;
            a->next = c;

            /* make a b and c consecutive again -D.Trump*/
            temp = b;
            b = c;
            c = temp; 
        }

        a = b;
        b = b->next;
        c = c->next;

        }

        

        if(flag) break; /*if flag is not 0 the linked-list is sorted*/
        

    }

    return header;
}


/*---------------------------------------print functions for menu 1-----------------------------------*/

void print_bdg(Movie_Name *list_nm, Movie_Budget *list_bdg,int start,int end){

    Movie_Name *header;
    int i;
    header = list_nm;

    for(i=1;i<=end;i++){

        if(i>=start){
            
            while(list_nm!=NULL){ /*finds same movie in other linked-list*/
            
                if(!strcmp(list_nm->name,list_bdg->name)){ /* prints information about movie*/

                    if(list_bdg->budget == -2)
                        printf("Unknown        ");
                    else
                        printf("%-15d",list_bdg->budget);
                    
                    printf("%-15s %-50s %.1f   %d\n",list_nm->genre,list_nm->name,list_nm->score,list_bdg->year);
                    
                    break;
                }
            
                list_nm = list_nm->next;
            }

            list_nm = header;
        }

        list_bdg = list_bdg->next;  
    }
}

void print_nm(Movie_Name *list_nm, Movie_Budget *list_bdg,int start,int end){
    
    Movie_Budget *header;
    int i;
    header = list_bdg;

    for(i=1;i<=end;i++){

        if(i>=start){
            
            while(list_bdg!=NULL){ /*finds same movie in other linked-list*/
            
                if(!strcmp(list_nm->name,list_bdg->name)){ /* prints information about movie*/

                    if(list_bdg->budget == -2)
                        printf("Unknown        ");
                    else
                        printf("%-15d",list_bdg->budget);
                    
                    printf("%-15s %-50s %.1f   %d\n",list_nm->genre,list_nm->name,list_nm->score,list_bdg->year);
                    
                    break;
                }
            
                list_bdg = list_bdg->next;
            }

            list_bdg = header;
        }

        list_nm = list_nm->next;  
    }
}