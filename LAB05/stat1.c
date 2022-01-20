#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<sys/stat.h>                                                                                                                                                    
#include<sys/types.h>                                                                                                                                                   
#include<unistd.h>                                                                                                                                                      
int main(){                                                                                                                                                             
        struct stat buf;                                                                                                                                                
        char file[30];                                                                                                                                                  
        printf("Enter the filename\n");                                                                                                                                 
        scanf("%s",file);                                                                                                                                               
        if(stat(file,&buf)==-1){                                                                                                                                        
                printf("Error occured\n");                                                                                                                              
                return 0;                                                                                                                                               
        }                                                                                                                                                               
        else{                                                                                                                                                           
                printf("File size:%d\n",buf.st_size);                                                                                                                   
                if(buf.st_mode & S_IRUSR)                                                                                                                               
                        printf("Readable by User\n");                                                                                                                   
                else                                                                                                                                                    
                        printf("Not readable by user\n");                                                                                                               
                if(buf.st_mode & S_IWUSR)                                                                                                                               
                        printf("Writable by User\n");                                                                                                                   
                else                                                                                                                                                    
                        printf("Not writable by user\n");                                                                                                               
                if(buf.st_mode & S_IXUSR)                                                                                                                               
                        printf("Executable by User\n");                                                                                                                 
                else                                                                                                                                                    
                        printf("Not executable by user\n");                                                                                                             
                if(buf.st_mode & S_IRGRP)                                                                                                                               
                        printf("Readable by Group\n");                                                                                                                  
                else                                                                                                                                                    
                        printf("Not readable by group\n");                                                                                                              
                if(buf.st_mode & S_IWGRP)                                                                                                                               
                        printf("Writable by Group\n");                                                                                                                  
                else                                                                                                                                                    
                        printf("Not writable by group\n");                                                                                                              
                if(buf.st_mode & S_IXGRP)                                                                                                                               
                        printf("Executable by Group\n");                                                                                                                
                else                                                                                                                                                    
                        printf("Not executable by group\n");                                                                                                            
                if(buf.st_mode & S_IWOTH)                                                                                                                               
                        printf("Writable by Others\n");                                                                                                                 
                else                                                                                                                                                    
                        printf("Not writable by others\n");                                                                                                             
                if(buf.st_mode & S_IROTH)                                                                                                                               
                        printf("Readable by Others\n");                                                                                                                 
                else                                                                                                                                                    
                        printf("Not readable by others\n");                                                                                                             
                if(buf.st_mode & S_IXOTH)                                                                                                                               
                        printf("Executable by Others\n");                                                                                                               
                else                                                                                                                                                    
                        printf("Not executable by others\n");                                                                                                           
                }                                                                                                                                                       

        return 0;                                                                                                                                                       
}                    