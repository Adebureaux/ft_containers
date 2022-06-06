#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include <cstdio>
#include <cstddef>
#include <memory>

namespace ft {
	template <class T>
	class vector_iterator {
		public:
			/* Typedefs */
			typedef T												value_type;
			typedef T&												reference;
			typedef T*												pointer;
			typedef std::ptrdiff_t									difference_type;
			typedef	size_t											size_type;
			/* End Typedefs */

			/* Constructors */
			vector_iterator() : _itr(NULL) {};
			vector_iterator(pointer itr) : _itr(itr) {};
			/* End Constructors */

			/* Operator overload */
			bool operator==(const vector_iterator &rhs) const {
				return (_itr == rhs._itr ? true : false);
			};
			bool operator!=(const vector_iterator &rhs) const {
				return (_itr != rhs._itr ? true : false);
			};
			vector_iterator& operator++() {
				_itr++;
				return (*this); 
			};
			vector_iterator operator++(int) {
				vector_iterator tmp = *this;
				++*this;
				return (tmp);
			};
			bool operator<(const vector_iterator &rhs) const {
				return (_itr < rhs._itr ? true : false);
			};
			bool operator>(const vector_iterator &rhs) const {
				return (_itr > rhs._itr ? true : false);
			};
			reference operator*() {
				return (*_itr);
			}
			pointer operator->() {
				return (_itr);
			}
			/* End Operator overload */

		protected:
			pointer _itr;
	};
}
#endif
