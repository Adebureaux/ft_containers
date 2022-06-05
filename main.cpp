#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void)
{
	/* std::vector */
	{
		std::vector<std::string> vec;
		vec.push_back("1");
		vec.push_back("2");
		std::vector<std::string>::iterator it1 = vec.begin();
		std::vector<std::string>::iterator it2;
		it2 = it1;
		std::cout << &it1 << " | " << &it2 << std::endl;
		std::cout << *it1 << " | " << *it2 << std::endl;

		std::vector<std::string>::iterator it3 = vec.begin();
		std::vector<std::string>::iterator it4(it3);
		std::cout << &it3 << " | " << &it4 << std::endl;
		std::cout << *it3 << " | " << *it4 << std::endl;
	}
	std::cout << std::endl;
	/* ft::vector */
	{
		ft::vector<std::string> vec;
		vec.push_back("1");
		vec.push_back("2");
		ft::vector<std::string>::iterator it1 = vec.begin();
		ft::vector<std::string>::iterator it2;
		it2 = it1;
		std::cout << &it1 << " | " << &it2 << std::endl;
		std::cout << *it1 << " | " << *it2 << std::endl;

		ft::vector<std::string>::iterator it3 = vec.begin();
		ft::vector<std::string>::iterator it4(it3);
		std::cout << &it3 << " | " << &it4 << std::endl;
		std::cout << *it3 << " | " << *it4 << std::endl;
	}
	return (0);	
}
