#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<string.h>                                                                                                                                                      
#include<errno.h>                                                                                                                                                       
#include<sys/wait.h>                                                                                                                                                    
#include<stdlib.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        int fd[2];                                                                                                                                                      
        if(pipe(fd)<0){                                                                                                                                                 
                printf("Error in creating pipe\n");                                                                                                                     
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        int pid=fork();                                                                                                                                                 
        if(pid<0){                                                                                                                                                      
                printf("Error in forking\n");                                                                                                                           
                exit(1);                                                                                                                                                
        }                                                                                                                                                               
        else if(pid==0){                                                                                                                                                
                dup2(fd[0],0);                                                                                                                                          
                close(fd[1]);                                                                                                                                           
                close(fd[0]);                                                                                                                                           
                execlp("wc","wc","-c",(char*)NULL);                                                                                                                     
        }                                                                                                                                                               
        else{                                                                                                                                                           
                dup2(fd[1],1);                                                                                                                                          
                close(fd[0]);                                                                                                                                           
                close(fd[1]);                                                                                                                                           
                execlp("ls","ls","./",(char*)NULL);                                                                                                                     
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                         