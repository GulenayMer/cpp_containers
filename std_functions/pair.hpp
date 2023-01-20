/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:05 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/20 15:19:23 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

// defined in <utility>

namespace ft 
{
	/* 
		a way to store two obj.s as a single unit
	*/
	template<class T1, class T2>
	struct pair
	{
		/* memb. types */
		typedef T1	first_type;
		typedef T2	second_type;

		/* member objs */
		T1 first;
		T2 second;
		

		pair(): first(T1()), second(T2()) {};
		pair( const T1& x, const T2& y ): first(x), second(y) {};
		
		template< class U1, class U2 >
		pair( const pair<U1, U2>& p ): first(p.first), second(p.second) {};
		

		pair& operator=( const pair& other ): first(other.first), second(other.second)
		{
			return (*this);
		};
		
	};
		/* ###### non memb. func.s  ######## */
		
		/* u & t -- values to construct the pair from */
	template< class T1, class T2 >
	ft::pair<T1, T2> make_pair( T1 t, T2 u )
	{
		return (ft::pair<T1, T2>(t, u));
	};


	/* compares lhs & rhs lexicographically  */

	template< class T1, class T2 >
	bool operator==( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};

	template< class T1, class T2 >
	bool operator!=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{
		return !(lhs == rhs);
	};

	template< class T1, class T2 >
	bool operator<( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{
		return (lhs.first < rhs.first && lhs.second < rhs.second);
	};


	template< class T1, class T2 >
	bool operator<=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{
		return !(rhs < lhs);
	};
	
	template< class T1, class T2 >
	bool operator>( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{
		return (rhs < lhs);
	};

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{
		return !(lhs < rhs);
	};
}


#endif