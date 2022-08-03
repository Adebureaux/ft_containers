#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "utility.hpp"
#include "vector.hpp"
#include "map.hpp"

#ifndef STD
# define NAMESPACE std
#else
# define NAMESPACE std
#endif

using namespace NAMESPACE;

int main(void)
{
  map<char,int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;


  map<char, int>::const_iterator tmp = foo.begin(); //tmp iterates through foo
  map<char, int>::const_iterator tmp2 = bar.begin(); //tmp2 iterates through bar

  swap(bar, foo); //tmp iterates through bar
				//tmp2 iterates through foo


  map<char, int>	other;

  other['1'] = 73;
  other['2'] = 173;
  other['3'] = 763;
  other['4'] = 73854;
  other['5'] = 74683;
  other['6'] = 753;

  map<char, int>::const_iterator tmp3 = other.begin(); // tmp3 iterates through other

	while(tmp != bar.end())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp++;
	}
	tmp--;

	while(tmp2 != foo.end())
	{
		std::cout << tmp2->first << " => " << tmp2->second << '\n';
		tmp2++;
	}
	tmp2--;

	int i = 0;
	while(tmp != bar.begin())
	{
		std::cout << tmp->first << " => " << tmp->second << '\n';
		tmp--;
		if (i++ > 10)
			break;
	}
	std::cout << tmp->first << " => " << tmp->second << '\n';
	(void)tmp3;
}
