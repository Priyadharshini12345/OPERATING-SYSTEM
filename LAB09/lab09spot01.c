#include<stdio.h>                                                                                                                                                       
#include<sys/ipc.h>                                                                                                                                                     
#include<sys/shm.h>                                                                                                                                                     
#include<stdlib.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
#include<errno.h>                                                                                                                                                       
#include<string.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        key_t key;                                                                                                                                                      
        char* path="/home";                                                                                                                                             
        int id='a';                                                                                                                                                     
        char ch;                                                                                                                                                        
        int max;                                                                                                                                                        
        if((key=(ftok(path,id)))==(key_t) -1){                                                                                                                          
                perror("Error\n");                                                                                                                                      
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        int shmid=shmget(key,1024,0666|IPC_CREAT);                                                                                                                      
        int* shared_memory;                                                                                                                                             
        shared_memory=(int*)shmat(shmid,(void*)0,0);                                                                                                                    
        if(!shared_memory){                                                                                                                                             
                perror("Error:shmat\n");                                                                                                                                
                exit(EXIT_FAILURE);                                                                                                                                     
        }                                                                                                                                                               
        printf("Address:%p\n",shared_memory);                                                                                                                           
        printf("Key:%d\n",key);                                                                                                                                         
        printf("Enter the maximum size\n");                                                                                                                             
        scanf("%d",&max);                                                                                                                                               
        shared_memory=0;                                                                                                                                                
        int res;                                                                                                                                                        
        while(1){                                                                                                                                                       
        printf("Are you willing to add an item\n");                                                                                                                     
        scanf("%s",&ch);                                                                                                                                                
        (*shared_memory)++;                                                                                                                                             
        res=(*shared_memory);                                                                                                                                           
        if(ch=='n'|| res>max)                                                                                                                                           
                break;                                                                                                                                                  
        printf("Items in shared memory:%d\n",(*shared_memory));                                                                                                         
        }                                                                                                                                                               
        //shared_memory=shmat(shmid,NULL,0);                                                                                                                            
        shmdt(shared_memory);                                                                                                                                           
        return 0;                                                                                                                                                       
}                