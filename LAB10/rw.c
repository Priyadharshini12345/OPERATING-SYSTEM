#include<pthread.h>                                                                                                                                                     
#include<semaphore.h>                                                                                                                                                   
#include<stdio.h>                                                                                                                                                       
sem_t wrt;                                                                                                                                                              
pthread_mutex_t mutex;                                                                                                                                                  
int var=1;                                                                                                                                                              
int numreader=0;                                                                                                                                                        
void* writer(void* wno){                                                                                                                                                
        sem_wait(&wrt);                                                                                                                                                 
        var=var*2;                                                                                                                                                      
        printf("Writer %d modified var to %d\n",(*(int*)wno),var);                                                                                                      
        sem_post(&wrt);                                                                                                                                                 
}                                                                                                                                                                       
void* reader(void* rno){                                                                                                                                                
        pthread_mutex_lock(&mutex);                                                                                                                                     
        numreader++;                                                                                                                                                    
        if(numreader==1){                                                                                                                                               
                sem_wait(&wrt);                                                                                                                                         
        }                                                                                                                                                               
        pthread_mutex_unlock(&mutex);                                                                                                                                   
        printf("Reader %d read var as %d\n",(*(int*)rno),var);                                                                                                          
        pthread_mutex_lock(&mutex);                                                                                                                                     
        numreader--;                                                                                                                                                    
        if(numreader==0){                                                                                                                                               
                sem_post(&wrt);                                                                                                                                         
        }                                                                                                                                                               
        pthread_mutex_unlock(&mutex);                                                                                                                                   
}                                                                                                                                                                       
int main(){                                                                                                                                                             
        pthread_t write[5],read[10];                                                                                                                                    
        pthread_mutex_init(&mutex,NULL);                                                                                                                                
        sem_init(&wrt,0,1);                                                                                                                                             
        int a[10]={1,2,3,4,5,6,7,8,9,10};                                                                                                                               
        for(int i=0;i<10;i++){                                                                                                                                          
                pthread_create(&read[i],NULL,(void*)reader,(void*)&a[i]);                                                                                               
        }                                                                                                                                                               
        for(int i=0;i<5;i++){                                                                                                                                           
                pthread_create(&write[i],NULL,(void*)writer,(void*)&a[i]);                                                                                              
        }                                                                                                                                                               
        for(int i=0;i<10;i++)                                                                                                                                           
                pthread_join(read[i],NULL);                                                                                                                             
        for(int i=0;i<5;i++)                                                                                                                                            
                pthread_join(write[i],NULL);                                                                                                                            
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
               