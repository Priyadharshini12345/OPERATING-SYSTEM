#include<unistd.h>                                                                                                                                                      
#include<stdlib.h>                                                                                                                                                      
#include<stdio.h>                                                                                                                                                       
#include<time.h>                                                                                                                                                        
int child(){                                                                                                                                                            
        char* program="ls";                                                                                                                                             
        char* args[]={program,"-lh","./",NULL};                                                                                                                         
        execvp(program,args);                                                                                                                                           
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
int parent(){                                                                                                                                                           
        time_t t=time(NULL);                                                                                                                                            
        struct tm tm=*localtime(&t);                                                                                                                                    
        printf("Today's date is %d-%d-%d\n",tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);                                                                                    
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
int main(){                                                                                                                                                             
//      pid_t pid=fork();                                                                                                                                               
        if(fork()==0){                                                                                                                                                  
                printf("Child Pid:%d\n",getpid());                                                                                                                      
                child();                                                                                                                                                
                exit(0);                                                                                                                                                

        }                                                                                                                                                               
        else if(fork()>0){                                                                                                                                              
                printf("Parent process PID:%d\n",getpid());                                                                                                             
                parent();                                                                                                                                               
        }                                                                                                                                                               
        else{                                                                                                                                                           
                printf("Error in fork() process\n");                                                                                                                    
                exit(0);                                                                                                                                                
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                 