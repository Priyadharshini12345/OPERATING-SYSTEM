#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<dirent.h>                                                                                                                                                      
void main(){                                                                                                                                                            
        struct dirent* direntp;                                                                                                                                         
        DIR* dp;                                                                                                                                                        
        int i=1;                                                                                                                                                        
        dp=opendir("lab01");                                                                                                                                            
        if(dp==NULL)                                                                                                                                                    
                printf("Can't open the directory\n");                                                                                                                   
        else{                                                                                                                                                           
                for(;;){                                                                                                                                                
                        direntp=readdir(dp);                                                                                                                            
                        if(direntp==NULL)                                                                                                                               
                                break;                                                                                                                                  
                        printf("File %d:%s\n",i++,direntp->d_name);                                                                                                     
                }                                                                                                                                                       
        }                                                                                                                                                               
        closedir(dp);                                                                                                                                                   
}          