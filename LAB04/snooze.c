#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<signal.h>                                                                                                                                                      
void sig_handler(int signum){                                                                                                                                           
        if(signum==SIGALRM){                                                                                                                                            
                printf("Inside handler function\n");                                                                                                                    
                alarm(2);                                                                                                                                               
        }                                                                                                                                                               
        if(signum==SIGINT){                                                                                                                                             
                printf("Snoozing for 5 seconds..\n");                                                                                                                   
                alarm(5);                                                                                                                                               
        }                                                                                                                                                               
}                                                                                                                                                                       
void main(){                                                                                                                                                            
        signal(SIGALRM,sig_handler);                                                                                                                                    
        signal(SIGINT,sig_handler);                                                                                                                                     
        alarm(2);                                                                                                                                                       
        for(int i=1;i<=5;i++){                                                                                                                                          
                printf("Inside main function\n");                                                                                                                       
                pause();                                                                                                                                                
        }                                                                                                                                                               
}                  