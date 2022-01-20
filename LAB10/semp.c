#include <pthread.h>                                                                                                                                                    
#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<semaphore.h>                                                                                                                                                   
sem_t sem1 ;                                                                                                                                                            
void * threadFunc(void *arg){                                                                                                                                           
        sem_wait(&sem1);                                                                                                                                                
        int j;                                                                                                                                                          
        printf("New thread started\n");                                                                                                                                 
        for (j = 1; ; j++)                                                                                                                                              
        {                                                                                                                                                               
                printf("Loop %d\n", j);                                                                                                                                 
                sleep(1);                                                                                                                                               
                pthread_testcancel();                                                                                                                                   
        }                                                                                                                                                               
        return NULL;                                                                                                                                                    
                                                                                                                                                                        
}                                                                                                                                                                       
int main(int argc, char *argv[]){                                                                                                                                       
        pthread_t thr;                                                                                                                                                  
        int s;                                                                                                                                                          
        void *res;                                                                                                                                                      
        int val;                                                                                                                                                        
        if(sem_init(&sem1,0,0)==-1)                                                                                                                                     
                perror("SEMAPHORE1 open");                                                                                                                              
        if( sem_getvalue(&sem1, &val) == -1 ){                                                                                                                          
                perror("Could not get value of named semaphore. Error:");                                                                                               
        }                                                                                                                                                               
        printf("Semaphore value before wait : %d \n", val );                                                                                                            
        s = pthread_create(&thr, NULL, threadFunc, NULL);                                                                                                               
        if (s != 0)                                                                                                                                                     
                printf("ERROR:pthread_create\n");                                                                                                                       
        int i=1;                                                                                                                                                        
        while(i<=5){                                                                                                                                                    
                printf("main %d\n",i);                                                                                                                                  
                sleep(1);                                                                                                                                               
                i++;                                                                                                                                                    
        }                                                                                                                                                               
        sem_post(&sem1);                                                                                                                                                
        printf("Now main sleeps for 15 secs then cancel\n");                                                                                                            
        sleep(9); /* Allow new thread to run a while */                                                                                                                 
        printf("AFTER main Sleep\n");                                                                                                                                   
        s = pthread_cancel(thr);                                                                                                                                        
        if (s != 0)                                                                                                                                                     
                printf("ERROR:pthread_cancel\n");                                                                                                                       
        s = pthread_join(thr, &res);                                                                                                                                    
        if (s != 0)                                                                                                                                                     
                printf("ERROR:-pthread_join");                                                                                                                          
        if (res == PTHREAD_CANCELED)                                                                                                                                    
                printf("Thread was canceled\n");                                                                                                                        
        else                                                                                                                                                            
                printf("Thread was not canceled (should not happen!)\n");                                                                                               
        return 0;                                                                                                                                                       

        }                