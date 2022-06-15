#ifndef TOOLS_HPP
# define TOOLS_HPP

#include <cstdio>
#include <cstddef>
#include <memory>
#include <limits>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"
#include "vector_iterator.hpp"

namespace ft {
	/* Enable_if */
	template <bool B, class T = void>
	struct enable_if {};
	template <class T>
	struct enable_if<true, T> {
		typedef T type; 
	};
	/* End Enable_if */

	/* Is_integral */
	template <typename T>
	struct is_integral {
		static const bool value = false;
	};
	template <>
	struct is_integral<bool> {
		static const bool value = true;
	};
	template <>
	struct is_integral<char> {
		static const bool value = true;
	};
	template <>
	struct is_integral<short> {
		static const bool value = true;
	};
	template <>
	struct is_integral<int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<long> {
		static const bool value = true;
	};
	template <>
	struct is_integral<long long> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned char> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned short> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned int> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned long> {
		static const bool value = true;
	};
	template <>
	struct is_integral<unsigned long long> {
		static const bool value = true;
	};
	/* End Is_integral */

	/* Distance */
	template <class InputIterator>
	std::ptrdiff_t distance(InputIterator first, InputIterator last) {
		std::ptrdiff_t distance = 0;
		if (first > last)
			throw (std::length_error("cannot create ft::vector larger than max_size()"));
		while (first++ < last)
			distance++;
		return (distance);
	};
	/* End Distance */
}
#endif
