#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void)
{
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		typedef std::vector<int>::iterator iter_type;
		iter_type from (myvector.begin());
		iter_type until (myvector.end());
		std::reverse_iterator<iter_type> rev_until (from);
		std::reverse_iterator<iter_type> rev_from (until);
		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		typedef ft::vector<int>::iterator iter_type;
		iter_type from (myvector.begin());
		iter_type until (myvector.end());
		ft::reverse_iterator<iter_type> rev_until (from);
		ft::reverse_iterator<iter_type> rev_from (until);
		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
	return (0);	
}
