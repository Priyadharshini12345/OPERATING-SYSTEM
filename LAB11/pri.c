#include<stdio.h>                                                                                                                                                       
#include<string.h>                                                                                                                                                      
#define MAX 30                                                                                                                                                          
int main(){                                                                                                                                                             
        int bt[MAX],at[MAX],n,i,j,temp,p[MAX],st[MAX],ft[MAX],wt[MAX],ta[MAX];                                                                                          
        float twt=0,tat=0;                                                                                                                                              
//      float awt=0,atat=0;                                                                                                                                             
        char pn[MAX][MAX],t[MAX];                                                                                                                                       
        printf("Enter the number of processes\n");                                                                                                                      
        scanf("%d",&n);                                                                                                                                                 
        for(i=0;i<n;i++){                                                                                                                                               
                printf("Enter the process name:\n");                                                                                                                    
                scanf("%s",pn[i]);                                                                                                                                      
                printf("Enter the arrival time for process %d:\n",i+1);                                                                                                 
                scanf("%d",&at[i]);                                                                                                                                     
                printf("Enter the burst time for process %d:\n",i+1);                                                                                                   
                scanf("%d",&bt[i]);                                                                                                                                     
                printf("Enter the priority for process %d:\n",i+1);                                                                                                     
                scanf("%d",&p[i]);                                                                                                                                      
        }                                                                                                                                                               
        for(i=0;i<n;i++){                                                                                                                                               
                for(j=0;j<n;j++){                                                                                                                                       
                        if(p[i]<p[j]){                                                                                                                                  
                                temp=p[i];                                                                                                                              
                                p[i]=p[j];                                                                                                                              
                                p[j]=temp;                                                                                                                              
                                temp=at[i];                                                                                                                             
                                at[i]=at[j];                                                                                                                            
                                at[j]=temp;                                                                                                                             
                                temp=bt[i];                                                                                                                             
                                bt[i]=bt[j];                                                                                                                            
                                bt[j]=temp;                                                                                                                             
                                strcpy(t,pn[i]);                                                                                                                        
                                strcpy(pn[i],pn[j]);                                                                                                                    
                                strcpy(pn[j],t);                                                                                                                        
                        }                                                                                                                                               
                }                                                                                                                                                       
        }                                                                                                                                                               
        for(i=0;i<n;i++){                                                                                                                                               
                if(i==0){                                                                                                                                               
                        st[i]=at[i];                                                                                                                                    
                        wt[i]=st[i]-at[i];                                                                                                                              
                        ft[i]=st[i]+bt[i];                                                                                                                              
                        ta[i]=ft[i]-at[i];                                                                                                                              
                }                                                                                                                                                       
                else{                                                                                                                                                   
                        st[i]=ft[i-1];                                                                                                                                  
                        wt[i]=st[i]-at[i];                                                                                                                              
                        ft[i]=st[i]+bt[i];                                                                                                                              
                        ta[i]=ft[i]-at[i];                                                                                                                              
                }                                                                                                                                                       
                twt=twt+wt[i];                                                                                                                                          
                tat=tat+ta[i];                                                                                                                                          
        }                                                                                                                                                               
        twt=twt/n;                                                                                                                                                      
        tat=tat/n;                                                                                                                                                      
        printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME\t PRIORITY\t WAITING TIME\t TURNAROUND TIME\n");                                                                 
        for(i=0;i<n;i++)                                                                                                                                                
                printf("%s\t\t %d\t\t %d\t\t %d\t\t %d\t\t %d\n",pn[i],at[i],bt[i],p[i],wt[i],ta[i]);                                                                   
        printf("AVERAGE WAITING TIME: %f\n",twt);                                                                                                                       
        printf("AVERAGE TURNAROUND TIME:%f\n",tat);                                                                                                                     
        return 0;                                                                                                                                                       
}                             