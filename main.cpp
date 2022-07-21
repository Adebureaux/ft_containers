#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "vector.hpp"
#include "map.hpp"

#define LOC ft

class test {
	private:
		int x;
		int y;
};

int main(void)
{
	LOC::pair <std::string,double> pair("salut", 2.99);
	std::cout << pair.first << std::endl;
	LOC::map<int, int*> bst;
	int* tab = new int[1000];
	for (int i = 0; i < 1000; i++)
		bst.insert(std::pair<int, int*>(i % 10, tab));
	delete[] tab;
	bst.prettyPrint();
	return (0);
}
