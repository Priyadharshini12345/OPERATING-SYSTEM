#!/bin/sh                                                                                                                                                               
echo "Display numbers from 1 to 9"                                                                                                                                      
for NUM in 1 2 3 4 5 6 7 8 9                                                                                                                                            
do                                                                                                                                                                      
        echo "Entry" $NUM ":" $NUM                                                                                                                                      
done                                                                                                                                                                    
echo "Displaying the arguments"                                                                                                                                         
for TOKEN in $*                                                                                                                                                         
do                                                                                                                                                                      
        echo $TOKEN                                                                                                                                                     
done                                                                                                                                                                    
echo "Arithmetic operations:"                                                                                                                                           
for NUM in 1 2                                                                                                                                                          
do                                                                                                                                                                      
        echo "Enter the operands"                                                                                                                                       
        read A                                                                                                                                                          
        read B                                                                                                                                                          
        val=`expr $A + $B`                                                                                                                                              
        echo "Addition: $val"                                                                                                                                           
        res=`expr $A - $B`                                                                                                                                              
        echo "Diffrence: $res"                                                                                                                                          
        mul=`expr $A \* $B`                                                                                                                                             
        echo "Product: $mul"                                                                                                                                            
        div=`expr $A / $B`                                                                                                                                              
        echo "Division: $div"                                                                                                                                           
done                                                                                                                                                                    
echo "Nested For loops"                                                                                                                                                 
for NUM in 1 2 3 4 5                                                                                                                                                    
do                                                                                                                                                                      
        outer=1                                                                                                                                                         
        echo "Pass $outer in outer loop"                                                                                                                                
        inner=1                                                                                                                                                         
        for NO in 1 2 3 4 5                                                                                                                                             
        do                                                                                                                                                              
                echo "Pass $inner in inner loop"                                                                                                                        
                inner=`expr $inner + 1`                                                                                                                                 
        done                                                                                                                                                            
        outer=`expr $outer + 1`                                                                                                                                         
done                                                                                                                                                                    
                           