#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include "vector.hpp"

#define TESTED_TYPE int
#define TESTED_NAMESPACE std

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it(vct.begin());
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_iterator ite(vct.end());

	std::cout << *it << std::endl;

	for (int i = 1; it != ite; ++i)
		*it++ = i;
        std::cout << vct.size() << " " << vct.capacity() << std::endl;

	it = vct.begin();
	ite = vct.begin();


	return (0);
}
