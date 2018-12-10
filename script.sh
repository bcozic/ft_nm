#! /bin/bash

success=0
fail=0

rm diff_test
rm fail_test
for OUT in /usr/bin/*;
do
	./ft_nm $OUT > test
	nm $OUT > test2
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
	./ft_nm $OUT > test
	nm $OUT > test2
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
	./ft_nm $OUT > test
	nm $OUT > test2
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
	./ft_nm $OUT > test
	nm $OUT > test2
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
	./ft_nm $OUT > test
	nm $OUT > test2
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
	./ft_nm $OUT > test
	nm $OUT > test2
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