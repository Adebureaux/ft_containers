#include <map>
#include <list>
#include <string>
#include <iostream>
#include "../map.hpp"

#ifndef LOC
# define LOC ft
#endif

template <class Key, class T>
void verify(LOC::map<Key, T>& map, std::string what) {
	std::cout << "MAP TEST " << what << " SIZE = " << map.size() << std::endl;
	typename LOC::map<Key, T>::iterator it;

	for (it = map.begin(); it != map.end(); it++)
	{
		std::cout << it->first
				<< ':'
				<< it->second
				<< std::endl;
	}
}

int main(void)
{
	LOC::pair<std::string, double> pr("PI", 3.14);
	LOC::map<std::string, double> bst;
	bst.insert(pr);
	bst.insert(LOC::pair<std::string, double>("P", 1));
	bst.insert(LOC::pair<std::string, double>("D", 2));
	bst.insert(LOC::pair<std::string, double>("Q", 3));
	bst.insert(LOC::pair<std::string, double>("C", 4));
	bst.insert(LOC::pair<std::string, double>("N", 5));
	bst.insert(LOC::pair<std::string, double>("K", 5));
	bst.insert(LOC::pair<std::string, double>("A", 5));
	bst.insert(LOC::pair<std::string, double>("P", 5));
	LOC::map<std::string, double>::iterator it = bst.insert(bst.begin(), LOC::pair<std::string, double>("*", 42));
	verify<std::string, double>(bst, "INSERT 1");
	LOC::map<std::string, double>::iterator ite(bst.end());
	std::cout << (--ite)->first << ":" << ite->second << std::endl;
	ite--;
	std::cout << ite->first << ":" << ite->second << std::endl;
	ite++;
	ite++;
	ite++;
	std::cout << ite->first << ":" << ite->second << std::endl;
	it =  bst.begin();
  	bst.insert(it, LOC::pair<std::string, double>("+", 300));
  	bst.insert(it, LOC::pair<std::string, double>("-", 400));
	verify(bst, "INSERT 2");
	LOC::map<std::string, double> map;
	map.insert(bst.begin(), bst.find("-"));
	verify(map, "CONSTRUCTOR 1");
	LOC::map<std::string, double> map_copy(map.begin(), map.end());
	verify(map_copy, "CONSTRUCTOR 2");
	LOC::map<std::string, double>::const_iterator tmp;
	tmp = map.insert(map.begin(), LOC::pair<std::string, double>("P", 558));
	std::cout << tmp->first << ":" << tmp->second << std::endl;
	tmp = map.insert(map.begin(), LOC::pair<std::string, double>("X", 91));
	std::cout << tmp->first << ":" << tmp->second << std::endl;
	LOC::map<std::string, double>::const_iterator it1 = map.begin(), it2 = map.end();
	std::cout << it1->first << ":" << it1->second << std::endl;
	it2--;
	std::cout << it2->first << ":" << it2->second << std::endl;
	tmp = map.insert(map.begin(), LOC::pair<std::string, double>("P", 558));
	std::cout << tmp->first << ":" << tmp->second << std::endl;
	tmp = map.insert(map.end(), LOC::pair<std::string, double>("X", 91));
	std::cout << tmp->first << ":" << tmp->second << std::endl;
	LOC::map<int, int> int_map;
	int_map.insert(LOC::pair<int, int>(12, 42));
	LOC::map<int, int>::iterator int_itr(int_map.end());
	int_itr--;
	std::cout << int_itr->first << " " << int_itr->second << std::endl;
	typedef LOC::map<int, std::string>::value_type VAL;
	std::list<VAL> lst;
	LOC::map<int, std::string>::iterator mpit;
	lst.push_back(VAL(42, "lol"));
	lst.push_back(VAL(50, "mdr"));
	lst.push_back(VAL(35, "funny"));
	lst.push_back(VAL(45, "bunny"));
	lst.push_back(VAL(21, "fizz"));
	lst.push_back(VAL(35, "this key is already inside"));
	lst.push_back(VAL(55, "fuzzy"));
	lst.push_back(VAL(38, "buzz"));
	lst.push_back(VAL(55, "inside too"));
	LOC::map<int, std::string> mp(lst.begin(), lst.end());
	verify(mp, "CONSTRUCTOR 3");
	std::cout << mp.empty() << std::endl;
	mp.clear();
	std::cout << mp.empty() << std::endl;
	mp.clear();
	LOC::map<char, std::string> foo;
	foo['a'] = "an element";
	foo['b'] = "another element";
	foo['c'] = foo['b'];
	std::cout << "foo['a'] is " << foo['a'] << '\n';
	std::cout << "foo['b'] is " << foo['b'] << '\n';
	std::cout << "foo['c'] is " << foo['c'] << '\n';
	std::cout << "foo['d'] is " << foo['d'] << '\n';
	std::cout << "foo now contains " << foo.size() << " elements.\n";
	LOC::map<char, int> first;
	LOC::map<char, int> second;
	first['x']=8;
	first['y']=16;
	first['z']=32;
	second = first;
	first = LOC::map<char, int>();
	std::cout << "Size of first : " << first.size() << std::endl;
	std::cout << "Size of second : " << second.size() << std::endl;
	int i;
	LOC::map<int, int> baz;
	if (baz.max_size() > 1000)
	{
		for (i = 0; i < 1000; i++)
			baz[i] = 0;
		std::cout << "The map contains 1000 elements." << std::endl;
	}
	else
		std::cout << "The map could not hold 1000 elements." << std::endl;
	LOC::map<char, int> doo;
	LOC::map<char, int> roo;
	doo['x'] = 100;
	doo['y'] = 200;
	roo['a'] = 11;
	roo['b'] = 22;
	roo['c'] = 33;
	doo.swap(roo);
	verify(doo, "SWAP 1");
	verify(roo, "SWAP 2");
	LOC::map<char, int> zoo;
	LOC::map<char, int>::key_compare cmp = zoo.key_comp();
	zoo['a'] = 100;
	zoo['b'] = 200;
	zoo['c'] = 300;
	std::cout << "mymap contains:" << std::endl;
	char highest = zoo.rbegin()->first;
	LOC::map<char, int>::iterator itzoo = zoo.begin();
	do {
		std::cout << itzoo->first << " => " << itzoo->second << std::endl;
	} while (cmp((*itzoo++).first, highest));
	LOC::map<char, int> woo;
	LOC::pair<const char, int>* p;
	p = woo.get_allocator().allocate(5);
	size_t size = sizeof(LOC::map<char, int>::value_type) * 5;
	std::cout << "The allocated array has a size of " << size << " bytes." << std::endl;
	woo.get_allocator().deallocate(p, 5);
	LOC::map<int, std::string> huge;
	for (int i = 0; i < 10000; i++)
		huge.insert(LOC::pair<int, std::string>(i, "HUGE!"));
	LOC::map<char, int>::iterator find_itr;
	find_itr = roo.find('x');
	std::cout << find_itr->first << " " << find_itr->second << std::endl;
	return (0);
}
