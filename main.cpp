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
	LOC::map<char, int> first;
	LOC::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second = first;
	first = LOC::map<char,int>();

	std::cout << "Size of first : " << first.size() << std::endl;
	std::cout << "Size of second : " << second.size() << std::endl;
	return (0);
}
