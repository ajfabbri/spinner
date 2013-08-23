#!/bin/bash

ITER=17
USLEEP=2

if [ -z "$1" ]
then
	echo "Usage: $0 <cpu 0> ... <cpu n>"
fi

for cpu in "$@"
do
	taskset -c $cpu spinner -i $ITER -s $USLEEP &
done
