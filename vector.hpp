/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:11 by mgulenay          #+#    #+#             */
/*   Updated: 2022/12/21 20:27:03 by mgulenay         ###   ########.fr       */
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
#include <vector>


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

		public: 
		
		/*  ####################################  Aliases --  template parameters , types : ##########################  */
		typedef T		value_type;
		typedef Alloc	allocator_type;
	
		typedef typename allocator_type::pointer				pointer; // T*
    	typedef typename allocator_type::const_pointer			const_pointer; // const T*
		typedef typename allocator_type::reference				reference; // T&
  		typedef typename allocator_type::const_reference		const_reference; // const T&
		typedef typename allocator_type::size_type				size_type; 
		typedef typename allocator_type::difference_type		difference_type;
		typedef typename allocator_type::iterator				iterator; 
		typedef typename allocator_type::const_iterator			const_iterator;
    	typedef typename allocator_type::reverse_iterator		reverse_iterator;
		typedef typename allocator_type::const_reverse_iterator	const_reverse_iterator;


		private:
		
		/*  ####################################  Attributes : ##########################  */
		allocator_type	_allocType;  // copy of allocator_type object
		pointer 		_pointer_Arr; // pointer to allocated uninitialized storage
		size_type 		_size; // number of actual objs stored
		size_type 		_capasity; // storage capasity ( capasity >= size)
		

		public: 
		
		/* #############################     CONSTRUCTORS     ######################################## */
			
		/*
			default constructor : the container keeps & uses an internal copy of this allocator
			 (an alias to the 2. template parameter) 
		*/
		explicit vector (const allocator_type &alloc = allocator_type())
			: 	_allocType(alloc), _pointer_Arr(NULL), _size(0), _capasity(0)
		{ 
			//std::cout << GREEN << " (default) constructor called " << RESET << std::endl; 
		};
	
		/*
			constructor with parameters : Constructs a container with n elements. Initialize each elements by copying of val.
			 + allocate (size_type n, allocator<void>::const_pointer hint=0) :
				Attempts to allocate a block of storage with a size large enough to contain 
				n elements of member type value_type (an alias of the allocator's template parameter), and returns a pointer to the first element. 
			 + void construct( pointer p, const_reference val ) : constructs an object in the allocated storage 
		 */
		explicit vector (size_type n, const value_type &val = value_type(), 
						const allocator_type &alloc = allocator_type())
			: _allocType(alloc), _pointer_Arr(NULL), _size(n), _capasity(n)
		{
			_pointer_Arr = _allocType.allocate(_capasity);
			
			for (size_t i = 0; i < _size; i++)
				_allocType.construct( &_pointer_Arr[i], val );
		};
	
		/*   
			copy constructor 
		*/
		vector (const vector &x)
			: 	_allocType(x._allocType), _size(x.size), _capasity(x.capacity)
		{
			//std::cout << GREEN << " copy constructor called " << RESET << std::endl;
			_pointer_Arr = _allocType.allocate(_capasity);
			for (int i = 0; i < _size; i++)
				_allocType.construct( &_pointer_Arr[i], x.val );
		}

		// 
		vector& operator=( const vector& other )
		{
			if (*this != other)
			{
				vector tmp(x);
				swap(tmp);
				return (*this);	
			}
		};
		
		allocator_type get_allocator() const;

		
			/* ########################## DESTRUCTOR  ##############################  */
		~vector()
		{
			std::cout << RED << " destructor called " << RESET << std::endl;
	
		}

		/* ###########################     ITERATORS  ##############################  */
		
		/* iterator pointing to the first element of the vector */
		iterator begin() { return iterator(_pointer_Arr); };
		const_iterator begin() const { return const_iterator(_pointer_Arr); };
		
		/* iterator pointing to the 'past-the-end' element of the vector */
		iterator end() { return iterator(_pointer_Arr + _size); };
		const_iterator end() const { return const_iterator(_pointer_Arr + _size); };
		
		/* reverse iterator pointing to the 'before-the-first' element of the vector */
		reverse_iterator rbegin() { return reverse_iterator(_pointer_Arr - 1); };
		const_reverse_iterator rbegin() const { return const_reverse_iterator(_pointer_Arr - 1); };
		
		/* reverse iterator pointing to the last element of the vector */
		reverse_iterator rend() { return reverse_iterator(_pointer_Arr + _size - 1); };
		const_reverse_iterator rend() const { return const_reverse_iterator(_pointer_Arr + _size - 1); };

	
		/* ##########################     ELEMENT ACCESS   ##############################  */
		
		/* a reference to the element at n index  */
		reference at( size_type pos )
		{
			if ( pos >= _size )
				throw std::out_of_range("out range");
			return _pointer_Arr[pos];
		};
		
		/* a reference to the element at n index  */
		reference operator[]( size_type pos ) { return _pointer_Arr[pos]; };
		const_reference operator[]( size_type pos ) const { return _pointer_Arr[pos]; };
		
		/* Access the first element */
		reference front() { return _pointer_Arr[0]; };
		const_reference front() const { return _pointer_Arr[0]; };
		
		/* Access the last element */
		reference back() { return _pointer_Arr[_size - 1]; };
		const_reference back() const { return _pointer_Arr[_size - 1]; };
		
		T* data();

		/* ############################   CAPASITY   ##############################  */
		
		/* returns true if the vector is empty */
		bool		empty() const {  return (_size == 0); };
		
		/* returns the size of the vector  */
		size_type	size() const { return _size; };

		/* returns the maximum size that can be allocated  */
		size_type	max_size() const;
		
		/* the new capasity to be allocated */
		void		reserve(size_type new_cap)
		{
			if (new_cap > max_size())
				throw std::length_error("out of capasity");
			if (new_cap > _capasity)
				ReAlloc(new_cap);
		};

		/* returns the actual storage size allocated */
		size_type	capacity() const { return _capasity; };
		

		/* ##########################     MODIFIERS / METHODS   ##############################  */
		void clear();

		/* insert an element with a value of value at a positon pos &
			incereases the size of the vector
			needs to be reallocated if the capacity is not enough
		*/
		iterator insert( iterator pos, const value_type& value )
		{
			difference_type idx = pos - begin();
			insert(pos, 1, value);
			return iterator(&_pointer_Arr[idx]);
		};

		/* insert n elements with a value of value at a positon pos &
			incereases the size of the vector
			needs to be reallocated if the capacity is not enough
		*/
		void insert (iterator pos, size_type n, const value_type& value)
		{
			difference_type idx = pos - begin();
			
			if (_size + n > _capasity)
				ReAlloc(_capasity + n);
			
			iterator newPosition(&_pointer_Arr[idx]);
			
			// need to movethe rest of the elements from the pos
			// moveElements();
		};
		
		/* 
			removes from the vector one element & reduces size by 1 
		*/
		iterator erase( iterator pos )
		{
			return erase(pos, pos + 1);
		};

		iterator erase( iterator first, iterator last )
		{
			
		};
		
		/* adds the new element to the end ;
		 in case no capasity , has to reallocate & increase it 
		*/
		push_back(const T &value)
		{
			if (_size >= _capasity)
			{
				ReAlloc((_capasity + _size) / 2); // growing by 50%
			}
			_allocType.construct(_pointer_Arr[_size], value);
			_size += 1;
		};

		/* remove the last element */
		void pop_back()
		{
			if (_size)
				_alloc.destroy(&_pointer_Arr[_size - 1]);
				_size -= 1;
		};

		
		void resize( size_type count );
		void swap(vector &other);

		private: 

		void ReAlloc(size_t newCapasity)
		{
			// 1. allocate a new block of memory
			// 2. copy / move old elements into new block
			// 3. delete
			pointer temp = _allocType(newCapasity); // allocate()

			if (newCapasity < _size) // downsizing 
				_size = newCapasity;

			for (size_t i = 0; i < _size; i++)
				_allocType.construct(&temp[i], _pointer_Arr[i]);
			
			this->~vector(); // delete the old mem
			_pointer_Arr = temp;
			_capasity = newCapasity;
		}


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


/* 

// void construct ( pointer p, const_reference val ) :
			// Constructs an element object on the location pointed by p.

#endif