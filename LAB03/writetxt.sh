#!/bin/sh                                                                                                                                                               
echo "Creating a new file"                                                                                                                                              
cat<<EOF >/home/s2019103562/filen.txt                                                                                                                                   
First Word First Line                                                                                                                                                   
Second Word Second Line                                                                                                                                                 
EOF                                                                                                                                                                     
echo "Displaying the contents of the file  filen.txt"                                                                                                                   
cat filen.txt                                             