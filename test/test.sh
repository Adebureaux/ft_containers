#!/bin/sh

cd test
echo "Compiling test with ft::vector"
c++ -std=c++98 -Wall -Wextra -Werror vector.cpp -o ft_vector
echo "Compiling test with std::vector"
c++ -DLOC=std -std=c++98 -Wall -Wextra -Werror vector.cpp -o std_vector

valgrind -q ./ft_vector > ft_vector.txt 2> ft_vector_err.log
./std_vector > std_vector.txt 2> std_vector_err.log

echo "Checking diff"
diff ft_vector.txt std_vector.txt

if [[ $? == 1 ]]  
then
	echo -e "\033[1;31mfailed !\033[m"
else
	echo -e "\033[1;32mSuccess !\033[m"
fi

rm -rf ft_vector std_vector
