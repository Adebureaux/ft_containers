#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include "../stack.hpp"

#ifndef LOC
# define LOC ft
#endif

int main(void)
{
	std::deque<int> deq(3, 100);
	LOC::vector<int> vct(2, 200);
	LOC::stack<int> first;
	LOC::stack<int, std::deque<int> > second(deq);
	LOC::stack<int, LOC::vector<int> > third;
	LOC::stack<int, LOC::vector<int> > fourth(vct);
	std::cout << "size of first: " << first.size() << std::endl;
	std::cout << "size of second: " << second.size() << std::endl;
	std::cout << "size of third: " << third.size() << std::endl;
	std::cout << "size of fourth: " << fourth.size() << std::endl;
	for (int i = 0; i < 5; ++i)
		first.push(i);
	std::cout << "Popping out elements...";
	while (!first.empty()) {
		std::cout << ' ' << first.top();
		first.pop();
	}
	std::cout << std::endl;
	LOC::vector<std::string> huge(1000, "HUGE!");
	LOC::stack<std::string, LOC::vector<std::string> > fifth(huge);
	std::cout << "size of fifth: " << fifth.size() << std::endl;
	huge.push_back("Hello");
	std::cout << "size of fifth: " << fifth.size() << std::endl;
	fifth.push("Hey");
	LOC::stack<std::string, LOC::vector<std::string> > fifth_cpy(huge);
	std::cout << (fifth == fifth_cpy) << std::endl;
	std::cout << (fifth != fifth_cpy) << std::endl;
	std::cout << (fifth < fifth_cpy) << std::endl;
	std::cout << (fifth <= fifth_cpy) << std::endl;
	std::cout << (fifth > fifth_cpy) << std::endl;
	std::cout << (fifth >= fifth_cpy) << std::endl;
	std::cout << (third == fourth) << std::endl;
	std::cout << (third != fourth) << std::endl;
	std::cout << (third < fourth) << std::endl;
	std::cout << (third <= fourth) << std::endl;
	std::cout << (third > fourth) << std::endl;
	std::cout << (third >= fourth) << std::endl;
	return (0);
}
