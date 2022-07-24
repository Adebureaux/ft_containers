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
	LOC::pair<std::string, double> pr("PI", 3.14);
	LOC::map<std::string, double> bst;
	bst.insert(pr);
	bst.insert(LOC::pair<std::string, double>("P", 1));
	bst.insert(LOC::pair<std::string, double>("D", 2));
	bst.insert(LOC::pair<std::string, double>("Q", 3));
	bst.insert(LOC::pair<std::string, double>("C", 4));
	bst.insert(LOC::pair<std::string, double>("N", 5));
	LOC::map<std::string, double>::iterator it(bst.begin());
	std::cout << it->first << std::endl;
	it++;
	std::cout << it->first << std::endl;
	// bst.prettyPrint();
	return (0);
}
