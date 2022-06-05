#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "vector_iterator.hpp"

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
			typedef ft::vector_iterator<value_type>					iterator;
			typedef ft::vector_iterator<value_type const>			const_iterator;
			// typedef ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef ft::reverse_iterator<iterator const>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef	size_t											size_type;
			/* End Typedefs */

			/* Constructors */
			explicit vector(const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(_size), _vector(_alloc.allocate(_capacity)) {};
	
			explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(_size), _vector(_alloc.allocate(_capacity)) {
				for (size_type i = 0; i < _capacity; i++)
					_alloc.construct(&_vector[i], val);
			};

			template <class InputIterator>
					vector(InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(last - first), _capacity(_size), _vector(_alloc.allocate(_capacity)) {};

			vector(const vector& x) {
				(void)x;
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
			/* ... */
			/* End Operator= */

			/* ... */


			/* Iterators */
			iterator begin() {
				return iterator(&_vector[0]);
			};
			const_iterator begin() const {
				return iterator(&_vector[0]);
			};
			iterator end() {
				return iterator(&_vector[_size]);
			};
			const_iterator end() const {
				return iterator(&_vector[_size]); 
			};

			/* ... */

			/* End Iterators */


			/* Element access */
			reference operator[](size_type n) {
				return (_vector[n]);
			};

			const_reference operator[](size_type n) const {
				return (_vector[n]);
			};

			/* ... */

			/* End Element access */

			void reallocate(size_type size)
			{
				pointer tmp = _alloc.allocate(size);
				for (size_type i = 0; i < size; i++)
					_alloc.construct(&tmp[i], _vector[i]);
				this->~vector();
				_capacity = size;
				_vector = tmp;
			};

			void push_back(const T& value)
			{
				reallocate(_size + 1);
				_alloc.construct(&_vector[0], value);
			};


		protected:

		private:
			Alloc		_alloc;
			size_type	_size;
			size_type	_capacity;
			pointer		_vector;
	};
}
#endif
