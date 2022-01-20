#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                   
#include<stdlib.h>                                                                                                                                                      
#include<string.h>                                                                                                                                                      
#include<memory.h>                                                                                                                                                      
#define BUFFER_SIZE 1000                                                                                                                                                
int main(){                                                                                                                                                             
        int ParentToChild[2];                                                                                                                                           
        int ChildToParent[2];                                                                                                                                           
        int pid;                                                                                                                                                        
        char* message2="Message from Parent to Child\n";                                                                                                                
        char* message1="Message from Child To Parent\n";                                                                                                                
        char readbuffer[BUFFER_SIZE];                                                                                                                                   
        if(pipe(ParentToChild)<0)                                                                                                                                       
                printf("Error in creating pipe\n");                                                                                                                     
        if(pipe(ChildToParent)<0)                                                                                                                                       
                printf("Error in creating pipe\n");                                                                                                                     
        if((pid=fork())<0){                                                                                                                                             
                printf("Error in forking\n");                                                                                                                           
                exit(1);                                                                                                                                                
        }                                                                                                                                                               
        else if(pid==0){                                                                                                                                                
                close(ParentToChild[1]);                                                                                                                                
                close(ChildToParent[0]);                                                                                                                                
                write(ChildToParent[1],message1,strlen(message1));                                                                                                      
                close(ChildToParent[1]);                                                                                                                                
                int readLength=read(ParentToChild[0],readbuffer,BUFFER_SIZE);                                                                                           
                readbuffer[readLength]='\0';                                                                                                                            
                printf("%s\n",readbuffer);                                                                                                                              
                close(ParentToChild[0]);                                                                                                                                
        }                                                                                                                                                               
        else{                                                                                                                                                           
                close(ParentToChild[0]);                                                                                                                                
                close(ChildToParent[1]);                                                                                                                                
                write(ParentToChild[1],message2,strlen(message2));                                                                                                      
                close(ParentToChild[1]);                                                                                                                                
                int readLength=read(ChildToParent[0],readbuffer,BUFFER_SIZE);                                                                                           
                readbuffer[readLength]='\0';                                                                                                                            
                printf("%s\n",readbuffer);                                                                                                                              
                close(ChildToParent[0]);                                                                                                                                
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
                      