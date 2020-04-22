#!/bin/bash
# Extract URLs from a html file and write them to a text file.
# ./parse.sh output.txt input.html

if [ $# -lt 2 ] 
then
   echo "$0: less than two arguments"
   exit 1
fi 

#if [ -e $1 ]
#then
#	echo "$0: output file already exists"  # don't overwrite an existing file
#	exit 1
#fi

if [ ! -e $2 ] 
then
   echo "$0: html file does not exist" 
   exit 1 
fi

grep -o "https?:[^\"]*" "$2" > "$1"  # matches everything from "http:" or "https:" up to (but not including) a double quote
sed -i '/babelfish\|100bestwebsites/d' "$1"  # delete lines with "babelfish" and "100bestwebsites"
sed -i '/List_of_.*_products/d' "$1"  # delete lines with "List_of_.*_products"

exit 0 