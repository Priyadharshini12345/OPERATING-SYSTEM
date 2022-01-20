#include<stdio.h>                                                                                                                                                       
int findmin(int time[],int n){                                                                                                                                          
        int i,minimum=time[0],pos=0;                                                                                                                                    
        for(i=1;i<n;i++){                                                                                                                                               
                if(time[i]<minimum){                                                                                                                                    
                        minimum=time[i];                                                                                                                                
                        pos=i;                                                                                                                                          
                }                                                                                                                                                       
        }                                                                                                                                                               
        return pos;                                                                                                                                                     
}                                                                                                                                                                       
int main(){                                                                                                                                                             
        int i,j,k,flag1,flag2,faults=0,counter=0,time[10],pages[50],frames[10],no_of_frames,no_of_pages,pos;                                                            
        printf("Enter the number of frames:\t");                                                                                                                        
        scanf("%d",&no_of_frames);                                                                                                                                      
        printf("Enter the number of pages:\t");                                                                                                                         
        scanf("%d",&no_of_pages);                                                                                                                                       
        printf("Enter the pages:\n");                                                                                                                                   
        for(i=0;i<no_of_pages;i++)                                                                                                                                      
                scanf("%d",&pages[i]);                                                                                                                                  
        for(j=0;j<no_of_frames;j++)                                                                                                                                     
                frames[j]=-1;                                                                                                                                           
        for(i=0;i<no_of_pages;i++){                                                                                                                                     
                flag1=flag2=0;                                                                                                                                          
                for(j=0;j<no_of_frames;j++){                                                                                                                            
                        if(frames[j]==pages[i]){                                                                                                                        
                                counter++;                                                                                                                              
                                time[j]=counter;                                                                                                                        
                                flag1=flag2=1;                                                                                                                          
                                break;                                                                                                                                  
                        }                                                                                                                                               
                }                                                                                                                                                       
                if(flag1==0){                                                                                                                                           
                        for(j=0;j<no_of_frames;j++){                                                                                                                    
                                if(frames[j]==-1){                                                                                                                      
                                        counter++;                                                                                                                      
                                        faults++;                                                                                                                       
                                        frames[j]=pages[i];                                                                                                             
                                        time[j]=counter;                                                                                                                
                                        flag2=1;                                                                                                                        
                                        break;                                                                                                                          
                                }                                                                                                                                       
                        }                                                                                                                                               
                }                                                                                                                                                       
                if(flag2==0){                                                                                                                                           
                        pos=findmin(time,no_of_frames);                                                                                                                 
                        counter++;                                                                                                                                      
                        faults++;                                                                                                                                       
                        frames[pos]=pages[i];                                                                                                                           
                        time[pos]=counter;                                                                                                                              
                }                                                                                                                                                       
                printf("\n");                                                                                                                                           
                for(j=0;j<no_of_frames;j++)                                                                                                                             
                        printf("%d\t",frames[j]);
        }                                                                                                                                                               
        printf("\nTotal number of Page Faults:%d\n",faults);                                                                                                            
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
                             