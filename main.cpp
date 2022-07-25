#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "vector.hpp"
#include "tools.hpp"
#include "map.hpp"

#define LOC ft

int main(void)
{
	LOC::map<std::string, double> bst;
	bst.insert(LOC::pair<std::string, double>("P", 1));
	bst.insert(LOC::pair<std::string, double>("D", 2));
	bst.insert(LOC::pair<std::string, double>("Q", 3));
	bst.insert(LOC::pair<std::string, double>("C", 4));
	bst.insert(LOC::pair<std::string, double>("N", 5));
	bst.insert(LOC::pair<std::string, double>("K", 5));
	bst.insert(LOC::pair<std::string, double>("A", 5));
	bst.insert(LOC::pair<std::string, double>("P", 5));
	LOC::map<std::string, double>::iterator it;
	LOC::map<std::string, double>::iterator ite(bst.end()); // should create a node past the end of the leftmost node
	std::cout << ite->first << std::endl; // Not the last element
	for (it = bst.begin(); it != bst.end(); it++)
	{
		std::cout << it->first
				<< ':'
				<< it->second
				<< std::endl;
	}
	// bst.prettyPrint();
	return (0);
}
