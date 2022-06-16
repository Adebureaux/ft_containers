#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "tools.hpp"

namespace ft {
	template <class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			/* Typedefs */
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef T&												reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			typedef typename ft::vector_iterator<value_type>		iterator;
			typedef typename ft::vector_iterator<const value_type>	const_iterator;
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
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_vector[i], first[i]);
			};
			vector(const vector& x) 
			: _alloc(x._alloc), _size(x._size), _capacity(x._size), _vector(_alloc.allocate(_capacity)) {
				*this = x;
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
				if (x._size > _capacity)
				{
					this->~vector();
					_capacity = x._size;
					_size = x._size;
					_vector = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&_vector[i], x._vector[i]);
				}
				else
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.destroy(&_vector[i]);
					for (size_type i = 0; i < x._size; i++)
						_alloc.construct(&_vector[i], x._vector[i]);
					_size = x._size;
				}
				return (*this);
			};
			/* End Operator= */

			/* Iterators */
			iterator begin() {
				return iterator(&_vector[0]);
			};
			const_iterator begin() const {
				return iterator(&_vector[0]);
			};
			iterator end() {
				return (iterator(&_vector[_size]));
			};
			const_iterator end() const {
				return (iterator(&_vector[_size])); 
			};
			reverse_iterator rbegin() {
				return (reverse_iterator(&_vector[_size]));
			};
			const_reverse_iterator rbegin() const {
				return (reverse_iterator(&_vector[_size]));
			};
			reverse_iterator rend() {
				return (reverse_iterator(&_vector[0]));
			};
			const_reverse_iterator rend() const {
				return (reverse_iterator(&_vector[0])); 
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
				if (n < _size)
				{
					for (size_type i = 0; i < n; i++)
						_alloc.destroy(&_vector[i]);
					_size = n;
				}
				else if (n > _size)
				{
					if (n > _capacity)
						reserve(n);
					for (size_type i = _size; i < n; i++)
						push_back(val);
				}
			};
			size_type capacity() const {
				return (_capacity);
			};
			bool empty() const {
				return (!_size ? true : false);
			};
			void reserve(size_type n) {
				if (n > max_size())
					throw (std::length_error("vector::reserve larger than max_size()"));
				if (n > _size)
				{
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
				_size = ft::distance(first, last);
				if (_size > _capacity)
				{
					_capacity = _size;
					pointer tmp = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], first[i]);
					this->~vector();
					_vector = tmp;
				}
				else
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&_vector[i], first[i]);
				}
			};
			void assign(size_type n, const value_type& val) {
				_size = n;
				if (_size > _capacity)
				{
					_capacity = _size;
					pointer tmp = _alloc.allocate(_capacity);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], val);
					this->~vector();
					_vector = tmp;
				}
				else
				{
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&_vector[i], val);
				}
			};
			void push_back(const T& value) {
				if (!_capacity || _size + 1 > _capacity)
				{
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
				(void)position;
				(void)val;
			};
			void insert(iterator position, size_type n, const value_type& val) {
				(void)position;
				(void)n;
				(void)val;
			};
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
				(void)position;
				(void)first;
				(void)last;
			};
			/* End Modifiers */

		private:
			Alloc		_alloc;
			size_type	_size;
			size_type	_capacity;
			pointer		_vector;
	};
}
#endif
