#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        char* binaryPath="ls";                                                                                                                                          
        char* arg1="-a";                                                                                                                                                
        char* arg2="-s";                                                                                                                                                
        execlp(binaryPath,arg1,arg2,NULL);                                                                                                                              
        return 0;                                                                                                                                                       
}     