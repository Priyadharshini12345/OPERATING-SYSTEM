#define _GNU_SOURCE                                                                                                                                                     
#include<sched.h>                                                                                                                                                       
#include<signal.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
#include<stdlib.h>                                                                                                                                                      
#include<stdio.h>                                                                                                                                                       
#define STACK 1000                                                                                                                                                      
int do_something(){                                                                                                                                                     
        printf("Child pid:%d\n",getpid());                                                                                                                              
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
int main(){                                                                                                                                                             
        void* stack=malloc(STACK);                                                                                                                                      
        if(!stack){                                                                                                                                                     
                perror("Malloc failed\n");                                                                                                                              
                exit(0);                                                                                                                                                
        }                                                                                                                                                               
        if(clone(&do_something,(char*)stack+STACK,CLONE_VM,0)<0){                                                                                                       
                perror("Clone failed\n");                                                                                                                               
                exit(0);                                                                                                                                                
        }                                                                                                                                                               
        printf("Parent id:%d\n",getpid());                                                                                                                              
        do_something();                                                                                                                                                 
        free(stack);                                                                                                                                                    
        return 0;                                                                                                                                                       
}                        