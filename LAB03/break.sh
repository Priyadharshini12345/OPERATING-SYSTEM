#!/bin/sh                                                                                                                                                               
a=0                                                                                                                                                                     
while [ $a -lt 10 ]                                                                                                                                                     
do                                                                                                                                                                      
        echo $a                                                                                                                                                         
        if [ $a -eq 5 ]                                                                                                                                                 
        then break                                                                                                                                                      
        fi                                                                                                                                                              
        a=`expr $a + 1`                                                                                                                                                 
done                                                                                                                                                                    
echo "*****"                                                                                                                                                            
#break out of both outer as well as inner loop                                                                                                                          
for var1 in 1 2 3 4 5                                                                                                                                                   
do                                                                                                                                                                      
        for var2 in 6 7 8 9 10                                                                                                                                          
        do                                                                                                                                                              
                echo $var2                                                                                                                                              
                if [ $var1 -eq 1 -a $var2 -eq 9 ]                                                                                                                       
                then                                                                                                                                                    
                        break 2                                                                                                                                         
                fi                                                                                                                                                      
        done                                                                                                                                                            
done            