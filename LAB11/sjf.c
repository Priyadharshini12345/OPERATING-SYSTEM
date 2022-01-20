#include<stdio.h>                                                                                                                                                       
int mat[10][6];                                                                                                                                                         
void swap(int* a,int* b){                                                                                                                                               
        int temp=*a;                                                                                                                                                    
        *a=*b;                                                                                                                                                          
        *b=temp;                                                                                                                                                        
}                                                                                                                                                                       
void arrangeArrival(int n,int mat[][6]){                                                                                                                                
        for(int i=0;i<n;i++){                                                                                                                                           
                for(int j=0;j<n-i-1;j++){                                                                                                                               
                        if(mat[1][j]>mat[1][j+1]){                                                                                                                      
                                for(int k=0;k<5;k++){                                                                                                                   
                                        swap(&mat[k][j],&mat[k][j+1]);                                                                                                  
                                }                                                                                                                                       
                        }                                                                                                                                               
                }                                                                                                                                                       
        }                                                                                                                                                               
}                                                                                                                                                                       
void completionTime(int n,int mat[][6]){                                                                                                                                
        int temp,val;                                                                                                                                                   
        mat[3][0]=mat[1][0]+mat[2][0];                                                                                                                                  
        mat[5][0]=mat[3][0]-mat[1][0];                                                                                                                                  
        mat[4][0]=mat[5][0]-mat[2][0];                                                                                                                                  
        for(int i=1;i<n;i++){                                                                                                                                           
                temp=mat[3][i-1];                                                                                                                                       
                int low=mat[2][i];                                                                                                                                      
                for(int j=i;j<n;j++){                                                                                                                                   
                        if(temp>=mat[1][j] && low>=mat[2][j]){                                                                                                          
                                low=mat[2][j];                                                                                                                          
                                val=j;                                                                                                                                  
                        }                                                                                                                                               
                }                                                                                                                                                       
                mat[3][val]=temp+mat[2][val];                                                                                                                           
                mat[5][val]=mat[3][val]-mat[1][val];                                                                                                                    
                mat[4][val]=mat[5][val]-mat[2][val];                                                                                                                    
                for(int k=0;k<6;k++){                                                                                                                                   
                        swap(&mat[k][val],&mat[k][i]);                                                                                                                  
                }                                                                                                                                                       
        }                                                                                                                                                               
}                                                                                                                                                                       
                                                                                                                                                                        
int main(){                                                                                                                                                             
        float twt=0,tat=0;                                                                                                                                              
        int n;                                                                                                                                                          
        printf("Enter the number of processes:\n");                                                                                                                     
        scanf("%d",&n);                                                                                                                                                 
        for(int i=0;i<n;i++){                                                                                                                                           
                printf("Enter the process ID:\n");                                                                                                                      
                scanf("%d",&mat[0][i]);                                                                                                                                 
                printf("Enter the arrival time of process %d:\n",i+1);                                                                                                  
                scanf("%d",&mat[1][i]);                                                                                                                                 
                printf("Enter the burst time of process %d:\n",i+1);                                                                                                    
                scanf("%d",&mat[2][i]);                                                                                                                                 
        }                                                                                                                                                               
                arrangeArrival(n,mat);                                                                                                                                  
                completionTime(n,mat);                                                                                                                                  
                printf("PROCESS ID\t ARRIVAL TIME\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n");                                                                    
                for(int i=0;i<n;i++){                                                                                                                                   
                        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n",mat[0][i],mat[1][i],mat[2][i],mat[4][i],mat[5][i]);
                }                                                                                                                                                       
                for(int i=0;i<n;i++){                                                                                                                                   
                        twt=twt+mat[4][i];                                                                                                                              
                        tat=tat+mat[5][i];                                                                                                                              
                }                                                                                                                                                       
                twt=twt/n;                                                                                                                                              
                tat/n;                                                                                                                                                  
                printf("AVERAGE WAITING TIME: %f\n",twt);                                                                                                               
                printf("AVERAGE TURNAROUND TIME:%f\n",tat);                                                                                                             
                return 0;                                                                                                                                               
        }                                                                                                                                                               
                               