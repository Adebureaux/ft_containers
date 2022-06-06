#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {
	template <class T>
	class iterator_traits<T*> {
		public:
			/* Typedefs */
			typedef T												value_type;
			typedef T&												reference;
			typedef T*												pointer;
			typedef std::ptrdiff_t									difference_type;
			typedef	size_t											size_type;

		protected:

		private:
	};
}
#endif
