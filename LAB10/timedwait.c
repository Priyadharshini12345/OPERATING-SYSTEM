#include<stdio.h>                                                                                                                                                       
#include<semaphore.h>                                                                                                                                                   
#include<time.h>                                                                                                                                                        
int main(){                                                                                                                                                             
        sem_t sem;                                                                                                                                                      
        sem_init(&sem,0,0);                                                                                                                                             
        struct timespec tm;                                                                                                                                             
        int i=0;                                                                                                                                                        
        do{                                                                                                                                                             
                clock_gettime(CLOCK_REALTIME,&tm);                                                                                                                      
                tm.tv_sec+=1;                                                                                                                                           
                i++;                                                                                                                                                    
                printf("i=%d\n",i);                                                                                                                                     
                if(i==10)                                                                                                                                               
                        sem_post(&sem);                                                                                                                                 
        }while(sem_timedwait(&sem,&tm)==-1);                                                                                                                            
        printf("Semaphore acquired after %d timeouts\n",i);                                                                                                             
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
        