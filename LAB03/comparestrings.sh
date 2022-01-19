#!/bin/sh                                                                                                                                                               
compare(){                                                                                                                                                              
echo "Enter string1"                                                                                                                                                    
read name1                                                                                                                                                              
echo "Enter string2"                                                                                                                                                    
read name2                                                                                                                                                              
if test "$name1" = "$name2"                                                                                                                                             
then                                                                                                                                                                    
        echo "1"                                                                                                                                                        
else                                                                                                                                                                    
        echo "0"                                                                                                                                                        
fi                                                                                                                                                                      
}                                                                                                                                                                       
compare      