#include <vector>
#include <iostream>
#include "../vector.hpp"

#ifndef LOC
# define LOC ft
#endif

int main(void)
{
	LOC::vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	typedef LOC::vector<int>::iterator iter_type;
	iter_type from (a.begin());
	iter_type until (a.end());
	LOC::reverse_iterator<iter_type> rev_until (from);
	LOC::reverse_iterator<iter_type> rev_from (until);
	while (rev_from != rev_until)
		std::cout << *rev_from++ << ' ';
	std::cout << std::endl;
	LOC::reverse_iterator<iter_type> rev_it;
	rev_it = 3 + a.rbegin();
	std::cout << *rev_it << std::endl;
	std::cout << rev_it[3] << std::endl;
	rev_it += 2;
	std::cout << *rev_it << std::endl;
	LOC::reverse_iterator<iter_type> rfrom, runtil;
	rfrom = a.rbegin();
	runtil = a.rend();
	std::cout << (runtil-rfrom) << std::endl;
	std::cout << (runtil-runtil) << std::endl;
	std::cout << *(5 + rfrom) << std::endl;
	LOC::vector<int> intvec;
	LOC::vector<long long> longvec;
	LOC::vector<double> doublevec;
	LOC::vector<char> charvec;
	std::cout << intvec.max_size() << std::endl;
	std::cout << longvec.max_size() << std::endl;
	std::cout << doublevec.max_size() << std::endl;
	std::cout << charvec.max_size() << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	a.resize(5);
	a.resize(8,100);
	a.resize(12);
	for (unsigned long i = 0; i < a.size(); i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;;
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	std::cout << a.empty() << std::endl;
	try {
		LOC::vector<int> b(-1);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		LOC::vector<int> b;
		b.resize(-1);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		LOC::vector<int> b;
		b.reserve(-1);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	LOC::vector<int>::size_type sz;
	LOC::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:"  << std::endl;;
	for (int i = 0; i < 100; i++) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << std::endl;
		}
	}
	LOC::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	std::cout << "making bar grow:" << std::endl;
	for (int i = 0; i < 100; i++) {
		bar.push_back(i);
		if (sz != bar.capacity()) {
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << std::endl;
		}
	}
	try {
		a.at(-1);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	try {
		a.at(a.size());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	LOC::vector<int> b(a.rbegin(), a.rend());
	iter_type start(b.begin());
	while (start != b.end())
		std::cout << *start++ << ' ';
	std::cout << std::endl;
	try {
		LOC::vector<int> b(a.rend(), a.rbegin());
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
