#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

#include "tools.hpp"

namespace ft {
	template <class T>
	class map_iterator {
		public:
			/* Typedefs */
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ft::random_access_iterator_tag	iterator_category;
			/* End Typedefs */

			/* Constructors */
			map_iterator() : _itr(0) {};
			map_iterator(pointer itr) : _itr(itr) {};
			map_iterator(const map_iterator& x) { *this = x; };
			/* End Constructors */

			/* Destructor */
			~map_iterator() {};
			/* End Destructor */
			
			/* Operator= */
			map_iterator& operator=(const map_iterator& x) {
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
			bool operator==(const map_iterator &rhs) const {
				return (_itr == rhs._itr ? true : false);
			};
			bool operator!=(const map_iterator &rhs) const {
				return (_itr != rhs._itr ? true : false);
			};
			reference operator*() const {
				return (*_itr);
			};
			pointer operator->() const {
				return (_itr);
			};
			map_iterator& operator++() {
				_itr++;
				return (*this);
			};
			map_iterator operator++(int) {
				map_iterator tmp = *this;
				++(*this);
				return (tmp);
			};
			map_iterator& operator--() {
				_itr--;
				return (*this);
			};
			map_iterator operator--(int) {
				map_iterator tmp = *this;
				--(*this);
				return (tmp);
			};
			map_iterator operator+(const int n) const {
				return (map_iterator(_itr + n));
			};
			difference_type operator+(const map_iterator& rhs) const {
				return (_itr + rhs._itr);
			};
			map_iterator operator-(const int n) const {
				return (map_iterator(_itr - n));
			};
			difference_type operator-(const map_iterator& rhs) const {
				return (_itr - rhs._itr);
			};
			bool operator<(const map_iterator& rhs) const {
				return (_itr < rhs._itr ? true : false);
			};
			bool operator>(const map_iterator& rhs) const {
				return (_itr > rhs._itr ? true : false);
			};
			bool operator<=(const map_iterator& rhs) const {
				return (_itr <= rhs._itr ? true : false);
			};
			bool operator>=(const map_iterator& rhs) const {
				return (_itr >= rhs._itr ? true : false);
			};
			map_iterator& operator+=(const difference_type n) {
				_itr += n;
				return (*this);
			};
			map_iterator& operator-=(const difference_type n) {
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
	map_iterator<Iterator> operator+(typename map_iterator<Iterator>::difference_type n, const map_iterator<Iterator>& rev_it) {
		return (rev_it + n);
	};
	/* End Operator+ */

	/* Operator- */
	template <class Iterator>
	typename map_iterator<Iterator>::difference_type operator-(const map_iterator<Iterator>& lhs, const map_iterator<Iterator>& rhs) {
		return (rhs.base().getitr() - lhs.base().getitr());
	};
	/* End Operator+ */
}
#endif
