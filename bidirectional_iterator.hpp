#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

#include "tools.hpp"

namespace ft {
	template <class T, bool Const>
	class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>{
		public:
			/* Typedefs */
			typedef std::ptrdiff_t										difference_type;
			typedef typename ft::conditional<Const, const T, T>::type	value_type;
			typedef value_type*											pointer;
			typedef value_type&											reference;
			typedef ft::bidirectional_iterator_tag						iterator_category;
			/* End Typedefs */

			/* Constructors */
			bidirectional_iterator() : _itr(0) {};
			bidirectional_iterator(pointer itr) : _itr(itr) {};
			template <bool B>
			bidirectional_iterator(const bidirectional_iterator<T, B> &x, typename ft::enable_if<!B>::type* = 0) {
				_itr = x.base();
			};
			/* End Constructors */

			/* Destructor */
			~bidirectional_iterator() {};
			/* End Destructor */
			
			/* Operator= */
			bidirectional_iterator& operator=(const bidirectional_iterator& x) {
				_itr = x.base();
				return (*this);
			};
			/* End Operator= */

			/* Getter */
			pointer base() const {
				return (_itr);
			};
			/* End Getter */

			/* Operator overload */
			template <bool B>
			bool operator==(const bidirectional_iterator<T, B> &rhs) const {
				return (_itr == rhs.base());
			};
			template <bool B>
			bool operator!=(const bidirectional_iterator<T, B> &rhs) const {
				return (_itr != rhs.base());
			};
			reference operator*() const {
				return (*_itr);
			};
			pointer operator->() const {
				return (_itr);
			};
			bidirectional_iterator& operator++() {
				_itr++;
				return (*this);
			};
			bidirectional_iterator operator++(int) {
				bidirectional_iterator tmp = *this;
				++(*this);
				return (tmp);
			};
			bidirectional_iterator& operator--() {
				_itr--;
				return (*this);
			};
			bidirectional_iterator operator--(int) {
				bidirectional_iterator tmp = *this;
				--(*this);
				return (tmp);
			};
			/* End Operator overload */

		private:
			pointer _itr;
	};
}
#endif
