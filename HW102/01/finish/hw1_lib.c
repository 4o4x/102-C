/*
** hw4_lib.c:
**
** The source file implementing library functions.
**
** Author: Yakup Genc. (c) 2018-2021
**
** Revision: 2021.03.03.20.16
**
*/

#include <stdio.h>
#include "hw1_lib.h"

double f3(double a, double b, double c, double d,double x){

    return ((a*x+b)*x+c)*x+d;
}

double f4(double a, double b, double c, double d, double e, double x){

    return (((a*x+b)*x+c)*x+d)*x+e;
}

double inter(double x, double y, double fx, double fy){

    return (x*fy-y*fx)/(fy-fx); /*Linear interpolation formula*/
					                        
			
}



double integral3(double a0, double a1, double a2, double a3, double xs, double xe, double delta)
{
    double result=f3(a0,a1,a2,a3,xs);
    double i;
    for(i=xs+delta;i<=xe-delta;i=i+delta){
        result += 2*f3(a0,a1,a2,a3,i);		/*   Trapozodi rule > (delta * (x0+2x1+2x2+ ......+2xn-1+xn)/2)    */ 
    }
    result+=f3(a0,a1,a2,a3,i);

    return (delta*result)/2;
}


double integral4(double a0, double a1, double a2, double a3, double a4, double xs, double xe, double delta)
{
    double result=f4(a0,a1,a2,a3,a4,xs);
    double i;
    for(i=xs+delta;i<=xe-delta;i=i+delta){       
        result += 2*f4(a0,a1,a2,a3,a4,i);	/*     Trapozodi rule > (delta * (x0+2x1+2x2+ ......+2xn-1+xn)/2)    */ 
    }
    result+=f4(a0,a1,a2,a3,a4,xe);

    return (delta*result)/2;
}



double root3(double a0, double a1, double a2, double a3, double xs, double xe)
{
    double root;
	do{
        root = inter(xs,xe,f3(a0,a1,a2,a3,xs),f3(a0,a1,a2,a3,xe));
        if((f3(a0,a1,a2,a3,root)>0))
            xs=root;
        else
            xe =root;

	}while(!(f3(a0,a1,a2,a3,root)<0.0000000001 && f3(a0,a1,a2,a3,root)>-0.0000000001));
	return root;

}


double root4(double a0, double a1, double a2, double a3, double a4, double xs, double xe)
{
    double root;
	do{
        root = inter(xs,xe,f4(a0,a1,a2,a3,a4,xs),f4(a0,a1,a2,a3,a4,xe));
        if((f4(a0,a1,a2,a3,a4,root)>0))
            xs = root;
        else
            xe = root;

	}while(!(f4(a0,a1,a2,a3,a4,root)<0.0000000001 && f4(a0,a1,a2,a3,a4,root)>-0.000000000000001));
	return root;

}








