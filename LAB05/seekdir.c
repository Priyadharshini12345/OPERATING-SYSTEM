#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                   
#include<dirent.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
void main(){                                                                                                                                                            
        struct dirent* ptr;                                                                                                                                             
        int offset,offset_5,i=0;                                                                                                                                        
        DIR* dir;                                                                                                                                                       
        dir=opendir("lab02");                                                                                                                                           
        if(dir==NULL)                                                                                                                                                   
                printf("Can't open the directory\n");                                                                                                                   
        else{                                                                                                                                                           
                while((ptr=readdir(dir))!=NULL){                                                                                                                        
                        offset=telldir(dir);                                                                                                                            
                        if(++i==5)                                                                                                                                      
                                offset_5=offset;                                                                                                                        
                        printf("File name:%s, Offset:%d\n",ptr->d_name,offset);                                                                                         
                }                                                                                                                                                       
                seekdir(dir,offset_5);                                                                                                                                  
                printf("Reading the dircectory again with the offset of 5,that is skipping the first 5 filenames\n");                                                   
                while((ptr=readdir(dir))!=NULL){                                                                                                                        
                        offset=telldir(dir);                                                                                                                            
                        printf("File name:%s, Offset:%d\n",ptr->d_name,offset);                                                                                         
                }                                                                                                                                                       
        }                                                                                                                                                               
                closedir(dir);                                                                                                                                          
}                      