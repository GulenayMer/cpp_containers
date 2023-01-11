/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:05:52 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/10 15:05:52 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
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

}


#endif