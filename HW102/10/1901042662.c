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


int fill_list(movie **list,char***arr_genre,int (*number_of_genre),char* file);

int fill_name(char** str,FILE *fp);

void menu_1(movie *list, int lenght_of_list,char**arr_genre,int number_of_genre);

void menu_2(char**arr_genre,int number_of_genre);

void menu_3(movie *list, int lenght_of_list);

void menu_4(movie *list, int lenght_of_list);

void menu_5(movie *list, int lenght_of_list,char**arr_genre,int number_of_genre);

void menu_6(movie *list, int lenght_of_list);

void menu_7(movie *list, int lenght_of_list,char**arr_genre,int number_of_genre);








int main(int argc,char *argv[]){
    int i;
    movie *list;
    int lenght_of_list;
    char ** arr_genre;
    int number_of_genre =0;
    int menu;
    int check_menu;
    
    lenght_of_list = fill_list(&list,&arr_genre,&number_of_genre,argv[1]);
    
    

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
                menu_1(list,lenght_of_list,arr_genre,number_of_genre);                
                break;
            case 2:
                menu_2(arr_genre,number_of_genre);              
                break;

            case 3:
                menu_3(list,lenght_of_list);
                break;

            case 4:
                menu_4(list,lenght_of_list);
                break;
            
            case 5:
                menu_5(list,lenght_of_list,arr_genre,number_of_genre);                               
                break;
            
            case 6:
                menu_6(list,lenght_of_list);           
                break;

            case 7:
                menu_7(list,lenght_of_list,arr_genre,number_of_genre);
                break;
            
        }
        
        
        

    
    }

}


int fill_list(movie **list,char***arr_genre,int* number_of_genre,char* file){

    FILE * fp;

    movie *temp_list_x;
    movie *temp_list_y = NULL;
    
    int counter_list=0,k,i;
    
    char * str;
    char **temp_genre1,**temp_genre2 = NULL;
        
    double bdgt,scr; 
    int gint,yint;

    int check_bdgt;
    int stlen;
    int flag =0;



    fp = fopen(file,"r");

    if(fp==NULL){
        printf("Dosya acilmadi\n");
        return -1;
    }
    
    while(getc(fp) != '\n');
    

    while(1){
        
        /*--------------- Budget and checking EOF -----------*/
        
        check_bdgt = fscanf(fp,"%lf",&bdgt);

        if(check_bdgt == EOF)
            break;
    
        else if(!check_bdgt)
            bdgt = -1;
        
        while(getc(fp)!= ',');

        /*------------------- Dynamic Memory Allocation ----------------------*/
        
        counter_list++;

        temp_list_x = (movie*)calloc(counter_list,sizeof(movie));
        
        for(k=0;k<counter_list-1;k++) temp_list_x[k] = temp_list_y[k];

        temp_list_x[counter_list-1].budget = bdgt;


        /*--------------------- Genre ---------------------*/
        flag =0;

        stlen = fill_name(&str,fp);
        
        for(i=0;i<(*number_of_genre);i++){
            
            if(!strncmp(temp_genre2[i],str,stlen)){
                flag = 1;
                temp_list_x[counter_list-1].genre = i;
                break;
            }
        }


        if(!flag){
            
            (*number_of_genre)++;
            
            temp_genre1 = (char**)calloc((*number_of_genre),sizeof(char*));
        
            for(k=0;k<(*number_of_genre)-1;k++) temp_genre1[k] = temp_genre2[k];

            temp_list_x[counter_list-1].genre = (*number_of_genre)-1;
            temp_genre1[(*number_of_genre)-1] = (char*) calloc(stlen,sizeof(char));
            strncpy(temp_genre1[(*number_of_genre)-1],str,stlen);

            if(temp_genre2 != NULL) free(temp_genre2);
            temp_genre2 = temp_genre1;
            

        }

        free(str);
        /*--------------------- Name ---------------------*/


        stlen = fill_name(&str,fp);
        

        temp_list_x[counter_list-1].name = (char*) calloc(stlen,sizeof(char));

        strncpy(temp_list_x[counter_list-1].name,str,stlen);

        free(str);

        
        /*--------------------- Score ---------------------*/

        fscanf(fp,"%lf",&scr);
        while(getc(fp)!= ',');
        temp_list_x[counter_list-1].score = scr;


        /*--------------------- Year ---------------------*/

        fscanf(fp,"%d",&yint);
        while(getc(fp)!= '\n');
        temp_list_x[counter_list-1].year = yint;
        

        /*--------------------- Dynamic Memory Allocation ---------------------*/
        if(temp_list_y != NULL) free(temp_list_y);
        temp_list_y = temp_list_x;


        

        
    }

    *list = temp_list_y;
    *arr_genre = temp_genre2;

    

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

void menu_1(movie *list, int lenght_of_list,char**arr_genre,int number_of_genre){

    /* I couldn't finish :( */

    int op1,op2,under,upper,i,j,index=-1;
    double max=0,temp_max,temp_min=0,min;
    int check_menu;

    while(1){
        min=0;
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
            upper++;
            under == upper;
        }

        else if(op2==2){
            printf("\nEnter Start Vaule: ");
            scanf("%d",&under);
            under++;
            
            printf("\nEnter End Vaule: ");
            scanf("%d",&upper);
            
            upper++;
            
        }

        
        

        switch(op1){

            case 5:
                
                max = 0;

                for(i=0;i<=lenght_of_list;i++){
                    if(list[i].year>max)
                        max = list[i].year;

                }
                
                
                
                for(i=0;i<=upper;i++){
                    temp_min = max;
                    for(j=0;j<lenght_of_list;j++){
                        
                        if(list[j].year<temp_min && min<=list[j].year && j !=index){
                            temp_min = list[j].year;
                            index = j;

                        }

                    }

                    min = temp_min;

                    if(i>=under){
                        
                        
                        printf("-20s%-5.1lf   %-4d\n",list[index].budget,list[index].name,list[index].score,list[index].year);
                    }
                }



                
                break;
            case 2:
                
                
                break;

        }
        
        
        

    
    }


}


