#include<unistd.h>                                                                                                                                                      
#include<stdio.h>                                                                                                                                                       
#include<string.h>                                                                                                                                                      
#include<stdlib.h>                                                                                                                                                      
#include<wait.h>                                                                                                                                                        
#define BUFFER_SIZE 255                                                                                                                                                 
int main(){                                                                                                                                                             
        char readbuffer[BUFFER_SIZE],writebuffer[BUFFER_SIZE];                                                                                                          
        int readLength,returnVal;                                                                                                                                       
        int mypipe[2];                                                                                                                                                  
        if(pipe(mypipe)<0){                                                                                                                                             
                printf("Error in creating pipe\n");                                                                                                                     
                exit(1);                                                                                                                                                
        }                                                                                                                                                               
        if((returnVal=fork())<0){                                                                                                                                       
                printf("Error in forking\n");                                                                                                                           
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        else if(returnVal==0){                                                                                                                                          
                close(mypipe[1]);                                                                                                                                       
                readLength=read(mypipe[0],readbuffer,BUFFER_SIZE);                                                                                                      
                readbuffer[readLength]='\0';                                                                                                                            
                printf("Received:%s\n",readbuffer);                                                                                                                     
                close(mypipe[0]);                                                                                                                                       
        }                                                                                                                                                               
        else{                                                                                                                                                           
                close(mypipe[0]);                                                                                                                                       
                printf("Enter the content to enter into the write end of the pipe\n");                                                                                  
                scanf("%[^\n]s",writebuffer);                                                                                                                           
                write(mypipe[1],writebuffer,strlen(writebuffer));                                                                                                       
                printf("Sent:%s\n",writebuffer);                                                                                                                        
                close(mypipe[1]);                                                                                                                                       
                waitpid(returnVal,NULL,0);                                                                                                                              
                printf("Parent Process Exiting\n");                                                                                                                     
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                             