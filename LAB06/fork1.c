#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                   
int main(){                                                                                                                                                             
        pid_t p=fork();                                                                                                                                                 
        fork();                                                                                                                                                         
        printf("My id is %d:",getpid());                                                                                                                                
        if(getpid()>0)                                                                                                                                                  
                printf("I am the parent\n");                                                                                                                            
        else if(getpid()==0)                                                                                                                                            
                printf("I am the child\n");                                                                                                                             
        else                                                                                                                                                            
                printf("Error\n");                                                                                                                                      
        return 0;                                                                                                                                                       
}         