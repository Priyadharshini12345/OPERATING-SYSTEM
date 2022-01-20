#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<string.h>                                                                                                                                                      
#define BUFFER_SIZE 255                                                                                                                                                 
int main(){                                                                                                                                                             
        char write1msg[BUFFER_SIZE];                                                                                                                                    
        char write2msg[BUFFER_SIZE];                                                                                                                                    
        char readmsg[BUFFER_SIZE];                                                                                                                                      
        int readLength;                                                                                                                                                 
        int mypipe1[2],mypipe2[2];                                                                                                                                      
        int returnVal1,returnVal2;                                                                                                                                      
        returnVal1=pipe(mypipe1);                                                                                                                                       
        if(returnVal1==-1)                                                                                                                                              
                printf("Error in creating pipe 1\n");                                                                                                                   
        returnVal2=pipe(mypipe2);                                                                                                                                       
        if(returnVal2==-1)                                                                                                                                              
                printf("Error in creating pipe 2\n");                                                                                                                   
        int pid=fork();                                                                                                                                                 
        if(pid<0)                                                                                                                                                       
                printf("Error in forking\n");                                                                                                                           
        else if(pid==0){                                                                                                                                                
                close(mypipe1[1]);                                                                                                                                      
                close(mypipe2[0]);                                                                                                                                      
                printf("Enter the message to be sent to pipe 2\n");                                                                                                     
                scanf("%[^\n]s",write2msg);                                                                                                                             
                write(mypipe2[1],write2msg,strlen(write2msg));                                                                                                          
                close(mypipe2[1]);                                                                                                                                      
                readLength=read(mypipe1[0],readmsg,BUFFER_SIZE);                                                                                                        
                readmsg[readLength]='\0';                                                                                                                               
                printf("Received from pipe1:%s\n",readmsg);                                                                                                             
                close(mypipe1[0]);                                                                                                                                      
        }                                                                                                                                                               
        else{                                                                                                                                                           
                close(mypipe1[0]);                                                                                                                                      
                close(mypipe2[1]);                                                                                                                                      
                printf("Enter the message to be sent to pipe 1\n");                                                                                                     
                scanf("%[^\n]s",write1msg);                                                                                                                             
                write(mypipe1[1],write1msg,strlen(write1msg));                                                                                                          
                close(mypipe1[1]);                                                                                                                                      
                readLength=read(mypipe2[0],readmsg,BUFFER_SIZE);                                                                                                        
                readmsg[readLength]='\0';                                                                                                                               
                printf("Received from Pipe2:%s\n",readmsg);                                                                                                             
                close(mypipe2[0]);                                                                                                                                      
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
                                                                                                                                                                        
                 