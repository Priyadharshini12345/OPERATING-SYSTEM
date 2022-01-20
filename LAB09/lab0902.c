#include<stdio.h>                                                                                                                                                       
#include<sys/shm.h>                                                                                                                                                     
#include<stdlib.h>                                                                                                                                                      
#include<string.h>                                                                                                                                                      
#include<errno.h>                                                                                                                                                       
int main(){                                                                                                                                                             
        void* shared_memory;                                                                                                                                            
        char buff[100];                                                                                                                                                 
        int shmid;                                                                                                                                                      
        shmid=shmget((key_t)2345,1024,0666);                                                                                                                            
        if(shmid<0){                                                                                                                                                    
                perror("Error in main:shmid\n");                                                                                                                        
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        printf("Key of shared memory:%d\n",shmid);                                                                                                                      
        shared_memory=shmat(shmid,NULL,0);                                                                                                                              
        if(!shared_memory){                                                                                                                                             
                perror("Error in main:shmat\n");                                                                                                                        
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        printf("Process attached at %p address\n",shared_memory);                                                                                                       
        printf("Data read from memory:%s\n",(char*)shared_memory);                                                                                                      
        if(shmdt(shared_memory)==-1){                                                                                                                                   
                perror("Error in main:shmdt\n");                                                                                                                        
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                    