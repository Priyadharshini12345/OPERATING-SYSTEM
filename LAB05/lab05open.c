#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<dirent.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
void main(){                                                                                                                                                            
        DIR* dp;                                                                                                                                                        
        int i=1;                                                                                                                                                        
        struct dirent* ptr;                                                                                                                                             
        dp=opendir("lab01/inner");                                                                                                                                      
        if(dp==NULL)                                                                                                                                                    
                printf("can't open the directory\n");                                                                                                                   
        else{                                                                                                                                                           
                printf("Listing the files of subdirectory\n");                                                                                                          
                while((ptr=readdir(dp))!=NULL){                                                                                                                         
                        printf("File:%d is %s\n",i++,ptr->d_name);                                                                                                      
                }                                                                                                                                                       
        }                                                                                                                                                               
        closedir(dp);                                                                                                                                                   
}            