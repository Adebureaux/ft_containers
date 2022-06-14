#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	ft::vector<int> a(100, 100);
	ft::vector<int> b(a.begin(), a.end());
	std::cout << b.size() << std::endl;
	ft::vector<int> c(a.rbegin(), a.rend());
	std::cout << c.size() << std::endl;
	return (0);
}
