#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "utility.hpp"

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			template <bool Const>
			class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T> {
				public:
					/* Typedefs */
					typedef typename ft::iterator_traits<T*>::difference_type	difference_type;
					typedef typename ft::conditional<Const, const T, T>::type	value_type;
					typedef value_type*											pointer;
					typedef value_type&											reference;
					typedef ft::random_access_iterator_tag						iterator_category;
					/* End Typedefs */

					/* Constructors */
					random_access_iterator() : _itr(0) {};
					random_access_iterator(pointer itr) : _itr(itr) {};
					template <bool B>
					random_access_iterator(const random_access_iterator<B>& x, typename ft::enable_if<!B>::type* = 0) : _itr(x.operator->()) {};
					/* End Constructors */

					/* Destructor */
					~random_access_iterator() {};
					/* End Destructor */
					
					/* Operator= */
					random_access_iterator& operator=(const random_access_iterator& x) {
						_itr = x.operator->();
						return (*this);
					};
					/* End Operator= */

					/* Operator overload */
					template <bool B>
					bool operator==(const random_access_iterator<B>& rhs) const {
						return (_itr == rhs.operator->());
					};
					template <bool B>
					bool operator!=(const random_access_iterator<B>& rhs) const {
						return (_itr != rhs.operator->());
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
					difference_type operator+(const random_access_iterator<B>& rhs) const {
						return (_itr + rhs.operator->());
					};
					random_access_iterator operator-(const int n) const {
						return (random_access_iterator(_itr - n));
					};
					template <bool B>
					difference_type operator-(const random_access_iterator<B>& rhs) const {
						return (_itr - rhs.operator->());
					};
					template <bool B>
					bool operator<(const random_access_iterator<B>& rhs) const {
						return (_itr < rhs.operator->());
					};
					template <bool B>
					bool operator>(const random_access_iterator<B>& rhs) const {
						return (_itr > rhs.operator->());
					};
					template <bool B>
					bool operator<=(const random_access_iterator<B>& rhs) const {
						return (_itr <= rhs.operator->());
					};
					template <bool B>
					bool operator>=(const random_access_iterator<B>& rhs) const {
						return (_itr >= rhs.operator->());
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

					/* Operator+ friend */
					friend random_access_iterator operator+(int n, const random_access_iterator& x) {
						return (x.operator->() + n);
					};
					/* End Operator+ friend */

				private:
					pointer _itr;
			};
		public:
			/* Typedefs */
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef random_access_iterator<false>					iterator;
			typedef random_access_iterator<true> 					const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef	size_t											size_type;
			/* End Typedefs */

			/* Constructors */
			explicit vector(const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(0), _vector(0) {};
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(_size) {
				if (n > max_size())
					throw (std::length_error("cannot create ft::vector larger than max_size()"));
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_vector[i], val);
			};
			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			: _alloc(alloc), _size(ft::distance(first, last)), _capacity(_size), _vector(_alloc.allocate(_capacity)) {
				for (size_type i = 0; i < _size; i++, first++)
					_alloc.construct(&_vector[i], *first);
			};
			vector(const vector& x) {
				_alloc = x._alloc;
				_size = x._size;
				_capacity = x._size;
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0 ; i < _size ; i++)
					_alloc.construct(_vector + i, x[i]);
			};
			/* End Constructors */

			/* Destructor */
			~vector() {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_vector[i]);
				_alloc.deallocate(_vector, _capacity);
			};
			/* End Destructor */

			/* Operator= */
			vector& operator=(const vector& x) {
				if (this == &x)
					return (*this);
				for (size_type i = 0 ; i < _size ; i++)
					_alloc.destroy(_vector + i);
				if (x._size > _capacity) {
					_alloc.deallocate(_vector, _capacity);
					_capacity = x._size;
					_vector = _alloc.allocate(_capacity);
				}
				for (size_type i = 0 ; i < x._size ; i++)
					_alloc.construct(&_vector[i], x[i]);
				_size = x._size;
				return (*this);
			};
			/* End Operator= */

			/* Iterators */
			iterator begin() {
				return (iterator(&_vector[0]));
			};
			const_iterator begin() const {
				return (const_iterator(&_vector[0]));
			};
			iterator end() {
				return (iterator(&_vector[_size]));
			};
			const_iterator end() const {
				return (const_iterator(&_vector[_size])); 
			};
			reverse_iterator rbegin() {
				return (reverse_iterator(end()));
			};
			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(end()));
			};
			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			};
			const_reverse_iterator rend() const {
				return (const_reverse_iterator(begin())); 
			};
			/* End Iterators */

			/* Capacity */
			size_type size() const {
				return (_size);
			};
			size_type max_size() const {
				return (_alloc.max_size());
			};
			void resize(size_type n, value_type val = value_type()) {
				if (n < _size) {
					while (n < _size)
						_alloc.destroy(&_vector[--_size]);
				}
				else
					insert(iterator(&_vector[_size]), n - _size, val);
			};
			size_type capacity() const {
				return (_capacity);
			};
			bool empty() const {
				return (!_size);
			};
			void reserve(size_type n) {
				if (n > max_size())
					throw (std::length_error("vector::reserve"));
				if (n > _capacity) {
					pointer tmp = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _vector[i]);
					this->~vector();
					_capacity = n;
					_vector = tmp;
				}
			};
			/* End Capacity */

			/* Element access */
			reference operator[](size_type n) {
				return (_vector[n]);
			};
			const_reference operator[](size_type n) const {
				return (_vector[n]);
			};
			reference at(size_type n){
				if (n >= _size)
					throw (std::out_of_range("vector::at the position is out of range"));
				return (_vector[n]);
			};
			const_reference at(size_type n) const {
				if (n >= _size)
					throw (std::out_of_range("vector::at the position is out of range"));
				return (_vector[n]);
			};
			reference front() {
				return (_vector[0]);
			};
			const_reference front() const {
				return (_vector[0]);
			};
			reference back() {
				return (_vector[_size - 1]);
			};
			const_reference back() const {
				return (_vector[_size - 1]);
			};
			/* End Element access */

			/* Modifiers */
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
				size_type n = ft::distance(first, last);

				if (n > _capacity)
					reserve(n);
				clear();
				for (size_type i = 0; i < n; i++, first++)
					_alloc.construct(&_vector[i], *first);
				_size = n;
			};
			void assign(size_type n, const value_type& val) {
				if (n > _capacity)
					reserve(n);
				clear();
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_vector[i], val);
				_size = n;
			};
			void push_back(const T& value) {
				if (!_capacity || _size + 1 > _capacity) {
					_capacity = !_capacity ? 1 : _capacity * 2;
					pointer tmp = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _vector[i]);
					this->~vector();
					_vector = tmp;
				}
				_alloc.construct(&_vector[_size++], value);
			};
			void pop_back() {
				if (_size)
					_alloc.destroy(&_vector[--_size]);
			};
			iterator insert(iterator position, const value_type& val) {
				size_type pos = position - begin();

				insert(position, 1, val);
				return (&_vector[pos]);
			};
			void insert(iterator position, size_type n, const value_type& val) {
				size_type pos = position - begin();

				if (!n)
					return;
				if (_size + n > _capacity)
					reserve(_size + std::max(_size, n));
				for (int i = int(_size - 1); i >= int(pos); i--) {
					_alloc.construct(&_vector[i + n], _vector[i]);
					_alloc.destroy(&_vector[i]);
				}
				for (size_type i = 0; i < n; i++)
					_alloc.construct(&_vector[i + pos], val);
				_size += n;
			};
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
				size_type pos = position - begin();
				size_type n = ft::distance(first, last);

				if (!n)
					return;
				if (_size + n > _capacity)
					reserve(_size + std::max(_size, n));
				for (int i = int(_size - 1); i >= int(pos); i--) {
					_alloc.construct(&_vector[i + n], _vector[i]);
					_alloc.destroy(&_vector[i]);
				}
				for (size_type i = 0; i < n; i++, first++)
					_alloc.construct(&_vector[i + pos], *first);
				_size += n;
			};
			iterator erase(iterator position) {
				size_type pos = position - begin();

				_alloc.destroy(&_vector[pos]);
				for (size_type i = pos; i < _size - 1; i++) {
					_alloc.construct(&_vector[i], _vector[i + 1]);
					_alloc.destroy(&_vector[i + 1]);
				}
				_size--;
				return (&_vector[pos]);
			};
			iterator erase(iterator first, iterator last) {
				size_type l = last - begin();
				size_type f = first - begin();
				size_type n = last - first;

				for (size_type i = f; i < l; i++)
					_alloc.destroy(&_vector[i]);
				for (size_type i = f; i < _size - n; i++) {
					_alloc.construct(&_vector[i], _vector[i + n]);
					_alloc.destroy(&_vector[i + n]);
				}
				_size -= n;
				return (&_vector[f]);
			};
			void swap(vector& x) {
				if (this == &x)
					return;
				std::swap(_alloc, x._alloc);
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_vector, x._vector);
			};
			void clear() {
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(&_vector[i]);
				_size = 0;
			};
			/* End Modifiers */

			/* Allocator */
			allocator_type get_allocator() const {
				return (_alloc);
			};
			/* End Allocator */

		private:
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
			pointer			_vector;
	};

	/* Non-member function overloads */
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(lhs == rhs));
	};
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (lhs == rhs || lhs < rhs);
	};
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (!(lhs <= rhs));
	};
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs) {
		return (lhs == rhs || lhs > rhs);
	};
	template <class T, class Alloc>
	void swap(vector<T, Alloc>& x, vector<T, Alloc>& y) {
		x.swap(y);
	};
	/* End Non-member function overloads */
}
#endif
