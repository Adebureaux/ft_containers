#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

#include "tools.hpp"

namespace ft {
	template <class T, bool Const>
	class random_access_iterator {
		public:
			/* Typedefs */
			typedef std::ptrdiff_t										difference_type;
			typedef typename ft::conditional<Const, const T, T>::type	value_type;
			typedef value_type*											pointer;
			typedef value_type&											reference;
			typedef ft::random_access_iterator_tag						iterator_category;
			/* End Typedefs */

			/* Constructors */
			random_access_iterator() : _itr(0) {};
			random_access_iterator(pointer itr) : _itr(itr) {};
			template <bool B>
			random_access_iterator(const random_access_iterator<T, B> &x, typename ft::enable_if<!B>::type* = 0) {
				_itr = x.base();
			};
			/* End Constructors */

			/* Destructor */
			~random_access_iterator() {};
			/* End Destructor */
			
			/* Operator= */
			random_access_iterator& operator=(const random_access_iterator& x) {
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
			bool operator==(const random_access_iterator<T, B> &rhs) const {
				return (_itr == rhs.base() ? true : false);
			};
			template <bool B>
			bool operator!=(const random_access_iterator<T, B> &rhs) const {
				return (_itr != rhs.base() ? true : false);
			};
			reference operator*() const {
				return (*_itr);
			};
			pointer operator->() const {
				return (_itr);
			};
			random_access_iterator& operator++() {
				_itr++;
				return (*this);
			};
			random_access_iterator operator++(int) {
				random_access_iterator tmp = *this;
				++(*this);
				return (tmp);
			};
			random_access_iterator& operator--() {
				_itr--;
				return (*this);
			};
			random_access_iterator operator--(int) {
				random_access_iterator tmp = *this;
				--(*this);
				return (tmp);
			};
			random_access_iterator operator+(const int n) const {
				return (random_access_iterator(_itr + n));
			};
			template <bool B>
			difference_type operator+(const random_access_iterator<T, B>& rhs) const {
				return (_itr + rhs.base());
			};
			random_access_iterator operator-(const int n) const {
				return (random_access_iterator(_itr - n));
			};
			template <bool B>
			difference_type operator-(const random_access_iterator<T, B>& rhs) const {
				return (_itr - rhs.base());
			};
			template <bool B>
			bool operator<(const random_access_iterator<T, B>& rhs) const {
				return (_itr < rhs.base() ? true : false);
			};
			template <bool B>
			bool operator>(const random_access_iterator<T, B>& rhs) const {
				return (_itr > rhs.base() ? true : false);
			};
			template <bool B>
			bool operator<=(const random_access_iterator<T, B>& rhs) const {
				return (_itr <= rhs.base() ? true : false);
			};
			template <bool B>
			bool operator>=(const random_access_iterator<T, B>& rhs) const {
				return (_itr >= rhs.base() ? true : false);
			};
			random_access_iterator& operator+=(const difference_type n) {
				_itr += n;
				return (*this);
			};
			random_access_iterator& operator-=(const difference_type n) {
				_itr -= n;
				return (*this);
			};
			reference operator[](size_t n) const {
				return (_itr[n]);
			};
			/* End Operator overload */

		private:
			pointer _itr;
	};
	/* Operator+ */
	template <class Iterator, bool B>
	random_access_iterator<Iterator> operator+(typename random_access_iterator<Iterator, B>::difference_type n, const random_access_iterator<Iterator, B>& rev_it) {
		return (rev_it + n);
	};
	/* End Operator+ */

	/* Operator- */
	template <class Iterator, bool B>
	typename random_access_iterator<Iterator>::difference_type operator-(const random_access_iterator<Iterator, B>& lhs, const random_access_iterator<Iterator, B>& rhs) {
		return (rhs.base() - lhs.base());
	};
	/* End Operator+ */
}
#endif
