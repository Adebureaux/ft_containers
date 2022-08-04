#ifndef STACK_HPP
# define STACK_HPP

#include "utility.hpp"
#include "vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			/* Typedefs */
			typedef T													value_type;
			typedef Container											container_type;
			typedef size_t												size_type;
			/* End Typedefs */

		public:
			/* Member functions */
			explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {};
			bool empty() const {
				return (c.empty());
			};
			size_type size() const {
				return (c.size());
			};
			value_type& top() {
				return (c.back());
			};
			const value_type& top() const {
				return (c.back());
			};
			void push(const value_type& val) {
				c.push_back(val);
			};
			void pop() {
				c.pop_back();
			};
			/* End Member functions */

			/* Friend operator overload */
			template <class U, class C>
			friend bool operator==(const stack<U, C>& lhs, const stack<U, C>& rhs);
			template <class U, class C>
			friend bool operator!=(const stack<U, C>& lhs, const stack<U, C>& rhs);
			template <class U, class C>
			friend bool operator<(const stack<U, C>& lhs, const stack<U, C>& rhs);
			template <class U, class C>
			friend bool operator<=(const stack<U, C>& lhs, const stack<U, C>& rhs);
			template <class U, class C>
			friend bool operator>(const stack<U, C>& lhs, const stack<U, C>& rhs);
			template <class U, class C>
			friend bool operator>=(const stack<U, C>& lhs, const stack<U, C>& rhs);
			/* End Friend operator overload */

		protected:
			container_type	c;
	};

	/* Non-member function overloads */
	template <class T, class Container>
	bool operator==(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c == rhs.c);
	};
	template <class T, class Container>
	bool operator!=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (!(lhs == rhs));
	};
	template <class T, class Container>
	bool operator<(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs.c < rhs.c);
	};
	template <class T, class Container>
	bool operator<=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs == rhs || lhs < rhs);
	};
	template <class T, class Container>
	bool operator>(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (!(lhs <= rhs));
	};
	template <class T, class Container>
	bool operator>=(const stack<T, Container>& lhs, const stack<T, Container>& rhs) {
		return (lhs == rhs || lhs > rhs);
	};
	/* End Non-member function overloads */
}
#endif
