#!/bin/sh                                                                                                                                                               
#compound assignment                                                                                                                                                    
arr=(1 2 3 4 5 6 7)                                                                                                                                                     
echo "Elements of the array are ${arr[@]}"                                                                                                                              
echo "No of elements in an array is:${#arr[@]}"                                                                                                                         
echo "Accessing the elements of an array using for loop"                                                                                                                
for i in ${arr[@]}                                                                                                                                                      
do                                                                                                                                                                      
        echo $i                                                                                                                                                         
done                                                                                                                                                                    
echo "Elements from index 2 to 4"                                                                                                                                       
echo ${arr[@]:2:4}                                                                                                                                                      
echo "Count of Elements in the array"                                                                                                                                   
echo ${#arr[@]}                                                                                                                                                         
echo "Elements from index 5"                                                                                                                                            
echo ${arr[@]:5}                                                                                                                                                        
echo "Searching and replacing the element in the array"                                                                                                                 
echo ${arr[@]//7/8}                                                                                                                                                     
echo "Deleting the element at index 6"                                                                                                                                  
unset arr[6]                                                                                                                                                            
echo ${arr[@]}                                                                                                                                                          
names=([0]="Priya" [1]="Dharshini" [2]="Jayashri" [3]="Prem" [4]="Yuvashri" [5]="Ramya")                                                                                
echo "The contents of the array are:"                                                                                                                                   
for i in "${names[@]}"                                                                                                                                                  
do                                                                                                                                                                      
        echo $i                                                                                                                                                         
done                                                                                                                                                                    
echo "Count of letters of the word at index 0"                                                                                                                          
echo ${#names[0]}                                                                                                                                                       
echo "Count of letters of the word at index 1"                                                                                                                          
echo ${#names[1]}                                                                                                                                                       
echo "Searching and replacing in an array"                                                                                                                              
echo ${names[@]//Prem/Preethi}                                                                                                                                          
unset names[1]                                                                                                                                                          
echo "Deleting the element at index 1"                                                                                                                                  
echo ${names[*]}                                     