#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<sys/wait.h>                                                                                                                                                    
#include<unistd.h>                                                                                                                                                      
void waitex(){                                                                                                                                                          
        int stat;                                                                                                                                                       
        if(fork()==0)                                                                                                                                                   
                exit(0);                                                                                                                                                
        else                                                                                                                                                            
                wait(&stat);                                                                                                                                            
        if(WIFEXITED(stat))                                                                                                                                             
                printf("Exit status:%d\n",WEXITSTATUS(stat));                                                                                                           
        else if(WIFSIGNALED(stat))                                                                                                                                      
                psignal(WTERMSIG(stat),"Exit signal");                                                                                                                  
}                                                                                                                                                                       
int main(){                                                                                                                                                             
        waitex();                                                                                                                                                       
        return 0;                                                                                                                                                       
}             