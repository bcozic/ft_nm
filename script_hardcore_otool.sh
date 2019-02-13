#! /bin/bash

for ((i=1; i<=10000; i++)); do

	random_cpy=$RANDOM
	let "random_cpy %= $2"
	begin=$2
	let "begin -= $random_cpy"
	dd if=$1 of=file1 bs=1 count=$begin > /dev/null 2>&1
	dd if=/dev/random of=file2 bs=1 count=$random_cpy > /dev/null 2>&1
	cat file2 >> file1
	./ft_otool file1 > /dev/null 2>&1
done
