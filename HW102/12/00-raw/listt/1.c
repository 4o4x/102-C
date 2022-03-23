#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){
    char str[5000];
    int i,flag,j=0;
    
    FILE *fpr,*fpw;
    
    fpr = fopen("deneme.txt","rt");
    fpw = fopen("a.txt","wt");

    for(j=0;j<32000;j++){
        
        flag = 0;
        fscanf(fpr,"%s",str);

        for(i=0;i<strlen(str);i++){
                        
            if(str[i]== ','){
                flag = 1;
                str[i] = ' ';
            }
            
        }
        printf("Loading..%.2lf\r",((double)j/10000)*100);
        if(flag){
            fprintf(fpw,"%s\n",str);
        }

    }

    fclose(fpr);
    fclose(fpw);
    

}