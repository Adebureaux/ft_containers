#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	std::vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	a.resize(5);
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	return (0);
}
