#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <cstdio>
#include <cstddef>
#include <memory>

namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			/* Typedefs */
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			// typedef ft::random_access_iterator<value_type>			iterator;
			// typedef ft::random_access_iterator<const value_type>	const_iterator;
			// typedef ft::reverse_iterator<iterator>					reverse_iterator;
			// typedef ft::const_reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef	size_t											size_type;
			/* End Typedefs */

			/* Constructors */
			explicit vector (const allocator_type& alloc = allocator_type())
			{

			};
			explicit vector (size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type())
			{

			};
			template <class InputIterator>
					vector	(InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type())
			{

			};
			vector (const vector& x)
			{

			};
			/* End Constructors */

		protected:

		private:
	};
}
#endif
