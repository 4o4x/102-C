#include <stdio.h>
#include <math.h>
void calculate_fibonacci_sequence();
void decide_perfect_harmonic_number();
void difference_max_min();
void bmi_calculation();



int main(){
    calculate_fibonacci_sequence();
    decide_perfect_harmonic_number();
    difference_max_min();
    bmi_calculation();



}







void calculate_fibonacci_sequence(){
    
    int i,first,second,temp;

    int flag;                   /*  If the input number is not positive integer  -->   flag = -1
                                    If the input is not a number                 -->   flag = 1   
                                    If the input is '*'                          -->   flag = 2            */
    char char_digit;
    int  int_digit;
    char clear_buffer;
    double number_of_digit;
    double number;
    
  
    printf("Please enter term(s) number: ");
    
    while(1){
        char_digit = '0';
        flag=0;
        first = 0;
        second = 1;
        number_of_digit =0;
        number = 0;

        while((char_digit = getchar())!= '\n'){       /* getchar() will read until enter is pressed */
            
            if(char_digit == '*'){ 

                flag = 2;  /*return;*/
                
                break;
            }

            else if(char_digit == '-'){
            
                
                flag = -1;

                
                break;
            }

            else if (char_digit-'0' > 9 || char_digit-'0'<0 ){  /*!!!> You should read the next comment before looking at this < !!!
                                                                    There is no other numerical character in ASCII, So the value of int_digit by subtracting '0' from char_digit
                                                                    must be between 9 and 0 So int_digit cannot be greater or less than this.
                                                                    if the input does not provide the condition , input is not numeric
                                                                 */
                flag = 1;
                break;
            }

            number_of_digit++;                   
            
            int_digit = char_digit - '0';       /* In ASCII '0' = 48 ,'1' = 49 ...... '9' = 57 
                                                    So We can find the value of int_digit by subtracting '0' from char_digit. */

            number += int_digit*pow(10,(-1*number_of_digit));   /* We do not know how many digits the input has.
                                                                    So we cannot know  the digit values ​​of the inputs in advance. 
                                                                    But we know the place values ​​of numbers after the comma in floating numbers.
                                                                    Therefore we write the input like a float.    
                                                                    */
        }

        number = number*pow(10,number_of_digit);        /*In the end we find integer vaule using number_of_digit*/
    
        
        if( flag == 2){         /*  input = '*'       */
            while((clear_buffer = getchar())!= '\n'){} /* to clean buffer*/
            return;
        }
        
        
        else if(flag == -1){     /* input<0 */
            
            while((clear_buffer = getchar())!= '\n'){} /* to clean buffer*/
            
            printf("Please enter “positive” term(s) number:");
            continue;

        }

        else if(flag == 1){          /*    input is not numeric   */
            
            while((clear_buffer = getchar())!= '\n'){} /* to clean buffer*/
            
            printf("Please enter “numeric” term(s) number:");
            continue;
        }
    
    
        printf("Fibonacci Sequence:\n");
        
        printf("\n1\n");      /* First term of Fibonacci  Sequence */

        for(i=0;i<number-2;i++){
        
            temp = second;            
            second = first+second;
            first = temp;
        
            printf("\n%d\n",second);
        }

        printf("\nPlease enter term(s) number: ");
    
    }
   
    
}

void decide_perfect_harmonic_number(){
while(1){
    
    int i,perfect=1,numbers_of_divisor=1;
    double harmonic=1;
    
    char char_digit;
    int int_digit;
    double number_of_digit=0;
    double number = 0;
    
    printf("\nPlease input a number: ");
    while((char_digit = getchar())!= '\n'){
        
        if(char_digit == '*'){ 

                return;
            }

        number_of_digit++;
        int_digit = char_digit - '0';   /* In ASCII '0' = 48 ,'1' = 49 ...... '9' = 57 
                                                    So We can find the value of int_digit by subtracting '0' from char_digit. */

        number += int_digit*pow(10,(-1*number_of_digit));/* We do not know how many digits the input has.
                                                                    So we cannot know  the digit values ​​of the inputs in advance. 
                                                                    But we know the place values ​​of numbers after the comma in floating numbers.
                                                                    Therefore we write the input like a float.    
                                                                    */
        


    }

    number = number*pow(10,number_of_digit);    /*In the end we find integer vaule using number_of_digit*/
    number = (int)number;




    printf("\nNatural Number Divisors:1");
    
    for(i=2;i<=number;i++){
        if((int)number%i ==0){
            numbers_of_divisor++;
            printf(",%d",i);
            
            perfect += i;   /* sum of all divisors*/
            
            harmonic += (1/(double)i);  /*    =   1/divisor(1) + 1/divisor(2) +.......+ 1/divisor(n)   */
        }
    }

    perfect=perfect-number;    /*  not including itself */
    
    harmonic = (double)numbers_of_divisor/harmonic; /*if (number of divisor/sum of the (1/divisors)) is equal a intiger that number is harmonic number */
   
    printf("\n\nIs Perfect Number? : ");

    if(perfect == number)
        printf("Yes");
    else 
        printf("No");

    printf("\n\nIs Harmonic Divisor Number? : ");

  
    if(harmonic - (int)harmonic <0.000000000001  && harmonic - (int)harmonic > -0.000000000001 ) /*Checks if number is  float or integer*/
        printf("Yes");
    else 
        printf("No");

   


}

}

void difference_max_min(){
    int i;
    double number,max,min;
    
    printf("\nPlease enter 5 numbers: ");
    scanf("%lf",&number);
    
    max = number;
    min = number;

    for(i=0;i<4;i++){
        
        scanf("%lf",&number);
        
        if(number > max )
            max = number;

        else if (number< min)
            min = number;
                
    }

    printf("\nMaximum number is:%g\n",max);
    printf("\nMinimum number is:%g\n",min);
    printf("\nDifference between maximum and minimum is %g\n",max - min);

}



void bmi_calculation(){
    
    double weight,height,bmi;
    
    printf("\nPlease enter weight(kg): ");
    scanf("%lf",&weight);
    
    printf("\nPlease enter height(m): ");
    scanf("%lf",&height);

    bmi = (weight)/(height*height);   /* BMI(Body Mass Index) Formula : bmi = weight(kg)/(height(m))^2  */ 

    printf("\nYour category:");
    
    if(bmi<16.0)
        printf("Severely Underweight\n");
    
    else if(bmi>=16.0 && bmi<=18.4)
        printf("Underweight\n");
    
    else if(bmi>=18.5 && bmi<=24.9)
        printf("Normal\n");
    
    else if(bmi>=25.0 && bmi<=29.9)
        printf("Overweight\n");
    
    else
        printf("Obese\n");
}   