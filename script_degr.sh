#! /bin/bash

for ((i=1; i<=$2; i++)); do
	newfsize=$2
	((newfsize-=$i))
	dd if=$1 of=a.out bs=1 count=$newfsize
	./ft_nm a.out
	if [ $? != 0 ]
	then
		valgrind ./ft_nm a.out
		exit 1
	fi
	echo $newfsize
done
