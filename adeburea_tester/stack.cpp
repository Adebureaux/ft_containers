#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include "../stack.hpp"

#ifndef LOC
# define LOC ft
#endif

template <class T>
void verify(LOC::stack<T>& stack, std::string what) {
	std::cout << "STACK TEST " << what << " SIZE = " << stack.size() << " CAPACITY = " << stack.capacity() << std::endl;
	typename LOC::stack<T>::iterator it = stack.begin();
	while (it < stack.end())
	{
		std::cout << *it++;
		if (it != stack.end())
			std::cout << ' ';
	}
	std::cout << std::endl;
}

int main(void)
{
	std::deque<int> deq(3, 100);
	LOC::vector<int> vct(2, 200);

	LOC::stack<int>first;
	LOC::stack<int, std::deque<int> >second(deq);
	LOC::stack<int, LOC::vector<int> >third;
	LOC::stack<int, LOC::vector<int> >fourth (vct);

	std::cout << "size of first: " << first.size() << std::endl;
	std::cout << "size of second: " << second.size() << std::endl;
	std::cout << "size of third: " << third.size() << std::endl;
	std::cout << "size of fourth: " << fourth.size() << std::endl;
	return (0);
}
