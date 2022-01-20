#include<stdio.h>                                                                                                                                                       
#include<sys/ipc.h>                                                                                                                                                     
#include<sys/shm.h>                                                                                                                                                     
#include<stdlib.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
#include<string.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        key_t key;                                                                                                                                                      
        char* path="/home";                                                                                                                                             
        int id='a';                                                                                                                                                     
        char ch;                                                                                                                                                        
        if((key=(ftok(path,id)))==(key_t) -1){                                                                                                                          
                printf("Error\n");                                                                                                                                      
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        int shmid=shmget(key,1024,0666|IPC_CREAT);                                                                                                                      
        void* shared_memory;                                                                                                                                            
        shared_memory=(int*)shmat(shmid,(void*)0,0);                                                                                                                    
        if(!shared_memory){                                                                                                                                             
                printf("Error:main:shmat\n");                                                                                                                           
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        int res;                                                                                                                                                        
        printf("Address:%p\n",shared_memory);                                                                                                                           
        printf("Key:%d\n",key);                                                                                                                                         
        while(1){                                                                                                                                                       
                printf("Are you willing to remove an item from the shared memory\n");                                                                                   
                scanf("%s",&ch);                                                                                                                                        
                (int*)shared_memory--;                                                                                                                                  
                res=(int*)shared_memory;                                                                                                                                
                if(ch=='n' || res<0)                                                                                                                                    
                        break;                                                                                                                                          
        //      (int*)shared_memory--;                                                                                                                                  
                printf("Items in the shared memory after consumption:%d\n",(int*)shared_memory);                                                                        
        }                                                                                                                                                               
        shmdt(shared_memory);                                                                                                                                           
        return 0;                                                                                                                                                       
}                      