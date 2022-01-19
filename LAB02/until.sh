#!/bin/sh                                                                                                                                                               
a=0                                                                                                                                                                     
until [ ! $a -le 5 ]                                                                                                                                                    
do                                                                                                                                                                      
        echo $a                                                                                                                                                         
        a=`expr $a + 1`                                                                                                                                                 
done                                                                                                                                                                    
c=0                                                                                                                                                                     
d=0                                                                                                                                                                     
outer=1                                                                                                                                                                 
echo "Nested until loops"                                                                                                                                               
until [ ! $c -lt 5 ]                                                                                                                                                    
do                                                                                                                                                                      
        echo "Pass $outer in outer loop"                                                                                                                                
        inner=1                                                                                                                                                         
        until [ ! $d -lt 5 ]                                                                                                                                            
        do                                                                                                                                                              
                echo "Pass $inner in inner loop"                                                                                                                        
                inner=`expr $inner + 1`                                                                                                                                 
                d=`expr $d + 1`                                                                                                                                         
        done                                                                                                                                                            
        outer=`expr $outer + 1`                                                                                                                                         
        c=`expr $c + 1`                                                                                                                                                 
done      