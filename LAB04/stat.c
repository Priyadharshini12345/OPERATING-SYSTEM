#include<stdio.h>                                                                                                                                                       
#include<sys/stat.h>                                                                                                                                                    
void main(){                                                                                                                                                            
        struct stat sfile;                                                                                                                                              
        stat("alarm.c",&sfile);                                                                                                                                         
        printf("Permissions:%o\n",sfile.st_mode);                                                                                                                       
        printf("Group id:%ld\n",sfile.st_gid);                                                                                                                          
        printf("User id:%ld\n",sfile.st_uid);                                                                                                                           
        printf("Recent modified time:%d\n",sfile.st_mtime);                                                                                                             
        printf("Recent accessed time:%d\n",sfile.st_atime);                                                                                                             
        printf("Size of the file in bytes:%d\n",sfile.st_size);                                                                                                         
        printf("Id of the device in which we have the file:%d\n",sfile.st_dev);                                                                                         
}       