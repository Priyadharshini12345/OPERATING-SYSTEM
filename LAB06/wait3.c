#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<stdlib.h>                                                                                                                                                      
#include<sys/wait.h>                                                                                                                                                    
void waitex(){                                                                                                                                                          
        int i,stat;                                                                                                                                                     
        pid_t pid[5];                                                                                                                                                   
        for(i=0;i<5;i++){                                                                                                                                               
                if((pid[i]=fork())==0){                                                                                                                                 
                        sleep(1);                                                                                                                                       
                        exit(100+i);                                                                                                                                    
                }                                                                                                                                                       
        }                                                                                                                                                               
        for(i=0;i<5;i++){                                                                                                                                               
                pid_t cpid=waitpid(pid[i],&stat,0);                                                                                                                     
                if(WIFEXITED(stat))                                                                                                                                     
                        printf("Child %d terminated with status:%d\n",WEXITSTATUS(stat));                                                                               
        }                                                                                                                                                               
}                                                                                                                                                                       
int main(){                                                                                                                                                             
        waitex();                                                                                                                                                       
        return 0;                                                                                                                                                       
}              