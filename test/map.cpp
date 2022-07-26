#include <map>
#include <string>
#include <iostream>
#include "../map.hpp"

#ifndef LOC
# define LOC ft
#endif

template <class Key, class T>
void verify(LOC::map<Key, T>& map, std::string what) {
	std::cout << "MAP TEST " << what << " SIZE = " << map.size() << std::endl;
	typename LOC::map<Key, T>::iterator it;

	for (it = map.begin(); it != map.end(); it++)
	{
		std::cout << it->first
				<< ':'
				<< it->second
				<< std::endl;
	}
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
	bst.insert(LOC::pair<std::string, double>("*", 42));
	verify<std::string, double>(bst, "INSERT 1");
	LOC::map<std::string, double>::iterator ite(bst.end());
	std::cout << (--ite)->first << ":" << ite->second << std::endl;
	ite--;
	std::cout << ite->first << ":" << ite->second << std::endl;
	ite++;
	ite++;
	ite++;
	std::cout << ite->first << ":" << ite->second << std::endl;
	return (0);
}
