/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomAccessIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:15:22 by mgulenay          #+#    #+#             */
/*   Updated: 2022/12/22 17:06:52 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RANDOMACCESSITERATOR_HPP
#define RANDOMACCESSITERATOR_HPP

/* 
	random-access iterators can be used to access elements at
	an arbitrary offset position relative to the element they 
	point to, offering the same functionality as pointer.

	These iterators are the most complete iterators in terms of
	functionality. All pointer types are also valid random-access
	iterators.

	

*/

namespace ft
{
	template<typename T, bool B>
	class ReverseIterator;

class RandomAccessIterator
{
private:
	/* data */
public:
	RandomAccessIterator(/* args */);
	~RandomAccessIterator();
};

RandomAccessIterator::RandomAccessIterator(/* args */)
{
}

RandomAccessIterator::~RandomAccessIterator()
{
}






	
}

#endif