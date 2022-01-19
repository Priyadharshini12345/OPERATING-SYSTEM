#include<stdio.h>                                                                                                                                                       
#include<fcntl.h>                                                                                                                                                       
void main(){                                                                                                                                                            
        int fd=open("newfile.txt",O_RDONLY | O_CREAT);                                                                                                                  
        printf("%d",fd);                                                                                                                                                
        if(fd!=-1){                                                                                                                                                     
                printf("Successfully opened!\n");                                                                                                                       
        }                                                                                                                                                               
        if(fd==-1){                                                                                                                                                     
                printf("Error in opening the file\n");                                                                                                                  
        }                                                                                                                                                               
}         