#!/bin/bash

for ((counter = 0; counter < 10; ++counter))
do
	printf "Progress: %d\r" "$counter"
	sleep 0.1
done
printf "Progress: %d\n" "$counter"
