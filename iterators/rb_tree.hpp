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
		value_type	_data;

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

	};


	/* rb tree */
	template < class T, class Key, class Compare, class Alloc = std::allocator<T>>
	class rb_tree
	{

		public :

		typedef T												value_type; 
		typedef Key												key_type; 
		typedef Compare 										key_compare;
		typedef Node<value_type>								node_type;
		typedef Node<value_type>								*node_pointer;
		typedef Alloc											allocator_type;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef rb_iterator<value_type, node_type>				iterator;
		typedef rb_iterator<const value_type, node_type>		const_iterator;
		typedef	typename allocator_type::						node_allocator;

		private:

		node_pointer	_nil;
		node_pointer	_begin;
		node_pointer	_end;
		key_compare		_compare;
		node_allocator	_nodeAll;

		

	};


	
} 



#endif