#!/bin/sh

cd adeburea_tester

start=`date +%s%N`
valgrind ./ft_stack > ft_stack.out 2> ft_stack_err.log
end=`date +%s%N`
ft_execution=`expr $end - $start`

start=`date +%s%N`
valgrind ./std_stack > std_stack.out 2> std_stack_err.log
end=`date +%s%N`
std_execution=`expr $end - $start`

diff=`expr $ft_execution / $std_execution`
echo -n "Checking time execution : "
if (( $diff > 20 ))
then
	echo -e "\033[1;31mFailed ! The execution is more than $diff times slower.\033[m"
elif (( $diff == 0 || $diff == 1 ))
then
	echo -e "\033[1;32mSuccess ! ft::stack and std::stack has the same execution time\033[m"
else
	echo -e "\033[1;32mSuccess ! The execution is $diff time slower.\033[m"
fi

echo -n "Checking outfile diff   : "
diff ft_stack.out std_stack.out

if (( $? == 1 ))
then
	echo -e "\033[1;31mFailed ! ft_stack.out and std_stack.out are different.\033[m"
else
	echo -e "\033[1;32mSuccess !\033[m"
fi
