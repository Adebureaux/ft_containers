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
			typedef const T*						const_pointer;
			typedef T&								reference;
			typedef const T&						const_reference;
			typedef ft::random_access_iterator_tag	iterator_category;
			/* End Typedefs */

			/* Constructors */
			vector_iterator() : _itr(0) {};
			vector_iterator(pointer itr) : _itr(itr) {};
			vector_iterator(const vector_iterator& x) { *this = x; };
			vector_iterator(vector_iterator& x) { *this = x; };
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

			/* Getter */
			pointer getitr() const {
				return (_itr);
			};
			/* End Getter */

			/* Operator overload */
			bool operator==(const vector_iterator &rhs) const {
				return (_itr == rhs._itr ? true : false);
			};
			bool operator!=(const vector_iterator &rhs) const {
				return (_itr != rhs._itr ? true : false);
			};
			reference operator*() {
				return (*_itr);
			};
			const_reference operator*() const {
				return (*_itr);
			};
			pointer operator->() {
				return (_itr);
			};
			const_pointer operator->() const { 
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
			vector_iterator operator+(const int n) const {
				return (vector_iterator(_itr + n));
			};
			difference_type operator+(const vector_iterator& rhs) const {
				return (_itr + rhs._itr);
			};
			vector_iterator operator-(const int n) const {
				return (vector_iterator(_itr - n));
			};
			difference_type operator-(const vector_iterator& rhs) const {
				return (_itr - rhs._itr);
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
			vector_iterator& operator+=(const difference_type n) {
				_itr += n;
				return (*this);
			};
			vector_iterator& operator-=(const difference_type n) {
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
	vector_iterator<Iterator> operator+(typename vector_iterator<Iterator>::difference_type n, const vector_iterator<Iterator>& rev_it) {
		return (rev_it + n);
	};
	/* End Operator+ */

	/* Operator- */
	template <class Iterator>
	typename vector_iterator<Iterator>::difference_type operator-(const vector_iterator<Iterator>& lhs, const vector_iterator<Iterator>& rhs) {
		return (rhs.base().getitr() - lhs.base().getitr());
	};
	/* End Operator+ */
}
#endif
