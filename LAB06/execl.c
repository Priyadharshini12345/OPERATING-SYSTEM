#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        char* binaryPath="/bin/ls";                                                                                                                                     
        char* arg1="-a";                                                                                                                                                
        char* arg2="-s";                                                                                                                                                
        execl(binaryPath,arg1,arg2,NULL);                                                                                                                               
        return 0;                                                                                                                                                       
}    