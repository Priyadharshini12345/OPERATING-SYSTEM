#!/bin/sh                                                                                                                                                               
e=0                                                                                                                                                                     
while [ $e -le 10 ]                                                                                                                                                     
do                                                                                                                                                                      
        echo $e                                                                                                                                                         
        if [ $e -eq 5 ]                                                                                                                                                 
        then                                                                                                                                                            
                echo "Stopped"                                                                                                                                          
                break                                                                                                                                                   
        fi                                                                                                                                                              
        e=`expr $e + 1`                                                                                                                                                 
done                                                                                                                                                                    
for NUM in 10 11 12 13 14 15                                                                                                                                            
do                                                                                                                                                                      
        if [ $NUM -eq 12 ]                                                                                                                                              
        then                                                                                                                                                            
                continue                                                                                                                                                
        fi                                                                                                                                                              
        echo $NUM                                                                                                                                                       
done                                                                                                                                                                    
                                                                                                                                                                        
                      