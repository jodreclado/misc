#!/bin/bash
# Execute perform-measurement.sh on each URL inside the second argument and write the output to the first argument.
# ./run-experiment.sh results.txt popular.txt

rank=0

> "$1"  # clear file before writing 

while read url 
do
   let "rank=rank+1"
   echo "Performing byte-size measurement on $url"
   size=$(./perform-measurement.sh $url)

   if [ $size -gt 0 ] 
   then
      echo "...successful"
      echo $rank $url $size >> "$1"
   else 
      echo "...failure"
   fi

done < "$2"

exit 0