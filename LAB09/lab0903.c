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
        if((key=(ftok(path,id)))==(key_t) -1){                                                                                                                          
                printf("Error\n");                                                                                                                                      
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        printf("Key generated:%d\n",key);                                                                                                                               
        int shmid=shmget(key,1024,0666|IPC_CREAT);                                                                                                                      
        void* shared_memory;                                                                                                                                            
        shared_memory=shmat(shmid,NULL,0);                                                                                                                              
        if(!shared_memory){                                                                                                                                             
                perror("Error in main:shmat\n");                                                                                                                        
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        printf("Enter the data to write\n");                                                                                                                            
        read(0,(char*)shared_memory,100);                                                                                                                               
        printf("You wrote:%s\n",(char*)shared_memory);                                                                                                                  
        if(shmdt(shared_memory)==-1){                                                                                                                                   
                perror("Error in main:shmdt\n");                                                                                                                        
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                      