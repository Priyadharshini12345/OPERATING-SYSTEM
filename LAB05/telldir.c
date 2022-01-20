#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<dirent.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                   
#include<unistd.h>                                                                                                                                                      
void main(){                                                                                                                                                            
        DIR* dp;                                                                                                                                                        
        struct dirent* ptr;                                                                                                                                             
        int offset;                                                                                                                                                     
        dp=opendir("lab03");                                                                                                                                            
        if(dp==NULL)                                                                                                                                                    
                printf("Can't open the directory\n");                                                                                                                   
        else{                                                                                                                                                           
                while((ptr=readdir(dp))!=NULL){                                                                                                                         
                        offset=telldir(dp);                                                                                                                             
                        printf("File %d:%s\n",offset,ptr->d_name);                                                                                                      
                }                                                                                                                                                       
        }                                                                                                                                                               
        closedir(dp);                                                                                                                                                   
}                   