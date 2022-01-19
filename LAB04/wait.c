#include<stdio.h>                                                                                                                                                       
#include<time.h>                                                                                                                                                        
#define CLK_TICK 10                                                                                                                                                     
void wait(int sec){                                                                                                                                                     
        clock_t end_wait;                                                                                                                                               
        end_wait=clock()+sec*CLK_TICK;                                                                                                                                  
        while(clock()<end_wait){                                                                                                                                        
        }                                                                                                                                                               
}                                                                                                                                                                       
void main(){                                                                                                                                                            
        printf("Start the wait\n");                                                                                                                                     
        wait(10);                                                                                                                                                       
        printf("End the wait");                                                                                                                                         
}               