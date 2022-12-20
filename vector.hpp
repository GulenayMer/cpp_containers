/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:11 by mgulenay          #+#    #+#             */
/*   Updated: 2022/12/20 20:40:34 by mgulenay         ###   ########.fr       */
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
		pointer 		_pointer_Arr; // pointer to allocated uninitialized storage
		size_type 		_size; // number of actual objs stored
		size_type 		_capasity; // storage capasity

		
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

		/* ####################    CONSTRUCTORS  #############################
			constructs a vector, initializing its contents depending on the constructor version used : */
			
		//default constructor : the container keeps & uses an internal copy // of this allocator -- an alias to the 2. template parameter
		explicit vector (const allocator_type &alloc = allocator_type())
			: 	_allocType(alloc),  
				_pointer_Arr(NULL),
			 	_size(0),
			  	_capasity(0)
		{ std::cout << GREEN << " (default) constructor called " << RESET << std::endl; };
		 
		/* constructor with parameters : Constructs a container with n elements. Each element is a copy of val. */
		explicit vector (size_type n, const value_type &val = value_type(), 
						const allocator_type &alloc = allocator_type())
			: 	_allocType(alloc), 
				_pointer_Arr(NULL), 
				_size(n), 
				_capasity(n)
		{
			//std::cout << GREEN << " constructor with n elements called " << RESET << std::endl;
			this->_pointer_Arr = _allocType.allocate(n);
			for (size_t i = 0; i < this->_size; i++)
				this->_pointer_Arr[i] = val;
			
		};
	
		// copy constructor 
		vector (const vector &x)
			: 	_allocType(x._allocType), 
				_pointer_Arr(x._pointer_Arr), 
				_size(x.size), 
				_capasity(x.capacity)
		{
			//std::cout << GREEN << " copy constructor called " << RESET << std::endl;
			for (int i = 0; i < x.size(); i++)
				_pointer_Arr[i] = x._pointer_Arr[i];
		}

		// 
		vector& operator=( const vector& other );
		
		allocator_type get_allocator() const;

		
			/* ########################## DESTRUCTOR  ##############################  */
		~vector()
		{
			std::cout << RED << " destructor called " << RESET << std::endl;
	
		}

		/* ###########################     ITERATORS  ##############################  */
		iterator begin();
		iterator end();
		reverse_iterator rbegin();
		reverse_iterator rend();
		
		/* ##########################     ELEMENT ACCESS   ##############################  */
		reference at( size_type pos );
		reference operator[]( size_type pos );
		reference front();
		reference back();
		T* data();

		/* ############################   CAPASITY   ##############################  */
		bool		empty() const {  return (this->size) == 0 };
		size_type	size() const { return (this->size) };
		size_type	max_size() const;
		void		reserve(size_type new_cap);
		size_type	capacity() const { return (this->capacity) };
		

		/* ##########################     MODIFIERS / METHODS   ##############################  */
		void clear();
		iterator insert( const_iterator pos, const T& value );
		iterator erase( iterator pos );
		push_back(const T &value);
		void pop_back();
		void resize( size_type count );
		void swap(vector &other);
	}


	/* ##########################     NON-MEMBER FUNCTIONS   ##############################  */
	template< class T, class Alloc >
	// true if the contents of the vectors are equal, false otherwise
	bool operator==(const ft::vector<T,Alloc>& lhs,
                	const ft::vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return false;
		}
		return true;
	}

	template< class T, class Alloc >
	// return true if the contents of the vectors are not equal, false otherwise
	bool operator!=( const ft::vector<T,Alloc>& lhs,
                	const ft::vector<T,Alloc>& rhs )
	{
		if ( !(lhs == rhs) )
			return (true);
		return (false);
	}

	template< class T, class Alloc >
	// true if the contents of the lhs are lexicographically less than the contents of rhs, false otherwise
	bool operator<( const ft::vector<T,Alloc>& lhs,
                	const ft::vector<T,Alloc>& rhs );
	
	template< class T, class Alloc >
	// true if the contents of the lhs are lexicographically less than or equal to the contents of rhs, false otherwise
	bool operator<=( const ft::vector<T,Alloc>& lhs,
                	const ft::vector<T,Alloc>& rhs );
	
	template< class T, class Alloc >
	// true if the contents of the lhs are lexicographically greater than the contents of rhs, false otherwise
	bool operator>( const ft::vector<T,Alloc>& lhs,
                	const ft::vector<T,Alloc>& rhs );

	template< class T, class Alloc >
	// true if the contents of the lhs are lexicographically greater than or equal to the contents of rhs, false otherwise
	bool operator>=( const ft::vector<T,Alloc>& lhs,
                	const ft::vector<T,Alloc>& rhs );
	
}



// to dos :
// increase the capasity of the vector to a value that is greate or
// equal to new_cap  : void reserve(size_type new_cap);


/* pointer allocate (size_type n, allocator<void>::const_pointer hint=0);
				Attempts to allocate a block of storage with a size large enough to contain 
				n elements of member type value_type (an alias of the allocator's template 
				parameter), and returns a pointer to the first element. */

// void construct ( pointer p, const_reference val ) :
			// Constructs an element object on the location pointed by p.

#endif