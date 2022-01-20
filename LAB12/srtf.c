#include<stdio.h>                                                                                                                                                       
int main(){                                                                                                                                                             
        int n,count=0,i,j,smallest,time;                                                                                                                                
        double avg=0,tt=0,end;                                                                                                                                          
        printf("Enter the number of processes:\t");                                                                                                                     
        scanf("%d",&n);                                                                                                                                                 
        int at[10],bt[10],x[10];                                                                                                                                        
        for(i=0;i<n;i++){                                                                                                                                               
                printf("Enter the arrival time for process %d:\t",i+1);                                                                                                 
                scanf("%d",&at[i]);                                                                                                                                     
                printf("\nEnter the burst time for process %d:\t",i+1);                                                                                                 
                scanf("%d",&bt[i]);                                                                                                                                     
        }                                                                                                                                                               
        printf("PROCESS\t\t ARRIVALTIME\t\t BURSTTIME\t\t WAITINGTIME\t\t TURNAROUNDTIME\n");                                                                           
        for(i=0;i<n;i++)                                                                                                                                                
                x[i]=bt[i];                                                                                                                                             
        bt[9]=9999;                                                                                                                                                     
        for(time=1;count!=n;time++){                                                                                                                                    
                smallest=9;                                                                                                                                             
                for(i=0;i<n;i++){                                                                                                                                       
                        if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0){                                                                                               
                                smallest=i;                                                                                                                             
                                bt[smallest]--;                                                                                                                         
                                if(bt[smallest]==0){                                                                                                                    
                                        count++;                                                                                                                        
                                        end=time+1;                                                                                                                     
                                        avg=avg+end-at[smallest]-x[smallest];                                                                                           
                                        tt=tt+end-at[smallest];                                                                                                         
                                }                                                                                                                                       
                        }                                                                                                                                               
                        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n",i+1,at[i],bt[i],avg,tt);                                                                              
                }                                                                                                                                                       
                                                                                                                                                                        
        }                                                                                                                                                               
                printf("\nAVERAGE WAIITNG TIME:\t%f",avg/n);                                                                                                            
                printf("\nAVERAGE TURNAROUND TIME:\t%f\n",tt/n);                                                                                                        
                return 0;                                                                                                                                               
        }                                                                                                                                                               
                                    