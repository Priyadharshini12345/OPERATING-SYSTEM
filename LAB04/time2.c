#include<stdio.h>                                                                                                                                                       
#include<time.h>                                                                                                                                                        
#define LEN 150                                                                                                                                                         
char buf[LEN];                                                                                                                                                          
void main(){                                                                                                                                                            
struct tm* localtimeans;                                                                                                                                                
time_t curtime;                                                                                                                                                         
curtime=time(NULL);                                                                                                                                                     
localtimeans=localtime(&curtime);                                                                                                                                       
printf("%s\n",asctime(localtimeans));                                                                                                                                   
strftime(buf,LEN,"Today is %A,%b,%d\n",localtimeans);                                                                                                                   
fputs(buf,stdout);                                                                                                                                                      
strftime(buf,LEN,"Time is %I:%M:%P\n",localtimeans);                                                                                                                    
fputs(buf,stdout);                                                                                                                                                      
}                     