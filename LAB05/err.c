#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<errno.h>                                                                                                                                                       
#include<string.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
#include<dirent.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        DIR* dp;                                                                                                                                                        
        dp=opendir("lab06");                                                                                                                                            
        if(dp==NULL){                                                                                                                                                   
                printf("The error generated: %d\n",errno);                                                                                                              
                printf("The description of the error: %s\n",strerror(errno));                                                                                           
                perror("Error message printed by perror: ");                                                                                                            
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        else{                                                                                                                                                           
                closedir(dp);                                                                                                                                           
                exit(EXIT_SUCCESS);                                                                                                                                     
                printf("Successfully closed!");                                                                                                                         
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                  