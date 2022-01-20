#include<stdio.h>                                                                                                                                                       
#include<semaphore.h>                                                                                                                                                   
#define BUFFERSIZE 6                                                                                                                                                    
sem_t empty,full,mutex;                                                                                                                                                 
void consumer(int a){                                                                                                                                                   
        sem_wait(&full);                                                                                                                                                
        sem_wait(&mutex);                                                                                                                                               
        printf("Consumed an item %d\n",a);                                                                                                                              
        sem_post(&empty);                                                                                                                                               
        sem_post(&mutex);                                                                                                                                               
}                                                                                                                                                                       
int main(){                                                                                                                                                             
        int mu,empt,fu;                                                                                                                                                 
        char ch;                                                                                                                                                        
        int a=BUFFERSIZE;                                                                                                                                               
        sem_init(&mutex,0,1);                                                                                                                                           
        sem_init(&full,0,BUFFERSIZE);                                                                                                                                   
        sem_init(&empty,0,0);                                                                                                                                           
        do{                                                                                                                                                             
                sem_getvalue(&empty,&empt);                                                                                                                             
                sem_getvalue(&full,&fu);                                                                                                                                
                sem_getvalue(&mutex,&mu);                                                                                                                               
                if(mu==1 && fu!=0){                                                                                                                                     
                        consumer(a);                                                                                                                                    
                        a--;                                                                                                                                            
                }                                                                                                                                                       
                else{                                                                                                                                                   
                        printf("BUFFER IS EMPTY\n");                                                                                                                    
                        break;                                                                                                                                          
                }                                                                                                                                                       
                printf("Enter y to continue and n to exit\n");                                                                                                          
                scanf("%s",&ch);                                                                                                                                        
        }while(ch!='n');                                                                                                                                                
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
                                                                                                                                                                        
                                                                                                                                                                        
                   