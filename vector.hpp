/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:11 by mgulenay          #+#    #+#             */
/*   Updated: 2022/12/19 17:58:16 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP


#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */


#include <memory>
#include <iostream>

/*
	dynamic array
	-- no need to do the vector<bool> specialization

	vector<T,A> 
	a contiguously allocated sequence of Ts;

	template < class T, class Alloc = allocator<T> > class vector;

	Allocator, a template arg. that the container uses to acquire & release memory
	std::allocator<T> uses new() & delete()

*/

namespace ft
{
	
	/* a generic class template vector */
	template < class T, class Alloc = std::allocator<T> > 
	class vector
	{
		protected:
		
		allocator_type	_allocType;
		pointer 		_pointer; // pointer to allocated uninitialized storage
		size_type 		_length;
		size_type 		_capasity;

		
		public: 
		/* template parameters , types : */
		typedef T		value_type;
		typedef Alloc	allocator_type;
	
		typedef typename allocator_type::pointer				pointer; // T*
    	typedef typename allocator_type::const_pointer			const_pointer; // const T*
		typedef typename allocator_type::reference				reference; // T&
  		typedef typename allocator_type::const_reference		const_reference; // const T&
		typedef typename allocator_type::size_type				size_type; 
   		/* typedef typename allocator_type::difference_type		difference_type; 
		typedef typename allocator_type::iterator				iterator; 
		typedef typename allocator_type::const_iterator			const_iterator;
    	typedef typename allocator_type::reverse_iterator		reverse_iterator;
		typedef typename allocator_type::const_reverse_iterator	const_reverse_iterator;
 */

		/* Constructs a vector, 
			initializing its contents depending on the constructor version used : */
			
		//default constructor : the container keeps & uses an internal copy
		// of this allocator -- an alias to the 2. template parameter
		explicit vector (const allocator_type &alloc = allocator_type()) 
			: _allocType(alloc), _pointer(NULL), _length(0), _capasity(0)
		{
			std::cout << GREEN << " (default) constructor called " << RESET << std::endl;
		}; 

		/* constructor with parameters :
			Constructs a container with n elements. Each element is a copy of val. */
		explicit vector (size_type n, const value_type &val = value_type(), 
						const allocator_type &alloc = allocator_type())
			: _allocType(alloc), _pointer(NULL), _length(n), _capasity(n)
		{
			std::cout << GREEN << " constructor with n elements called " << RESET << std::endl;
			
			/* pointer allocate (size_type n, allocator<void>::const_pointer hint=0);
				Attempts to allocate a block of storage with a size large enough to contain 
				n elements of member type value_type (an alias of the allocator's template 
				parameter), and returns a pointer to the first element. */
			this->_pointer = _allocType.allocate(n);
			for (size_t i = 0; i < this->_length; i++)
				this->_pointer[i] = val;
				 

		// void construct ( pointer p, const_reference val ) :
			// Constructs an element object on the location pointed by p.
		};
	
		// copy constructor 
		vector (const vector &x): _pointer(0), _length(0), _capasity(0), _allocType(x._allocType)
		{
			std::cout << GREEN << " copy constructor called " << RESET << std::endl;
			*this = x;
		}


		// destructor
		~vector()
		{
			std::cout << RED << " destructor called " << RESET << std::endl;
			delete[] this->_pointer;
		}
	
	}
}







#endif