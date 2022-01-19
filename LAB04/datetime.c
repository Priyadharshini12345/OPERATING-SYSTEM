#include<stdio.h>                                                                                                                                                       
#include<time.h>                                                                                                                                                        
void main(){                                                                                                                                                            
        struct tm str_t;                                                                                                                                                
        time_t timeofday;                                                                                                                                               
        str_t.tm_year=2021-1900;                                                                                                                                        
        str_t.tm_mon=02;                                                                                                                                                
        str_t.tm_mday=10;                                                                                                                                               
        str_t.tm_hour=12;                                                                                                                                               
        str_t.tm_min=31;                                                                                                                                                
        str_t.tm_sec=56;                                                                                                                                                
        timeofday=mktime(&str_t);                                                                                                                                       
        time_t curtime;                                                                                                                                                 
        curtime=time(NULL);                                                                                                                                             
        struct tm* localtimeans;                                                                                                                                        
        localtimeans=localtime(&curtime);                                                                                                                               
        printf("The current date and time is %s",asctime(localtimeans));                                                                                                
        printf("The date and time after 2 days from now will be:\n");                                                                                                   
        printf(ctime(&timeofday));                                                                                                                                      
}                                   