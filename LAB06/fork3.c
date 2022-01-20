#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                   
#define MAXCOUNT 10                                                                                                                                                     
void childProcess(){                                                                                                                                                    
        int i;                                                                                                                                                          
        for(i=1;i<=MAXCOUNT;i++)                                                                                                                                        
                printf("This line is from child %d\n",i);                                                                                                               
                printf("****Child Process is done****\n");                                                                                                              
}                                                                                                                                                                       
void ParentProcess(){                                                                                                                                                   
        int i;                                                                                                                                                          
        for(i=1;i<=MAXCOUNT;i++)                                                                                                                                        
                printf("This line is from Parent %d\n",i);                                                                                                              
        printf("****Parent process is done****\n");                                                                                                                     
}                                                                                                                                                                       
                                                                                                                                                                        
int main(){                                                                                                                                                             
        pid_t p;                                                                                                                                                        
        p=fork();                                                                                                                                                       
        if(p==0)                                                                                                                                                        
                childProcess();                                                                                                                                         
        else                                                                                                                                                            
                ParentProcess();                                                                                                                                        
        return 0;                                                                                                                                                       
}                              