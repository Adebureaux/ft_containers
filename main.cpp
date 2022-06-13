#include <string>
#include <vector>
#include <iostream>
#include "vector.hpp"

int main(void) {
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		typedef std::vector<int>::iterator iter_type;
		iter_type from (myvector.begin());
		iter_type until (myvector.end());
		std::reverse_iterator<iter_type> rev_until (from);
		std::reverse_iterator<iter_type> rev_from (until);
		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);
		typedef ft::vector<int>::iterator iter_type;
		iter_type from (myvector.begin());
		iter_type until (myvector.end());
		ft::reverse_iterator<iter_type> rev_until (from);
		ft::reverse_iterator<iter_type> rev_from (until);
		std::cout << "myvector:";
		while (rev_from != rev_until)
			std::cout << ' ' << *rev_from++;
		std::cout << '\n';
	}
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_it;

		rev_it = 3 + myvector.rbegin();

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	}
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_it;

		rev_it = 3 + myvector.rbegin();

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	}
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) 
			myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
	}
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) 
			myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
	}
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		rev_iterator += 2;

		std::cout << "The third element from the end is: " << *rev_iterator << '\n';
	}
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

		rev_iterator += 2;

		std::cout << "The third element from the end is: " << *rev_iterator << '\n';
	}
	
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef std::vector<int>::iterator iter_type;

		std::reverse_iterator<iter_type> rev_it;

		rev_it = myvector.rbegin() +3;

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	}
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

		typedef ft::vector<int>::iterator iter_type;

		ft::reverse_iterator<iter_type> rev_it;

		rev_it = myvector.rbegin() +3;

		std::cout << "The fourth element from the end is: " << *rev_it << '\n';
	}
	{
		std::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		std::reverse_iterator<std::vector<int>::iterator> from,until;

		from = myvector.rbegin();
		until = myvector.rend();

		std::cout << "myvector has " << (until-from) << " elements.\n";
		std::cout << "myvector has " << (until-until) << " elements.\n";
		std::cout << "myvector has " << *(5 + from) << " elements.\n";
	}
	{
		ft::vector<int> myvector;
		for (int i=0; i<10; i++) myvector.push_back(i);

		ft::reverse_iterator<ft::vector<int>::iterator> from,until;

		from = myvector.rbegin();
		until = myvector.rend();

		std::cout << "myvector has " << (until-from) << " elements.\n";
		std::cout << "myvector has " << (until-until) << " elements.\n";
		std::cout << "myvector has " << *(5 + from) << " elements.\n";
	}
	{
		std::vector<int> intvec;
		std::vector<long long> longvec;
		std::vector<double> doublevec;
		std::vector<char> charvec;
		std::cout << "max size = " << intvec.max_size() << "\n";
		std::cout << "max size = " << longvec.max_size() << "\n";
		std::cout << "max size = " << doublevec.max_size() << "\n";
		std::cout << "max size = " << charvec.max_size() << "\n";
	}
	{
		ft::vector<int> intvec;
		ft::vector<long> longvec;
		ft::vector<double> doublevec;
		ft::vector<char> charvec;
		std::cout << "max size = " << intvec.max_size() << "\n";
		std::cout << "max size = " << longvec.max_size() << "\n";
		std::cout << "max size = " << doublevec.max_size() << "\n";
		std::cout << "max size = " << charvec.max_size() << "\n";
	}
	{
		std::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);
	
		std::cout << "size of vector is " << myvector.size() << std::endl;
		std::cout << "capacity of vector is " << myvector.capacity() << std::endl;

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		std::cout << "myvector contains:";
		for (unsigned long i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		std::cout << "size of vector is " << myvector.size() << std::endl;
		std::cout << "capacity of vector is " << myvector.capacity() << std::endl;
	}
	std::cout << std::endl;
	{
		ft::vector<int> myvector;

		// set some initial content:
		for (int i=1;i<10;i++) myvector.push_back(i);

		std::cout << "size of vector is " << myvector.size() << std::endl;
		std::cout << "capacity of vector is " << myvector.capacity() << std::endl;

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		std::cout << "myvector contains:";
		for (unsigned long i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
		std::cout << "size of vector is " << myvector.size() << std::endl;
		std::cout << "capacity of vector is " << myvector.capacity() << std::endl;
	}
	std::cout << std::endl;
	{
		std::vector<int> a;
		a.resize(100);
		std::cout << "size of vector is " << a.size() << std::endl;
		std::cout << "capacity of vector is " << a.capacity() << std::endl;
	}
	{
		ft::vector<int> a;
		a.resize(100);
		std::cout << "size of vector is " << a.size() << std::endl;
		std::cout << "capacity of vector is " << a.capacity() << std::endl;
	}
	{
		std::vector<int> a;
		a.push_back(5);
		std::cout << "size of vector is " << a.size() << std::endl;
		std::cout << "capacity of vector is " << a.capacity() << std::endl;
	}
	{
		ft::vector<int> a;
		a.push_back(5);
		std::cout << "size of vector is " << a.size() << std::endl;
		std::cout << "capacity of vector is " << a.capacity() << std::endl;
	}
	{
		std::vector<int> a;
		a.push_back(5);
		std::cout << a.empty() << std::endl;
	}
	{
		ft::vector<int> a;
		a.push_back(5);
		std::cout << a.empty() << std::endl;
	}
	return (0);	
}
