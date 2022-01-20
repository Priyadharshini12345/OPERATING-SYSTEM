#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<sys/stat.h>                                                                                                                                                    
#include<sys/types.h>                                                                                                                                                   
#include<unistd.h>                                                                                                                                                      
int main(int argc,char* argv[]){                                                                                                                                        
        int n;                                                                                                                                                          
        struct stat buf;                                                                                                                                                
        for(n=1;n<argc;n++){                                                                                                                                            
                if(lstat(argv[n],&buf)==-1){                                                                                                                            
                        printf("Error in accessing the file\n");                                                                                                        
                        return 0;                                                                                                                                       
                }                                                                                                                                                       
                 if(S_ISLNK(buf.st_mode))                                                                                                                               
                        printf("%s is a symbolic link\n",argv[n]);                                                                                                      
                else                                                                                                                                                    
                        printf("%s is not a symbolic link\n",argv[n]);                                                                                                  
                printf("The size of the file:%d\n",buf.st_size);                                                                                                        
                printf((S_IRUSR & buf.st_mode) ? "r" : "-");                                                                                                            
                printf((S_IWUSR &buf.st_mode) ? "w" : "-");                                                                                                             
                printf((S_IXUSR & buf.st_mode) ? "x" : "-");                                                                                                            
                printf((S_IRGRP & buf.st_mode) ? "r" : "-");                                                                                                            
                printf((S_IWGRP & buf.st_mode) ? "w" : "-");                                                                                                            
                printf((S_IXGRP & buf.st_mode) ? "x" : "-");                                                                                                            
                printf((S_IROTH & buf.st_mode) ? "r" : "-");                                                                                                            
                printf((S_IWOTH & buf.st_mode) ? "w" : "-");                                                                                                            
                printf((S_IXOTH & buf.st_mode) ? "x" : "-");                                                                                                            
                printf("\n");                                                                                                                                           
                printf("Number of links:%d\n",buf.st_nlink);                                                                                                            
                printf("File inode:%d\n",buf.st_ino);                                                                                                                   

        }                                                                                                                                                               
        return 0;                                                                                                                                                       
}                