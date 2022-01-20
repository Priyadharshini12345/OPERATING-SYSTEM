#include<stdio.h>                                                                                                                                                       
int main(){                                                                                                                                                             
        int i,j,n,pages[50],frame[10],n1,k,avail,count=0;                                                                                                               
        printf("Enter the number of frames:\t");                                                                                                                        
        scanf("%d",&n1);                                                                                                                                                
        printf("Enter the number of pages:\t");                                                                                                                         
        scanf("%d",&n);                                                                                                                                                 
        printf("Enter the pages\n");                                                                                                                                    
        for(i=1;i<=n;i++)                                                                                                                                               
                scanf("%d",&pages[i]);                                                                                                                                  
        for(i=0;i<n1;i++)                                                                                                                                               
                frame[i]=-1;                                                                                                                                            
        j=0;                                                                                                                                                            
        printf("Ref string\t\t Page frames\n");                                                                                                                         
        for(i=1;i<=n;i++){                                                                                                                                              
                printf("%d\t\t",pages[i]);                                                                                                                              
                avail=0;                                                                                                                                                
                for(k=0;k<n1;k++)                                                                                                                                       
                        if(frame[k]==pages[i])                                                                                                                          
                                avail=1;                                                                                                                                
                if(avail==0){                                                                                                                                           
                        frame[j]=pages[i];                                                                                                                              
                        j=(j+1)%n1;                                                                                                                                     
                        count++;                                                                                                                                        
                        for(k=0;k<n1;k++)                                                                                                                               
                                printf("%d\t",frame[k]);                                                                                                                
                }                                                                                                                                                       
                printf("\n");                                                                                                                                           
        }                                                                                                                                                               
        printf("Total number of page faults:%d\n",count);                                                                                                               
        return 0;                                                                                                                                                       
}                    