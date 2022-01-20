#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<unistd.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        char* args[]={"./fork",NULL};                                                                                                                                   
        execvp(args[0],args);                                                                                                                                           
        return 0;                                                                                                                                                       
}    