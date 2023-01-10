/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_base.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:16:43 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/10 15:03:23 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_BASE_HPP
#define ITERATOR_BASE_HPP

#include <cstddef> // std::ptrdiff_t


namespace ft
{
	
	/*    ################ ITERATOR TRAITS (feature/attribute) ###################### */
	/*
		used to distinguish different iterators, built for different abilities.
		Iterator Categories : iterator_category :  
	*/
	
	class input_iterator_tag {}; // identifies the category of an iterator as an input iter.
	class output_iterator_tag {}; // identifies the category of an iterator as an output iter.
	class forward_iterator_tag : public input_iterator_tag {}; // identifies the category of an iterator as a forward iter.
	class bidirectional_iterator_tag : public forward_iterator_tag {}; // identifies the category of an iterator as a bidirectional iter.
	class random_access_iterator_tag : public bidirectional_iterator_tag {}; // identifies the category of an iterator as a rand-acc. iter.
	
	/*    ################ ITERATOR BASE CLASS -- std::iterator ###################### */

		/* 
			# iterator base class template can be used to derive iterator classes from it.
			# simplifies definitions of the required types for iterators.
			# does not provide any of the functionality an iterator is expected to have.
		*/
	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
  	class iterator
	{
		public : 
    		typedef Category  iterator_category;
    		typedef T         value_type; // the type pointed to by the iterator
    		typedef Distance  difference_type; // distance btw iterators is represented as this type
    		typedef Pointer   pointer; // represents a pointer to value_type
    		typedef Reference reference; // represents a reference to value_type
  	};
  

	/* 
		traits class defining properties of iterators
		Iterator stands for the type of the iterator. Thus, we can write code that
		uses for any iterator in its category, the types of its elements, etc. 
		# this structure has 2 advantages: 
		1) it ensures that an iterator provides all type definition.
		2) It can be (partially) specialized for (sets of) special iterators. This is done
		for ordinary iterators that also can be used as iterators.
	*/
	template<class Iterator> // iterator type, can be also T
	class iterator_traits
	{
		public:
		typedef typename Iterator::iterator_category	iterator_category; 
		typedef typename Iterator::value_type			value_type; // the type of the element the iterator can point to
		typedef typename Iterator::difference_type		difference_type; // type to express the result of substracting one iterator from another
		typedef typename Iterator::pointer 				pointer; // the type of the pointer to an element the iterator can point to
		typedef typename Iterator::reference 			reference; // the type of the reference to an element the iterator can point to
	};

	/* 
		partial specialization for pointer & const pointer types
		# for any type "pointer to T", it is defined that it has the random acc. iter. category.
	*/
	template<class T>
	class iterator_traits<T*>
	{
		public: 
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T 								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*         						pointer;
		typedef T&								reference;
	};

	template <class T> 
	class iterator_traits<const T*>
	{
		public:
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T 								value_type;
		typedef ptrdiff_t						difference_type;
		typedef const T*         				pointer;
		typedef const T&						reference;
	};

} 

#endif