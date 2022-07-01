#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	ft::vector<int> myvector;
	for (int i=0; i<=10; i++)
		myvector.push_back(i);
	ft::vector<int>::iterator it = myvector.erase(myvector.begin(), myvector.begin() + 2);
	std::cout << *it << std::endl;
	std::cout << myvector.size() << " " << myvector.capacity() << std::endl;
	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	return (0);
}
