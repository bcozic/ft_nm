#! /bin/bash

for ((i=1; i<=$1; i++)); do
	newfsize=$1
	((newfsize-=$i))
	cp a2.out a.out
	dd if=a.out of=a2.out bs=1 count=$newfsize
	./ft_nm a.out
	if [ $? != 0 ]
	then
		exit 1
	fi
	echo $newfsize
done
