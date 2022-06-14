#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	std::vector<int> a(100, 100);
	std::vector<int> b(a.begin(), a.end());
	std::cout << b.size() << std::endl;
	std::vector<int> c(a.rbegin(), a.rend());
	std::cout << c.size() << std::endl;
	return (0);
}
