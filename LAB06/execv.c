#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        char* args[]={"./fork2",NULL};                                                                                                                                  
        printf("I am in execv.c \n");                                                                                                                                   
        execv(args[0],args);                                                                                                                                            
        printf("This will not be printed\n");                                                                                                                           
        return 0;                                                                                                                                                       
}       