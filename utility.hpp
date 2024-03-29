#ifndef UTILITY_HPP
# define UTILITY_HPP

#include <cstdio>
#include <cstddef>
#include <memory>
#include <limits>
#include <functional>
#include <stdexcept>
#include "iterator_traits.hpp"
#include "reverse_iterator.hpp"

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

	/* Conditional */
	template <bool B, class T = void, class U = void>
	struct conditional {};
	template <class T, class U>
	struct conditional<true, T, U> {
		typedef T type;
	};
	template <class T, class U>
	struct conditional<false, T, U> {
		typedef U type;
	};
	/* End Conditional */

	/* Iterator */
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};
	/* End Iterator */

	/* Lexicographical_compare */
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
		while (first1 != last1 && first2 != last2) {
			if (*first1 < *first2)
				return (true);
			if (*first2 < *first1)
				return (false);
			++first1;
			++first2;
		}
		return (first1 == last1 && first2 != last2);
	};
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp) {
		while (first1 != last1 && first2 != last2) {
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
			++first1;
			++first2;
		}
		return (first1 == last1 && first2 != last2);
	};
	/* End Lexicographical_compare */

	/* Equal */
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	};
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	};
	/* End Equal */

	/* Distance */
	template <class InputIterator>
	std::ptrdiff_t distance(InputIterator first, InputIterator last) {
		std::ptrdiff_t distance = 0;

		while (first++ != last)
			distance++;
		return (distance);
	};
	/* End Distance */

	/* Pair */
	template <class T1, class T2>
	struct pair {
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;

		pair() : first(first_type()), second(second_type()) {};
		template <class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {};
		pair(const first_type& a, const second_type& b) : first(a), second(b) {};
		pair& operator=(const pair& pr) {
			first = pr.first;
			second = pr.second;
			return (*this);
		};
	};
	template <class T1, class T2>
	bool operator==(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};
	template <class T1, class T2>
	bool operator!=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (!(lhs == rhs));
	};
	template <class T1, class T2>
	bool operator<(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (lhs.first < rhs.first || (!(rhs.first<lhs.first) && lhs.second < rhs.second));
	};
	template <class T1, class T2>
	bool operator<=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (lhs.first <= rhs.first || lhs.second <= rhs.second);
	};
	template <class T1, class T2>
	bool operator>(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (rhs < lhs);
	};
	template <class T1, class T2>
	bool operator>=(const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return (!(lhs<rhs));
	};
	/* End Pair */

	/* Make_pair */
	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y) {
		return (pair<T1, T2>(x, y));
	};
	/* End Make_pair */
}
#endif
