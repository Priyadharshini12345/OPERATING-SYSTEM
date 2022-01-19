#include<stdio.h>                                                                                                                                                       
#include<fcntl.h>                                                                                                                                                       
int close(int fd);                                                                                                                                                      
void main(){                                                                                                                                                            
        int fd=open("newfile.txt",O_RDONLY);                                                                                                                            
        if(fd<0){                                                                                                                                                       
                printf("Error in opening the file\n");                                                                                                                  
        }                                                                                                                                                               
        printf("opened at %d",fd);                                                                                                                                      
        if(close(fd)<0){                                                                                                                                                
                printf("Closing unsuccessful\n");                                                                                                                       
        }                                                                                                                                                               
        else if(close(fd)>0)                                                                                                                                            
                printf("Closed successfully!");                                                                                                                         
}                              