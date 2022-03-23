#include <stdio.h>
#include <math.h>

void amstrong_palidrome();
void sum_of_primes_between_two_intiger();
void write_polynomial();
int digit(int number , int which);
int is_prime(int number);



int main(){
    write_polynomial();
    amstrong_palidrome();
   
    sum_of_primes_between_two_intiger();
    
}


int is_prime(int number){ /*checks if the number is prime. if the number is prime function returns 1 else returns 0*/
    int i;
    for(i=2;i<number;i++){
        if(number %i == 0)
            return 0;
    }
    return 1;
}

int digit(int number , int which){   /*finds digit vaule (units digit = 1 , tens digit = 2 .....)*/
    
    return (number%(int)pow(10,which))/(int)pow(10,which-1);
}

void write_polynomial(){
     int flag=0;
     int n;
     float a;
     int i;

    printf("\nEnter your polynomial [n a_n a_n-1 a_n-2 ... a_0]:");
    scanf("%d",&n);
    
    for(i = n; i>=1;i-- ){
        scanf(" %f",&a);
    
        if(a){

            if( (0.95 < a && a <= 1.05)  || (a < -0.95 && -1.05 <=a )){

                if(a < -0.95 && -1.05 <=a)
                    printf("-");

                else if((0.95 < a && a <= 1.05)){

                    if(flag == 1)
                        printf("+");
                }
                
            }

            
            else if(a - (int)a < 0.00000001 || a - (int)a > - 0.00000001 )
                printf("%+d",(int)a);

            

            else if(flag ==1)
                printf("%+.1f",a);

            else
                printf("%.1f",a);

            flag = 1;

        

        if(i>1)
            printf("x^%d",i);
        else if(i==1)
            printf("x");
        
        }

        
            
    }
    
    scanf("%f",&a);

    if(a){
        if(flag ==1)
            if(a - (int)a < 0.00000001 || a - (int)a > - 0.00000001 )
                printf("%+d",(int)a);
            else 
                printf("%+.1f",a);
        else
            if(a - (int)a < 0.00000001 || a - (int)a > - 0.00000001 )
                printf("%+d",(int)a);
            else 
                printf("%.1f",a);
    }
       

    printf("\n");


}

void amstrong_palidrome(){
    
    int palidrome_flag = 0 , amstrong_flag = 0;
    int number;
    int number_of_digits = 0;
    
    double temp;
    int i;
    int amst = 0;
    int pali = 0;


    printf("Please enter an integer number: ");
    scanf("%d",&number);

    while(number<0){
        printf("\n<Error> You entered negative number\nPlease enter an positive integer number: ");
        scanf("%d",&number);
    }


    temp= number;

    while(temp>=1){ /* determines how many digits the number is */
        temp = temp/10;
        number_of_digits++;
    }

    temp = 0;

    for(i=1;i<= number_of_digits;i++){
         
        amst += (int)pow(digit(number,i),3); /*the sum of cubes of its digits. */
        
        

    }

    
    if(amst == number) amstrong_flag = 1; /*if the sum of cubes of the number digits is equal to the number, the number is amstrong number*/


    for(i=1; i<= number_of_digits;i++){
        temp+= digit(number,i)*pow(10,-1*i);      /* turns the number from ABCDE to 0.EDCBA*/
        
    }

    pali = temp*pow(10,number_of_digits);  /* turns 0.EBCBA to EBCBA*/
    

    if(pali == number) palidrome_flag = 1; /* if the number ABCDE is equal to EDCBA ,the number is polidrome number */

    
    
    if(palidrome_flag == 1 && amstrong_flag == 1)
        printf("\n %d is both Palindrome and Armstrong number.",number);
    
    else if (palidrome_flag == 0 && amstrong_flag == 0)
        printf("\nThis number does not satisfy any special cases");

    else {
        if(palidrome_flag == 1)
            printf("\nThis number is only Palindrome number.");
        else
            printf("\nThis number is only Armstrong number.");
    }

}


void sum_of_primes_between_two_intiger(){

    int i,first_number, second_number,sum_of_primes = 0,temp;

    printf("\nPlease enter first integer number:");
    scanf(" %d",&first_number);

    while(first_number<0){
        printf("\n<Error> You entered negative number\nPlease enter first (positive) integer number: ");
        scanf(" %d",&first_number);
    }

    printf("\nPlease enter second integer number:");
    scanf(" %d",&second_number);

    while(second_number<0){
        printf("\n<Error> You entered negative number\nPlease enter second (positive) integer number: ");
        scanf(" %d",&second_number);
    }
    

    if(first_number > second_number){
        temp = first_number;
        first_number = second_number;
        second_number = temp;
    }


    for(i=first_number+1;i<second_number;i++){
        if(is_prime(i))     /*Cheks if the number is prime*/
            sum_of_primes += i;
    }

    printf("\nSum of prime numbers between %d and %d : %d\n",first_number,second_number,sum_of_primes);
}