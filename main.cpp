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
	LOC::map<std::string, double>::iterator it(bst.begin());
	std::cout << it->first << std::endl;
	// bst.prettyPrint();
	return (0);
}
