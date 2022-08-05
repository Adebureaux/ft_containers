#include <set>
#include <list>
#include <string>
#include <iostream>
#include "../set.hpp"

#ifndef LOC
# define LOC ft
#endif

template <class T>
void verify(LOC::set<T>& set, std::string what) {
	std::cout << "set TEST " << what << " SIZE = " << set.size() << std::endl;
	typename LOC::set<T>::iterator it;

	for (it = set.begin(); it != set.end(); it++) {
		std::cout << *it << std::endl;
	}
}

int main(void) {
	LOC::set<std::string> bst;
	bst.insert("P");
	bst.insert("D");
	bst.insert("Q");
	bst.insert("C");
	bst.insert("N");
	bst.insert("K");
	bst.insert("A");
	bst.insert("P");
	LOC::set<std::string>::iterator it = bst.insert(bst.begin(), "*");
	verify<std::string>(bst, "INSERT 1");
	LOC::set<std::string>::iterator ite(bst.end());
	std::cout << *(--ite) << std::endl;
	ite--;
	std::cout << *ite << std::endl;
	ite++;
	ite++;
	ite++;
	std::cout << *ite << std::endl;
	it = bst.begin();
  	bst.insert(it, "+");
  	bst.insert(it, "-");
	verify(bst, "INSERT 2");
	LOC::set<std::string> set;
	set.insert(bst.begin(), bst.find("-"));
	verify(set, "CONSTRUCTOR 1");
	LOC::set<std::string> set_copy(set.begin(), set.end());
	verify(set_copy, "CONSTRUCTOR 2");
	LOC::set<std::string>::const_iterator tmp;
	tmp = set.insert(set.begin(), "P");
	std::cout << *tmp << std::endl;
	tmp = set.insert(set.begin(), "X");
	std::cout << *tmp << std::endl;
	LOC::set<std::string>::const_iterator it1 = set.begin(), it2 = set.end();
	std::cout << *it1 << std::endl;
	it2--;
	std::cout << *it2 << std::endl;
	tmp = set.insert(set.begin(), "P");
	std::cout << *tmp << std::endl;
	tmp = set.insert(set.end(), "X");
	std::cout << *tmp << std::endl;
	LOC::set<int> int_set;
	int_set.insert(12);
	LOC::set<int>::iterator int_itr(int_set.end());
	int_itr--;
	std::cout << *int_itr << std::endl;
	std::list<int> lst;
	LOC::set<int>::iterator mpit;
	lst.push_back(42);
	lst.push_back(50);
	lst.push_back(35);
	lst.push_back(45);
	lst.push_back(21);
	lst.push_back(35);
	lst.push_back(55);
	lst.push_back(38);
	lst.push_back(55);
	LOC::set<int> mp(lst.begin(), lst.end());
	verify(mp, "CONSTRUCTOR 3");
	std::cout << mp.empty() << std::endl;
	mp.clear();
	std::cout << mp.empty() << std::endl;
	mp.clear();
	LOC::set<char> foo;
	std::cout << "foo now contains " << foo.size() << " elements.\n";
	LOC::set<char> first;
	LOC::set<char> second;
	first.insert('x');
	first.insert('y');
	first.insert('z');
	second = first;
	first = LOC::set<char>();
	std::cout << "Size of first : " << first.size() << std::endl;
	std::cout << "Size of second : " << second.size() << std::endl;
	int i;
	LOC::set<int> baz;
	if (baz.max_size() > 1000) {
		for (i = 0; i < 1000; i++)
			baz.insert(i);
		std::cout << "The set contains 1000 elements." << std::endl;
	}
	else
		std::cout << "The set could not hold 1000 elements." << std::endl;
	LOC::set<int> doo;
	LOC::set<int> roo;
	doo.insert(9);
	doo.insert(10);
	roo.insert(21);
	roo.insert(42);
	roo.insert(88);
	roo.insert(88);
	doo.swap(roo);
	verify(doo, "SWAP 1");
	verify(roo, "SWAP 2");
	LOC::set<int> zoo;
	LOC::set<int>::key_compare cmp = zoo.key_comp();
	zoo.insert(21);
	zoo.insert(74);
	zoo.insert(42);
	std::cout << "myset contains:" << std::endl;
	int highest = *zoo.rbegin();
	LOC::set<int>::iterator itzoo = zoo.begin();
	do {
		std::cout << *itzoo << std::endl;
	} while (cmp((*itzoo++), highest));
	LOC::set<std::string> huge;
	for (int i = 0; i < 10000; i++)
		huge.insert("HUGE!");
	LOC::set<int>::iterator find_itr;
	find_itr = zoo.find(42);
	std::cout << *find_itr << std::endl;
	zoo.clear();
	return (0);
}
