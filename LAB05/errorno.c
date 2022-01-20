#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<errno.h>                                                                                                                                                       
#include<string.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        int err;                                                                                                                                                        
        if(close(-1)==-1){                                                                                                                                              
                err=errno;                                                                                                                                              
                printf("The error generated is %d\n",err);                                                                                                              
                printf("Error description:%s\n",strerror(err));                                                                                                         
        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}      