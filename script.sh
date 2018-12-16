#! /bin/bash

success=0
fail=0

rm diff_test
rm fail_test
for OUT in /usr/bin/*;
do
	echo "$OUT"
	./ft_nm $OUT > test 2>> error
	if [ $? != 0 ]
	then
		valgrind ./ft_nm $OUT
		exit 1
	fi
	nm $OUT > test2 2>> error
	diff "test" "test2"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "$OUT :\n\n" >> diff_test
		echo -e "$OUT :\n" >> fail_test
		diff "test" "test2" >> diff_test
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
	./ft_nm $OUT > test 2>> error
	if [ $? != 0 ]
	then
		valgrind ./ft_nm $OUT
		exit 1
	fi
	nm $OUT > test2 2>> error
	diff "test" "test2"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "$OUT :\n\n" >> diff_test
		echo -e "$OUT :\n" >> fail_test
		diff "test" "test2" >> diff_test
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
	./ft_nm $OUT > test 2>> error
	if [ $? != 0 ]
	then
		valgrind ./ft_nm $OUT
		exit 1
	fi
	nm $OUT > test2 2>> error
	diff "test" "test2"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "$OUT :\n\n" >> diff_test
		echo -e "$OUT :\n" >> fail_test
		diff "test" "test2" >> diff_test
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
	./ft_nm $OUT > test 2>> error
	if [ $? != 0 ]
	then
		valgrind ./ft_nm $OUT
		exit 1
	fi
	nm $OUT > test2 2>> error
	diff "test" "test2"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "$OUT :\n\n" >> diff_test
		echo -e "$OUT :\n" >> fail_test
		diff "test" "test2" >> diff_test
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
	./ft_nm $OUT > test 2>> error
	if [ $? != 0 ]
	then
		valgrind ./ft_nm $OUT
		exit 1
	fi
	nm $OUT > test2 2>> error
	diff "test" "test2"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "$OUT :\n\n" >> diff_test
		echo -e "$OUT :\n" >> fail_test
		diff "test" "test2" >> diff_test
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
	./ft_nm $OUT > test 2>> error
	if [ $? != 0 ]
	then
		valgrind ./ft_nm $OUT
		exit 1
	fi
	nm $OUT > test2 2>> error
	diff "test" "test2"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "$OUT :\n\n" >> diff_test
		echo -e "$OUT :\n" >> fail_test
		diff "test" "test2" >> diff_test
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
	./ft_nm $OUT > test 2>> error
	if [ $? != 0 ]
	then
		valgrind ./ft_nm $OUT
		exit 1
	fi
	nm $OUT > test2 2>> error
	diff "test" "test2"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "$OUT :\n\n" >> diff_test
		echo -e "$OUT :\n" >> fail_test
		diff "test" "test2" >> diff_test
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
	./ft_nm $OUT > test 2>> error
	if [ $? != 0 ]
	then
		valgrind ./ft_nm $OUT
		exit 1
	fi
	nm $OUT > test2 2>> error
	diff "test" "test2"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "$OUT :\n\n" >> diff_test
		echo -e "$OUT :\n" >> fail_test
		diff "test" "test2" >> diff_test
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
	./ft_nm $OUT > test 2>> error
	if [ $? != 0 ]
	then
		valgrind ./ft_nm $OUT
		exit 1
	fi
	nm $OUT > test2 2>> error
	diff "test" "test2"
	res=$?
	if [ $res == 1 ]
	then
		echo -e "$OUT :\n\n" >> diff_test
		echo -e "$OUT :\n" >> fail_test
		diff "test" "test2" >> diff_test
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