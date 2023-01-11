/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:07:07 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/10 15:07:07 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft
{
	/* ########################## IS_INTEGRAL ######################## */

	/*  trait class that identifies whether T is an integral type
		- template takes T as parameter
		- value_type is bool
		- type either true_type or false_type
	 */
	template <class T> 
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
}


#endif