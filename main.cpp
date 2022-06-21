#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	{
		ft::vector<int> a;
		for (int i = 0; i < 6; i++)
			a.push_back(i);
		a.reserve(100);
		a.insert(a.end() - 2, 3, 9);
		ft::vector<int>::iterator it = a.begin();
		while (it != a.end())
			std::cout << *(it++) << ' ';
		std::cout << std::endl;
		std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	}
	{
		std::vector<int> a;
		for (int i = 0; i < 6; i++)
			a.push_back(i);
		a.reserve(100);
		a.insert(a.end() - 2, 3, 9);
		std::vector<int>::iterator it = a.begin();
		while (it != a.end())
			std::cout << *(it++) << ' ';
		std::cout << std::endl;
		std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	}
}
