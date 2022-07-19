#ifndef MAP_HPP
# define MAP_HPP

#include "tools.hpp"
#include "bidirectional_iterator.hpp"

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map {
		public:
			/* Typedefs */
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef std::pair<const key_type, mapped_type>			value_type;
			typedef	Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ft::bidirectional_iterator<T, false>			iterator;
			typedef ft::bidirectional_iterator<T, true> 			const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef	size_t											size_type;
			/* End Typedefs */

			/* Value_compare */
			class value_compare {
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) {};
			public:
				typedef bool result_type;
				typedef value_type first_argument_type;
				typedef value_type second_argument_type;
				bool operator()(const value_type& x, const value_type& y) const {
					return comp(x.first, y.first);
				};
			};
			/* End Value_compare */

			/* Constructors */
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _key_comp(comp) {
				_value_comp = value_compare();
			};
			template <class InputIterator> map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {

			};
			map(const map& x) {

			};
			/* End Constructors */

		private:
			allocator_type	_alloc;
			key_compare		_key_comp;
			value_compare	_value_comp;
	};
}
#endif
