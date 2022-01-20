#include<stdio.h>                                                                                                                                                       
#include<stdlib.h>                                                                                                                                                      
#include<sys/types.h>                                                                                                                                                   
#include<sys/stat.h>                                                                                                                                                    
#include<unistd.h>                                                                                                                                                      
#include<fcntl.h>                                                                                                                                                       
int main(int argc,char* argv[]){                                                                                                                                        
        int fd=0;                                                                                                                                                       
        if(fd=open(argv[1],O_RDONLY)==-1){                                                                                                                              
                printf("Error in opening the file\n");                                                                                                                  
                return 0;                                                                                                                                               
        }                                                                                                                                                               
        struct stat buf;                                                                                                                                                
        if(fstat(fd,&buf)<0){                                                                                                                                           
                printf("Error\n");                                                                                                                                      
                return 0;                                                                                                                                               
        }                                                                                                                                                               
        printf("Information of the file:\n");                                                                                                                           
        printf("File size:%ld\n",buf.st_size);                                                                                                                          
        printf("Number of links:%ld\n",buf.st_nlink);                                                                                                                   
        printf("File inode:%ld\n",buf.st_ino);                                                                                                                          
        printf((buf.st_mode & S_IRUSR) ? "r" : "-");                                                                                                                    
        printf((buf.st_mode & S_IWUSR) ? "w" : "-");                                                                                                                    
        printf((buf.st_mode & S_IXUSR) ? "x" : "-");                                                                                                                    
        printf((buf.st_mode & S_IRGRP) ? "r" : "-");                                                                                                                    
        printf((buf.st_mode & S_IWGRP) ? "w" : "-");                                                                                                                    
        printf((buf.st_mode & S_IXGRP) ? "x" : "-");                                                                                                                    
        printf((buf.st_mode & S_IROTH) ? "r" : "-");                                                                                                                    
        printf((buf.st_mode & S_IWOTH) ? "w" : "-");                                                                                                                    
        printf((buf.st_mode & S_IXOTH) ? "x" : "-");                                                                                                                    
        printf("\n");                                                                                                                                                   
        if(S_ISLNK(buf.st_mode))                                                                                                                                        
                printf("The file is a symbolic link\n");                                                                                                                
        else                                                                                                                                                            
                printf("Not a symbolic link\n");                                                                                                                        
        return 0;                                                                                                                                                       
}                                                                                                                                                                       
                          