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
        else{                                                                                                                                                           
        printf("Key generated:%d\n",key);                                                                                                                               
        int shmid=shmget(key,1024,0666|IPC_CREAT);                                                                                                                      
        void* shared_memory;                                                                                                                                            
        char buff[100];                                                                                                                                                 
        shared_memory=shmat(shmid,NULL,0);                                                                                                                              
        printf("Data read from memory:%s\n",(char*)shared_memory);                                                                                                      
        shmdt(shared_memory);                                                                                                                                           
        shmctl(shmid,IPC_RMID,NULL);                                                                                                                                    
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
}                             