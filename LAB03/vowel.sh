#!/bin/sh                                                                                                                                                               
vowel(){                                                                                                                                                                
echo "Enter n"                                                                                                                                                          
read n                                                                                                                                                                  
a=0                                                                                                                                                                     
while [ $a -lt $n ]                                                                                                                                                     
do                                                                                                                                                                      
        read arr[$a]                                                                                                                                                    
        case "${arr[$a]}" in                                                                                                                                            
                "A") echo "${arr[$a]} is a vowel";;                                                                                                                     
                "E") echo "${arr[$a]} is a voewl";;                                                                                                                     
                "I")echo "${arr[$a]} is a vowel";;                                                                                                                      
                "O")echo "${arr[$a]} is a vowel";;                                                                                                                      
                "U")echo "${arr[$a]} is a vowel";;                                                                                                                      
                *)                                                                                                                                                      
                echo "${arr[$a]} is a consonant";;                                                                                                                      
                                                                                                                                                                        
        esac                                                                                                                                                            
        a=`expr $a + 1`                                                                                                                                                 
done                                                                                                                                                                    
}                                                                                                                                                                       
vowel                         