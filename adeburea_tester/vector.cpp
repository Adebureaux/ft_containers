#include <vector>
#include <string>
#include <iostream>
#include "../vector.hpp"

#ifndef LOC
# define LOC ft
#endif

template <class T>
void verify(LOC::vector<T>& vec, std::string what) {
	std::cout << "VECTOR TEST " << what << " SIZE = " << vec.size() << " CAPACITY = " << vec.capacity() << std::endl;
	typename LOC::vector<T>::iterator it = vec.begin();
	while (it < vec.end())
	{
		std::cout << *it++;
		if (it != vec.end())
			std::cout << ' ';
	}
	std::cout << std::endl;
}

int main(void)
{
	LOC::vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	typedef LOC::vector<int>::iterator iter_type;
	iter_type from(a.begin());
	iter_type until(a.end());
	LOC::reverse_iterator<iter_type> rev_until(from);
	LOC::reverse_iterator<iter_type> rev_from(until);
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
	verify(a, "RESIZE 1");
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
	std::cout << "MAKING FOO GROW:"  << std::endl;;
	for (int i = 0; i < 100; i++) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "CAPACITY CHANGED: " << sz << std::endl;
		}
	}
	LOC::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	std::cout << "MAKING BAR GROW:" << std::endl;
	for (int i = 0; i < 100; i++) {
		bar.push_back(i);
		if (sz != bar.capacity()) {
			sz = bar.capacity();
			std::cout << "CAPACITY CHANGED: " << sz << std::endl;
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
		std::cout << *it++ << ' ';
	std::cout << std::endl;
	iter_type start = a.begin();
	while (start != a.end())
		std::cout << *start++ << ' ';
	std::cout << std::endl;
	a.resize(8, 100);
	verify(a, "RESIZE 2");
	a.resize(25);
	verify(a, "RESIZE 3");
	a.resize(0);
	verify(a, "RESIZE 4");
	try {
		a.resize(-1);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	a.resize(25, 10);
	verify(a, "RESIZE 5");
	a.assign(28, 42);
	verify(a, "ASSIGN 1");
	start = a.begin();
	a.assign(start, a.end());
	verify(a, "ASSIGN 2");
	a.assign(18, 42);
	LOC::vector<int> c(100, 25);
	c = a;
	start = c.begin();
	verify(c, "COPY CRUSH");
	LOC::vector<int> d(c);
	start = d.begin();
	verify(d, "COPY CONSTRUCTOR");
	LOC::vector<int> e;
	e = a;
	verify(e, "EQUAL");
	e.resize(18, 25);
	verify(e, "RESIZE 6");
	int sum = 0;
  	a.push_back(100);
  	a.push_back(200);
  	a.push_back(300);
	while (!a.empty())
	{
		sum += a.back();
		a.pop_back();
	}
	std::cout << "SUM OF ELEMENTS " << sum << std::endl;
	verify(e, "POP_BACK 1");
	e.insert(e.begin() + 8, 6, 14);
	iter_type itr = e.insert(e.begin() + 2, 12);
	std::cout << *itr << std::endl;
	e.reserve(100);
	verify(e, "INSERT 1");
	a = e;
	it = a.begin();
	it = a.insert(it, 200);
	a.insert(it, 2, 300);
	it = a.begin();
	LOC::vector<int> f(2, 400);
	a.insert(it + 2, f.begin(), f.end());
	verify(a, "INSERT 2");
	int arr[] = { 501, 502, 503, 500, 55 };
	a.insert(a.begin(), arr, arr + 3);
	verify(a, "INSERT 3");
	a.insert(a.end(), 34, 42);
	verify(a, "INSERT 3");
	a.insert(a.begin() + 10, 2, 22);
	verify(a, "INSERT 4");
	LOC::vector<int> g(1, 1);
	a.insert(a.begin(), g.begin(), g.begin());
	a.insert(a.begin(), g.begin(), g.end());
	a.insert(a.end(), g.end(), g.end());
	verify(a, "INSERT 5");
	for (int i = 0; i < 148; i++)
		a.insert(a.begin() + 12, i);
	verify(a, "INSERT 6");
	while (a.size() > 21)
		a.pop_back();
	verify(a, "POP_BACK 2");
	LOC::vector<int> h;
	for (int i = 0; i < 6; i++)
		h.push_back(i);
	h.reserve(100);
	h.insert(h.begin(), 3, 9);
	verify(h, "INSERT 7");
	LOC::vector<std::string> i;
	i.insert(i.begin(), "hi");
	i.insert(i.begin() + 1, 8, "hey");
	for (int j = 0; j < 20; j++)
		i.insert(i.begin(), "hello");
	verify(i, "INSERT 8");
	for (int i = 1; i <= 10; i++)
		h.push_back(i);
	itr = h.erase(h.end() - 1);
	std::cout << *itr << std::endl;
	h.erase(h.begin(), h.begin() + 3);
	verify(h, "ERASE 1");
	LOC::vector<std::string>::iterator strit = i.erase(i.begin());
	std::cout << *strit << std::endl;
	verify(i, "ERASE 2");
	strit = i.erase(i.begin() + 8, i.end());
	std::cout << *strit << std::endl;
	verify(i, "ERASE 3");
	i.push_back("foo");
	i.push_back("bar");
	i.push_back("baz");
	i.insert(i.begin(), "arr");
	strit = i.erase(i.end());
	std::cout << *strit << std::endl;
	verify(i, "ERASE 4");
	a.swap(b);
	verify(a, "SWAP 1");
	verify(b, "SWAP 2");
	LOC::vector<std::string> j(10, "abcde");
	j.swap(i);
	verify(j, "SWAP 3");
	verify(i, "SWAP 4");
	LOC::swap(i, j);
	verify(i, "SWAP 5");
	verify(j, "SWAP 6");
	j.assign(5, "coucou");
	verify(j, "ASSIGN 3");
	i.reserve(100);
	i.assign(j.begin() + 2, j.end());
	verify(i, "ASSIGN 4");
	LOC::vector<std::string> k;
	k.push_back("a");
	k.push_back("b");
	k.reserve(100);
	LOC::vector<std::string> l(k);
	k = l;
	verify(l, "STRING TEST 1");
	LOC::vector<std::string> m;
	std::string *ptr;
	ptr = m.get_allocator().allocate(5);
	for (int i = 0; i < 5; i++)
		m.get_allocator().construct(&ptr[i], "get_alloc");
	std::cout << "VECTOR TEST " << "GET_ALLOCATOR 1" << " SIZE = " << m.size() << " CAPACITY = " << m.capacity() << std::endl;
	for (size_t i = 0; i < 4; i++)
		std::cout << ptr[i] << ' ';
	std::cout << ptr[4] << std::endl;
	for (int i = 0; i < 5; i++)
		m.get_allocator().destroy(&ptr[i]);
	m.get_allocator().deallocate(ptr, 5);
	l.push_back("A");
	bool boolean = k == l;
	std::cout << std::boolalpha;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 1 : " << boolean << std::endl;
	LOC::vector<std::string> n;
	LOC::vector<std::string> o = n;
	boolean = o == n;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 2 : " << boolean << std::endl;
	boolean = k != l;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 3 : " << boolean << std::endl;
	boolean = o != n;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 4 : " << boolean << std::endl;
	boolean = o <= n;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 4 : " << boolean << std::endl;
	LOC::vector<int>fou(3, 200);
	LOC::vector<int>bou(3, 300);
	boolean = fou < bou;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 5 : " << boolean << std::endl;
	boolean = fou > bou;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 6 : " << boolean << std::endl;
	LOC::vector<std::string> p;
	for (std::string str = "a"; str <= "z"; str[0]++)
		p.push_back(str);
	LOC::vector<std::string> q(p);
	boolean = p == q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 7 : " << boolean << std::endl;
	boolean = p != q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 8 : " << boolean << std::endl;
	boolean = p < q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 9 : " << boolean << std::endl;
	boolean = p > q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 10 : " << boolean << std::endl;
	boolean = p <= q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 11 : " << boolean << std::endl;
	boolean = p >= q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 12 : " << boolean << std::endl;
	p.push_back("p");
	q.push_back("q");
	boolean = p == q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 13 : " << boolean << std::endl;
	boolean = p != q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 14 : " << boolean << std::endl;
	boolean = p < q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 15 : " << boolean << std::endl;
	boolean = p > q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 16 : " << boolean << std::endl;
	boolean = p <= q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 17 : " << boolean << std::endl;
	boolean = p >= q;
	std::cout << "VECTOR TEST RELATIONAL OPERATOR 18 : " << boolean << std::endl;
	return (0);
}
