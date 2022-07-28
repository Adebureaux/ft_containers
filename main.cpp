#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "utility.hpp"
#include "vector.hpp"
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
	LOC::map<std::string, double>::iterator ite = bst.end();
	for (LOC::map<std::string, double>::iterator it = bst.begin(); it != ite; it++)
	{
		std::cout << it->first << ':'
				<< it->second
				<< std::endl;
	}
	// LOC::map<std::string, double>::const_iterator itr(bst.end());
	// LOC::map<std::string, double>::iterator it(bst.begin());
	// LOC::map<std::string, double> map(it, bst.end());
	// LOC::map<std::string, double>::const_iterator tmp;
	// tmp = map.insert(map.begin(), LOC::pair<std::string, double>("P", 558));
	// std::cout << tmp->first << ":" << tmp->second << std::endl;
	// tmp = map.insert(map.begin(), LOC::pair<std::string, double>("X", 91));
	// std::cout << tmp->first << ":" << tmp->second << std::endl;
	// LOC::pair<LOC::map<std::string, double>::iterator, bool> pair = map.insert(LOC::pair<std::string, double>("ABC", 12));
	// std::cout << pair.first->first << ":" << pair.second << std::endl;
	// pair = map.insert(LOC::pair<std::string, double>("ABC", 12));
	// std::cout << pair.first->first << ":" << pair.second << std::endl;
	// bst.prettyPrint();
	LOC::map<double, int> int_map;
	int_map.insert(LOC::pair<int, int>(10, 12));
	LOC::map<double, int>::iterator int_itr(int_map.end());
	int_itr--;
	std::cout << int_itr->first << " " << int_itr->second << std::endl;
	return (0);
}
