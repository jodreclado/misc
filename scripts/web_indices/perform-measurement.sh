#!/bin/bash
# Take a URL as an argument and output the size of the corresponding page in bytes.

if [ $# -eq 0 ] 
then
   echo "$0: no argument was provided"
   exit 1
fi

temp=$(mktemp)  # make temp file
wget --tries=3 --timeout=30 -q -O "$temp" $1  # download to temp file, turn off output, set tries to 3 and timeout to 30s
status=$?  # store exit status of last command (wget)

if [ $status -eq 0 ]  # status = 0 if no problems occured with wget
then 
   wc -c < "$temp"  # print byte count without file name
else 
   echo 0 
fi

rm "$temp"  # delete temp file 

exit 0