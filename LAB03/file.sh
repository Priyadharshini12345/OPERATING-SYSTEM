#!/bin/sh                                                                                                                                                               
echo "Enter filename"                                                                                                                                                   
read file                                                                                                                                                               
if [ -r $file ]                                                                                                                                                         
then                                                                                                                                                                    
        echo "The file has read access"                                                                                                                                 
        else                                                                                                                                                            
                echo "The file has no read access"                                                                                                                      
                fi                                                                                                                                                      
                if [ -w $file ]                                                                                                                                         
                then echo "The file has write access"                                                                                                                   
                else                                                                                                                                                    
                        echo "The file has no write access"                                                                                                             
                fi                                                                                                                                                      
        if [ -x $file ]                                                                                                                                                 
        then echo "The file has execute access"                                                                                                                         
        else                                                                                                                                                            
                echo "The file has no execute access"                                                                                                                   
        fi                                                                                                                                                              
        if [ -s $file ]                                                                                                                                                 
        then                                                                                                                                                            
                echo "The file size is not zero"                                                                                                                        
        else echo "Zero file size"                                                                                                                                      
        fi                                                                                                                                                              
        if [ -f $file ]                                                                                                                                                 
        then                                                                                                                                                            
                echo "The file is a ordinary file"                                                                                                                      
        else                                                                                                                                                            
                echo "Special file"                                                                                                                                     
        fi                                                                                                                                                              
        if [ -d $file ]                                                                                                                                                 
        then echo "The file is a directory"                                                                                                                             
        else                                                                                                                                                            
                echo "This is not a directory"                                                                                                                          
        fi                                                                                                                                                              
        if [ -e $file ]                                                                                                                                                 
        then echo "File exists"                                                                                                                                         
        else                                                                                                                                                            
                echo "The file does not exists"                                                                                                                         
        fi            