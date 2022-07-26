#ifndef MAP_HPP
# define MAP_HPP

#define BLACK 0
#define RED 1

#include "tools.hpp"

namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map {
		private:
			class _node {
				public:
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
					bidirectional_iterator() : _itr(0), _map(NULL) {};
					bidirectional_iterator(nodeptr itr, map* map) : _itr(itr), _map(map) {};
					template <bool B>
					bidirectional_iterator(const bidirectional_iterator<B>& x, typename ft::enable_if<!B>::type* = 0) : _itr(x.base()), _map(x._map) {};
					/* End Constructors */

					/* Destructor */
					~bidirectional_iterator() {};
					/* End Destructor */
					
					/* Operator= */
					bidirectional_iterator& operator=(const bidirectional_iterator& x) {
						_itr = x.base();
						_map = x._map;
						return (*this);
					};
					/* End Operator= */

					/* Operator overload */
					template <bool B>
					bool operator==(const bidirectional_iterator<B>& rhs) const {
						return (_itr == rhs.base());
					};
					template <bool B>
					bool operator!=(const bidirectional_iterator<B>& rhs) const {
						return (_itr != rhs.base());
					};
					reference operator*() const {
						return (_itr->data);
					};
					pointer operator->() const {
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
						// Here we give _itr is provided form end() and point on NULL, in this case I should try to retrieve the node before the NULL pointer.
						// std::cout << _itr << std::endl;
						// if (!_itr) {
						// 	const Key k = "Q";
						// 	_itr = _map->_find_node(k);
						// 	_itr = _itr->right;
						// }
						bidirectional_iterator tmp = *this;
						_itr = _predecessor(_itr);
						return (tmp);
					};
					/* End Operator overload */

					/* Getter */
					nodeptr base() const {
						return (_itr);
					};
					/* End Getter */

				private:
				nodeptr _successor(nodeptr x) const {
					nodeptr y;

					// this !x case is only when we are trying to increment end() _itr pointer
					if (!x && _map->_root != _map->_null)
						return (_map->_maximum(_map->_root));
					//
					if (x->right != _map->_null)
						return (_map->_minimum(x->right));
					y = x->parent;
					while (y && y != _map->_null && x == y->right) {
						x = y;
						y = y->parent;
					}
					return (y);
				};
				nodeptr _predecessor(nodeptr x) const {
					nodeptr y;

					// this !x case is only when we are trying to decrement end() _itr pointer
					if (!x && _map->_root != _map->_null)
						return (_map->_maximum(_map->_root));
					//
					if (x->left != _map->_null)
						return (_map->_maximum(x->left));
					y = x->parent;
					while (y && y != _map->_null && x == y->left) {
						x = y;
						y = y->parent;
					}
					return (y);
				};

				private:
					nodeptr _itr;
					map* 	_map;
			};

		public:
			class		value_comp;
			/* Typedefs */
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type, mapped_type>			value_type;
			typedef	Compare											key_compare;
			typedef	value_comp										value_compare;
			typedef typename Alloc::template rebind<_node>::other	allocator_type;
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
				_null->color = BLACK;
				_null->left = NULL;
				_null->right = NULL;
				_root = _null;
			};
			// template <class InputIterator> map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {

			// };
			// map(const map& x) {

			// };
			/* End Constructors */

			/* Destructor */
			~map() {
				clear();
				_alloc.deallocate(_null, 1);
			};
			/* End Destructor */

			/* Iterators */
			iterator begin() {
				return (iterator(_minimum(_root), this));
			};
			const_iterator begin() const {
				return (const_iterator(_minimum(_root), this));
			};
			iterator end() {
				return (iterator(NULL, this));
			};
			const_iterator end() const {
				return (const_iterator(NULL, this));
			};
			/* End Iterators */

			/* Capacity */
			size_type size() const {
				return (_size);
			};

			/* End Capacity */

			/* Modifiers */
			ft::pair<iterator, bool>insert(const value_type& val) {
				nodeptr node;
				nodeptr y;
				nodeptr x;

				if (_find_node(val.first))
					return (make_pair(iterator(), false));
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
					//if (node->data.first < x->data.first)
					if (_key_comp(node->data.first, x->data.first))
						x = x->left;
					else
						x = x->right;
				}
				node->parent = y;
				if (!y)
					_root = node;
				// else if (node->data.first < y->data.first)
				else if (_key_comp(node->data.first, y->data.first))
					y->left = node;
				else
					y->right = node;
				// if new node is a _root node, simply return
				if (!node->parent) {
					node->color = BLACK;
					return (make_pair(iterator(node, this), true));
				}
				// if the grandparent is null, simply return
				if (!node->parent->parent)
					return (make_pair(iterator(node, this), true));
				_fix_insert(node);
				return (make_pair(iterator(node, this), true));
			};

			void clear() {
				_recursive_clear(_root);
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

		private:
			void initializeNULLNode(nodeptr node, nodeptr parent) {
				node->parent = parent;
				node->left = NULL;
				node->right = NULL;
				node->color = BLACK;
			};
			void preOrderHelper(nodeptr node) {
				if (node != _null) {
					std::cout<<node->data.first<<" ";
					preOrderHelper(node->left);
					preOrderHelper(node->right);
				}
			}

			void inOrderHelper(nodeptr node) {
				if (node != _null) {
					inOrderHelper(node->left);
					std::cout<<node->data.first<<" ";
					inOrderHelper(node->right);
				}
			}

			void postOrderHelper(nodeptr node) {
				if (node != _null) {
					postOrderHelper(node->left);
					postOrderHelper(node->right);
					std::cout<<node->data.first<<" ";
				} 
			}

			nodeptr searchTreeHelper(nodeptr node, key_type key) {
				if (node == _null || key == node->data.first) {
					return node;
				}

				//if (key < node->data.first) 
				if (_key_comp(key, node->data.first)) {
					return searchTreeHelper(node->left, key);
				}
				return searchTreeHelper(node->right, key);
			}

			// fix the rb tree modified by the delete operation
			void fixDelete(nodeptr x) {
				nodeptr s;
				while (x != _root && x->color == BLACK) {
					if (x == x->parent->left) {
						s = x->parent->right;
						if (s->color == 1) {
							// case 3.1
							s->color = BLACK;
							x->parent->color = RED;
							_left_rotate(x->parent);
							s = x->parent->right;
						}

						if (s->left->color == BLACK && s->right->color == BLACK) {
							// case 3.2
							s->color = RED;
							x = x->parent;
						} else {
							if (s->right->color == BLACK) {
								// case 3.3
								s->left->color = BLACK;
								s->color = RED;
								_right_rotate(s);
								s = x->parent->right;
							} 

							// case 3.4
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							_left_rotate(x->parent);
							x = _root;
						}
					} else {
						s = x->parent->left;
						if (s->color == 1) {
							// case 3.1
							s->color = BLACK;
							x->parent->color = RED;
							_right_rotate(x->parent);
							s = x->parent->left;
						}

						if (s->right->color == 0 && s->right->color == 0) {
							// case 3.2
							s->color = RED;
							x = x->parent;
						} else {
							if (s->left->color == 0) {
								// case 3.3
								s->right->color = BLACK;
								s->color = RED;
								_left_rotate(s);
								s = x->parent->left;
							}

							// case 3.4
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							_right_rotate(x->parent);
							x = _root;
						}
					} 
				}
				x->color = BLACK;
			}

			void rbTransplant(nodeptr u, nodeptr v) {
				if (u->parent == NULL) {
					_root = v;
				} else if (u == u->parent->left){
					u->parent->left = v;
				} else {
					u->parent->right = v;
				}
				v->parent = u->parent;
			}


			void deleteNodeHelper(nodeptr node, key_type key) {
				// find the node containing key
				nodeptr z = _null;
				nodeptr x, y;
				while (node != _null) {
					if (node->data.first == key) {
						z = node;
					}

					if (node->data.first <= key) {
						node = node->right;
					}
					else {
						node = node->left;
					}
				}

				if (z == _null) {
					std::cout<<"Couldn't find key in the tree"<<std::endl;
					return;
				} 

				y = z;
				int y_original_color = y->color;
				if (z->left == _null) {
					x = z->right;
					rbTransplant(z, z->right);
				} else if (z->right == _null) {
					x = z->left;
					rbTransplant(z, z->left);
				} else {
					y = _minimum(z->right);
					y_original_color = y->color;
					x = y->right;
					if (y->parent == z) {
						x->parent = y;
					} else {
						rbTransplant(y, y->right);
						y->right = z->right;
						y->right->parent = y;
					}

					rbTransplant(z, y);
					y->left = z->left;
					y->left->parent = y;
					y->color = z->color;
				}
				delete z;
				if (y_original_color == 0){
					fixDelete(x);
				}
			}
			
			// fix the red-black tree

			void printHelper(nodeptr _root, std::string indent, bool last) {
				// print the tree structure on the screen
				if (_root != _null) {
					std::cout<<indent;
					if (last) {
						std::cout<<"R----";
						indent += "     ";
					} else {
						std::cout<<"L----";
						indent += "|    ";
					}
						
					std::string sColor = _root->color?"RED":"BLACK";
					std::cout << _root->data.first << " " << _root->data.second << "("<<sColor<<")"<<std::endl;
					printHelper(_root->left, indent, false);
					printHelper(_root->right, indent, true);
				}
				// cout<<_root->left->data<<endl;
			}

			


		public:
			// Pre-Order traversal
			// Node->Left Subtree->Right Subtree
			void preorder() {
				preOrderHelper(this->_root);
			}

			// In-Order traversal
			// Left Subtree -> Node -> Right Subtree
			void inorder() {
				inOrderHelper(this->_root);
			}

			// Post-Order traversal
			// Left Subtree -> Right Subtree -> Node
			void postorder() {
				postOrderHelper(this->_root);
			}

			// search the tree for the key k
			// and return the corresponding node
			nodeptr searchTree(int k) {
				return searchTreeHelper(this->_root, k);
			}

			nodeptr get_root(){
				return this->_root;
			}

			// delete the node from the tree
			void deleteNode(key_type key) {
				deleteNodeHelper(this->_root, key);
			}

			// print the tree structure on the screen
			void prettyPrint() {
				if (_root) {
					printHelper(this->_root, "", true);
				}
			}

		private:
			/* Help functions */
			nodeptr _find_node(const key_type& key) {
				nodeptr node = _root;
				nodeptr z = _null;

				while (node != _null) {
					//if (node->data.first == key)
					if (_equal(node->data.first, key))
						z = node;
					//if (node->data.first <= key)
					if (!_key_comp(key, node->data.first))
						node = node->right;
					else
						node = node->left;
				}
				if (z == _null)
					return (NULL);
				return (z);
			};
			void _recursive_clear(nodeptr root) {
				if (root != _null) {
					_recursive_clear(root->left);
					_recursive_clear(root->right);
					_alloc.deallocate(root, 1);
				}
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
				while (node->left != _null)
					node = node->left;
				return (node);
			};
			nodeptr _maximum(nodeptr node) const {
				while (node->right != _null)
					node = node->right;
				return (node);
			};
			bool _equal(const key_type& lhs, const key_type& rhs) const {
				return (_key_comp(lhs, rhs) == false && _key_comp(rhs, lhs) == false);
			};
			/* End Help functions */

		private:
			allocator_type	_alloc;
			key_compare		_key_comp;
			size_type		_size;
			nodeptr			_root;
			nodeptr			_null;
	};
}
#endif
