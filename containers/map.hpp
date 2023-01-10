/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:05 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/10 15:52:08 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_HPP
#define MAP_HPP


#include <memory> // std::allocator
#include <functional> // std::less
#include <iostream>
#include "../iterators/iterator_base.hpp"
#include "../iterators/random_access_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../std_functions/is_integral.hpp"
#include "../std_functions/std_functions.hpp"
#include "../std_functions/lexicographical_compare.hpp"

namespace ft
{
	// key type; mapped type; key compare; 
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T>> >
	class map 
	{
		
		public: 

		typedef Key										key_type;
		typedef T										mapped_type;
		typedef ft::pair<const key_type, mapped_type>	value_type;
		typedef Compare 								key_compare;
		typedef Alloc									allocator_type;
		typedef typename allocator_type					type_allocator;
		typedef typename pointer						pointer;
		typedef typename const_pointer					const_pointer;
		typedef typename reference						reference;
		typedef typename const_reference				const_reference;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;

	
		/* ###################     CONSTRUCTORS     ############################# */
		explicit map (const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()){};
		
		template <class InputIterator>  map (InputIterator first, InputIterator last,       
			const key_compare& comp = key_compare(),       
			const allocator_type& alloc = allocator_type()){};
		
		map (const map& x){};
		

		~map(){};

		map& operator= (const map& x){};

		/* ###########################     ITERATORS  ##############################  */
		
		iterator begin(){};
		const_iterator begin() const{};
		iterator end(){};
		const_iterator end() const{};
		reverse_iterator rbegin(){};
		const_reverse_iterator rbegin() const{};
		reverse_iterator rend(){};
		const_reverse_iterator rend() const{};
		

		/* ###########################   CAPASITY  ##############################  */

		bool empty() const{};
		size_type size() const{};
		size_type max_size() const{};


		/* ##########################     ELEMENT ACCESS   ##############################  */
		mapped_type& operator[] (const key_type& k){};
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
		key_compare key_comp() const{};
		value_compare value_comp() const{};
		


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