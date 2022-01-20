#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                   
int main(){                                                                                                                                                             
        fork();                                                                                                                                                         
        fork();                                                                                                                                                         
        fork();                                                                                                                                                         
        printf("Hello World\n");                                                                                                                                        
        //calling fork n times executes the processes after the fork call 2^n times                                                                                     
        return 0;                                                                                                                                                       
}       