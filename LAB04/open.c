#include<unistd.h>                                                                                                                                                      
#include<fcntl.h>                                                                                                                                                       
#include<sys/stat.h>                                                                                                                                                    
#include<sys/types.h>                                                                                                                                                   
#include<stdio.h>                                                                                                                                                       
void main()                                                                                                                                                             
{                                                                                                                                                                       
        int fd;                                                                                                                                                         
        fd=creat("newfile.txt",S_IRWXU);                                                                                                                                
        if(fd>0){                                                                                                                                                       
                printf("Created a new file\n");                                                                                                                         
        }                                                                                                                                                               
        else{                                                                                                                                                           
                printf("Unsuccessful\n");                                                                                                                               
        }                                                                                                                                                               
}         
