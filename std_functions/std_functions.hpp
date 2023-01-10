/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_functions.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:41:55 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/10 15:08:13 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD_FUNCTIONS_HPP
#define STD_FUNCTIONS_HPP

// #include <type_traits>
#include <iostream>

namespace ft
{

	/* ########################## ENABLE_IF ######################## */
	
	/* useful to hide signatures on compile time when a particular
	condition is not met, since in this case, the member enavble_if::type
	will not be defined & attempting to compile using it should fail 
		- Cond is a compile-time constant of type bool.
		- T, a type
	*/
	template <bool Cond, class T = void>
	struct enable_if {};
	
	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};
	
	
	
	/* ##########################  EQUAL ######################## */

	/*
		compares the elements in the range f1, l1 with those in the range beginning
		at f2 & returns true if all of the elements in both ranges match.
	*/
	template <class InputIterator1, class InputIterator2> 
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if ( !(*first1 == *first2) )
				return false;
			++first1;
			++first2;
		}
		return true;
	};

	/*
	Binary function that accepts two elements as argument 
	(one of each of the two sequences, in the same order), and returns a value convertible to bool. 
	The value returned indicates whether the elements are considered to match in the context of this func.
	The function shall not modify any of its arguments.
	This can either be a function pointer or a function object.
	*/
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>  
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if ( pred(*first1, *first2) == false)
				return false;
			++first1;
			++first2;
		}
		return true;
	};
} 

#endif