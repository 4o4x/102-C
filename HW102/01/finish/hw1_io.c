/*
** hw1_io.c:
**
** The source file implementing output functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
**
*/


#include <stdio.h>
#include "hw1_io.h"


void write_polynomial3(double a0, double a1, double a2, double a3)
{
    int flag=0;

    if(a0!=0){

          if(a0 == 1 || a0 ==-1){

            if(a0 ==-1)
                printf("-");

            else if(a0 == 1){

                 if(flag == 1)
                    printf("+");
            }
            printf("x^3");
        }


        else if(flag ==1)
                printf("%+.1fx^3",a0);

        else
            printf("%.1fx^3",a0);

        flag = 1;

    }


    if(a1!=0){

        if(a1 == 1 || a1 ==-1){

            if(a1 ==-1)
                printf("-");

            else if(a1 == 1){

                 if(flag == 1)
                    printf("+");
            }
            printf("x^2");
        }


        else if(flag ==1)
                printf("%+.1fx^2",a1);

        else
            printf("%.1fx^2",a1);

        flag = 1;
    }

    if(a2!=0){

         if(a2 == 1 || a2 ==-1){
            if(a2 ==-1)
                printf("-");

            else if(a2 == 1){

                 if(flag == 1)
                    printf("+");
            }

            printf("x");
            }

        else if(flag ==1)
                printf("%+.1fx",a2);

        else
            printf("%.1fx",a2);

        flag = 1;

    }
    if(a3!=0){

        if(flag ==1)
            printf("%+.1f",a3);
        else
            printf("%.1f",a3);
    }
    printf("\n");

}


void write_polynomial4(double a0, double a1, double a2, double a3, double a4)
{
    int flag=0;
     if(a0!=0){

          if(a0 == 1 || a0 ==-1){

            if(a0 ==-1)
                printf("-");

            else if(a0 == 1){

                 if(flag == 1)
                    printf("+");
            }
            printf("x^4");
        }


        else if(flag ==1)
                printf("%+.1fx^4",a0);

        else
            printf("%.1fx^4",a0);

        flag = 1;

    }




    if(a1!=0){

          if(a1 == 1 || a1 ==-1){

            if(a1 ==-1)
                printf("-");

            else if(a1 == 1){

                 if(flag == 1)
                    printf("+");
            }
            printf("x^3");
        }


        else if(flag ==1)
                printf("%+.1fx^3",a1);

        else
            printf("%.1fx^3",a1);

        flag = 1;

    }


    if(a2!=0){

        if(a2 == 1 || a2 ==-1){

            if(a2 ==-1)
                printf("-");

            else if(a2 == 1){

                 if(flag == 1)
                    printf("+");
            }
            printf("x^2");
        }


        else if(flag ==1)
                printf("%+.1fx^2",a2);

        else
            printf("%.1fx^2",a2);

        flag = 1;
    }

    if(a3!=0){

         if(a3 == 1 || a3 ==-1){
            if(a3 ==-1)
                printf("-");

            else if(a3 == 1){

                 if(flag == 1)
                    printf("+");
            }

            printf("x");
            }

        else if(flag ==1)
                printf("%+.1fx",a3);

        else
            printf("%.1fx",a3);

        flag = 1;

    }
    if(a4!=0){

        if(flag ==1)
            printf("%+.1f",a4);
        else
            printf("%.1f",a4);
    }
    printf("\n");
}
