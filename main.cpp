#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	ft::vector<int> myvector;
	for (int i=0; i<=10; i++)
		myvector.push_back(i);
	// ft::vector<int> f(2, 400);
	// myvector.insert(myvector.begin(), f.begin(), f.end());
	// myvector.reserve(100);
	myvector.insert(myvector.begin(), 1, 2);
	std::cout << myvector.size() << " " << myvector.capacity() << std::endl;
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	return (0);
}
