#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<stdlib.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        int mypipe[2];                                                                                                                                                  
        if(pipe(mypipe)<0){                                                                                                                                             
                printf("Error in creating pipe\n");                                                                                                                     
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        printf("Descriptors are %d and %d\n",mypipe[0],mypipe[1]);                                                                                                      
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
                           