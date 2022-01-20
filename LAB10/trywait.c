#include<stdio.h>                                                                                                                                                       
#include<semaphore.h>                                                                                                                                                   
#include<errno.h>                                                                                                                                                       
int main(){                                                                                                                                                             
        sem_t sem;                                                                                                                                                      
        int val,rc;                                                                                                                                                     
        sem_init(&sem,0,1);                                                                                                                                             
        sem_getvalue(&sem,&val);                                                                                                                                        
        printf("Initial value of the semaphore is %d\n",val);                                                                                                           
        sem_wait(&sem);                                                                                                                                                 
        sem_getvalue(&sem,&val);                                                                                                                                        
        printf("The value of the semaphore after the wait is %d\n",val);                                                                                                
        rc=sem_trywait(&sem);                                                                                                                                           
        if(rc==-1)                                                                                                                                                      
                printf("sem_trywait could not decrement the semaphore value\n");                                                                                        
        return 0;                                                                                                                                                       
}          