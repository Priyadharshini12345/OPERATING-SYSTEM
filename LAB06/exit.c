#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        pid_t p=fork();                                                                                                                                                 
        if(getpid()==0)                                                                                                                                                 
                printf("Child Process\n");                                                                                                                              
        else                                                                                                                                                            
                exit(0);                                                                                                                                                
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
         