#include<sys/types.h>                                                                                                                                                   
#include<sys/stat.h>                                                                                                                                                    
#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<fcntl.h>                                                                                                                                                       
void main(){                                                                                                                                                            
        int fd=access("difftime.c",F_OK);                                                                                                                               
        if(fd==-1){                                                                                                                                                     
                printf("Error:File does not exists\n");                                                                                                                 
        }                                                                                                                                                               
        else{                                                                                                                                                           
                printf("File exists\n");                                                                                                                                
        }                                                                                                                                                               
        int fd1=access("difftime.c",R_OK);                                                                                                                              
        if(fd1==-1){                                                                                                                                                    
        printf("Error:File is not a readable one\n");                                                                                                                   
        }                                                                                                                                                               
        else                                                                                                                                                            
                printf("Readable file\n");                                                                                                                              
        int fd2=access("difftime.c",W_OK);                                                                                                                              
        if(fd2==-1)                                                                                                                                                     
        {                                                                                                                                                               
                printf("Error:File is not a writable file\n");                                                                                                          
        }                                                                                                                                                               
        else                                                                                                                                                            
                printf("Writable file\n");                                                                                                                              
        int fd3=access("difftime.c",X_OK);                                                                                                                              
        if(fd==-1){                                                                                                                                                     
                printf("Error:File is not an executable file\n");                                                                                                       
        }                                                                                                                                                               
        else                                                                                                                                                            
                printf("Executable file\n");                                                                                                                            
}                                                                                                                                                                       
              