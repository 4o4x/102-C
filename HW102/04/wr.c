#include <stdio.h>

void write_polynomial();

int main(){
    //amstrong_palidrome();
   // sum_of_primes_between_two_intiger();
   int i;
   for(i=0;i<11;i++){
    printf("\n%d:",i+1);
   write_polynomial();}
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
            printf("%+.1f",a);
        else
            printf("%.1f",a);
    }
       

    printf("\n");


}