#! /bin/bash

for ((i=1; i<=10000; i++)); do

	random_cpy=$RANDOM
	let "random_cpy %= $2"
	begin=$2
	let "begin -= $random_cpy"
	dd if=$1 of=file1 bs=1 count=$begin
	dd if=/dev/random of=file2 bs=1 count=$random_cpy
	cat file2 >> file1
	./ft_nm file1
	if [ $? != 0 ]
	then
		valgrind ./ft_nm file1
		exit 1
	fi
	echo $begin
done
