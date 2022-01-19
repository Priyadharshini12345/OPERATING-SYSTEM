#include<stdio.h>                                                                                                                                                       
#include<time.h>                                                                                                                                                        
void main(){                                                                                                                                                            
        time_t st,end;                                                                                                                                                  
        st=time(NULL);                                                                                                                                                  
        int n;                                                                                                                                                          
        for(int i=0;i<100000;i++){                                                                                                                                      
                n=n*i;                                                                                                                                                  
        }                                                                                                                                                               
        end=time(NULL);                                                                                                                                                 
        printf("Amount of time used by the program snippet is %ld seconds\n",difftime(st,end));                                                                         
}                     