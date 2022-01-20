#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<dirent.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                   
int main(int argc,char* argv[]){                                                                                                                                        
        DIR* d;                                                                                                                                                         
        struct dirent de, *dep;                                                                                                                                         
        char* mydir;                                                                                                                                                    
        int i;                                                                                                                                                          
        if(argc==1)                                                                                                                                                     
                mydir=".";                                                                                                                                              
        else                                                                                                                                                            
                mydir=argv[1];                                                                                                                                          
        d=opendir(mydir);                                                                                                                                               
        if(d==NULL)                                                                                                                                                     
                printf("Can't open the directory\n");                                                                                                                   
        i=1;                                                                                                                                                            
        while(readdir_r(d,&de,&dep)==0 && dep!=NULL){                                                                                                                   
                printf("Directory entry is %d:%s\n",i++,de.d_name);                                                                                                     
        }                                                                                                                                                               
        closedir(d);                                                                                                                                                    
        return 0;                                                                                                                                                       
}          