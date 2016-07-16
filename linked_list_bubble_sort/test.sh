#!/bin/bash

count=$((RANDOM % 1000))

#Clear input
> input.txt

#Generate random input datas [input.txt]
for ((run=1; run <= count; run++)); do
	echo $RANDOM >> input.txt
done

echo "Test with " $count " random datas"

#Run main program
./hw $count input.txt > output.txt

#Generate the correct for comparison [compare_output.tx]
sort -n input.txt > compare_output.txt

#Check [output.txt] and [compare_output.tx] by using diff command
diff_result=$(diff output.txt compare_output.txt)

if [$diff_result == ""]; then
	echo "Pass bubble sort check!"
else
	echo "Bubble sort check failed!"
fi