void menu_2(char**arr_genre,int number_of_genre){
    int i;
    for(i=0;i<number_of_genre;i++){
        printf("\n%s",arr_genre[i]);
    }

    printf("\n");
}

void menu_3(movie *list, int lenght_of_list){
    
    int critic,way,i,flag = 0;
    
    while(1){

        flag = 0;

        printf("Enter Year: ");
        scanf("%d",&critic);

        printf("Until(0) or Since(1) than %d: ",critic);
        scanf("%d",&way);

        switch(way){
            
            case 1:

                for(i=0;i<lenght_of_list;i++){
                    
                    if(list[i].year>critic){
                        flag = 1;
                        printf("\n%s",list[i].name);
                    }
                }
                break;
            
            case 0:

                for(i=0;i<lenght_of_list;i++){
                    
                    if(list[i].year<critic){
                        flag = 1;
                        printf("\n%s",list[i].name);
                    }
                }
                break;
        }
        
        printf("\n");

        if(flag ==1)
            break;
        else if(flag == 0)
            printf("\nTRY AGAIN\n\n");
   
    }
}


void menu_4(movie *list, int lenght_of_list){
    
    int critic,way,i,flag = 0;
    
    while(1){

        flag = 0;

        printf("Enter Score: ");
        scanf("%d",&critic);

        printf("Less(0) or Greater(1) than %d: ",critic);
        scanf("%d",&way);

        switch(way){
            
            case 1:

                for(i=0;i<lenght_of_list;i++){
                    
                    if(list[i].score>critic){
                        flag = 1;
                        printf("\n%s",list[i].name);
                    }
                }
                break;
            
            case 0:

                for(i=0;i<lenght_of_list;i++){
                    
                    if(list[i].score<critic){
                        flag = 1;
                        printf("\n%s",list[i].name);
                    }
                }
                break;
        }
        
        printf("\n");

        if(flag ==1)
            break;
        else if(flag == 0)
            printf("\nTRY AGAIN\n\n");
   
    }
}

void menu_5(movie *list, int lenght_of_list,char**arr_genre,int number_of_genre){

    

    int i=0,j,k,flag;
    char vaule;
    char * temp1;
    char * temp2 = NULL;
    
    while(1){
        
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
        
        for(k=0;k<lenght_of_list;k++){
            
            if(!strncmp(temp2,list[k].name,i)){
                
                printf("\nBudget: ");

                if(list[k].budget == -1)
                    printf("Unknown");
                else
                    printf("%lf",list[k].budget);
                
                printf("\nGenre : %s",arr_genre[list[k].genre]);
                printf("\nName  : %s",list[k].name);
                printf("\nScore : %.1lf",list[k].score);
                printf("\nYear  : %d\n",list[k].year);
                 
                flag = 1;
                break;


            }
        }

        if(flag ==1 )
            break;

    }

}


void menu_6(movie *list, int lenght_of_list){
    int i;
    double result;

    for(i=0;i<lenght_of_list;i++){
        result+=list[i].score;
    }

    printf("\nAverage:%lf\n",result/(double)lenght_of_list);
}

void menu_7(movie *list, int lenght_of_list,char**arr_genre,int number_of_genre){

    int i,j,couter=0;

    for(i=0;i<number_of_genre;i++){
        
        couter=0;
        
        for(j=0;j<lenght_of_list;j++){

            if(list[j].genre == i){
                couter++;
            }
        }
    
        printf("\n%s %d",arr_genre[i],couter);


    }

    printf("\n");
    
    
}


