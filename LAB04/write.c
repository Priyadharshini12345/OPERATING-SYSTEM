#include<stdio.h>                                                                                                                                                       
#include<fcntl.h>                                                                                                                                                       
#include<string.h>                                                                                                                                                      
int close(int fd);                                                                                                                                                      
size_t write(int fd,void* buf,size_t cnt);                                                                                                                              
void main(){                                                                                                                                                            
        int s;                                                                                                                                                          
        int fd=open("newfile.txt",O_WRONLY | O_CREAT | O_TRUNC,0644);                                                                                                   
        if(fd<0){                                                                                                                                                       
                printf("error in opening\n");                                                                                                                           
        }                                                                                                                                                               
        s=write(fd, "Hello All\n",strlen("Hello All\n"));                                                                                                               
        printf("%d bytes were written in %d",s,fd);                                                                                                                     
        close(fd);                                                                                                                                                      
}                                    