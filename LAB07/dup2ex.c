#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<string.h>                                                                                                                                                      
#include<errno.h>                                                                                                                                                       
#include<sys/wait.h>                                                                                                                                                    
#include<stdlib.h>                                                                                                                                                      
char* process=NULL;                                                                                                                                                     
void read_from_fd(int fd){                                                                                                                                              
        char c;                                                                                                                                                         
        printf("Process %s reading from descriptor %d\n",process,fd);                                                                                                   
        while((read(fd,&c,1))!=0)                                                                                                                                       
                printf("%c",c);                                                                                                                                         
}                                                                                                                                                                       
int main(){                                                                                                                                                             
        process="PARENT";                                                                                                                                               
        int fd[2];                                                                                                                                                      
        if(pipe(fd)<0){                                                                                                                                                 
                printf("Error in creating pipe\n");                                                                                                                     
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        int pid=fork();                                                                                                                                                 
        if(pid<0){                                                                                                                                                      
                printf("Error in forking:%s\n",strerror(errno));                                                                                                        
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        else if(pid==0){                                                                                                                                                
                process="CHILD";                                                                                                                                        
                close(fd[1]);                                                                                                                                           
                dup2(fd[0],0);                                                                                                                                          
                close(fd[0]);                                                                                                                                           
                read_from_fd(0);                                                                                                                                        
        }                                                                                                                                                               
        else{                                                                                                                                                           
                const char* data="Hello All";                                                                                                                           
                dup2(fd[1],1);                                                                                                                                          
                close(fd[0]);                                                                                                                                           
                close(fd[1]);                                                                                                                                           
                write(1,data,strlen(data));                                                                                                                             
                close(1);                                                                                                                                               
                waitpid(pid,0,0);                                                                                                                                       
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                              