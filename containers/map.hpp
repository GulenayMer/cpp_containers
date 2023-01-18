/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:05 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/19 00:15:33 by mgulenay         ###   ########.fr       */
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
#include "../std_functions/is_integral.hpp"
#include "../std_functions/std_functions.hpp"
#include "../std_functions/lexicographical_compare.hpp"
#include "../std_functions/pair.hpp"



/*
	# key values are used to sort & identify the elm.s
	# mapped values store the content associated to this key.
	# key & mapped_value may differ ; 
	 are groupped together in member type value_type, which is a pair_type combaining both.
*/
namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T>> >
	class map 
	{
		
		public: 

		typedef Key												key_type; // a map is uniquely identified by its key value
		typedef T												mapped_type; // each elm. in a map stores some data as its mapped_value
		typedef ft::pair<const Key, T>							value_type;
		typedef Compare 										key_compare; // a binary predicate ; takes 2 keys & returns a bool
		typedef Alloc											allocator_type;
		typedef std::size_t										size_type;
		typedef std::ptrdiff_t									difference_type;
		typedef typename allocator_type::reference				reference;  // value_type&
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		typedef typename ft::bst_iterator<value_type, key_compare, allocator_type>	bst_tree;
		typedef typename ft::bst_iterator<value_type, key_compare, allocator_type>::iterator			bt_iterator;
		typedef typename ft::bst_iterator<value_type, key_compare, allocator_type>::const_iterator	const_bt_iterator;
		
		/* compares obj.s of type value_type by the first components of the pairs */
		typedef class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			friend class Map<Key, T, Compare, Alloc>; // map can access mem.of this class
			
			protected :
				Compare						_comp; // the stored comparator
				value_compare(Compare _c): _comp(_c) {}; // constructs a new v_c obj.

			public:
				// cmp.s the 2 values of type value_type
				bool operator()(const value_type& _x, const value_type& _y) const
				{
					return _comp(_x.first, _y.first);
				};
		};

		private : 

			allocator_type		_alloc_type;
			key_compare			_key_cmp;
			bst_tree 				_bst;

		public: 
			
		/* ###################     CONSTRUCTORS     ############################# */
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
			: _alloc_type(alloc), _key_cmp(comp) {};
		
		// constr.s the c with the contents of the range [first, last).
		template <class InputIterator>  map (InputIterator first, InputIterator last,       
			const key_compare& comp = key_compare(),       
			const allocator_type& alloc = allocator_type())
			: _alloc_type(alloc), _key_cmp(comp)	
		{
			// iter. through map && add values to the tree
			//	insert();
		};
		
		map (const map& x): _alloc_type(x._alloc_type), _key_cmp(x._key_cmp), _bt(x._bst)
		{};
		

		~map(){};

		map& operator= (const map& x)
		{
			if (this != &x)
			{
				_alloc_type = x._alloc_type;
				_key_cmp = x._key_cmp;
				_bst = x._bst;
			}
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
			return (_bst.size());
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
		
		/* 
			insert elm.s / nodes unless the c contains an elm. with an eq. key
			 + returns a pair consisting of an iterator to the inserted elm. &&
				bool value set to true only if the insertation took place
		*/		
		ft::pair<iterator,bool> insert (const value_type& val)
		{
			return ( _bst.insert(val) );
		};
		
		/* inserts the value in the pos. as close as poss. to the pos. prior to the pos. */
		iterator insert (iterator pos, const value_type& val)
		{
			return ( _bst.insert(pos, val) );
		};

		// inserts elm.s from range [first, last).
		template <class InputIterator>  
		void insert (InputIterator first, InputIterator last)
		{
			return ( _bst.insert(first, last) );
		};
		
		void erase (iterator pos)
		{
			return ( _bst.erase(pos) );
		};
		
		size_type erase (const key_type& k)
		{
			return ( _bst.erase(k) );
		};
		
		void erase (iterator first, iterator last)
		{
			_bst.erase(first, last);
			return ;
		};

		void swap (map& x)
		{
			_bst.swap(x._bst);
		};

		void clear()
		{
			_bst.clear();
		};



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
		iterator find (const key_type& k)
		{
			return ( _bst.find(k) );
		};

		const_iterator find (const key_type& k) const
		{
			return ( _bst.find(k) );
		};
		
		size_type count (const key_type& k) const
		{
			return ( _bst.count(k) );
		};

		iterator lower_bound (const key_type& k)
		{
			return ( _bst.lower_bound(k) );
		};
		
		const_iterator lower_bound (const key_type& k) const
		{
			return ( _bst.lower_bound(k) );
		};
		
		iterator upper_bound (const key_type& k)
		{
			return ( _bst.upper_bound(k) );
		};
		
		const_iterator upper_bound (const key_type& k) const
		{
			return ( _bst.upper_bound(k) );
		};
		
		pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return ( _bst.equal_range(k) );
		};
		
		pair<iterator,iterator> equal_range (const key_type& k)
		{
			return ( _bst.equal_range(k) );
		};

		
		/* ###########################    ALLOCATOR  ##############################  */
		allocator_type get_allocator() const
		{
			return ( _bst.get_allocator() );
		};
		
	};

	/* ###########################   NON_MEMBER FUNC.s  ##############################  */

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return ( lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()) );
	};
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	};
				
	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()) );
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(rhs < lhs);
	};
				 
	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs < lhs);
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs)
	};

	template< class Key, class T, class Compare, class Alloc >
	void swap( ft::map<Key,T,Compare,Alloc>& lhs,
           ft::map<Key,T,Compare,Alloc>& rhs )
	{
		lhs.swap(rhs);	
	};
	
}


#endif