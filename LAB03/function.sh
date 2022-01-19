#!/bin/sh                                                                                                                                                               
#function without argument                                                                                                                                              
Hello(){                                                                                                                                                                
        echo "Hello"                                                                                                                                                    
        echo "Function call without parameters"                                                                                                                         
}                                                                                                                                                                       
Hello                                                                                                                                                                   
#function with argument                                                                                                                                                 
Hello2(){                                                                                                                                                               
        echo "Hello $1"                                                                                                                                                 
        echo "Function call with parameter"                                                                                                                             
}                                                                                                                                                                       
Hello2 Priya                                                                                                                                                            
#nested functions                                                                                                                                                       
one(){                                                                                                                                                                  
        echo "Function one"                                                                                                                                             
        two                                                                                                                                                             
}                                                                                                                                                                       
two(){                                                                                                                                                                  
        echo "Function two nested inside function one"                                                                                                                  
}                                                                                                                                                                       
one                                                                                                                                                                     
#functions with return                                                                                                                                                  
value(){                                                                                                                                                                
        echo "Hello ALL"                                                                                                                                                
        return 100                                                                                                                                                      
}                                                                                                                                                                       
value                                                                                                                                                                   
ret=$?                                                                                                                                                                  
echo "Returned value is $ret"                                                                                                                                           
find_avg(){                                                                                                                                                             
a=0                                                                                                                                                                     
sum=0                                                                                                                                                                   
echo "Enter a number"                                                                                                                                                   
read n                                                                                                                                                                  
while [ $a -lt $n ]                                                                                                                                                     
do                                                                                                                                                                      
        read arr[$a]                                                                                                                                                    
        sum=`expr $sum + ${arr[$a]}`                                                                                                                                    
        a=`expr $a + 1`                                                                                                                                                 
done                                                                                                                                                                    
avg=`expr $sum / ${#arr[@]}`                                                                                                                                            
return $avg                                                                                                                                                             
}                                                                                                                                                                       
find_avg                                                                                                                                                                
res=$?                                                                                                                                                                  
echo "Average of $n numbers is $res"                                                                                                                                    
square(){                                                                                                                                                               
        echo "Enter n"                                                                                                                                                  
        read number                                                                                                                                                     
        i=0                                                                                                                                                             
        while [ $i -lt $number ]                                                                                                                                        
        do                                                                                                                                                              
                rest=`expr $i \* $i`                                                                                                                                    
                echo "Square of $i is $rest"                                                                                                                            
                i=`expr $i + 1`                                                                                                                                         
        done                                                                                                                                                            
}                                                                                                                                                                       
square                                                                                                                                                                  
echo "Factorial of 5 is"                                                                                                                                                
fact(){                                                                                                                                                                 
        if [ $1 -gt 1 ]                                                                                                                                                 
        then                                                                                                                                                            
                i=`expr $1 - 1`                                                                                                                                         
                j=`fact $i`                                                                                                                                             
                k=`expr $1 \* $j`                                                                                                                                       
                echo $k                                                                                                                                                 
        else                                                                                                                                                            
                echo 1                                                                                                                                                  
        fi                                                                                                                                                              
}                                                                                                                                                                       
fact 5                                         