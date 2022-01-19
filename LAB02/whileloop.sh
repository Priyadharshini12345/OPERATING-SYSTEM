#!/bin/sh                                                                                                                                                               
a=0                                                                                                                                                                     
while [ $a -lt 10 ]                                                                                                                                                     
do                                                                                                                                                                      
        echo $a                                                                                                                                                         
        a=`expr $a + 1`                                                                                                                                                 
done                                                                                                                                                                    
INPUT="Start"                                                                                                                                                           
while [ "$INPUT" != "quit" ]                                                                                                                                            
do                                                                                                                                                                      
        read INPUT                                                                                                                                                      
        echo "You entered: $INPUT"                                                                                                                                      
done                                                                                                                                                                    
c=0                                                                                                                                                                     
d=0                                                                                                                                                                     
outer=1                                                                                                                                                                 
echo "Nested while loops"                                                                                                                                               
while [ $c -lt 5 ]                                                                                                                                                      
do                                                                                                                                                                      
        echo "Pass $outer in outer loop"                                                                                                                                
       inner=1                                                                                                                                                          
        while [ $d -lt 5 ]                                                                                                                                              
        do                                                                                                                                                              
                echo "Pass $inner in inner loop"                                                                                                                        
                inner=`expr $inner + 1`                                                                                                                                 
                d=`expr $d + 1`                                                                                                                                         
        done                                                                                                                                                            
        outer=`expr $outer + 1`                                                                                                                                         
        c=`expr $c + 1`                                                                                                                                                 
done                                                                                                                                                                    
                                                                                                                                                                        
                                      