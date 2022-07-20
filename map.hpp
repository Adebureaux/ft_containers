#ifndef MAP_HPP
# define MAP_HPP

#include "tools.hpp"
#include "bidirectional_iterator.hpp"


namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map {
		struct Node {
			T data; // holds the key
			Node *parent; // pointer to the parent
			Node *left; // pointer to left child
			Node *right; // pointer to right child
			bool color; // 1 -> Red, 0 -> Black
		};
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
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t									difference_type;
			typedef	size_t											size_type;
			typedef Node											*nodeptr;
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
				_null = new Node;
				_null->color = 0;
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
				delete _null;
			};


		private:
			void initializeNULLNode(nodeptr node, nodeptr parent) {
				node->data = 0;
				node->parent = parent;
				node->left = NULL;
				node->right = NULL;
				node->color = 0;
			};
			void preOrderHelper(nodeptr node) {
				if (node != _null) {
					std::cout<<node->data<<" ";
					preOrderHelper(node->left);
					preOrderHelper(node->right);
				}
			}

			void inOrderHelper(nodeptr node) {
				if (node != _null) {
					inOrderHelper(node->left);
					std::cout<<node->data<<" ";
					inOrderHelper(node->right);
				}
			}

			void postOrderHelper(nodeptr node) {
				if (node != _null) {
					postOrderHelper(node->left);
					postOrderHelper(node->right);
					std::cout<<node->data<<" ";
				} 
			}

			nodeptr searchTreeHelper(nodeptr node, int key) {
				if (node == _null || key == node->data) {
					return node;
				}

				if (key < node->data) {
					return searchTreeHelper(node->left, key);
				}
				return searchTreeHelper(node->right, key);
			}

			// fix the rb tree modified by the delete operation
			void fixDelete(nodeptr x) {
				nodeptr s;
				while (x != _root && x->color == 0) {
					if (x == x->parent->left) {
						s = x->parent->right;
						if (s->color == 1) {
							// case 3.1
							s->color = 0;
							x->parent->color = 1;
							leftRotate(x->parent);
							s = x->parent->right;
						}

						if (s->left->color == 0 && s->right->color == 0) {
							// case 3.2
							s->color = 1;
							x = x->parent;
						} else {
							if (s->right->color == 0) {
								// case 3.3
								s->left->color = 0;
								s->color = 1;
								rightRotate(s);
								s = x->parent->right;
							} 

							// case 3.4
							s->color = x->parent->color;
							x->parent->color = 0;
							s->right->color = 0;
							leftRotate(x->parent);
							x = _root;
						}
					} else {
						s = x->parent->left;
						if (s->color == 1) {
							// case 3.1
							s->color = 0;
							x->parent->color = 1;
							rightRotate(x->parent);
							s = x->parent->left;
						}

						if (s->right->color == 0 && s->right->color == 0) {
							// case 3.2
							s->color = 1;
							x = x->parent;
						} else {
							if (s->left->color == 0) {
								// case 3.3
								s->right->color = 0;
								s->color = 1;
								leftRotate(s);
								s = x->parent->left;
							}

							// case 3.4
							s->color = x->parent->color;
							x->parent->color = 0;
							s->left->color = 0;
							rightRotate(x->parent);
							x = _root;
						}
					} 
				}
				x->color = 0;
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

			void deleteNodeHelper(nodeptr node, int key) {
				// find the node containing key
				nodeptr z = _null;
				nodeptr x, y;
				while (node != _null){
					if (node->data == key) {
						z = node;
					}

					if (node->data <= key) {
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
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						} else {
							if (k == k->parent->left) {
								// case 3.2.2
								k = k->parent;
								rightRotate(k);
							}
							// case 3.2.1
							k->parent->color = 0;
							k->parent->parent->color = 1;
							leftRotate(k->parent->parent);
						}
					} else {
						u = k->parent->parent->right; // uncle

						if (u->color == 1) {
							// mirror case 3.1
							u->color = 0;
							k->parent->color = 0;
							k->parent->parent->color = 1;
							k = k->parent->parent;
						} else {
							if (k == k->parent->right) {
								// mirror case 3.2.2
								k = k->parent;
								leftRotate(k);
							}
							// mirror case 3.2.1
							k->parent->color = 0;
							k->parent->parent->color = 1;
							rightRotate(k->parent->parent);
						}
					}
					if (k == _root) {
						break;
					}
				}
				_root->color = 0;
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
					std::cout<<_root->data<<"("<<sColor<<")"<<std::endl;
					printHelper(_root->left, indent, false);
					printHelper(_root->right, indent, true);
				}
				// cout<<_root->left->data<<endl;
			}

			void deleteHelper(nodeptr _root) {
				if (_root != _null) {
					deleteHelper(_root->left);
					deleteHelper(_root->right);
					delete _root;
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
			void insert(T key) {
				deleteNode(key);
				// Ordinary Binary Search Insertion
				nodeptr node = new Node;
				node->parent = NULL;
				node->data = key;
				node->left = _null;
				node->right = _null;
				node->color = 1; // new node must be red

				nodeptr y = NULL;
				nodeptr x = this->_root;

				while (x != _null) {
					y = x;
					if (node->data < x->data) {
						x = x->left;
					} else {
						x = x->right;
					}
				}

				// y is parent of x
				node->parent = y;
				if (y == NULL) {
					_root = node;
				} else if (node->data < y->data) {
					y->left = node;
				} else {
					y->right = node;
				}

				// if new node is a _root node, simply return
				if (node->parent == NULL){
					node->color = 0;
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
			void deleteNode(int data) {
				deleteNodeHelper(this->_root, data);
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
