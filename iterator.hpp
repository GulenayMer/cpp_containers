/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:16:43 by mgulenay          #+#    #+#             */
/*   Updated: 2022/12/22 17:26:07 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <stddef.h>

/* Template paramater Iter :
	 the iterator type to retrieve properties for 
*/
namespace ft
{
	template<class Iter>
	struct iterator_traits
	{
		typedef typename difference_type 	Iter::difference_type;
		typedef typename value_type 		Iter::value_type;
		typedef typename pointer 			Iter::pointer;
		typedef typename reference 			Iter::reference;
		typedef typename iterator_category 	Iter::iterator_category;
	}

} 



#endif