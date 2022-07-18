#ifndef MAP_HPP
# define MAP_HPP

#include "tools.hpp"

namespace ft {
template < class Key, class T, class Compare = less<Key>, class Alloc = allocator<pair<const Key,T> >>
	class map {
		public:
			/* Typedefs */
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef T&												reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef pointer 										iterator;
			typedef const_pointer 									const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef	size_t											size_type;
			/* End Typedefs */

		protected:

		private:
	};
}
#endif
