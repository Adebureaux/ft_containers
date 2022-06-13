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
			: _alloc(alloc), _size(0), _capacity(_size), _vector(_alloc.allocate(_capacity)) {};

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(_size), _vector(_alloc.allocate(_capacity)) {
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_vector[i], val);
			};

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			: _alloc(alloc), _size(ft::distance(first, last)), _capacity(_size), _vector(_alloc.allocate(_capacity)) {
				for (size_type i = 0; i < _size; i++, first++)
					_alloc.construct(&_vector[i], *first);
			};

			vector(const vector& x)
			: _capacity(0), _vector(_alloc.allocate(_capacity)) {
				*this = x;
			};
			/* End Constructors */

			/* Destructor */
			~vector() {
				for (size_type i = 0; i < _capacity; i++)
					_alloc.destroy(&_vector[i]);
				_alloc.deallocate(_vector, _capacity);
			};
			/* End Destructor */

			/* Operator= */
			vector& operator=(const vector& x) {
				this->~vector();
				_capacity = x._capacity;
				_size = x._size;
				_vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_vector[i], x._vector[i]);
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
				return (std::numeric_limits<difference_type>::max() / sizeof(value_type));
			};
			void resize(size_type n, value_type val = value_type()) {
				pointer tmp = _alloc.allocate(n);
				for (size_type i = 0; i < n; i++)
					i < _size ? _alloc.construct(&tmp[i], _vector[i]) : _alloc.construct(&tmp[i], val);
				this->~vector();
				_capacity = _capacity < n ? n : _capacity;
				_size = n;
				_vector = tmp;
			};
			size_type capacity() const {
				return (_capacity);
			};
			bool empty() const {
				return (!_size ? true : false);
			};
			/* ... */
			/* End Capacity */


			/* Element access */
			reference operator[](size_type n) {
				return (_vector[n]);
			};

			const_reference operator[](size_type n) const {
				return (_vector[n]);
			};

			/* ... */

			/* End Element access */

			void push_back(const T& value) {
				
				if (!_capacity || _size + 1 > _capacity)
				{
					size_type size = !_capacity ? 1 : _capacity * 2;
					pointer tmp = _alloc.allocate(size);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _vector[i]);
					this->~vector();
					_capacity = size;
					_vector = tmp;
				}
				_alloc.construct(&_vector[_size++], value);
			};

		private:
			Alloc		_alloc;
			size_type	_size;
			size_type	_capacity;
			pointer		_vector;
	};
}
#endif
