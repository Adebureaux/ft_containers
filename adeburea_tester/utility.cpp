#include <string>
#include <iostream>
#include "../utility.hpp"

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
	{
		LOC::pair<int, char> foo(10, 'z');
		LOC::pair<int, char> bar(90, 'a');
		if (foo == bar)
			std::cout << "foo and bar are equal" << std::endl;
		if (foo != bar)
			std::cout << "foo and bar are not equal" << std::endl;
		if (foo < bar)
			std::cout << "foo is less than bar" << std::endl;;
		if (foo > bar)
			std::cout << "foo is greater than bar" << std::endl;;
		if (foo<=bar) std::cout << "foo is less than or equal to bar" << std::endl;;
		if (foo>=bar) std::cout << "foo is greater than or equal to bar" << std::endl;;
	}
	{
		LOC::pair<std::string, char> foo("foo", 'z');
		LOC::pair<std::string, char> bar("foo", 'z');
		if (foo == bar)
			std::cout << "foo and bar are equal" << std::endl;
		if (foo != bar)
			std::cout << "foo and bar are not equal" << std::endl;
		if (foo < bar)
			std::cout << "foo is less than bar" << std::endl;
		if (foo > bar)
			std::cout << "foo is greater than bar" << std::endl;
		if (foo <= bar)
			std::cout << "foo is less than or equal to bar" << std::endl;
		if (foo >= bar)
			std::cout << "foo is greater than or equal to bar" << std::endl;
	}
	LOC::pair <int, int> foo;
	LOC::pair <int, int> bar;
	foo = LOC::make_pair (10, 20);
	bar = LOC::make_pair (10.5, 'A');
	std::cout << "foo: " << foo.first << ", " << foo.second << std::endl;
	std::cout << "bar: " << bar.first << ", " << bar.second << std::endl;
	return (0);
}
