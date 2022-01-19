#!/bin/sh                                                                                                                                                               
echo "0 Sunday 1 Monday 2 Tuesday 3 Wednesday 4 Thursday 5 Friday 6 Saturday"                                                                                           
echo "Enter N"                                                                                                                                                          
read N                                                                                                                                                                  
case $N in                                                                                                                                                              
        "0")echo "You entered Sunday";;                                                                                                                                 
        "1")echo "You entered Monday";;                                                                                                                                 
        "2")echo "You entered Tuesday";;                                                                                                                                
        "3")echo "You entered Wednesday";;                                                                                                                              
        "4")echo "You entered Thursday";;                                                                                                                               
        "5")echo "You entered Friday";;                                                                                                                                 
        "6")echo "You entered Saturday";;                                                                                                                               
        esac       