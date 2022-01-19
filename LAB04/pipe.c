#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<stdlib.h>                                                                                                                                                      
void main(){                                                                                                                                                            
        char buf[30];                                                                                                                                                   
        char* msg1="Hello World #1";                                                                                                                                    
        char* msg2="Hello World #2";                                                                                                                                    
        char* msg3="Hello World #3";                                                                                                                                    
        int p[2],i;                                                                                                                                                     
        if(pipe(p)<0)                                                                                                                                                   
                exit(1);                                                                                                                                                
        write(p[1],msg1,30);                                                                                                                                            
        write(p[1],msg2,30);                                                                                                                                            
        write(p[1],msg3,30);                                                                                                                                            
        for(i=0;i<3;i++){                                                                                                                                               
                read(p[0],buf,30);                                                                                                                                      
                printf("%s\n",buf);                                                                                                                                     
        }                                                                                                                                                               
}                            