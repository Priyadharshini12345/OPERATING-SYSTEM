#include<stdio.h>                                                                                                                                                       
#include<fcntl.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
int close(int fd);                                                                                                                                                      
size_t read(int fd,void* buf,size_t cnt);                                                                                                                               
void main(){                                                                                                                                                            
        int fd,s;                                                                                                                                                       
        char* c=(char*) malloc(100*sizeof(char));                                                                                                                       
        fd=open("newfile.txt",O_RDONLY);                                                                                                                                
        if(fd<0){                                                                                                                                                       
                printf("Error in opening the file\n");                                                                                                                  
        }                                                                                                                                                               
        s=read(fd,c,100);                                                                                                                                               
        printf("%d bytes read from %d",s,fd);                                                                                                                           
        printf("Read bytes:%s",c);                                                                                                                                      
        close(fd);                                                                                                                                                      
}               