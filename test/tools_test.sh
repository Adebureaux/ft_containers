#!/bin/sh

cd test

start=`date +%s%N`
valgrind ./ft_tools > ft_tools.out 2> ft_tools_err.log
end=`date +%s%N`
ft_execution=`expr $end - $start`

start=`date +%s%N`
valgrind ./std_tools > std_tools.out 2> std_tools_err.log
end=`date +%s%N`
std_execution=`expr $end - $start`

diff=`expr $ft_execution / $std_execution`
diff=`expr $diff + 1`
echo -n "Checking time execution : "
if [[ "$diff" > "20" ]]
then
	echo -e "\033[1;31mFailed ! The execution is more than $diff times slower.\033[m"
elif [[ "$diff" == "1" ]]
then
	echo -e "\033[1;32mSuccess ! ft::tools and std::tools has the same execution time\033[m"
else
	echo -e "\033[1;32mSuccess ! The execution is $diff times slower.\033[m"
fi

echo -n "Checking outfile diff   : "
diff ft_tools.out std_tools.out

if [[ "$?" == "1" ]]
then
	echo -e "\033[1;31mFailed ! ft_tools.out and std_tools.out are different.\033[m"
else
	echo -e "\033[1;32mSuccess !\033[m"
fi
