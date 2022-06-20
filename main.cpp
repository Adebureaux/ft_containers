#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	{
		std::vector<int> a(1, 21);
		a.reserve(100);
		a.insert(a.begin(), 42);
		std::vector<int>::iterator it = a.begin();
		while (it != a.end())
			std::cout << *(it++) << ' ';
		std::cout << std::endl;
		std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	}
	{
		ft::vector<int> a(1, 21);
		a.reserve(100);
		a.insert(a.begin(), 42);
		ft::vector<int>::iterator it = a.begin();
		while (it != a.end())
			std::cout << *(it++) << ' ';
		std::cout << std::endl;
		std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	}
}
