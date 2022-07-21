#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "vector.hpp"
#include "map.hpp"

#define LOC ft

int main(void)
{
    LOC::map<std::string, int> bst;
	bst.insert(std::pair<std::string, int>("abc", 100));
	bst.insert(std::pair<std::string, int>("ab", 100));
    bst.prettyPrint();
    return (0);
}
