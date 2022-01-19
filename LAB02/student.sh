#!/bin/sh                                                                                                                                                               
echo "Enter N"                                                                                                                                                          
read N                                                                                                                                                                  
a=0                                                                                                                                                                     
while [ $a -lt $N ]                                                                                                                                                     
do                                                                                                                                                                      
        echo "Enter marks"                                                                                                                                              
        read MARK                                                                                                                                                       
        NAME[$a]=$MARK                                                                                                                                                  
        sum=`expr $sum + $MARK`                                                                                                                                         
        a=`expr $a + 1`                                                                                                                                                 
done                                                                                                                                                                    
avg=`expr $sum / $N`                                                                                                                                                    
echo "Class average is $avg"                                                                                                                                            
e=0                                                                                                                                                                     
while [ $e -lt $N ]                                                                                                                                                     
do                                                                                                                                                                      
        if [ ${NAME[$e]} -gt $avg ]                                                                                                                                     
        then                                                                                                                                                            
                echo "Grade: A"                                                                                                                                         
                e=`expr $e + 1`                                                                                                                                         
                elif [ ${NAME[$e]} -eq $avg ]                                                                                                                           
                then                                                                                                                                                    
                        echo "Grade: B"                                                                                                                                 
                        e=`expr $e + 1`                                                                                                                                 
                else                                                                                                                                                    
                                echo "Grade: C"                                                                                                                         
                                e=`expr $e + 1`                                                                                                                         
                        fi                                                                                                                                              
                done                                                                                                                                                    
                                                                                                                                                                        

                             