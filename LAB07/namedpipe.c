#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
#include<string.h>                                                                                                                                                      
#include<errno.h>                                                                                                                                                       
#include<fcntl.h>                                                                                                                                                       
#include<sys/stat.h>                                                                                                                                                    
#include<sys/types.h>                                                                                                                                                   
#define FIFO_FILE "MYFIFOFILE"                                                                                                                                          
int main(){                                                                                                                                                             
        int fd;                                                                                                                                                         
        fd=open(FIFO_FILE,O_CREAT|O_WRONLY);                                                                                                                            
        char arr1[80],arr2[80];                                                                                                                                         
        char end[10];                                                                                                                                                   
        strcpy(end,"end");                                                                                                                                              
        int to_end;                                                                                                                                                     
        if(fd<0)                                                                                                                                                        
                printf("Error\n");                                                                                                                                      
        while(1){                                                                                                                                                       
                printf("Enter string\n");                                                                                                                               
                fgets(arr1,80,stdin);                                                                                                                                   
                int stringlen=strlen(arr1);                                                                                                                             
                arr1[stringlen]='\0';                                                                                                                                   
                to_end=strcmp(arr1,end);                                                                                                                                
                printf("%d\n",to_end);                                                                                                                                  
                if(to_end!=0){                                                                                                                                          
                        write(fd,arr1,strlen(arr1));                                                                                                                    
                        printf("Sent string:%s and length is %d\n",arr1,strlen(arr1));                                                                                  
                }                                                                                                                                                       
                else if(to_end==0){                                                                                                                                     
                        write(fd,arr1,strlen(arr1));                                                                                                                    
                        printf("Sent string:%s and length is %d\n",arr1,strlen(arr1));                                                                                  
                        close(fd);                                                                                                                                      
                        break;                                                                                                                                          
                }                                                                                                                                                       
        }                                                                                                                                                               
        int fd1=open(FIFO_FILE,O_RDONLY);                                                                                                                               
        if(fd1<0){                                                                                                                                                      
                printf("Error:%s",strerror(errno));                                                                                                                     
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        while(1){                                                                                                                                                       
        if(read(fd1,arr2,sizeof(arr2))==0)                                                                                                                              
                break;                                                                                                                                                  
        int readlength=strlen(arr2);                                                                                                                                    
        arr2[readlength]='\0';                                                                                                                                          
        printf("Received:%s\n",arr2);                                                                                                                                   
        }                                                                                                                                                               
        close(fd);                                                                                                                                                      
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
                     