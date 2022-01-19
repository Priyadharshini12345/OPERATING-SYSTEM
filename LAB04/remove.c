#include<stdio.h>                                                                                                                                                       
#include<fcntl.h>                                                                                                                                                       
int unlink(const char* pathname);                                                                                                                                       
void main(){                                                                                                                                                            
        if(unlink("newfile.txt")==0){                                                                                                                                   
                printf("File deleted successfully\n");                                                                                                                  
        }                                                                                                                                                               
        else                                                                                                                                                            
                printf("Error occured\n");                                                                                                                              
}      