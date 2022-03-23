#include <stdio.h>
#include <string.h>

typedef struct{
    char name[20];
    int age;
    int label;
}customer;


#define critical_x 5
#define critical_y 3
#define critical_z 2


int lenseq(customer*seq);
int miniseqlen(customer*seq);
void print_seq(customer *seq);
int place(customer*seq,int temp_label);
void adding(customer *seq,char *temp_name, int temp_age,int temp_label,int index);
void delete(customer*seq);

int main(){
    customer bank[51];
    char temp_name[20];
    int temp_age,temp_label,i,j,menu;

    for(i=0;i<50;i++){bank[i].label = -5;}

    printf("\n***********Banking System***********\n");
    while(1){
        
        
        printf("\n--------------------------------------------\n");
        print_seq(bank);

        printf("\n\n1-Add customer\n2-Process customer\n3-Exit System\n");
        scanf("%d",&menu);

        if(menu == 1){

            printf("\nPlease enter the name of the customer: ");
            scanf("%s",temp_name);
            printf("\nPlease enter the age of the customer: ");
            scanf("%d",&temp_age);
            printf("\nPlease enter the label of the customer: ");
            scanf("%d",&temp_label);

            
            adding(bank,temp_name,temp_age,temp_label,place(bank,temp_label));


        }

        else if(menu == 2){
            
            if(lenseq(bank)){
                printf("\nProceed customer is %s\n",bank[0].name);
                delete(bank);}
            else
                printf("\nThere is not any customer in bank system sequence.");
        }

        else if(menu == 3)
            return 0;
    
    }
}


void print_seq(customer *seq){ /*prints sequence*/
    int i;

    printf("\nCurrent Sequence: ");
    for(i=0;seq[i].label!=-5;i++){
        printf("%d",seq[i].label);
        
        if(seq[i+1].label == -5)
            return;
        printf("-");
    }
}

int lenseq(customer*seq){ /*returns lenght of sequence*/
    int i;
    for(i=0;seq[i].label!=-5;i++){}
    return i;
}

int miniseqlen(customer*seq){ /*Returns the length of the first mini sequence within the sequence*/
    
    int i,count_employee=0,count_retired=0,count_student=0,count_unemployeed=0,count_other=0;

    for(i=0;lenseq(seq);i++){
        
        switch(seq[i].label){

            case 0:
            count_employee++;
            break;

            case 1:
            count_retired++;
            break;

            case 2:
            count_student++;
            break;

            case 3:
            count_unemployeed++;
            break;

            case 4:
            count_other++;
            break;

        }

    if(count_employee>critical_x || count_retired>critical_y || count_student>critical_y || count_unemployeed>critical_z || count_other>critical_z)
        return i;
    
    else if(seq[i].label>seq[i+1].label)
        return i+1;
    }

}

int place(customer*seq,int temp_label){
    int i,j,critical,count=0;
    int flag;
    
    if(temp_label == 0)
        critical = critical_x;
    else if(temp_label == 1 ||temp_label == 2)
        critical = critical_y;
    else if(temp_label == 3 ||temp_label == 4)
        critical =critical_z;

    
    for(i=0;i<miniseqlen(seq);i++){
        
        if(temp_label==seq[i].label)
            count++;
        
        if(count == critical)
            return miniseqlen(seq) + place(&seq[miniseqlen(seq)],temp_label);


        if(temp_label < seq[i].label )
            return i;
    }

    return i;

}




void adding(customer *seq,char *temp_name, int temp_age,int temp_label,int index){
    int i;

    

    for(i = lenseq(seq);i>index;i--){
        seq[i]=seq[i-1];
    }
    
    strcpy(seq[index].name,temp_name);
    seq[index].age = temp_age;
    seq[index].label = temp_label;
}

void delete(customer*seq){
    int i;

    for(i=1;i<lenseq(seq);i++){
        seq[i-1] = seq[i];
    }
    seq[i-1].label = -5;
}