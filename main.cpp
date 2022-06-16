#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	ft::vector<int> a;
	a.assign(18, 42);
	ft::vector<int> c(100, 25);
	c = a;
	std::cout << "SIZE = " << c.size() << " CAPACITY = " << c.capacity() << std::endl;
	ft::vector<int>::iterator start = c.begin();
	while (start < c.end())
		std::cout << *start++ << ' ';
	std::cout << '\n';
}
