#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "tools.hpp"
#include "vector_iterator.hpp"

namespace ft {
	template <class Iterator>
	class reverse_iterator {
		public:
			/* Typedefs */
			typedef Iterator												iterator_type;
			typedef typename ft::iterator_traits<Iterator>::value_type		iterator_category;
			typedef typename ft::iterator_traits<Iterator>::difference_type	difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer			pointer;
			typedef typename ft::iterator_traits<Iterator>::reference		reference;
			/* End Typedefs */

			/* Constructors */
			reverse_iterator() : _itr() {};
			explicit reverse_iterator(iterator_type it) : _itr(it) {};
			template <class Iter>
 			reverse_iterator(const reverse_iterator<Iter>& rev_it) { *this = rev_it; };
			/* End Constructors */

			/* Destructor */
			virtual ~reverse_iterator() {};
			/* End Destructor */
			
			/* Operator= */
			reverse_iterator& operator=(const reverse_iterator& rev_it) {
				_itr = rev_it._itr;
				return (*this);
			};
			/* End Operator= */

			/* Base */
			iterator_type base() const {
				iterator_type tmp = _itr;
				tmp--;
				return (tmp);
			};
			/* End Base */

			/* Operator overload */
			reference operator*() const {
				iterator_type tmp = base();
				return (*tmp);
			};
			reverse_iterator operator+(difference_type n) const {
				return (*(_itr) - n);
			};
			reverse_iterator& operator++() {
				_itr--;
				return (*this);
			};
			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			};
			reverse_iterator operator+=(difference_type n) {
				_itr -= n;
				return (*this);
			};
			reverse_iterator operator-(difference_type n) const {
				return (reverse_iterator(_itr + n));
			};
			reverse_iterator& operator--() {
				_itr++;
				return (*this);
			};
			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			};
			reverse_iterator& operator-=(difference_type n) {
				_itr += n;
				return (*this);
			};
			pointer operator->() const {
				return &(operator*());
			};
			reference operator[](difference_type n) const {
				return (_itr[n]);
			};
			/* End Operator overload */

		public:
			iterator_type _itr;
	};
	/* Relational operators */
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() == rhs.base() ? true : false);
	};
	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() != rhs.base() ? true : false);
	};
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() > rhs.base() ? true : false);
	};
	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() >= rhs.base() ? true : false);
	};
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() < rhs.base() ? true : false);
	};
	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() <= rhs.base() ? true : false);
	};
	/* End Relational operators */

	/* Operator+ */
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {

		return (rev_it.operator+(n));
	};
	/* End Operator+ */
	/* Operator- */
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs - rhs);
	};
	/* End Operator+ */
}
#endif
			
