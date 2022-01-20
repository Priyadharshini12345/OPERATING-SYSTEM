#include<stdio.h>                                                                                                                                                       
#include<unistd.h>                                                                                                                                                      
#include<fcntl.h>                                                                                                                                                       
#include<sys/stat.h>                                                                                                                                                    
#include<sys/types.h>                                                                                                                                                   
#include<string.h>                                                                                                                                                      
#define BUFF_SIZE 1024                                                                                                                                                  
struct student{                                                                                                                                                         
        int reg;                                                                                                                                                        
        char name[BUFF_SIZE];                                                                                                                                           
        int marks;                                                                                                                                                      
};                                                                                                                                                                      
void main(){                                                                                                                                                            
        int fd,pid,p[2],temp;                                                                                                                                           
        struct student buff[5];                                                                                                                                         
        struct student s[5];                                                                                                                                            
        char file[10]="W7SPOT",temp1[20];                                                                                                                               
        fd=open(file,O_WRONLY|O_CREAT);                                                                                                                                 
        s[0].reg=1021;                                                                                                                                                  
        strcpy(s[0].name,"Hema");                                                                                                                                       
        s[0].marks=97;                                                                                                                                                  
        s[1].reg=1025;                                                                                                                                                  
        strcpy(s[1].name,"Chitra");                                                                                                                                     
        s[1].marks=99;                                                                                                                                                  
        s[2].reg=1027;                                                                                                                                                  
        strcpy(s[2].name,"Mala");                                                                                                                                       
        s[2].marks=100;                                                                                                                                                 
        s[3].reg=1028;                                                                                                                                                  
        strcpy(s[3].name,"Karthika");                                                                                                                                   
        s[3].marks=100;                                                                                                                                                 
        s[4].reg=1029;                                                                                                                                                  
        strcpy(s[4].name,"Jay");                                                                                                                                        
        s[4].marks=100;                                                                                                                                                 
        write(fd,s,sizeof(s));                                                                                                                                          
        close(fd);                                                                                                                                                      
        pipe(p);                                                                                                                                                        
        fd=open(file,O_RDONLY);                                                                                                                                         
        if((pid=fork())>0){                                                                                                                                             
                read(fd,buff,sizeof(s));                                                                                                                                
                write(p[1],buff,sizeof(s));                                                                                                                             
                for(int i=0;i<5;i++){                                                                                                                                   
                        for(int j=0;j<5;j++){                                                                                                                           
                                if(strcmp(s[j].name,s[i].name)>0){                                                                                                      
                                        temp=s[j].reg;                                                                                                                  
                                        s[j].reg=s[i].reg;                                                                                                              
                                        s[i].reg=temp;                                                                                                                  
                                        strcpy(temp1,s[j].name);                                                                                                        
                                        strcpy(s[j].name,s[i].name);                                                                                                    
                                        strcpy(s[i].name,temp1);                                                                                                        
                                        temp=s[j].marks;                                                                                                                
                                        s[j].marks=s[i].marks;                                                                                                          
                                        s[i].marks=temp;                                                                                                                
                                }                                                                                                                                       
                        }                                                                                                                                               
                }                                                                                                                                                       
                printf("Printing in alphabetical order correspondence to name\n");                                                                                      
                for(int i=0;i<5;i++){                                                                                                                                   
                        printf("%s\t",s[i].name);                                                                                                                       
                        printf("%d\t",s[i].reg);
                        printf("%d\t",s[i].marks);                                                                                                                      
                        printf("\n");                                                                                                                                   
                }                                                                                                                                                       
                printf("\n");                                                                                                                                           
        }                                                                                                                                                               
        else{                                                                                                                                                           
                printf("Printing the register number and marks of students\n");                                                                                         
                read(p[0],buff,sizeof(s));                                                                                                                              
                for(int i=0;i<5;i++){                                                                                                                                   
                        printf("%d\t",buff[i].reg);                                                                                                                     
                        printf("%d\t",buff[i].marks);                                                                                                                   
                        printf("\n");                                                                                                                                   

                }                                                                                                                                                       
                printf("\n");                                                                                                                                           
        }                                                                                                                                                               
        close(fd);                                                                                                                                                      
}                               