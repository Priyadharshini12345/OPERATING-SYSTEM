#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<signal.h>                                                                                                                                                      
void sig_handler(int signum){                                                                                                                                           
        printf("Inside handler function\n");                                                                                                                            
}                                                                                                                                                                       
void main(){                                                                                                                                                            
        signal(SIGALRM,sig_handler);                                                                                                                                    
        alarm(2);                                                                                                                                                       
        for(int i=1;i<=5;i++){                                                                                                                                          
                printf("Inside main function\n");                                                                                                                       
                sleep(1);                                                                                                                                               
        }                                                                                                                                                               
}      