#include <vector>
#include <string>
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
	LOC::vector<std::string> strvec;
	std::cout << intvec.max_size() << std::endl;
	std::cout << longvec.max_size() << std::endl;
	std::cout << doublevec.max_size() << std::endl;
	std::cout << charvec.max_size() << std::endl;
	std::cout << strvec.max_size() << std::endl;
	std::cout << a.size() << std::endl;
	std::cout << a.capacity() << std::endl;
	a.resize(5);
	a.resize(8, 100);
	a.resize(12);
	for (unsigned long i = 0; i < a.size(); i++)
		std::cout << a[i] << ' ';
	std::cout << std::endl;
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
	LOC::vector<int> baz(a.rend(), a.rend());
	LOC::vector<int> doo(a.rbegin(), a.rbegin());
	std::cout << baz.empty() << " " << doo.empty() << std::endl;
	LOC::vector<int> zoo(a.begin(), a.end());
	for (unsigned long i = 0; i < zoo.size(); i++)
		std::cout << zoo[i] << ' ';
	LOC::vector<int> paz;
	paz.push_back(78);
	paz.push_back(16);
	paz.front() -= paz.back();
	std::cout << paz.front() << std::endl;
	std::cout << paz.back() << std::endl;
	for (int i = 0; i < 3; i++)
		a.push_back(i);
	LOC::vector<int> first(7, 200);
	LOC::vector<int> second;
	LOC::vector<int> third;
	first.assign(7, 100);
	LOC::vector<int>::iterator it;
	it = first.begin() + 1;
	second.assign(it, first.end() - 1);
	int myints[] = { 1776, 7, 4 };
	third.assign(myints, myints + 3);
	std::cout << first.size() << " FIRST " << first.capacity() << std::endl;
	it = first.begin();
	while (it != first.end())
		std::cout << *it++ << " ";
	std::cout << std::endl;
	std::cout << second.size() << " SECOND " << second.capacity() << std::endl;
	it = second.begin();
	while (it != second.end())
		std::cout << *it++ << " ";
	std::cout << std::endl;
	std::cout << third.size() << " THIRD " << third.capacity() << std::endl;
	it = third.begin();
	while (it != third.end())
		std::cout << *it++ << " ";
	std::cout << std::endl;
	start = a.begin();
	while (start != a.end())
		std::cout << *start++ << ' ';
	a.resize(8, 100);
	start = a.begin();
	while (start != a.end())
		std::cout << *start++ << ' ';
	std::cout << std::endl;
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	a.resize(25);
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	a.resize(0);
	try {
		a.resize(-1);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	a.resize(25, 10);
	start = a.begin();
	while (start != a.end())
		std::cout << *start++ << ' ';
	std::cout << std::endl;
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	a.assign(28, 42);
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	start = a.begin();
	while (start < a.end())
		std::cout << *start++ << ' ';
	std::cout << std::endl;
	a.assign(start, a.end());
	start = a.begin();
	while (start - 12 < a.end())
		std::cout << *start++ << ' ';
	std::cout << std::endl;
	std::cout << "SIZE = " << a.size() << " CAPACITY = " << a.capacity() << std::endl;
	a.assign(18, 42);
	LOC::vector<int> c(100, 25);
	c = a;
	start = c.begin();
	while (start < c.end())
		std::cout << *start++ << ' ';
	std::cout << std::endl;
	std::cout << "SIZE = " << c.size() << " CAPACITY = " << c.capacity() << std::endl;
	LOC::vector<int> d(c);
	start = d.begin();
	for (unsigned long i = 0; i < d.size(); i++)
		std::cout << d[i] << ' ';
	std::cout << std::endl;
	std::cout << "SIZE = " << d.size() << " CAPACITY = " << d.capacity() << std::endl;
	LOC::vector<int> e;
	e = a;
	std::cout << "SIZE = " << e.size() << " CAPACITY = " << e.capacity() << std::endl;
	e.resize(18, 25);
	for (unsigned long i = 0; i < e.size(); i++)
		std::cout << d[i] << ' ';
	std::cout << std::endl;
	int sum = 0;
  	a.push_back(100);
  	a.push_back(200);
  	a.push_back(300);
	while (!a.empty())
	{
		sum += a.back();
		a.pop_back();
	}
	std::cout << "The elements of myvector add up to " << sum << std::endl;
}
