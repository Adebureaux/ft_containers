#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void)
{
	/* std::vector */
	{
		std::vector<int> vec;
		for (int i = 0; i < 18; i++)
		{
			std::cout << "Size = " << vec.size() << " | " << "Capacity = " << vec.capacity() << std::endl;
			vec.push_back(i);
		}
		std::vector<int>::iterator it1 = vec.begin();
		std::vector<int>::iterator it2;
		it2 = it1;
		std::cout << &it1 << " | " << &it2 << std::endl;
		std::cout << *it1 << " | " << *it2 << std::endl;

		std::vector<int>::iterator it3 = vec.begin();
		std::vector<int>::iterator it4(it3);
		std::cout << &it3 << " | " << &it4 << std::endl;
		std::cout << *it3 << " | " << *it4 << std::endl;
	}
	std::cout << std::endl;
	{
		std::vector<int> vec(250, 3);
		std::cout << "Size = " << vec.size() << " | " << "Capacity = " << vec.capacity() << std::endl;
		std::vector<int> copy(vec.begin(), vec.end());
		std::cout << "Size = " << copy.size() << " | " << "Capacity = " << copy.capacity() << std::endl;
	}
	{
		ft::vector<int> vec(250, 3);
		// std::cout << "Size = " << vec.size() << " | " << "Capacity = " << vec.capacity() << std::endl;
		ft::vector<int> copy(vec.begin(), vec.end());
		// std::cout << "Size = " << copy.size() << " | " << "Capacity = " << copy.capacity() << std::endl;
	}
	/* ft::vector */
	// {
	// 	ft::vector<std::string> vec;
	// 	vec.push_back("1");
	// 	vec.push_back("2");
	// 	ft::vector<std::string>::iterator it1 = vec.begin();
	// 	ft::vector<std::string>::iterator it2;
	// 	it2 = it1;
	// 	std::cout << &it1 << " | " << &it2 << std::endl;
	// 	std::cout << *it1 << " | " << *it2 << std::endl;

	// 	ft::vector<std::string>::iterator it3 = vec.begin();
	// 	ft::vector<std::string>::iterator it4(it3);
	// 	std::cout << &it3 << " | " << &it4 << std::endl;
	// 	std::cout << *it3 << " | " << *it4 << std::endl;
	// }
	return (0);	
}
