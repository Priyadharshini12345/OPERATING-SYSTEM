#include<stdio.h>                                                                                                                                                       
#include<semaphore.h>                                                                                                                                                   
#include<pthread.h>                                                                                                                                                     
#define BUFFERSIZE 6                                                                                                                                                    
sem_t empty,full,mutex;                                                                                                                                                 
void producer(int a){                                                                                                                                                   
        sem_wait(&empty);                                                                                                                                               
        sem_wait(&mutex);                                                                                                                                               
        printf("Produced an item %d\n",a);                                                                                                                              
        sem_post(&full);                                                                                                                                                
        sem_post(&mutex);                                                                                                                                               
}                                                                                                                                                                       
int main(){                                                                                                                                                             
        int em,fu,mu;                                                                                                                                                   
        sem_init(&mutex,0,1);                                                                                                                                           
        sem_init(&empty,0,BUFFERSIZE);                                                                                                                                  
        sem_init(&full,0,0);                                                                                                                                            
        char ch;                                                                                                                                                        
        int a=1;                                                                                                                                                        
        do{                                                                                                                                                             
                sem_getvalue(&mutex,&mu);                                                                                                                               
                sem_getvalue(&empty,&em);                                                                                                                               
                sem_getvalue(&full,&fu);                                                                                                                                
                if(mu==1 && em!=0){                                                                                                                                     
                        producer(a);                                                                                                                                    
                        printf("Do you want to continue:y/n\n");                                                                                                        
                        scanf("%s",&ch);                                                                                                                                
                        a++;                                                                                                                                            
                }                                                                                                                                                       
                else{                                                                                                                                                   
                        printf("BUFFER IS FULL\n");                                                                                                                     
                        break;                                                                                                                                          
                }                                                                                                                                                       
        }while(ch!='n');                                                                                                                                                
        return 0;                                                                                                                                                       
}                        