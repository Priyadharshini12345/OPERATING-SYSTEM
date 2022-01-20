#include<stdio.h>                                                                                                                                                       
#define MAX 30                                                                                                                                                          
int main(){                                                                                                                                                             
        int bt[MAX],at[MAX],temp[MAX],wt[MAX],tat[MAX],n;                                                                                                               
        float awt=0,atat=0;                                                                                                                                             
        printf("Enter the number of processes:\n");                                                                                                                     
        scanf("%d",&n);                                                                                                                                                 
        for(int i=0;i<n;i++){                                                                                                                                           
                printf("Enter the arrival time of process %d:\n",i+1);                                                                                                  
                scanf("%d",&at[i]);                                                                                                                                     
                printf("Enter the burst time of process %d:\n",i+1);                                                                                                    
                scanf("%d",&bt[i]);                                                                                                                                     
        }                                                                                                                                                               
        printf("PROCESS\t ARRIVAL TIME\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n");                                                                               
        temp[0]=0;                                                                                                                                                      
        for(int i=0;i<n;i++){                                                                                                                                           
                wt[i]=0;                                                                                                                                                
                tat[i]=0;                                                                                                                                               
                temp[i+1]=temp[i]+bt[i];                                                                                                                                
                wt[i]=temp[i]-at[i];                                                                                                                                    
                tat[i]=wt[i]+bt[i];                                                                                                                                     
                awt=awt+wt[i];                                                                                                                                          
                atat=atat+tat[i];                                                                                                                                       
                printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n",i+1,at[i],bt[i],wt[i],tat[i]);                                                                                
        }                                                                                                                                                               
        awt=awt/n;                                                                                                                                                      
        atat=atat/n;                                                                                                                                                    
        printf("AVERAGE WAITING TIME: %f\n",awt);                                                                                                                       
        printf("AVERAGE TURNAROUND TIME: %f\n",atat);                                                                                                                   
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
                              