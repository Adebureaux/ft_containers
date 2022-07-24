#include <map>
#include <string>
#include <iostream>
#include "../map.hpp"

#ifndef LOC
# define LOC ft
#endif

template <class Key, class T>
void verify(LOC::map<Key, T>& vec, std::string what) {
	std::cout << "MAP TEST " << what << " SIZE = " << vec.size() << std::endl;
	typename LOC::map<Key, T>::iterator it = vec.begin();
	while (it != vec.end())
	{
		it++;
		std::cout << it->first;
		if (it != vec.end())
			std::cout << ' ';
	}
	std::cout << std::endl;
}

int main(void)
{
	LOC::pair<std::string, double> pr("PI", 3.14);
	LOC::map<std::string, double> bst;
	bst.insert(pr);
	bst.insert(LOC::pair<std::string, double>("P", 1));
	bst.insert(LOC::pair<std::string, double>("D", 2));
	bst.insert(LOC::pair<std::string, double>("Q", 3));
	bst.insert(LOC::pair<std::string, double>("C", 4));
	bst.insert(LOC::pair<std::string, double>("N", 5));
	bst.insert(LOC::pair<std::string, double>("K", 5));
	bst.insert(LOC::pair<std::string, double>("A", 5));
	bst.insert(LOC::pair<std::string, double>("P", 5));
	verify<std::string, double>(bst, "INSERT 1");
	return (0);
}
