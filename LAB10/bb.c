#include<pthread.h>                                                                                                                                                     
#include<semaphore.h>                                                                                                                                                   
#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
#include<fcntl.h>                                                                                                                                                       
#define MAXITEMS 5                                                                                                                                                      
#define BUFFERSIZE 5                                                                                                                                                    
sem_t *empty;                                                                                                                                                           
sem_t *full;                                                                                                                                                            
int in=0;                                                                                                                                                               
int out=0;                                                                                                                                                              
int buffer[BUFFERSIZE];                                                                                                                                                 
pthread_mutex_t mutex;                                                                                                                                                  
void* producer(void* pno){                                                                                                                                              
        int item;                                                                                                                                                       
        for(int i=0;i<MAXITEMS;i++){                                                                                                                                    
                item=rand();                                                                                                                                            
                sem_wait(empty);                                                                                                                                        
                pthread_mutex_lock(&mutex);                                                                                                                             
                buffer[in]=item;                                                                                                                                        
                printf("Producer %d: Insert item %d at %d\n",(*(int*)pno),buffer[in],in);                                                                               
                in=(in+1)%BUFFERSIZE;                                                                                                                                   
                pthread_mutex_unlock(&mutex);                                                                                                                           
                sem_post(full);                                                                                                                                         
//              item++;                                                                                                                                                 
        }                                                                                                                                                               
}                                                                                                                                                                       
void* consumer(void* cno){                                                                                                                                              
        int item;                                                                                                                                                       
        for(int i=0;i<MAXITEMS;i++){                                                                                                                                    
                sem_wait(full);                                                                                                                                         
                pthread_mutex_lock(&mutex);                                                                                                                             
                item=buffer[out];                                                                                                                                       
                printf("Consumer %d: Remove item %d from %d\n",(*(int*)cno),item,out);                                                                                  
                out=(out+1)%BUFFERSIZE;                                                                                                                                 
                pthread_mutex_unlock(&mutex);                                                                                                                           
                sem_post(empty);                                                                                                                                        
        }                                                                                                                                                               
}                                                                                                                                                                       
int main(){                                                                                                                                                             
        pthread_t pro[5],con[5];                                                                                                                                        
        pthread_mutex_init(&mutex,NULL);                                                                                                                                
//      sem_init(&empty,0,BUFFERSIZE);                                                                                                                                  
//      sem_init(&full,0,0);                                                                                                                                            
        empty = sem_open("/mysem", O_CREAT, 0644, BUFFERSIZE);                                                                                                          
        full = sem_open("/mysemaphore", O_CREAT, 0644, 0);                                                                                                              
        int a[5]={1,2,3,4,5};                                                                                                                                           
        for(int i=0;i<5;i++){                                                                                                                                           
                pthread_create(&pro[i],NULL,(void*)producer,(void*)&a[i]);                                                                                              
        }                                                                                                                                                               
        for(int i=0;i<5;i++){                                                                                                                                           
                pthread_create(&con[i],NULL,(void*)consumer,(void*)&a[i]);                                                                                              
        }                                                                                                                                                               
        for(int i=0;i<5;i++){                                                                                                                                           
                pthread_join(pro[i],NULL);                                                                                                                              
        }                                                                                                                                                               
        for(int i=0;i<5;i++){                                                                                                                                           
                pthread_join(con[i],NULL);                                                                                                                              
        }                                                                                                                                                               
        pthread_mutex_destroy(&mutex);                                                                                                                                  
        sem_unlink("/mysem");                                                                                                                                           
        sem_unlink("/mysemaphore");                                                                                                                                     
        sem_close(empty);                                                                                                                                               
        sem_close(full);                                                                                                                                                
        return 0;
}                                                                                                                                                                       
                          