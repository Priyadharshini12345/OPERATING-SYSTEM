#include<stdio.h>                                                                                                                                                       
#include<time.h>                                                                                                                                                        
void main(){                                                                                                                                                            
        time_t mytime;                                                                                                                                                  
        mytime=time(NULL);                                                                                                                                              
        printf(ctime(&mytime));                                                                                                                                         
}     