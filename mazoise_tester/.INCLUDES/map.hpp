#ifndef MAP_HPP
# define MAP_HPP

#define BLACK 0
#define RED 1

#include "utility.hpp"

// Red Black Tree implementation in C++
// Author: Algorithm Tutor
// Tutorial URL: https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		private:
			class _node {
				public:
					_node() : data(pair<Key, T>()) {};
					_node(ft::pair<const Key, T>& val) : data(val) {};
					_node(const ft::pair<const Key, T>& val) : data(val) {};

				public:
					ft::pair<const Key, T>	data;
					_node					*parent;
					_node					*left;
					_node					*right;
					bool					color;
			};
		
		public:
			template <bool Const>
			class bidirectional_iterator : ft::iterator<ft::bidirectional_iterator_tag, T> {
				friend class map;
				public:
					/* Typedefs */
					typedef typename ft::iterator_traits<T*>::difference_type					difference_type;
					typedef ft::pair<const Key, T>												pair_type;
					typedef typename ft::conditional<Const, const pair_type, pair_type>::type	value_type;
					typedef typename ft::conditional<Const, const _node, _node>::type			*nodeptr;
					typedef value_type*															pointer;
					typedef value_type&															reference;
					typedef ft::bidirectional_iterator_tag										iterator_category;
					/* End Typedefs */

					/* Constructors */
					bidirectional_iterator() : _itr(0), _root(NULL), _null(NULL) {};
					bidirectional_iterator(nodeptr itr, nodeptr root, nodeptr null) : _itr(itr), _root(root), _null(null) {};
					template <bool B>
					bidirectional_iterator(const bidirectional_iterator<B>& x, typename ft::enable_if<!B>::type* = 0) : _itr(x._itr), _root(x._root), _null(x._null) {};
					/* End Constructors */

					/* Destructor */
					~bidirectional_iterator() {};
					/* End Destructor */
					
					/* Operator= */
					bidirectional_iterator& operator=(const bidirectional_iterator& x) {
						_itr = x._itr;
						_root = x._root;
						_null = x._null;
						return (*this);
					};
					/* End Operator= */

					/* Operator overload */
					template <bool B>
					bool operator==(const bidirectional_iterator<B>& rhs) const {
						return (_itr == rhs._itr);
					};
					template <bool B>
					bool operator!=(const bidirectional_iterator<B>& rhs) const {
						return (_itr != rhs._itr);
					};
					reference operator*() const {
						if (!_itr && _root)
							return (_null->data);
						return (_itr->data);
					};
					pointer operator->() const {
						if (!_itr && _root)
							return (&_null->data);
						return (&_itr->data);
					};
					bidirectional_iterator& operator++() {
						_itr = _successor(_itr);
						return (*this);
					};
					bidirectional_iterator operator++(int) {
						bidirectional_iterator tmp = *this;
						_itr = _successor(_itr);
						return (tmp);
					};
					bidirectional_iterator& operator--() {
						_itr = _predecessor(_itr);
						return (*this);
					};
					bidirectional_iterator operator--(int) {
						bidirectional_iterator tmp = *this;
						_itr = _predecessor(_itr);
						return (tmp);
					};
					/* End Operator overload */

				private:
					nodeptr _successor(nodeptr x) const {
						nodeptr y;

						if (!_root)
							return (NULL);
						if (!x && _root != _null)
							return (_maximum(_root));
						if (x->right != _null)
							return (_minimum(x->right));
						y = x->parent;
						while (y && y != _null && x == y->right) {
							x = y;
							y = y->parent;
						}
						return (y);
					};
					nodeptr _predecessor(nodeptr x) const {
						nodeptr y;

						if (!_root)
							return (NULL);
						if (!x && _root != _null)
							return (_maximum(_root));
						if (x->left != _null)
							return (_maximum(x->left));
						y = x->parent;
						while (y && y != _null && x == y->left) {
							x = y;
							y = y->parent;
						}
						return (y);
					};
					nodeptr _minimum(nodeptr node) const {
						while (node && node->left != _null)
							node = node->left;
						return (node);
					};
					nodeptr _maximum(nodeptr node) const {
						while (node && node->right != _null)
							node = node->right;
						return (node);
					};

				private:
					nodeptr _itr;
					nodeptr _root;
					nodeptr _null;
			};

			/* Typedefs */
		private:
			typedef typename Alloc::template rebind<_node>::other	node_allocator_type;

		public:
			class													value_comp;
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef	Compare											key_compare;
			typedef	value_comp										value_compare;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef bidirectional_iterator<false>					iterator;
			typedef bidirectional_iterator<true> 					const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef	size_t											size_type;
			typedef _node											*nodeptr;
			/* End Typedefs */

			/* Value_compare */
			class value_comp : std::binary_function<value_type, value_type, bool> {
				friend class map;
				public:
					bool operator()(const value_type& x, const value_type& y) const {
						return (comp(x.first, y.first));
					};
				protected:
					key_compare comp;
					value_comp(key_compare c) : comp(c) {};
			};
			/* End Value_compare */

			/* Constructors */
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _key_comp(comp), _size(0) {
				_null = _alloc.allocate(1);
				_alloc.construct(_null, _node());
				_null->color = BLACK;
				_null->left = NULL;
				_null->right = NULL;
				_root = _null;
			};
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			: _alloc(alloc), _key_comp(comp), _size(0) {
				_null = _alloc.allocate(1);
				_alloc.construct(_null, _node());
				_null->color = BLACK;
				_null->left = NULL;
				_null->right = NULL;
				_root = _null;
				insert(first, last);
			};
			map(const map& x) : _alloc(x._alloc), _key_comp(x._key_comp), _size(0) {
				_null = _alloc.allocate(1);
				_alloc.construct(_null, _node());
				_null->color = BLACK;
				_null->left = NULL;
				_null->right = NULL;
				_root = _null;
				insert(x.begin(), x.end());
			};
			/* End Constructors */

			/* Destructor */
			~map() {
				clear();
				_alloc.destroy(_null);
				_alloc.deallocate(_null, 1);
			};
			/* End Destructor */

			/* Operator= */
			map& operator=(const map& x) {
				if (this == &x)
					return (*this);
				clear();
				_root = _null;
				insert(x.begin(), x.end());
				return (*this);
			};
			/* End Operator= */

			/* Iterators */
			iterator begin() {
				return (iterator(_minimum(_root), _root, _null));
			};
			const_iterator begin() const {
				return (const_iterator(_minimum(_root), _root, _null));
			};
			iterator end() {
				return (iterator(NULL, _root, _null));
			};
			const_iterator end() const {
				return (const_iterator(NULL, _root, _null));
			};
			reverse_iterator rbegin() {
				return (reverse_iterator(end()));
			};
			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(end()));
			};
			reverse_iterator rend() {
				return (reverse_iterator(begin()));
			};
			const_iterator rend() const {
				return (const_reverse_iterator(begin()));
			};
			/* End Iterators */

			/* Capacity */
			bool empty() const {
				return (!_size);
			};
			size_type size() const {
				return (_size);
			};
			size_type max_size() const {
				return (_alloc.max_size());
			};
			/* End Capacity */


			/* Element access */
			mapped_type& operator[](const key_type& k) {
				return ((*((insert(ft::make_pair(k, mapped_type()))).first)).second);
			};
			/* End Element access */

			/* Modifiers */
			ft::pair<iterator, bool> insert(const value_type& val) {
				nodeptr node = _recursive_find(_root, val.first);

				if (node != _null)
					return (make_pair(iterator(node, _root, _null), false));
				return (make_pair(iterator(_insert(val), _root, _null), true));
			};
			iterator insert(iterator position, const value_type& val) {
				nodeptr node = _recursive_find(_root, val.first);

				(void)position;
				if (node == _null)
					node = _insert(val);
				return (iterator(node, _root, _null));
			};
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
				while (first != last)
					insert(*(first++));
			};
			void erase(iterator position) {
				_erase(position->first);
			};
			size_type erase(const key_type& k) {
				return (_erase(k));
			};
			void erase(iterator first, iterator last) {
				while (first != last)
					erase(first++);
			};
			void swap(map& x) {
				if (this == &x)
					return;
				std::swap(_alloc, x._alloc);
				std::swap(_key_comp, x._key_comp);
				std::swap(_size, x._size);
				std::swap(_root, x._root);
				std::swap(_null, x._null);
			};
			void clear() {
				_recursive_clear(_root);
				_root = _null;
			};
			/* End Modifiers */

			/* Observers */
			key_compare key_comp(void) const {
				return (key_compare());
			};
			value_compare value_comp(void) const {
				return (value_compare(_key_comp));
			};
			/* End Observers */

			/* Operations */
			iterator find(const key_type& k) {
				nodeptr node = _recursive_find(_root, k);

				if (node == _null)
					return (end());
				return (iterator(node, _root, _null));
			};
			const_iterator find(const key_type& k) const {
				nodeptr node = _recursive_find(_root, k);

				if (node == _null)
					return (end());
				return (const_iterator(node, _root, _null));
			};
			size_type count(const key_type& k) const {
				if (_recursive_find(_root, k) != _null)
					return (1);
				return (0);
			};
			iterator lower_bound(const key_type& k) {
				iterator itr = begin();

				while (itr != end()) {
					if (!_key_comp(itr->first, k))
						break;
					itr++;
				}
				return (itr);
			};
			const_iterator lower_bound(const key_type& k) const {
				const_iterator itr = begin();

				while (itr != end()) {
					if (!_key_comp(itr->first, k))
						break;
					itr++;
				}
				return (itr);
			};
			iterator upper_bound(const key_type& k) {
				iterator itr = begin();

				while (itr != end()) {
					if (!_key_comp(itr->first, k))
						break;
					itr++;
				}
				if (itr != end() && _equal(itr->first, k))
					itr++;
				return (itr);
			};
			const_iterator upper_bound(const key_type& k) const {
				const_iterator itr = begin();

				while (itr != end()) {
					if (!_key_comp(itr->first, k))
						break;
					itr++;
				}
				if (itr != end() && _equal(itr->first, k))
					itr++;
				return (itr);
			};
			ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
				return (make_pair(lower_bound(k), upper_bound(k)));
			};
			ft::pair<iterator, iterator> equal_range(const key_type& k) {
				return (make_pair(lower_bound(k), upper_bound(k)));
			};
			/* End Operations */

			/* Allocator */
			allocator_type get_allocator() const {
				return (allocator_type());
			};
			/* End Allocator */

		private:
			/* Help functions */
			nodeptr _recursive_find(nodeptr node, const key_type& key) const {
				if (node == _null || _equal(key, node->data.first))
					return (node);
				if (!_key_comp(node->data.first, key))
					return (_recursive_find(node->left, key));
				return (_recursive_find(node->right, key));
			};
			void _recursive_clear(nodeptr node) {
				if (node != _null) {
					_recursive_clear(node->left);
					_recursive_clear(node->right);
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					_size--;
				}
			};
			nodeptr _insert(const value_type& val) {
				nodeptr node;
				nodeptr y;
				nodeptr x;

				node = _alloc.allocate(1);
				_alloc.construct(node, _node(val));
				_size++;
				node->parent = NULL;
				node->left = _null;
				node->right = _null;
				node->color = RED;
				y = NULL;
				x = _root;
				while (x != _null) {
					y = x;
					if (_key_comp(node->data.first, x->data.first))
						x = x->left;
					else
						x = x->right;
				}
				node->parent = y;
				if (!y)
					_root = node;
				else if (_key_comp(node->data.first, y->data.first))
					y->left = node;
				else
					y->right = node;
				if (!node->parent) {
					node->color = BLACK;
					return (node);
				}
				if (!node->parent->parent)
					return (node);
				_fix_insert(node);
				return (node);
			};
			void _fix_insert(nodeptr k) {
				nodeptr u;

				while (k->parent->color == RED) {
					if (k->parent == k->parent->parent->right) {
						u = k->parent->parent->left;
						if (u->color == RED) {
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else {
							if (k == k->parent->left) {
								k = k->parent;
								_right_rotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							_left_rotate(k->parent->parent);
						}
					}
					else {
						u = k->parent->parent->right;
						if (u->color == RED) {
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						}
						else {
							if (k == k->parent->right) {
								k = k->parent;
								_left_rotate(k);
							}
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							_right_rotate(k->parent->parent);
						}
					}
					if (k == _root)
						break;
				}
				_root->color = BLACK;
			};
			size_type _erase(const key_type& key) {
				bool y_original_color;
				nodeptr node = _root;
				nodeptr z = _null;
				nodeptr x;
				nodeptr y;
	
				while (node != _null) {
					if (_equal(node->data.first, key))
						z = node;
					if (_key_comp(node->data.first, key))
						node = node->right;
					else
						node = node->left;
				}
				if (z == _null)
					return (0);
				y = z;
				y_original_color = y->color;
				if (z->left == _null) {
					x = z->right;
					_transplant(z, z->right);
				} else if (z->right == _null) {
					x = z->left;
					_transplant(z, z->left);
				}
				else {
					y = _minimum(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z)
						x->parent = y;
					else {
						_transplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}
					_transplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				_alloc.destroy(z);
				_alloc.deallocate(z, 1);
				_size--;
				if (y_original_color == BLACK)
					_fix_erase(x);
				return (1);
			};
			void _fix_erase(nodeptr x) {
				nodeptr s;
	
				while (x != _root && x->color == BLACK) {
					if (x == x->parent->left) {
						s = x->parent->right;
						if (s->color == RED) {
							s->color = BLACK;
							x->parent->color = RED;
							_left_rotate(x->parent);
							s = x->parent->right;
						}
						if (s->left->color == BLACK && s->right->color == BLACK) {
							s->color = RED;
							x = x->parent;
						}
						else {
							if (s->right->color == BLACK) {
								s->left->color = BLACK;
								s->color = RED;
								_right_rotate(s);
								s = x->parent->right;
							} 
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							_left_rotate(x->parent);
							x = _root;
						}
					}
					else {
						s = x->parent->left;
						if (s->color == RED) {
							s->color = BLACK;
							x->parent->color = RED;
							_right_rotate(x->parent);
							s = x->parent->left;
						}
						if (s->right->color == BLACK && s->right->color == BLACK) {
							s->color = RED;
							x = x->parent;
						} else {
							if (s->left->color == BLACK) {
								s->right->color = BLACK;
								s->color = RED;
								_left_rotate(s);
								s = x->parent->left;
							}
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							_right_rotate(x->parent);
							x = _root;
						}
					} 
				}
				x->color = BLACK;
			};
			void _transplant(nodeptr u, nodeptr v) {
				if (!u->parent)
					_root = v;
				else if (u == u->parent->left)
					u->parent->left = v;
				else
					u->parent->right = v;
				v->parent = u->parent;
			};
			void _right_rotate(nodeptr x) {
				nodeptr y = x->left;

				x->left = y->right;
				if (y->right != _null)
					y->right->parent = x;
				y->parent = x->parent;
				if (!x->parent)
					_root = y;
				else if (x == x->parent->right)
					x->parent->right = y;
				else
					x->parent->left = y;
				y->right = x;
				x->parent = y;
			};
			void _left_rotate(nodeptr x) {
				nodeptr y = x->right;

				x->right = y->left;
				if (y->left != _null)
					y->left->parent = x;
				y->parent = x->parent;
				if (!x->parent)
					_root = y;
				else if (x == x->parent->left)
					x->parent->left = y;
				else
					x->parent->right = y;
				y->left = x;
				x->parent = y;
			};
			nodeptr _minimum(nodeptr node) const {
				while (node && node->left != _null)
					node = node->left;
				return (node);
			};
			nodeptr _maximum(nodeptr node) const {
				while (node && node->right != _null)
					node = node->right;
				return (node);
			};
			bool _equal(const key_type& lhs, const key_type& rhs) const {
				return (_key_comp(lhs, rhs) == false && _key_comp(rhs, lhs) == false);
			};
			/* End Help functions */

		private:
			node_allocator_type	_alloc;
			key_compare			_key_comp;
			size_type			_size;
			nodeptr				_root;
			nodeptr				_null;
	};

	/* Non-member function overloads */
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& lhs,const map<Key, T, Compare, Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc>& lhs,const map<Key, T, Compare, Alloc>& rhs) {
		return (!(lhs == rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& lhs,const map<Key, T, Compare, Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc>& lhs,const map<Key, T, Compare, Alloc>& rhs) {
		return (lhs == rhs || lhs < rhs);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc>& lhs,const map<Key, T, Compare, Alloc>& rhs) {
		return (!(lhs <= rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& lhs,const map<Key, T, Compare, Alloc>& rhs) {
		return (lhs == rhs || lhs > rhs);
	};
	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc>& x, map<Key, T, Compare, Alloc>& y) {
		x.swap(y);
	};
  	/* End Non-member function overloads */
}
#endif
