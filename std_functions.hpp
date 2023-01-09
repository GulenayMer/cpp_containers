/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_functions.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:41:55 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/09 18:58:24 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STD_FUNCTIONS_HPP
#define STD_FUNCTIONS_HPP

// <type_traits>
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
	
	
	/* ########################## IS_INTEGRAL ######################## */

	/*  trait class that identifies whether T is an integral type
		- template takes T as parameter
		- value_type is bool
		- type either true_type or false_type
	 */
	template <typename T> 
	struct is_integral
	{
		static const bool value = false;
	};

	/*   ------ fundamental integral types -------  */
	template <>
	struct is_integral<bool>
	{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<char>
	{
		static const bool value = true;
	};
	
/* 	template <>
	struct is_integral<char16_t>
	{
		static const bool value = true;
	};
 */
	/* template <>
	struct is_integral<char32_t>
	{
		static const bool value = true;
	};
	 */
	template <>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<signed char>
	{
		static const bool value = true;
	};
	

	template <>
	struct is_integral<short int>
	{
		static const bool value = true;
	};


	template <>
	struct is_integral<int>
	{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<long int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<long long int>
	{
		static const bool value = true;
	};
	
	template <>
	struct is_integral<unsigned char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned short int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned long int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<unsigned long long int>
	{
		static const bool value = true;
	};

	template <typename T>
	struct is_integral<const T> : is_integral<T> {};
	
	template <typename T>
	struct is_integral<volatile T> : is_integral<T> {};

	template <typename T>
	struct is_integral<const volatile T> : is_integral<T> {};

	
	/* ########################## LEXICOGRAPHICAL_COMPARE ######################## */
	
	/* this comparasion is generally used to sort words alphabetically;
		involves comparing sequentially the elements that have the same
		position in both ranges against each other until one element is not
		equivalent to the other. 
		The result of these first non-matching elements is the result of the 
		lexi.comparison.
	*/
	
	/* 
		- first1, last1 : Input iterators of the first sequence.
		includes all elements btw f1 & l1 (except l1).
		- first2, last2 : Input iterators to the initial & final positions
		of the second sequence. 
	*/
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
					InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1 += 1;
			first2 += 1;
		}
		return (first2 != last2);
	};

	/*
	Binary function that accepts two arguments of the types pointed by the iterators, and
	returns a value convertible to bool. The value returned indicates whether the first argument is 
	considered to go before the second in the specific strict weak ordering it defines.
	The function shall not modify any of its arguments.
	This can either be a function pointer or a function object.
	*/
	template <class InputIterator1, class InputIterator2, class Compare> 
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, 
								InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (comp(*first1, *first2))
				return false;
			else if (comp(*first2, *first1))
				return true;
			first1 += 1;
			first2 += 1;
		}
		return (first2 != last2);					
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