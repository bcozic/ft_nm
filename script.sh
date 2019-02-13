#! /bin/bash

success=0
fail=0

rm -f diff_test2
for OUT in /usr/bin/*;
do
	echo "$OUT"
	./ft_nm $OUT > test3 2>> error
	nm $OUT > test4 2>> error
	diff "test3" "test4"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "\n\n$OUT :" >> diff_test2
		diff "test3" "test4" >> diff_test2
		((fail++))
	elif [ $res == 0 ]
	then
		((success++))
	else
		echo -e "$OUT Error diff"
	fi
done
for OUT in /bin/*;
do
	echo "$OUT"
	./ft_nm $OUT > test3 2>> error
	nm $OUT > test4 2>> error
	diff "test3" "test4"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "\n\n$OUT :" >> diff_test2
		diff "test3" "test4" >> diff_test2
		((fail++))
	elif [ $res == 0 ]
	then
		((success++))
	else
		echo -e "$OUT Error diff"
	fi
done
for OUT in /sbin/*;
do
	echo "$OUT"
	./ft_nm $OUT > test3 2>> error
	nm $OUT > test4 2>> error
	diff "test3" "test4"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "\n\n$OUT :" >> diff_test2
		diff "test3" "test4" >> diff_test2
		((fail++))
	elif [ $res == 0 ]
	then
		((success++))
	else
		echo -e "$OUT Error diff"
	fi
done
for OUT in /usr/lib/*;
do
	echo "$OUT"
	./ft_nm $OUT > test3 2>> error
	nm $OUT > test4 2>> error
	diff "test3" "test4"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "\n\n$OUT :" >> diff_test2
		diff "test3" "test4" >> diff_test2
		((fail++))
	elif [ $res == 0 ]
	then
		((success++))
	else
		echo -e "$OUT Error diff"
	fi
done
for OUT in /usr/sbin/*;
do
	echo "$OUT"
	./ft_nm $OUT > test3 2>> error
	nm $OUT > test4 2>> error
	diff "test3" "test4"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "\n\n$OUT :" >> diff_test2
		diff "test3" "test4" >> diff_test2
		((fail++))
	elif [ $res == 0 ]
	then
		((success++))
	else
		echo -e "$OUT Error diff"
	fi
done
for OUT in obj/*;
do
	echo "$OUT"
	./ft_nm $OUT > test3 2>> error
	nm $OUT > test4 2>> error
	diff "test3" "test4"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "\n\n$OUT :" >> diff_test2
		diff "test3" "test4" >> diff_test2
		((fail++))
	elif [ $res == 0 ]
	then
		((success++))
	else
		echo -e "$OUT Error diff"
	fi
done
for OUT in libft/obj/*;
do
	echo "$OUT"
	./ft_nm $OUT > test3 2>> error
	nm $OUT > test4 2>> error
	diff "test3" "test4"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "\n\n$OUT :" >> diff_test2
		diff "test3" "test4" >> diff_test2
		((fail++))
	elif [ $res == 0 ]
	then
		((success++))
	else
		echo -e "$OUT Error diff"
	fi
done
for OUT in /usr/libexec/*;
do
	echo "$OUT"
	./ft_nm $OUT > test3 2>> error
	nm $OUT > test4 2>> error
	diff "test3" "test4"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "\n\n$OUT :" >> diff_test2
		diff "test3" "test4" >> diff_test2
		((fail++))
	elif [ $res == 0 ]
	then
		((success++))
	else
		echo -e "$OUT Error diff"
	fi
done
for OUT in /usr/libexec/apache2/*;
do
	echo "$OUT"
	./ft_nm $OUT > test3 2>> error
	nm $OUT > test4 2>> error
	diff "test3" "test4"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "\n\n$OUT :" >> diff_test2
		diff "test3" "test4" >> diff_test2
		((fail++))
	elif [ $res == 0 ]
	then
		((success++))
	else
		echo -e "$OUT Error diff"
	fi
done
echo $success "success"
echo $fail "fail"