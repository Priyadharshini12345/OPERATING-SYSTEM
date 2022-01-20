#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<dirent.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                   
#include<sys/stat.h>                                                                                                                                                    
int main(){                                                                                                                                                             
        DIR* dp;                                                                                                                                                        
        struct dirent* direntp;                                                                                                                                         
        int file;                                                                                                                                                       
        int i=1,j=1;                                                                                                                                                    
        dp=opendir("lab01");                                                                                                                                            
        if(dp==NULL){                                                                                                                                                   
                printf("Error in opening the file\n");                                                                                                                  
                return 0;                                                                                                                                               
        }                                                                                                                                                               
        else{                                                                                                                                                           
                printf("Old directory listing\n");                                                                                                                      
                while((direntp=readdir(dp))!=NULL){                                                                                                                     
                        printf("File %d:%s\n",i++,direntp->d_name);                                                                                                     
                }                                                                                                                                                       
        }                                                                                                                                                               
        file=creat("lab01/NewFile.c",S_IRUSR | S_IWUSR | S_IXUSR);                                                                                                      
        close(file);                                                                                                                                                    
        rewinddir(dp);                                                                                                                                                  
        printf("New directory listing\n");                                                                                                                              
        while((direntp=readdir(dp))!=NULL){                                                                                                                             
                printf("File %d:%s\n",j++,direntp->d_name);                                                                                                             
        }                                                                                                                                                               
        closedir(dp);                                                                                                                                                   
}              