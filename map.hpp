#ifndef MAP_HPP
# define MAP_HPP

#include "tools.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> >>
	class map {
		public:
			/* Typedefs */
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef std::pair<const key_type, mapped_type>	value_type;
			typedef	Compare									key_compare;
			typedef 
			/* End Typedefs */

		public:
		template <class Key, class T, class Compare, class Alloc>
class map<Key,T,Compare,Alloc>::value_compare
{   // in C++98, it is required to inherit binary_function<value_type,value_type,bool>
  friend class map;
protected:
  Compare comp;
  value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
public:
  typedef bool result_type;
  typedef value_type first_argument_type;
  typedef value_type second_argument_type;
  bool operator() (const value_type& x, const value_type& y) const
  {
    return comp(x.first, y.first);
  }
}

		private:
	};
}
#endif
