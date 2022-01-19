#include<sys/types.h>                                                                                                                                                   
#include<sys/stat.h>                                                                                                                                                    
#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
void main(){                                                                                                                                                            
        char s[100];                                                                                                                                                    
        printf("%s\n",getcwd(s,100));                                                                                                                                   
        chdir("..");                                                                                                                                                    
        printf("%s\n",getcwd(s,100));                                                                                                                                   
}        