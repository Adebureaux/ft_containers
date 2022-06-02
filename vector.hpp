#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstdio>
#include <cstddef>
#include <memory>
#include <iostream>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			/* Typedefs */
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef T&												reference;
			typedef const T&										const_reference;
			typedef T*												pointer;
			typedef const T*										const_pointer;
			// typedef ft::random_access_iterator<value_type>			iterator;
			// typedef ft::random_access_iterator<const value_type>	const_iterator;
			// typedef ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef ft::const_reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef	size_t											size_type;
			/* End Typedefs */

			/* Constructors */
			explicit vector(const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(0), _capacity(_size), _vector(_alloc.allocate(_capacity)) {};
	
			explicit vector(size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(n), _capacity(_size), _vector(_alloc.allocate(_capacity)) {
				for (size_t i = 0; i < _capacity; i++)
					_alloc.construct(&_vector[i], val);
			};

			template <class InputIterator>
					vector(InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _size(last - first), _capacity(_size), _vector(_alloc.allocate(_capacity)) {};

			vector(const vector& x) {};
			/* End Constructors */

			/* Destructor */
			~vector() {
				for (size_t i = 0; i < _capacity; i++)
					_alloc.destroy(&_vector[i]);
				_alloc.deallocate(_vector, _capacity);
			};
			/* End Destructor */

			/* Operator= */
			/* ... */
			/* End Operator= */


			/* ... */


			/* Element access */
			reference operator[](size_type n)
			{
				return (_vector[n]);
			};

			const_reference operator[](size_type n) const
			{
				return (_vector[n]);
			};

			/* ... */

			/* End Element access */

		protected:

		private:
			Alloc		_alloc;
			size_type	_size;
			size_type	_capacity;
			pointer		_vector;
	};
}
#endif
