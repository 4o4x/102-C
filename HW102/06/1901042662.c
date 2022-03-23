#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3



typedef enum{
    up=0,right=1,left=2,down=3
}towards;



void swap_vaules(int (*arr)[N],int x1,int y1,int x2, int y2);
//void random_array(int (*arr)[N]);
void fill_array(int (*arr)[N]);
void print_array(int (*arr)[N]);
int move_puzzle(int (*arr)[N],towards move,int start_x,int start_y);

int check_puzzle(int (*arr)[N]);


int main(){
    towards move;
    int start_x,start_y;          /*   x --> rows    y --> column   */
    
    int puzzle[N][N];
    
    srand(time(NULL));
    
    fill_array(puzzle);

    long long int count=0;
    long long int min=0;
    
    //for(int x =0 ;x<1000;x++){

    count = 0;
    
    for(int k=0;k<10000;k++){
        move_puzzle(puzzle,rand()%(N+1),rand()%N,rand()%N);
        //print_array(puzzle);
        //printf("\n\n");
    }

    //print_array(puzzle);
    //printf("\n\n");


    //random_array(puzzle);

    while(!check_puzzle(puzzle)){ 
        //printf("\n\033[2J");
        //printf("\n\033[1;1H");
        //print_array(puzzle);

        //printf("\n\n\n");
        
        /*printf("\nEnter row: ");
        scanf(" %d",&start_x);
        printf("\nEnter column: ");
        scanf(" %d",&start_y);

        printf("\n\nUp = 0 , Right = 1, Left = 2, Down = 3 \nEnter direction:");
        scanf(" %d",&move);*/
        
        //printf("%d\n",rand());printf("%d\n",rand());
        
        if(move_puzzle(puzzle,rand()%(N+1),rand()%N,rand()%N));{
            printf("1\n");print_array(puzzle); printf("\n\n\n");}
        count++;
    }

    
    //min += count;
    

    //}
    //printf("\n");
    //print_array(puzzle);

    printf("\n-%lld-\n",count);
    
    printf("\n\n-------------You Won-------------\n\n");

}





void fill_array(int (*arr)[N]){   /* Fills array from 0 to N^2 */
    
    int i,j,counter=1;
    
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            arr[i][j]=counter++;
        }
    }

    arr[N-1][N-1]=0;
}




void random_array(int (*arr)[N]){  /*swaps each element in the array with a random element in the array*/

    int i,j,x1,y1;
    arr[N][N];
    
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            
            x1 = rand()%N;
            y1 = rand()%N;

            swap_vaules(arr,x1,y1,i,j);

        }
    }

}


void swap_vaules(int (*arr)[N],int x1,int y1,int x2, int y2){      /*swaps the elements in the array*/
    
    int temp;

    arr[x1][y1];
	
	temp = arr[x1][y1];
    arr[x1][y1] = arr[x2][y2];
    arr[x2][y2] = temp;

}

void print_array(int (*arr)[N]){ /*prints puzzle */
    
    int i,j,k;

    for(i=0;i<N;i++){
        
        for(k=0;k<(5*N);k++){
            printf("*");
        }
        printf("*\n");
        
        for(j=0;j<N;j++){
            
            if(arr[i][j]==0)              /* prints 0 as a space */
                printf("*    ");
            
            else printf("* %2d ",arr[i][j]);
        }
        printf("*\n");
    }
    for(k=0;k<(5*N)+1;k++){
            printf("*");
        }
        
}

int check_puzzle(int (*arr)[N]){  /* checks if puzzle has been solved*/
   
    int i,j,counter=1;

    
    
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            
            if(arr[i][j] != counter){
                
                if(i==N-1 && j == N-1) /*the last element has not be N*N */
                    return 1;

                else 
                    return 0;}
            
            counter++;
        }
    }
    return 1;
}

int move_puzzle(int (*arr)[N],towards move,int start_x,int start_y){

    int i,j;
    int flag = 0;

    switch(move){

        case right:

            for(i=start_y;i<N;i++){
            
                if(arr[start_x][i] == 0){
                    flag = 1;
                    for(j=i;j>start_y;j--){
                        swap_vaules(arr,start_x,j,start_x,j-1);
                    
                    }
                    
                    break;
                }
            
            }

            if(flag ==0) return 0;
            else return 1;

            break;
        

        case left:
            
            for(i=start_y;i>=0;i--){
            
                if(arr[start_x][i] == 0){
                    flag = 1;
                    for(j=i;j<start_y;j++){
                        swap_vaules(arr,start_x,j,start_x,j+1);
                    
                    }
                    break;
                }
            
            }

            if(flag ==0) return 0;
            else return 1;

            

        case up:
            
            for(i=start_x;i>=0;i--){
            
                if(arr[i][start_y] == 0){
                    flag = 1;
                    for(j=i;j<start_x;j++){
                        swap_vaules(arr,j,start_y,j+1,start_y);
                    
                    }
                    break;
                }
            
            }
            if(flag ==0) return 0;
            else return 1;
            break;
        
        case down:
             for(i=start_x;i<N;i++){
            
                if(arr[i][start_y] == 0){
                    flag = 1;
                    for(j=i;j>start_x;j--){
                        swap_vaules(arr,j,start_y,j-1,start_y);
                    
                    }
                    break;
                }
            
            }

            if(flag == 0) return 0;
            else return 1;
            break;

    }

        
}