#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

#include "tools.hpp"

namespace ft {
	template <class T>
	class bidirectional_iterator {
		public:
			/* Typedefs */
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ft::bidirectional_iterator_tag	iterator_category;
			/* End Typedefs */

			/* Constructors */
			bidirectional_iterator() : _itr(0) {};
			bidirectional_iterator(pointer itr) : _itr(itr) {};
			bidirectional_iterator(const bidirectional_iterator& x) { *this = x; };
			/* End Constructors */

			/* Destructor */
			~bidirectional_iterator() {};
			/* End Destructor */
			
			/* Operator= */
			bidirectional_iterator& operator=(const bidirectional_iterator& x) {
				_itr = x._itr;
				return (*this);
			};
			/* End Operator= */

			/* Getter */
			pointer getitr() const {
				return (_itr);
			};
			/* End Getter */

			/* Operator overload */
			bool operator==(const bidirectional_iterator &rhs) const {
				return (_itr == rhs._itr ? true : false);
			};
			bool operator!=(const bidirectional_iterator &rhs) const {
				return (_itr != rhs._itr ? true : false);
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
			bidirectional_iterator operator+(const int n) const {
				return (bidirectional_iterator(_itr + n));
			};
			difference_type operator+(const bidirectional_iterator& rhs) const {
				return (_itr + rhs._itr);
			};
			bidirectional_iterator operator-(const int n) const {
				return (bidirectional_iterator(_itr - n));
			};
			difference_type operator-(const bidirectional_iterator& rhs) const {
				return (_itr - rhs._itr);
			};
			bool operator<(const bidirectional_iterator& rhs) const {
				return (_itr < rhs._itr ? true : false);
			};
			bool operator>(const bidirectional_iterator& rhs) const {
				return (_itr > rhs._itr ? true : false);
			};
			bool operator<=(const bidirectional_iterator& rhs) const {
				return (_itr <= rhs._itr ? true : false);
			};
			bool operator>=(const bidirectional_iterator& rhs) const {
				return (_itr >= rhs._itr ? true : false);
			};
			bidirectional_iterator& operator+=(const difference_type n) {
				_itr += n;
				return (*this);
			};
			bidirectional_iterator& operator-=(const difference_type n) {
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
	template <class Iterator>
	bidirectional_iterator<Iterator> operator+(typename bidirectional_iterator<Iterator>::difference_type n, const bidirectional_iterator<Iterator>& rev_it) {
		return (rev_it + n);
	};
	/* End Operator+ */

	/* Operator- */
	template <class Iterator>
	typename bidirectional_iterator<Iterator>::difference_type operator-(const bidirectional_iterator<Iterator>& lhs, const bidirectional_iterator<Iterator>& rhs) {
		return (rhs.base().getitr() - lhs.base().getitr());
	};
	/* End Operator+ */
}
#endif
