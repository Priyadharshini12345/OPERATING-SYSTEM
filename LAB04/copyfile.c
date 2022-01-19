#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
#include<fcntl.h>                                                                                                                                                       
int close(int fd);                                                                                                                                                      
void main(int argc,char* argv[]){                                                                                                                                       
        int fd1,fd2;                                                                                                                                                    
        char buf[1000];                                                                                                                                                 
        long int n;                                                                                                                                                     
        if(((fd1=open(argv[1],O_RDONLY))==-1) || ((fd2=open(argv[2],O_CREAT | O_WRONLY | O_TRUNC,0700))==-1)){                                                          
                printf("Error\n");                                                                                                                                      
        }                                                                                                                                                               
        while((n=read(fd1,buf,1000))>0){                                                                                                                                
                if(write(fd2,buf,n)!=n){                                                                                                                                
                        printf("Writing problem");                                                                                                                      
                }                                                                                                                                                       
        }                                                                                                                                                               
        close(fd1);                                                                                                                                                     
        close(fd2);                                                                                                                                                     
}            