#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        char* binaryPath="/bin/bash";                                                                                                                                   
        char* arg1="-c";                                                                                                                                                
        char* const env[]={"HOSTNAME=14.139.161.31","PORT=8080",NULL};                                                                                                  
        char* arg2="echo \"Visit $HOSTNAME:$PORT from your browser\"";                                                                                                  
//      char* const env[]={"HOSTNAME=14.139.161.31","PORT=8080",NULL};                                                                                                  
        execle(binaryPath,binaryPath,arg1,arg2,NULL);                                                                                                                   
        return 0;                                                                                                                                                       
}                