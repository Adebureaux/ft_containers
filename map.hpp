#ifndef MAP_HPP
# define MAP_HPP

#define BLACK 0
#define RED 1

#include "tools.hpp"
#include "bidirectional_iterator.hpp"


namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map {
		private:
			class _node {
				public :
					_node(std::pair<const Key, T>& val) : data(val) {};
					_node(const std::pair<const Key, T>& val) : data(val) {};

				public:
					std::pair<const Key, T>	data; // holds the key/value
					_node					*parent; // pointer to the parent
					_node					*left; // pointer to left child
					_node					*right; // pointer to right child
					bool					color; // 1 -> Red, 0 -> Black
			};

		public:
			/* Typedefs */
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef std::pair<const key_type, mapped_type>			value_type;
			typedef	Compare											key_compare;
			typedef typename Alloc::template rebind<_node>::other	allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef ft::bidirectional_iterator<T, false>			iterator;
			typedef ft::bidirectional_iterator<T, true> 			const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef	size_t											size_type;
			typedef _node											*nodeptr;
			/* End Typedefs */

			/* Value_compare */
			class value_compare {
				public:
					bool operator()(const value_type& x, const value_type& y) const {
						return (key_compare(x.first, y.first));
					};
			};
			/* End Value_compare */

			/* Constructors */
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _key_comp(comp), _value_comp(value_compare()) {
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

			~map() {
				deleteHelper(this->_root);
				_alloc.deallocate(_null, 1);
			};


		private:
			void initializeNULLNode(nodeptr node, nodeptr parent) {
				node->data.first = 0;
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

				if (key < node->data.first) {
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
							leftRotate(x->parent);
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
								rightRotate(s);
								s = x->parent->right;
							} 

							// case 3.4
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->right->color = BLACK;
							leftRotate(x->parent);
							x = _root;
						}
					} else {
						s = x->parent->left;
						if (s->color == 1) {
							// case 3.1
							s->color = BLACK;
							x->parent->color = RED;
							rightRotate(x->parent);
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
								leftRotate(s);
								s = x->parent->left;
							}

							// case 3.4
							s->color = x->parent->color;
							x->parent->color = BLACK;
							s->left->color = BLACK;
							rightRotate(x->parent);
							x = _root;
						}
					} 
				}
				x->color = BLACK;
			}


			void rbTransplant(nodeptr u, nodeptr v){
				if (u->parent == NULL) {
					_root = v;
				} else if (u == u->parent->left){
					u->parent->left = v;
				} else {
					u->parent->right = v;
				}
				v->parent = u->parent;
			}

			// nodeptr findNode(key_type key) {
			// 	nodeptr z = _null;
			// 	nodeptr x, y;
			// 	while (node != _null){
			// 		if (node->data.first == key) {
			// 			z = node;
			// 		}

			// 		if (node->data.first <= key) {
			// 			node = node->right;
			// 		} else {
			// 			node = node->left;
			// 		}
			// 	}

			// 	if (z == _null) {
			// 		std::cout<<"Couldn't find key in the tree"<<std::endl;
			// 		return;
			// 	} 
			// };

			void deleteNodeHelper(nodeptr node, key_type key) {
				// find the node containing key
				nodeptr z = _null;
				nodeptr x, y;
				while (node != _null){
					if (node->data.first == key) {
						z = node;
					}

					if (node->data.first <= key) {
						node = node->right;
					} else {
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
					y = minimum(z->right);
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
			void fixInsert(nodeptr k){
				nodeptr u;
				while (k->parent->color == 1) {
					if (k->parent == k->parent->parent->right) {
						u = k->parent->parent->left; // uncle
						if (u->color == 1) {
							// case 3.1
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						} else {
							if (k == k->parent->left) {
								// case 3.2.2
								k = k->parent;
								rightRotate(k);
							}
							// case 3.2.1
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							leftRotate(k->parent->parent);
						}
					} else {
						u = k->parent->parent->right; // uncle

						if (u->color == 1) {
							// mirror case 3.1
							u->color = BLACK;
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							k = k->parent->parent;
						} else {
							if (k == k->parent->right) {
								// mirror case 3.2.2
								k = k->parent;
								leftRotate(k);
							}
							// mirror case 3.2.1
							k->parent->color = BLACK;
							k->parent->parent->color = RED;
							rightRotate(k->parent->parent);
						}
					}
					if (k == _root) {
						break;
					}
				}
				_root->color = BLACK;
			}

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
					std::cout<<_root->data.first<<"("<<sColor<<")"<<std::endl;
					printHelper(_root->left, indent, false);
					printHelper(_root->right, indent, true);
				}
				// cout<<_root->left->data<<endl;
			}

			void deleteHelper(nodeptr _root) {
				if (_root != _null) {
					deleteHelper(_root->left);
					deleteHelper(_root->right);
					_alloc.deallocate(_root, 1);
				}
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

			// find the node with the minimum key
			nodeptr minimum(nodeptr node) {
				while (node->left != _null) {
					node = node->left;
				}
				return node;
			}

			// find the node with the maximum key
			nodeptr maximum(nodeptr node) {
				while (node->right != _null) {
					node = node->right;
				}
				return node;
			}

			// find the successor of a given node
			nodeptr successor(nodeptr x) {
				// if the right subtree is not null,
				// the successor is the leftmost node in the
				// right subtree
				if (x->right != _null) {
					return minimum(x->right);
				}

				// else it is the lowest ancestor of x whose
				// left child is also an ancestor of x.
				nodeptr y = x->parent;
				while (y != _null && x == y->right) {
					x = y;
					y = y->parent;
				}
				return y;
			}

			// find the predecessor of a given node
			nodeptr predecessor(nodeptr x) {
				// if the left subtree is not null,
				// the predecessor is the rightmost node in the 
				// left subtree
				if (x->left != _null) {
					return maximum(x->left);
				}

				nodeptr y = x->parent;
				while (y != _null && x == y->left) {
					x = y;
					y = y->parent;
				}

				return y;
			}

			// rotate left at node x
			void leftRotate(nodeptr x) {
				nodeptr y = x->right;
				x->right = y->left;
				if (y->left != _null) {
					y->left->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == NULL) {
					this->_root = y;
				} else if (x == x->parent->left) {
					x->parent->left = y;
				} else {
					x->parent->right = y;
				}
				y->left = x;
				x->parent = y;
			}

			// rotate right at node x
			void rightRotate(nodeptr x) {
				nodeptr y = x->left;
				x->left = y->right;
				if (y->right != _null) {
					y->right->parent = x;
				}
				y->parent = x->parent;
				if (x->parent == NULL) {
					this->_root = y;
				} else if (x == x->parent->right) {
					x->parent->right = y;
				} else {
					x->parent->left = y;
				}
				y->right = x;
				x->parent = y;
			}

			// insert the key to the tree in its appropriate position
			// and fix the tree
			void insert(const value_type& val) {
				deleteNode(val.first); // delete node if the key is already existing (TO REMOVE ?)
				// Ordinary Binary Search Insertion
				nodeptr node = _alloc.allocate(1);
				node->parent = NULL;

				_alloc.construct(node, _node(val));
	
				//_alloc.construct(node, Node(key_value));

				// node->data = std::make_pair(val.first, val.second);
				node->left = _null;
				node->right = _null;
				node->color = RED; // new node must be red

				nodeptr y = NULL;
				nodeptr x = this->_root;

				while (x != _null) {
					y = x;
					if (node->data.first < x->data.first) {
						x = x->left;
					} else {
						x = x->right;
					}
				}

				// y is parent of x
				node->parent = y;
				if (y == NULL) {
					_root = node;
				} else if (node->data.first < y->data.first) {
					y->left = node;
				} else {
					y->right = node;
				}

				// if new node is a _root node, simply return
				if (node->parent == NULL){
					node->color = BLACK;
					return;
				}

				// if the grandparent is null, simply return
				if (node->parent->parent == NULL) {
					return;
				}

				// Fix the tree
				fixInsert(node);
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
			allocator_type	_alloc;
			key_compare		_key_comp;
			value_compare	_value_comp;
			nodeptr			_root;
			nodeptr			_null;
	};
}
#endif
