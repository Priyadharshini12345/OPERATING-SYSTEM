#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<sys/stat.h>                                                                                                                                                    
#include<ftw.h>                                                                                                                                                         
int list(const char* name,const struct stat* status,int type){                                                                                                          
        if(type==FTW_NS){                                                                                                                                               
                printf("Error occcured\n");                                                                                                                             
                return 0;                                                                                                                                               
        }                                                                                                                                                               
        if(type==FTW_F)                                                                                                                                                 
                printf("The object is a file\n");                                                                                                                       
        if(type==FTW_D)                                                                                                                                                 
                printf("The object is a directory\n");                                                                                                                  
        if(type==FTW_DNR)                                                                                                                                               
                printf("The object is a directry that can't be read\n");                                                                                                
}                                                                                                                                                                       
int main(int argc,char* argv[]){                                                                                                                                        
        if(argc==1)                                                                                                                                                     
                ftw(".",list,1);                                                                                                                                        
        else                                                                                                                                                            
                ftw(argv[1],list,1);                                                                                                                                    
        return 0;                                                                                                                                                       
}                  