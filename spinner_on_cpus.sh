#!/bin/bash

if [ -z "$1" ]
then
	echo "Usage: $0 <cpu 0> ... <cpu n>"
fi

for cpu in "$@"
do
	taskset -c $cpu spinner &
done
