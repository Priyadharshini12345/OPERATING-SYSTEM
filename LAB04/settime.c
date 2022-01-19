#include<stdio.h>                                                                                                                                                       
#include<time.h>                                                                                                                                                        
void main(){                                                                                                                                                            
        struct tm str_t;                                                                                                                                                
        time_t timeofday;                                                                                                                                               
        str_t.tm_year=2021-1900;                                                                                                                                        
        str_t.tm_mon=02;                                                                                                                                                
        str_t.tm_mday=8;                                                                                                                                                
        str_t.tm_hour=11;                                                                                                                                               
        str_t.tm_min=10;                                                                                                                                                
        str_t.tm_sec=5;                                                                                                                                                 
        str_t.tm_isdst=0;                                                                                                                                               
        timeofday=mktime(&str_t);                                                                                                                                       
        printf("Date and time is:\n");                                                                                                                                  
        printf(ctime(&timeofday));                                                                                                                                      
}                           