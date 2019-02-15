#! /bin/bash

for ((i=1; i<=$2; i++)); do
	newfsize=$2
	((newfsize-=$i))
	dd if=$1 of=a.out bs=1 count=$newfsize > /dev/null 2>&1
	./ft_nm a.out > /dev/null 2>&1
	if [ $? -gt 2 ]
	then
		valgrind ./ft_nm a.out
		exit 1
	fi
done
