#include<stdio.h>                                                                                                                                                       
int main(){                                                                                                                                                             
        int i,n,sum=0,count=0,quant,wt=0,tat=0,y;                                                                                                                       
        float avg_wt,avg_tat;                                                                                                                                           
        printf("Enter the number of processes:\t");                                                                                                                     
        scanf("%d",&n);                                                                                                                                                 
        int at[n],bt[n],temp[n];                                                                                                                                        
        y=n;                                                                                                                                                            
        for(i=0;i<n;i++){                                                                                                                                               
                printf("\nEnter the arrival time for process %d:\t",i+1);                                                                                               
                scanf("%d",&at[i]);                                                                                                                                     
                printf("\nEnter the burst time for process %d:\t",i+1);                                                                                                 
                scanf("%d",&bt[i]);                                                                                                                                     
                temp[i]=bt[i];                                                                                                                                          
        }                                                                                                                                                               
        printf("\nEnter the time quantum for the process:\t");                                                                                                          
        scanf("%d",&quant);                                                                                                                                             
        printf("Process\t\t ArrivalTime\t\t BurstTime\t\t TAT\t\t Waiting time\n");                                                                                     
        for(sum=0,i=0;y!=0;){                                                                                                                                           
                if(temp[i]<=quant && temp[i]>0){                                                                                                                        
                        sum=sum+temp[i];                                                                                                                                
                        temp[i]=0;                                                                                                                                      
                        count=1;                                                                                                                                        
                }                                                                                                                                                       
                else if(temp[i]>0){                                                                                                                                     
                        temp[i]=temp[i]-quant;                                                                                                                          
                        sum=sum+quant;                                                                                                                                  
                }                                                                                                                                                       
                if(temp[i]==0 && count==1){                                                                                                                             
                        y--;                                                                                                                                            
                        printf("Process[%d]\t\t %d\t\t %d\t\t %d\t\t\t\t %d\n",i+1,at[i],bt[i],sum-at[i],sum-at[i]-bt[i]);                                              
                        wt=wt+sum-at[i]-bt[i];                                                                                                                          
                        tat=tat+sum-at[i];                                                                                                                              
                        count=0;                                                                                                                                        
                }                                                                                                                                                       
                if(i==n-1)                                                                                                                                              
                        i=0;                                                                                                                                            
                else if(at[i+1]<=sum)                                                                                                                                   
                        i++;                                                                                                                                            
                else                                                                                                                                                    
                        i=0;                                                                                                                                            
        }                                                                                                                                                               
        avg_wt=wt*1.0/n;                                                                                                                                                
        avg_tat=tat*1.0/n;                                                                                                                                              
        printf("\nAVERAGE WAITING TIME:\t %f\n",avg_wt);                                                                                                                
        printf("AVERAGE TURNAROUND TIME:\t %f\n",avg_tat);                                                                                                              
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
                           