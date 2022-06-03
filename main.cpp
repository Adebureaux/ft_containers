#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void)
{
	/* std::vector */
	{
		std::vector<std::string> vec(10, "test");
		std::vector<std::string>::iterator it = vec.begin();
		while (it < vec.end())
			std::cout << *it++ << std::endl;
	}
	std::cout << std::endl;
	/* ft::vector */
	{
		ft::vector<std::string> vec(10, "test");
		ft::vector<std::string>::iterator it = vec.begin();
		while (it < vec.end())
			std::cout << *it++ << std::endl;
	}
	return (0);	
}
