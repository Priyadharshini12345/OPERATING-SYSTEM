#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<stdlib.h>                                                                                                                                                      
#include<fcntl.h>                                                                                                                                                       
#include<sys/wait.h>                                                                                                                                                    
#include<string.h>                                                                                                                                                      
#include<errno.h>                                                                                                                                                       
char* process=NULL;                                                                                                                                                     
void read_from_fd(int fd){                                                                                                                                              
        char c;                                                                                                                                                         
        while((read(fd,&c,1))!=0){                                                                                                                                      
                printf("Process %s reading from descriptor %d character %c\n",process,fd,c);                                                                            
                sleep(1);                                                                                                                                               
        }                                                                                                                                                               
}                                                                                                                                                                       
int main(){                                                                                                                                                             
        process="PARENT";                                                                                                                                               
        int read_fd=open("./file1",O_RDONLY);                                                                                                                           
        char c;                                                                                                                                                         
        read(read_fd,&c,1);                                                                                                                                             
        printf("Process %s reading from descriptor %d character %c\n",process,read_fd,c);                                                                               
        printf("Forking a new child process\n");                                                                                                                        
        int pid=fork();                                                                                                                                                 
        if(pid<0){                                                                                                                                                      
                printf("Error in forking\n");                                                                                                                           
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        else if(pid==0){                                                                                                                                                
                process="CHILD";                                                                                                                                        
                read_from_fd(read_fd);                                                                                                                                  
                exit(1);                                                                                                                                                
        }                                                                                                                                                               
        else{                                                                                                                                                           
                read_from_fd(read_fd);                                                                                                                                  
                waitpid(pid,0,0);                                                                                                                                       
                exit(1);                                                                                                                                                
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                      