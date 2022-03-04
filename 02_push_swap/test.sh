#!/bin/bash

for i in {1..25}
do
	echo "-|-|-|-|-|-|-|-|-|-|-"
	ARG=`ruby -e "puts (-500..500).to_a.shuffle.first(5).join(' ')"`;
	./push_swap $ARG | ./checker_Mac $ARG
	./push_swap $ARG | wc -l
done
