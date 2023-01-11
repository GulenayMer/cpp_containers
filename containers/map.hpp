/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:05 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/11 16:09:28 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
#define MAP_HPP


#include <memory> // std::allocator
#include <functional> // std::less
#include <iostream>
#include "../iterators/iterator_base.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/bst_iterator.hpp"
/* #include "../std_functions/is_integral.hpp"
#include "../std_functions/std_functions.hpp"
#include "../std_functions/lexicographical_compare.hpp" */
#include "../std_functions/pair.hpp"



/*
	# key values are used to sort & identify the elm.s
	# mapped values store the content associated to this key.
	# key & mapped_value may differ ; 
	 are groupped together in member type value_type, which is a pair_type combaning both.
*/
namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T>> >
	class map 
	{
		
		public: 

		typedef Key												key_type; // a map is uniquely identified by its key value
		typedef T												mapped_type; // each elm. in a map stores some data as its mapped_value
		typedef ft::pair<const key_type, mapped_type>			value_type;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef Compare 										key_compare; // a binary predicate ; takes 2 keys & returns a bool
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;  // value_type&
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef typename ft::bst_iterator<value_type, key_compare, allocator_type>	bst_tree;
		typedef typename ft::bst_iterator<value_type, key_compare, allocator_type>::iterator			bt_iterator;
		typedef typename ft::bst_iterator<value_type, key_compare, allocator_type>::const_iterator	const_bt_iterator;
		
		//typedef class value_compare {}

		private : 

			allocator_type		_alloc_type;
			key_compare			_key_cmp;
			bst_tree 				_bst;

		public: 
			
		/* ###################     CONSTRUCTORS     ############################# */
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
			: _alloc_type(alloc), _key_cmp(comp) {};
		
		template <class InputIterator>  map (InputIterator first, InputIterator last,       
			const key_compare& comp = key_compare(),       
			const allocator_type& alloc = allocator_type())
			: _alloc_type(alloc), _key_cmp(comp)	
		{
			// iter. through map && add values to the tree
		};
		
		map (const map& x): _alloc_type(x._alloc_type), _key_cmp(x._key_cmp), _bt(x._bst)
		{};
		

		~map(){};

		map& operator= (const map& x): _alloc_type(x._alloc_type), _key_cmp(x._key_cmp), _bt(x._bst)
		{
			return (*this);
		};


		/* ###########################     ITERATORS  ##############################  */
		
		iterator begin()
		{ 
			return (_bst.begin())
		};
		
		const_iterator begin() const
		{
			return (_bst.begin())
		};
		
		iterator end()
		{
			return (_bst.end());
		};
		
		const_iterator end() const
		{
			return (_bst.end());
		};

		reverse_iterator rbegin()
		{
			return (_bst.rbegin());
		};
		
		const_reverse_iterator rbegin() const
		{
			return (_bst.rbegin());
		};
		
		reverse_iterator rend()
		{
			return (_bst.rend());
		};
		
		const_reverse_iterator rend() const
		{
			return (_bst.rend());
		};
		

		/* ###########################   CAPASITY  ##############################  */

		bool empty() const
		{
			return (_bst.empty());
		};
		
		size_type size() const
		{
			return (_bst.sie());
		};
		
		size_type max_size() const
		{
			return (_bst.max_size());
		};


		/* ##########################     ELEMENT ACCESS   ##############################  */
		mapped_type& operator[] (const key_type& k)
		{};
		mapped_type& at (const key_type& k);const mapped_type& at (const key_type& k) const{};


		/* ##########################     MODIFIERS / METHODS   ##############################  */
		pair<iterator,bool> insert (const value_type& val){};
		iterator insert (iterator position, const value_type& val){};
		template <class InputIterator>  void insert (InputIterator first, InputIterator last){};
		
		void erase (iterator position){};
		size_type erase (const key_type& k){};
		void erase (iterator first, iterator last){};

		void swap (map& x){};

		void clear(){};



		/* ###########################    OBSERVERS  ##############################  */
		key_compare key_comp() const
		{
			return (_key_cmp);
		};

		value_compare value_comp() const
		{
			return (value_compare(_key_cmp));
		};
		


		/* ###########################    OPERATIONS  ##############################  */
		iterator find (const key_type& k){};
		const_iterator find (const key_type& k) const{};
		size_type count (const key_type& k) const{};
		iterator lower_bound (const key_type& k){};
		const_iterator lower_bound (const key_type& k) const{};
		iterator upper_bound (const key_type& k){};
		const_iterator upper_bound (const key_type& k) const{};
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const{};
		pair<iterator,iterator> equal_range (const key_type& k){};

		
		/* ###########################    ALLOCATOR  ##############################  */
		allocator_type get_allocator() const{};


		
	};


	
}


#endif