#!/bin/sh                                                                                                                                                               
filename="logicop.sh"                                                                                                                                                   
n=1;                                                                                                                                                                    
while read line                                                                                                                                                         
do                                                                                                                                                                      
        echo "Line number $n: $line"                                                                                                                                    
        n=$[ $n+1 ]                                                                                                                                                     
done<$filename  