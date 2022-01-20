#define _GNU_SOURCE                                                                                                                                                     
#include<sched.h>                                                                                                                                                       
#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<stdlib.h>                                                                                                                                                      
#include<signal.h>                                                                                                                                                      
#include<sys/wait.h>                                                                                                                                                    
int fn(void* arg){                                                                                                                                                      
        int i;                                                                                                                                                          
        printf("This part of code is running under child process\n");                                                                                                   
        int n=atoi(arg);                                                                                                                                                
        for(i=1;i<=10;i++)                                                                                                                                              
                printf("%d * %d = %d\n",n,i,(n*i));                                                                                                                     
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
                                                                                                                                                                        
int main(int argc,char* argv[]){                                                                                                                                        
        void* child_stack=malloc(1024 * 1024);                                                                                                                          
        if(child_stack == NULL){                                                                                                                                        
                printf("Unable to allocate memory. Malloc failed\n");                                                                                                   
                exit(0);                                                                                                                                                
        }                                                                                                                                                               

        printf("Using clone()\n");                                                                                                                                      
        int pid=clone(fn,child_stack+(1024*1024),SIGCHLD,argv[1]);                                                                                                      
        if(pid<0){                                                                                                                                                      
                printf("Error in clone process\n");                                                                                                                     
                exit(0);                                                                                                                                                
        }                                                                                                                                                               
        printf("Child Process:%d\n",getpid());                                                                                                                          
        wait(NULL);                                                                                                                                                     
        free(child_stack);                                                                                                                                              
        printf("INFO:Child process has been terminated\n");                                                                                                             
        printf("Using fork()\n");                                                                                                                                       
        if(fork()==0)                                                                                                                                                   
                printf("Child process:%d\n",getpid());                                                                                                                  
        else                                                                                                                                                            
                printf("Parent process:%d\n",getpid());                                                                                                                 
        return 0;                                                                                                                                                       
}                                   