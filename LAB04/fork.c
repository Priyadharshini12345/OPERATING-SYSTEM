#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                   
#include<unistd.h>                                                                                                                                                      
void main(){                                                                                                                                                            
        pid_t p=fork();                                                                                                                                                 
        fork();                                                                                                                                                         
        printf("My id is %d:\n",getpid());                                                                                                                              
        if(getpid()>0)                                                                                                                                                  
                printf("I am the parent\n");                                                                                                                            
        else if(getpid()==0)                                                                                                                                            
                printf("I am the child\n");                                                                                                                             
        else                                                                                                                                                            
                printf("Error\n");                                                                                                                                      
        if(p>0){                                                                                                                                                        
                fork();                                                                                                                                                 
                printf("Hello\n");                                                                                                                                      
        }                                                                                                                                                               
        printf("Outside\n");                                                                                                                                            
}                        