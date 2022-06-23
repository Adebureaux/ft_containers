#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	{
		std::vector<int> myvector;
		for (int i=1; i<=10; i++) myvector.push_back(i);
		std::vector<int>::iterator itr = myvector.erase(myvector.end() - 1);
		std::cout << *itr << std::endl;
		// myvector.erase(myvector.begin(),myvector.begin()+3);
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	{
		ft::vector<int> myvector;
		for (int i=1; i<=10; i++) myvector.push_back(i);
		ft::vector<int>::iterator itr = myvector.erase(myvector.end() - 1);
		std::cout << *itr << std::endl;
		// myvector.erase(myvector.begin(),myvector.begin()+3);
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	}
	return (0);
}
