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
	LOC::map<std::string, double>::iterator ite(bst.end());
	for (LOC::map<std::string, double>::iterator it = bst.begin(); it != ite; it++)
	{
		std::cout << it->first
				<< ':'
				<< it->second
				<< std::endl;
	}
	LOC::map<std::string, double>::const_iterator itr(bst.end());
	LOC::map<std::string, double>::iterator it(bst.begin());
	return (0);
}
