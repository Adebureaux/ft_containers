#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	ft::vector<int> a;
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	a.resize(12);
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	return (0);
}
