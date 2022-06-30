#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	ft::vector<int> myvector;
	for (int i=0; i<=10; i++)
		myvector.push_back(i);
	myvector.reserve(100);
	std::cout << myvector.size() << " " << myvector.capacity() << std::endl;
	myvector._rightshift(1, 2);
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	return (0);
}
