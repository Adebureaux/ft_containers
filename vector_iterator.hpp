#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "tools.hpp"

namespace ft {
	template <class T>
	class vector_iterator {
		public:
			/* Typedefs */
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ft::random_access_iterator_tag	iterator_category;
			/* End Typedefs */

			/* Constructors */
			vector_iterator() : _itr(0) {};
			vector_iterator(pointer itr) : _itr(itr) {};
			vector_iterator(const vector_iterator& x) { *this = x; };
			/* End Constructors */

			/* Destructor */
			~vector_iterator() {};
			/* End Destructor */
			
			/* Operator= */
			vector_iterator& operator=(const vector_iterator& x) {
				_itr = x._itr;
				return (*this);
			};
			/* End Operator= */

			/* Operator overload */
			bool operator==(const vector_iterator &rhs) const {
				return (_itr == rhs._itr ? true : false);
			};
			bool operator!=(const vector_iterator &rhs) const {
				return (_itr != rhs._itr ? true : false);
			};
			reference operator*() const {
				return (*_itr);
			};
			pointer operator->() const {
				return (_itr);
			};
			vector_iterator& operator++() {
				_itr++;
				return (*this);
			};
			vector_iterator operator++(int) {
				vector_iterator tmp = *this;
				++(*this);
				return (tmp);
			};
			vector_iterator& operator--() {
				_itr--;
				return (*this);
			};
			vector_iterator operator--(int) {
				vector_iterator tmp = *this;
				--(*this);
				return (tmp);
			};
			vector_iterator operator+(difference_type n) const {
				return (vector_iterator(_itr + n));
			};
			vector_iterator operator-(difference_type n) const {
				return (vector_iterator(_itr - n));
			};
			bool operator<(const vector_iterator& rhs) const {
				return (_itr < rhs._itr ? true : false);
			};
			bool operator>(const vector_iterator& rhs) const {
				return (_itr > rhs._itr ? true : false);
			};
			bool operator<=(const vector_iterator& rhs) const {
				return (_itr <= rhs._itr ? true : false);
			};
			bool operator>=(const vector_iterator& rhs) const {
				return (_itr >= rhs._itr ? true : false);
			};
			vector_iterator& operator+=(difference_type n) {
				_itr += rhs._itr;
				return (*this);
			};
			vector_iterator& operator-=(const vector_iterator& rhs) {
				_itr -= rhs._itr;
				return (*this);
			};
			reference operator[](size_t n) const {
				return (_itr[n]);
			};
			/* End Operator overload */
		private:
			pointer _itr;
	};
}
#endif
