#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
#include<fcntl.h>                                                                                                                                                       
#include<string.h>                                                                                                                                                      
#include<sys/stat.h>                                                                                                                                                    
#include<sys/types.h>                                                                                                                                                   
#define FIFO_FILE "OSSPOT"                                                                                                                                              
int main(){                                                                                                                                                             
        int fd;                                                                                                                                                         
        int mypipe[2];                                                                                                                                                  
        char readbuf[1024];                                                                                                                                             
        fd=open(FIFO_FILE,O_RDONLY);                                                                                                                                    
        char str1[1024];                                                                                                                                                
        if(pipe(mypipe)<0){                                                                                                                                             
                printf("Error in creating pipe\n");                                                                                                                     
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        int pid=fork();                                                                                                                                                 
        if(pid<0){                                                                                                                                                      
                printf("Error in forking\n");                                                                                                                           
                exit(1);                                                                                                                                                
        }                                                                                                                                                               
        else if(pid>0){                                                                                                                                                 
        while(1){                                                                                                                                                       
                if((read(fd,str1,1024))==0)                                                                                                                             
                        break;                                                                                                                                          
                system("sort -k 1,5 \"/home/s2019103562/lab07/OSSPOT\"");                                                                                               
        //      printf("%s\n",str1);                                                                                                                                    
                write(mypipe[1],str1,strlen(str1));                                                                                                                     
        }                                                                                                                                                               
        }                                                                                                                                                               
        else{                                                                                                                                                           
                int readLength=read(mypipe[0],readbuf,sizeof(readbuf));                                                                                                 
                readbuf[readLength-1]='\0';                                                                                                                             
                char c;                                                                                                                                                 
                int i=0;                                                                                                                                                
                while(i<readLength){                                                                                                                                    
                        if(readbuf[i]=='R'){                                                                                                                            
                                do{                                                                                                                                     
                                printf("%c",readbuf[i]);                                                                                                                
                                i++;                                                                                                                                    
                        }while(readbuf[i]!='\n');                                                                                                                       
                        }                                                                                                                                               
                        i++;                                                                                                                                            
                                                                                                                                                                        
                }                                                                                                                                                       
                printf("\n");                                                                                                                                           
                int j=0;                                                                                                                                                
                while(j<readLength){                                                                                                                                    
                        if(readbuf[j]=='M' && readbuf[j+1]=='a' && readbuf[j+2]=='r'){                                                                                  
                                do{                                                                                                                                     
                                        printf("%c",readbuf[j]);                                                                                                        
                                        j++;                                                                                                                            
                                }while(readbuf[j]!='\n');                                                                                                               
                        }                                                                                                                                               
                                j++;                                                                                                                                    
                }                                                                                                                                                       
                                                                                                                                                                        
                                                                                                                                                                        
        }                                                                                                                                                               
                                                                                                                                                                        
        close(fd);  