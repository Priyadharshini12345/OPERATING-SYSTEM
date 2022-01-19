#!/bin/sh                                                                                                                                                               
echo "Enter a number"                                                                                                                                                   
read num                                                                                                                                                                
#Logical and                                                                                                                                                            
if [ $num -gt 10 -a $num -lt 20 ]                                                                                                                                       
then echo "$num is greater than 10 and less than 20"                                                                                                                    
else                                                                                                                                                                    
        echo "$num is not greater than 10 and less than 20"                                                                                                             
fi                                                                                                                                                                      
#Logical Or                                                                                                                                                             
echo "Enter the first number"                                                                                                                                           
read n1                                                                                                                                                                 
echo "Enter the second number"                                                                                                                                          
read n2                                                                                                                                                                 
if [ $n1 -lt 10 -o $n2 -lt 10 ]                                                                                                                                         
then echo "A number is less than 10"                                                                                                                                    
else                                                                                                                                                                    
        echo "Numbers are not less than 10"                                                                                                                             
fi                                                                                                                                                                      
                                                                                                                                                                        
if [ ( $n1 -gt 5 -a $n2 -lt 20 ) -o ( $n1 -gt 100 -a $n2 -lt 200 ) ]                                                                                                    
then                                                                                                                                                                    
        echo "Yes"                                                                                                                                                      
else                                                                                                                                                                    
        echo "No"                                                                                                                                                       
fi                                                                                                                                                                      
                     