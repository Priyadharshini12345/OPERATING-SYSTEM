#include<sys/stat.h>                                                                                                                                                    
#include<sys/types.h>                                                                                                                                                   
#include<stdio.h>                                                                                                                                                       
void main(){                                                                                                                                                            
        if(mkdir("Lab05",0777)==-1)                                                                                                                                     
                printf("Error");                                                                                                                                        
        else                                                                                                                                                            
                printf("Directory created successfully!\n");                                                                                                            
}  