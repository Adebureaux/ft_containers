#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "vector.hpp"

int main (void) {
	{
		std::vector<std::string> a;
		for (std::string i = "a"; i <= "z"; i[0]++)
			a.push_back(i);
		std::vector<std::string> b(a);
		std::cout << std::boolalpha;
		bool boolean = a == b;
		std::cout << boolean << std::endl;
		a.push_back("a");
		b.push_back("b");
		boolean = a == b;
		std::cout << boolean << std::endl;
	}
}
