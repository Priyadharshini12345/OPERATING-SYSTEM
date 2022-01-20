#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<dirent.h>                                                                                                                                                      
#define D_GETFLAG 1                                                                                                                                                     
#define D_SETFLAG 2                                                                                                                                                     
#define D_FLAG_FILTER 0x00000001                                                                                                                                        
#define D_FLAG_STAT 0x00000002                                                                                                                                          
int dircntl(DIR* dir,int cmd, ...);                                                                                                                                     
int main(int argc,char* argv[]){                                                                                                                                        
        DIR* dp;                                                                                                                                                        
        int ret;                                                                                                                                                        
        dp=opendir("lab02");                                                                                                                                            
        if(dp==NULL)                                                                                                                                                    
                printf("Can't open the directory\n");                                                                                                                   
        else{                                                                                                                                                           
                if((ret=dircntl(dp,D_GETFLAG))==-1){                                                                                                                    
                        printf("Error occured\n");                                                                                                                      
                        return 0;                                                                                                                                       
                }                                                                                                                                                       
                if(ret & D_FLAG_FILTER)                                                                                                                                 
                        printf("Directory names are filtered\n");                                                                                                       
                else                                                                                                                                                    
                        printf("Directory names are not filtered\n");                                                                                                   
                if(ret & D_FLAG_STAT)                                                                                                                                   
                        printf("Servers are asked for extra stat information\n");                                                                                       
                else                                                                                                                                                    
                        printf("Servers are not asked for extra stat information\n");                                                                                   
        }                                                                                                                                                               
        closedir(dp);                                                                                                                                                   
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
                  