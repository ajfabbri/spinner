#!/bin/bash

ITER=13
USLEEP=5

if [ -z "$1" ]
then
	echo "Usage: $0 <cpu 0> ... <cpu n>"
fi

for cpu in "$@"
do
	taskset -c $cpu spinner -i $ITER -s $USLEEP &
done

wait
