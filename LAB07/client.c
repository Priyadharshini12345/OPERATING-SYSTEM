#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<fcntl.h>                                                                                                                                                       
#include<sys/stat.h>                                                                                                                                                    
#include<sys/types.h>                                                                                                                                                   
#include<string.h>                                                                                                                                                      
#include<stdlib.h>                                                                                                                                                      
#define FIFO_FILE "MYFIFOFILE"                                                                                                                                          
int main(){                                                                                                                                                             
        int fd;                                                                                                                                                         
        char end[10];                                                                                                                                                   
        char str[100];                                                                                                                                                  
        fd=open(FIFO_FILE,O_WRONLY);                                                                                                                                    
        if(fd<0){                                                                                                                                                       
                printf("Error in opening FIFO file\n");                                                                                                                 
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        strcpy(end,"end");                                                                                                                                              
        while(1){                                                                                                                                                       
                printf("Enter string:\n");                                                                                                                              
                fgets(str,100,stdin);                                                                                                                                   
                int stringlen=strlen(str);                                                                                                                              
                str[stringlen-1]='\0';                                                                                                                                  
                int to_end=strcmp(str,end);                                                                                                                             
                if(to_end!=0){                                                                                                                                          
                write(fd,str,strlen(str));                                                                                                                              
                printf("Sent string:%s and length is %d\n",str,strlen(str));                                                                                            
                }                                                                                                                                                       
                else if(to_end==0){                                                                                                                                     
                        close(fd);                                                                                                                                      
                        break;                                                                                                                                          
                }                                                                                                                                                       
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
