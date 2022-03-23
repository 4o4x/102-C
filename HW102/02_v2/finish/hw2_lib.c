/*
** hw2_lib.c:
**
** The source file implementing library functions.
**
*/

#include <stdio.h>
#include "hw2_lib.h"
#include <math.h>

int find_weekday_of_data(int day, int month, int year)
{
    
    /*The Gauss method */


    int result;
    int c_month[12] = {0,3,3,6,1,4,6,2,5,0,3,5}; /*    Common years 	*/
    int l_month[12] = {0,3,4,0,2,5,0,3,6,1,4,6}; /*    Leap years       */
    
    
    if(year%4 ==0) /*  to determine if it is a leap year  */ 
        
        result = ( day + l_month[month-1] + 5*( (year-1) %4) + 4*(( year-1) %100) + 6*(( year-1) %400)  )%7;  /* Gauss Formula*/
    
    else

        result = ( day + c_month[month-1] + 5*( (year-1) %4) + 4*(( year-1) %100) + 6*(( year-1) %400)  )%7;  /* Gauss Formula*/
    
    if(!result) /* method returns sunday as 0 */
        return 7; /* We assume that 7 is sunday */
    else 
        return result;
}


int count_day_between_dates(int start_day, int start_month, int start_year, int end_day, int end_month, int end_year)
{
    int result,i,leap_years = 0;
  
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
   

    if(end_year%4==0){   /* In leap year February has 29 day  */
        months[1] = 29;
        }
    

    for(i=start_year+1;i<end_year;i++){   /* Counts leap years between dates (start date and end date not included*/
        
        if(i%4 == 0)
            leap_years++;
    }
    
    result = (end_year-start_year)*365+leap_years; /* Calculates days between start_day,start_month ,start_year
                                                    and  start_day,start_month,end_year */

   

    if(start_month>end_month){       

        for(i=end_month-1;i<start_month-1;i++){ /*Calculates days between start_day,start_month ,end_year
                                                    and  start_day, end_month, end_year*/
            result -= months[i];
        }

        result +=(end_day-start_day);   /*Calculates days between start_day,end_month ,end_year
                                                    and  end_day, end_month, end_year*/
        
    }
    
    else if(start_month<end_month){   

        for(i=start_month-1;i<end_month-1;i++){ /*Calculates days between start_day,start_month ,end_year
                                                    and  start_day, end_month, end_year*/
            result += months[i];                
            
        }

        result +=(end_day-start_day);   /*Calculates days between start_day,end_month ,end_year
                                                    and  end_day, end_month, end_year*/
        

    }
    else
        result+=(end_day-start_day); 


    if((end_year-start_year)){
        
        if(start_year%4==0){    
                        
            if(start_month<=2) 
                result++;

            else if((start_month>2 && end_month >2)&& (end_year%4 == 0)){
                result++;
            }
        }
    
        else if(end_year%4 == 0){
            if(start_month>2 && end_month >2)
                result++;
        }

    }
  
    return result;

}


double find_angle(double a, double b, double c)
{
    double inscribed_angle,lenght1,lenght2;
    double pi = 3.14159265359;
    
    inscribed_angle = acos( ((a*a)-(b*b)-(c*c))/ (-2*b*c) ); /* Law of cosines > c^2 = a^2 + b^2 - 2ab.cos(x)*/
    
    lenght1 = sqrt( c*c+ (b/2)*(b/2) - 2*(b/2)*c*cos(inscribed_angle)); /*lenght of one median of triangle*/          
    lenght2 = sqrt( b*b+ (c/2)*(c/2) - 2*(c/2)*b*cos(inscribed_angle)); /*lenght of one median of triangle*/

    lenght1 = (2*lenght1)/3; /*  length of the one edge in little triangle */
    lenght2 = (2*lenght2)/3; /*  length of the one edge in little triangle */
    
    return acos( ( (a*a)-(lenght1*lenght1)-(lenght2*lenght2) )/ (-2*lenght1*lenght2)); /* Law of cosines > c^2 = a^2 + b^2 - 2ab.cos(x)*/

    



    
}


void print_tabulated(unsigned int r11, double r12, int r13, 
                     unsigned int r21, double r22, int r23, 
                     unsigned int r31, double r32, int r33, char border)
{
    
    
	int temp,i,j,x,space;
	int digit;
                                                    /*int vaules[3][3]= { {r11,r12,r13} , {r21,r22,r23} , {r31,r32,r33} };*/
    unsigned int v_1 [3]; /*= {r11,r21,r31};*/
    double v_2 [3]; /*= {r12,r22,r32};*/                                       /*     Gives error with "-ansi -pedantic-errors"        */
    int v_3 [3]; /*= {r13,r23,r33};*/

    v_1[0] = r11;
    v_1[1] = r21;
    v_1[2] = r31;

    v_2[0] = r12;
    v_2[1] = r22;
    v_2[2] = r32;

    v_3[0] = r13;
    v_3[1] = r23;
    v_3[2] = r33;
    

    
    for(x=0;x<31;x++)
            printf("%c",border);
    
    printf("\n");
    printf("|Row 101|Row ABCDEFG|RowXYZ123|");
    printf("\n");

    
    for(i=0;i<3;i++){
        
        for(x=0;x<31;x++)
            printf("%c",border);
        
        printf("\n");

        for(j=0;j<3;j++){
            
            if(j==0){
                temp = v_1[i];
	            digit = 0;
	            
                while (temp>=1){       /*Finding the numbers of digits*/
		            temp = temp/10;
		                digit++;
	            }

                space = 7-digit;        /* Determining how much space there will be*/

	            printf("|%*d%*c",(space/2)+digit,v_1[i],(space)-(space/2),' ');
            }
            
            else if(j==1){
	            
                
	            digit = 1;             /* There is a extra digit (".") in float numbers*/
	            temp = v_2[i]*100;     /* AB.XY -> ABXY  */

                if ((temp)<0)           /* sign */
                    digit++;

                if(temp%10==0){         /* ABX0 */
                    digit--;
                    if(temp%100==0)     /* AB00 */
                        digit-=2;       /* There is not "." if number is AB.XY*/
                }

                

                while (temp<=-1 || temp>=1){        /*Finding the numbers of digits*/
		            temp = temp/10;
		                digit++;            
	            }

                space = 11-digit;       /* Determining how much space there will be*/

                 printf("|%.*g%*c",digit-1,v_2[i],space,' ');
            }

            else{
                temp = v_3[i];
	            digit = 1;              /* sign */
	            
                while ( temp<=-1 ||temp>=1){        /*Finding the numbers of digits*/
		            temp = temp/10;
		                digit++;
	            }
                space = 9-digit;    /* Determining how much space there will be*/
	            printf("|%+d%*c",v_3[i],space,' ');


            }

        
        }

        printf("|\n");
    }

    for(x=0;x<31;x++)
            printf("%c",border);
	
    printf("\n");
}

