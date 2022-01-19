#!/bin/sh                                                                                                                                                               
NUMS="1 2 3 4 5 6 7 8 9 10"                                                                                                                                             
for N in $NUMS                                                                                                                                                          
do                                                                                                                                                                      
        Q=`expr $N % 2`                                                                                                                                                 
        if [ $Q -eq 0 ]                                                                                                                                                 
        then                                                                                                                                                            
                echo "$N is an even number"                                                                                                                             
                continue                                                                                                                                                
        fi                                                                                                                                                              
        echo "$N is an odd number"                                                                                                                                      
done                                                                                                                                                                    
echo "**********"   