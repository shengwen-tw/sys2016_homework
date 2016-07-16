#!/bin/bash

number=$RANDOM

for ((run=1; run <= number; run++)); do
	echo $RANDOM >> input
done

./hw <<< input > to_test

sort -n input > test
