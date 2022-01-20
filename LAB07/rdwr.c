#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<stdlib.h>                                                                                                                                                      
#include<string.h>                                                                                                                                                      
#define BUFFER_SIZE 255                                                                                                                                                 
int main(){                                                                                                                                                             
        int mypipe[2];                                                                                                                                                  
        char readbuffer[BUFFER_SIZE];                                                                                                                                   
        char writebuffer[BUFFER_SIZE];                                                                                                                                  
        if(pipe(mypipe)<0){                                                                                                                                             
                printf("Error in creating pipe\n");                                                                                                                     
                exit(1);                                                                                                                                                
        }                                                                                                                                                               
        printf("Enter the content to write to the pipe\n");                                                                                                             
        scanf("%[^\n]s",writebuffer);                                                                                                                                   
        printf("Writing to the pipe\n");                                                                                                                                
        write(mypipe[1],writebuffer,strlen(writebuffer));                                                                                                               
        int readLength=read(mypipe[0],readbuffer,BUFFER_SIZE);                                                                                                          
        readbuffer[readLength]='\0';                                                                                                                                    
        printf("%s\n",readbuffer);                                                                                                                                      
        close(mypipe[0]);                                                                                                                                               
        close(mypipe[1]);                                                                                                                                               
        return 0;                                                                                                                                                       
}                     