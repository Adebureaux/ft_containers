#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <list>
#include "vector.hpp"

#define TESTED_TYPE std::string

void    checkErase(ft::vector<TESTED_TYPE> const &vct,
                                        ft::vector<TESTED_TYPE>::iterator const &it)
{
        static int i = 0;
        std::cout << "[" << i++ << "] " << "erase: " << it - vct.begin() << std::endl;
        std::cout << vct.size() << " " << vct.capacity() << std::endl;
}

int             main(void)
{
        ft::vector<TESTED_TYPE> vct(10);

        for (unsigned long int i = 0; i < vct.size(); ++i)
                vct[i] = std::string((vct.size() - i), i + 65);
        std::cout << vct.size() << " " << vct.capacity() << std::endl;

        checkErase(vct, vct.erase(vct.begin() + 2));

        checkErase(vct, vct.erase(vct.begin()));
        checkErase(vct, vct.erase(vct.end() - 1));

        checkErase(vct, vct.erase(vct.begin(), vct.begin() + 3));
        checkErase(vct, vct.erase(vct.end() - 3, vct.end() - 1));

        vct.push_back("Hello");
        vct.push_back("Hi there");
        std::cout << vct.size() << " " << vct.capacity() << std::endl;
        checkErase(vct, vct.erase(vct.end() - 3, vct.end()));

        vct.push_back("ONE");
        vct.push_back("TWO");
        vct.push_back("THREE");
        vct.push_back("FOUR");
        std::cout << vct.size() << " " << vct.capacity() << std::endl;
        checkErase(vct, vct.erase(vct.begin(), vct.end()));

        return (0);
}
