#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
#include<dirent.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        struct dirent* direntp;                                                                                                                                         
        DIR* dp;                                                                                                                                                        
        dp=opendir("lab01");                                                                                                                                            
        if(dp==NULL)                                                                                                                                                    
                printf("Can't open the directory\n");                                                                                                                   
        char* ptr;                                                                                                                                                      
        for(;;){                                                                                                                                                        
                direntp=readdir(dp);                                                                                                                                    
                if(direntp==NULL)                                                                                                                                       
                        break;                                                                                                                                          
                else{                                                                                                                                                   
                        ptr=direntp->d_name;                                                                                                                            
                        if((ptr[0]=='E' && ptr[1]=='X') || (ptr[0]=='e' && ptr[1]=='x'))                                                                                
                                printf("%s\n",ptr);                                                                                                                     
                }                                                                                                                                                       
        }                                                                                                                                                               
        closedir(dp);                                                                                                                                                   
        return 0;                                                                                                                                                       
                                                                                                                                                                        
}                      