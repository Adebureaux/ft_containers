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
	LOC::map<char,int> mymap;
	LOC::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	std::cout << itlow->first << std::endl;
	std::cout << itup->first << std::endl;


	mymap.erase(itlow,itup);        // erases [itlow,itup)

	// print content:
	for (LOC::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	return (0);
}
