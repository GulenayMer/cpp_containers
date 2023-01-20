/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp          	                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:16:43 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/11 16:08:15 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RB_TREE_HPP
#define RB_TREE_HPP

#include "../iterators/iterator_base.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../std_functions/is_integral.hpp"
#include "../std_functions/std_functions.hpp"
#include "../std_functions/lexicographical_compare.hpp"
#include "../std_functions/pair.hpp"

/*
	implementation of rb tree; self balancing -- bst
*/

namespace ft
{

	/* struct for the each node */
	template <typename T>
	struct Node
	{
		typedef T	value_type; // data to store
		Node		*_root_ptr; // store the add. of the root
		Node		*_left_child; // store the add. of the left child
		Node		*_right_child; // store the add. of the right child
		bool		_is_black;
		bool		_is_left_child;
		value_type	_data;

		Node(): _root_ptr(NULL), _left_child(NULL), _right_child(NULL), _is_black(bool()), _is_left_child(bool()), _data(value_type()) {};
		Node(const value_type &value): _root_ptr(NULL), _left_child(NULL), _right_child(NULL), _is_black(bool()), _is_left_child(bool()), _data(value_type()) {};
		
		Node(const Node &src): _root_ptr(src._root_ptr), _left_child(src._left_child), _right_child(src._right_child),
							 _is_black(src._is_black), _is_left_child(src._is_left_child), _data(src._data) {};

		~Node() {};

		Node &operator=(const Node &src)
		{
			if (this != &src)
			{
				_root_ptr = src._root_ptr;
				_left_child = src._left_child;
				_right_child = src._right_child;
				_is_black = src._is_black;
				_is_left_child = src._is_left_child;
				_data = src._data; 
			}
			return (*this);
		};

	};

	template <typename N>
	bool is_left_child(const N &node_ptr)
	{
		return (node_ptr = node_ptr->_root_ptr->_left_child);
	};

	template <typename N>
	bool is_right_child(const N &node_ptr)
	{
		return (node_ptr = node_ptr->_root_ptr->_right_child);
	};

	template <typename N>
	bool is_red(const N &node_ptr)
	{
		return !(node_ptr->_is_black);
	};


	/* tree iterator */
	template <typename T, typename Itr>
	class rb_iterator
	{
		public :

		typedef T																value_type;
		typedef value_type														*pointer;
		typedef value_type														&reference;
		typedef	Itr																*iterator_type;
		typedef typename	iterator_traits<iterator_type>::difference_type		difference_type;
		typedef typename	iterator_traits<iterator_type>::value_type			node_type;
		typedef typename	iterator_traits<iterator_type>::pointer				node_pointer;
		typedef typename	iterator_traits<iterator_type>::reference	    	node_reference;
		typedef typename	iterator_traits<iterator_type>::iterator_category	iterator_category;

		private :

			node_pointer	_current_node;
			node_pointer	_nil;
			node_pointer	node_ptr;


		public :

		rb_iterator(): _current_node(NULL), _nil(NULL) {};
		rb_iterator(node_pointer current, node_pointer nil): _current_node(current), _nil(nil) {};

		rb_iterator(const rb_iterator &src): _current_node(src._current_node), _nil(src._nil) {};

		~rb_iterator(){};

		rb_iterator &operator=(const rb_iterator &src)
		{
			if (this != &src)
			{
				_current_node = src._current_node;
				_nil = src._nil;
			}
			return (*this);
		};

		node_pointer base() const 
		{
			return (_current_node);
		};

		node_pointer 	get_right_node(node_ptr node_ptr, node_ptr _nil)
		{
			while (node_ptr->_right_child != _nil)
				node_ptr = node_ptr->_right_child;
			return (node_ptr);
		};

				
		node_pointer	get_left_node(node_pointer node_ptr, node_ptr _nil)
		{
			while (node_ptr->_left_child != _nil)
				node_ptr = node_ptr->_left_child;
			return (node_ptr);
		};


	};


	/* rb tree 
			ft::rb_tree<value_type, key_type, value_compare, allocator_type>
			value_type : pair<key_type, mapped_type>
			compare : value_compare , compares obj.s of type value_type by the first components of the pairs 
	*/
	template<class T, class Key, class Compare, class Alloc = std::allocator<T>>
	class rb_tree
	{

		public :

		typedef T															value_type; 
		typedef Key															key_type; 
		typedef Compare 													key_compare;
		typedef Alloc														allocator_type;
		typedef std::size_t													size_type;
		typedef std::ptrdiff_t												difference_type;
		typedef Node<value_type>											node_type;
		typedef Node<value_type>											*node_pointer;
		typedef typename allocator_type::template rebind<node_type>::other	node_allocator;
		typedef rb_iterator<value_type, node_type>							iterator;
		typedef rb_iterator<const value_type, node_type>					const_iterator;
		typedef	typename allocator_type::									node_allocator;

		private:

		node_pointer	_rootBegin;
		node_pointer	_nodeBegin;
		node_pointer	_nodeEnd;
		key_compare		_compare;
		node_allocator	_nodeAlloc;
		size_type		_size;

		public :

		rb_tree(const key_compare &comp, const allocator_type &alloc): _compare(comp), _nodeAlloc(alloc), _size(size_type())
		{
			_rootBegin = _nodeAlloc.allocate(1);
			_nodeAlloc.construct(_rootBegin, value_type());
			_root->_is_black = true;
			_rootBegin->_root_ptr = _rootBegin;
			_rootBegin->_left_child = _rootBegin;
			_rootBegin->_right_child = _rootBegin;
			_nodeEnd = create_node(value_type());
			_nodeEnd->_is_black = true;
			_nodeBegin = _nodeEnd;
		};

		rb_tree(const rb_tree &src): _compare(src._compare), _nodeAlloc(src._nodeAlloc), _size(src._size)
		{
			_rootBegin = _nodeAlloc.allocate(1);
			_nodeAlloc.construct(_rootBegin, value_type());
			_root->_is_black = true;
			_rootBegin->_root_ptr = _rootBegin;
			_rootBegin->_left_child = _rootBegin;
			_rootBegin->_right_child = _rootBegin;
			_nodeEnd = create_node(value_type());
			_nodeEnd->_is_black = true;
			_nodeBegin = _nodeEnd;
			insert(src.begin(), src.end());
		};

		~rb_tree()
		{
			delete_node_recursive(_end);
			delete_node(_nil);
		}

		rb_tree &operator=(const rb_tree &src)
		{
			if (this != &src)
			{
				rb_tree temp(src);
				swap(temp);
			}
			return (*this);
		};


		/* iter */
		iterator	begin()
		{
			return (iterator(_nodeBegin, _rootBegin));
		};

		const_iterator	begin()
		{
			return (const_iterator(_nodeBegin, _rootBegin));
		};

		iterator	end()
		{
			return (iterator(_nodeEnd, _rootBegin));
		};

		const iterator	end()
		{
			return (const_iterator(_nodeEnd, _rootBegin));
		};

		/* capasity */
		bool	empty() const
		{
			return (_size == 0);
		};

		size_type size() const 
		{
			return (_size);
		};


	};


	
} 



#endif