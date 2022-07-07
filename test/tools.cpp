#include <vector>
#include <string>
#include <iostream>
#include "../tools.hpp"

#ifndef LOC
# define LOC ft
#endif

bool mycomp(char c1, char c2) {
	return (std::tolower(c1) < std::tolower(c2));
}

int main(void)
{
	char arr1[]= "Apple";
	char arr2[]= "Applee";
	std::cout << std::boolalpha;
	std::cout << LOC::lexicographical_compare(arr1, arr1 + 5, arr2, arr2 + 5) << std::endl;
	std::cout << LOC::lexicographical_compare(arr1, arr1 + 5, arr2, arr2 + 5, mycomp) << std::endl;
	return (0);
}
