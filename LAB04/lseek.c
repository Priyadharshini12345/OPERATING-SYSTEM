#include<stdio.h>                                                                                                                                                       
#include<sys/types.h>                                                                                                                                                   
#include<unistd.h>                                                                                                                                                      
#include<fcntl.h>                                                                                                                                                       
void main(){                                                                                                                                                            
        int fd;                                                                                                                                                         
        char buff[100];                                                                                                                                                 
        fd=open("Sample.txt",O_RDWR);                                                                                                                                   
        if(fd==-1)                                                                                                                                                      
                printf("Error in opening the file\n");                                                                                                                  
        read(fd,buff,20);                                                                                                                                               
        write(1,buff,20);                                                                                                                                               
        lseek(fd,5,SEEK_CUR);                                                                                                                                           
        read(fd,buff,20);                                                                                                                                               
        write(1,buff,20);                                                                                                                                               
}                                                                                                                                                                       
                