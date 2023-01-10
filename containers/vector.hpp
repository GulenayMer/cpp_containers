/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:11 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/10 15:08:32 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory> // std::allocator
#include <iostream>
#include "iterator_base.hpp"
#include "random_access_iterator.hpp"
#include "reverse_iterator.hpp"
#include "std_functions.hpp"
#include "is_integral.hpp"
#include "lexicographical_compare.hpp"


#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

/*
	vector<T,A>
	a contiguously allocated sequence of Ts;

	template < class T, class Alloc = allocator<T> > class vector;

	Allocator, a template arg. that the container uses to acquire & release memory
	std::allocator<T> uses new() & delete()
*/

namespace ft
{
	/* a generic class template vector */
	template < 
		class T, 
		class Alloc = std::allocator<T>
	> 
	class vector
	{

		public:
		
		/*  ######################   Aliases --  template parameters , types : #####################  */
		typedef T														value_type;
		typedef Alloc													allocator_type;
		typedef typename allocator_type::reference						reference; // T&
  		typedef typename allocator_type::const_reference				const_reference; // const T&
		typedef typename allocator_type::pointer						pointer; // T*
    	typedef typename allocator_type::const_pointer					const_pointer; // const T*
		typedef typename ft::random_access_iterator<value_type>			iterator; 
		typedef typename ft::random_access_iterator<const value_type>	const_iterator;
    	typedef typename ft::reverse_iterator<value_type>				reverse_iterator;
		typedef typename ft::reverse_iterator<const value_type>			const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type	difference_type; // ptrdiff_t
		typedef typename allocator_type::size_type							size_type; // size_t

		private:
		
		/*  ####################################  Attributes : ##########################  */
		allocator_type	_allocType;  // copy of allocator_type object
		pointer 		_pointer_Arr; // pointer to allocated uninitialized storage
		size_type 		_size; // number of actual objs stored
		size_type 		_capasity; // storage capasity ( capasity >= size)
		

		public: 
		
		/* ###################     CONSTRUCTORS     ############################# */
			
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
			constructor with parameters : Constructs a container with n elements. I
			Initialize each elements by copying of val.
			 + allocate (size_type n, allocator<void>::const_pointer hint=0) :
				Attempts to allocate a block of storage with a size large enough to contain 
				n elements of member type value_type (an alias of the allocator's template parameter), 
				and returns a pointer to the first element. 
			 + void construct( pointer p, const_reference val ) : constructs an object in the allocated storage 
		 */
		explicit vector (size_type n, const value_type &val = value_type(),
						const allocator_type &alloc = allocator_type())
			: _allocType(alloc), _pointer_Arr(NULL), _size(n), _capasity(n)
		{
			_pointer_Arr = _allocType.allocate(n);
			
			for (size_type i = 0; i < n; i++)
				_allocType.construct( &_pointer_Arr[i], val ); // _pointer_Arr + i
		};

		/*
			copy constructor
		*/
		vector (const vector &x)
			: 	_allocType(allocator_type()), _pointer_Arr(NULL), _size(0), _capasity(0)
		{
			//std::cout << GREEN << " copy constructor called " << RESET << std::endl;
		/* 	_pointer_Arr = _allocType.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				_allocType.construct( &_pointer_Arr[i], x.); */
				*this = x;
		}

	/* 	vector& operator=( const vector& x)
		{
			if (this != &x)
			{
				clear();
				assign(x.begin(), x.end());
			}
			return (*this);	
		}; */
		
		allocator_type get_allocator() const
		{
			return (Alloc(_allocType));
		};

		
			/* ########################## DESTRUCTOR  ##############################  */
		~vector()
		{
			//std::cout << RED << " destructor called " << RESET << std::endl;
			clear();
			if (_capasity > 0)
				_allocType.deallocate(_pointer_Arr, _capasity);
		}

		/* ###########################     ITERATORS  ##############################  */
		
		/* iterator pointing to the first element of the vector ; returns it to beginnig*/
		iterator begin() 
		{ 
			return iterator(_pointer_Arr); 
		};

		const_iterator cbegin() const 
		{ 
			return const_iterator(_pointer_Arr); 
		};
		
		/* iterator pointing to the 'past-the-end' element of the vector; returns it to end */
		iterator end()
		{ 
			return iterator(_pointer_Arr + _size); 
		};
		
		const_iterator cend() const 
		{ 
			return const_iterator(_pointer_Arr + _size);
		};
		
		/* reverse iterator pointing to the 'before-the-first' element of the vector */
		reverse_iterator rbegin() 
		{ 
			return reverse_iterator(end());
		};  
			//return reverse_iterator(_pointer_Arr - 1); 
		
		const_reverse_iterator crbegin() const 
		{ 
			//return const_reverse_iterator(_pointer_Arr - 1); 
			return const_reverse_iterator(end());
		};
		
		/* reverse iterator pointing to the last element of the vector */
		reverse_iterator rend() 
		{ 
			//return reverse_iterator(_pointer_Arr + _size - 1); 
			return reverse_iterator(begin());
		}; 
		
		const_reverse_iterator crend() const 
		{ 
			//return const_reverse_iterator(_pointer_Arr + _size - 1);
			return const_reverse_iterator(begin());
		}; 


		/* ############################   CAPASITY   ##############################  */
		
		/* returns the size of the vector  */
		size_type	size() const
		{ 
			return _size; 
		};
		
		/* returns the maximum size that can be allocated  */
		size_type	max_size() const
		{
			return (_allocType.max_size());
		};
		
		/* resizes the container so that it contains n elements
			-- if n < size; the content is reduced to its first n elements; 
				removing those beyond & destroying them
			-- if n > size; the content is expanded by inserting at the end as many
			elements as needed to reach a size of n. 
			-- if n > capasity; reallocation of the allocated storge space occurs.
			!!this func. changes the actual content of the cont. by inserting / erasing elm.from it!!
		 */
		void resize (size_type n, value_type val = value_type())
		{
			if (n > _capasity)
				reserve(n);
			if (n >= _size)
			{
				for (size_type i = _size; i < n; i++)
					_allocType.construct(&_pointer_Arr[i], val);
			}
			else
			{
				for (size_type i = n; i < _size; i++)
					_allocType.destroy(&_pointer_Arr[i]);
				_capasity = n;
			}
			_size = n;
		};
		
		/* returns the actual storage size allocated */
		size_type	capacity() const 
		{ 
			return (_capasity); 
		};
		
		/* returns true if the vector is empty */
		bool		empty() const 
		{  
			return (_size == 0); 
		};
		
		/* increases the capasity of the vector to a value that is ' >= new_cap'
			if new_cap is > the current capasity , new stroage is allocated,
			! reserve does not change the size of the vector !
			+ new_cap : in nb. of elements
		 */
		void		reserve(size_type new_cap)
		{
			if ( new_cap > max_size() )
				throw std::length_error("ft::reserve() : out of max. permitted size");
			else if (new_cap > _capasity)
				ReAlloc(new_cap);
		};

	
		/* ##########################     ELEMENT ACCESS   ##############################  */
		
		/* a reference to the element at n index  */
		reference operator[]( size_type pos ) 
		{ 
			return _pointer_Arr[pos];
		};
		
		const_reference operator[]( size_type pos ) const
		{ 
			return _pointer_Arr[pos];
		};
		
		/* a reference to the element at n index  */
		reference at(size_type pos)
		{
			if (pos >= _size)
				throw std::out_of_range("ft::vector::at Out of Range");
			return _pointer_Arr[pos];
		};

		const_reference at (size_type pos) const
		{
			if (pos >= _size)
				throw std::out_of_range("ft::vector::at Out of Range");
			return _pointer_Arr[pos];
		};
		
		/* Access the first element */
		reference front() 
		{ 
			return _pointer_Arr[0]; // *begin();
		};
		
		const_reference front() const 
		{
			return _pointer_Arr[0]; // *begin();
		};
		
		/* Access the last element */
		reference back() 
		{ 
			return _pointer_Arr[_size - 1];  // *(end() - 1)
		};
		
		const_reference back() const 
		{
			 return _pointer_Arr[_size - 1];  // *(end() - 1)
		};
		

		/* ##########################     MODIFIERS / METHODS   ##############################  */
		
		/* 	
			assigns new contents to the vector, replacing its current contents
			& modifying its size accordingly.
			++ any element held in the container before the call are destroyed &
				replaced by newly constructed element
			++ no capasity ? reallocate
		*/
	//	typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0 
	// used to prevent error : invalid type argument of unary ‘*’ (have ‘int’)
		template <class InputIterator>  
		void	assign (InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0 )
		{
			clear();
			while (first != last)
			{
				push_back(*first);
				++first;
			}	
		};
		
		/* new content are n elements , each initialized to a copy of val */
		void	assign (size_type n, const value_type& val)
		{
			clear();
			while (n)
			{
				push_back(val);
				--n;
			}
		};

		/* 
			adds the new element to the end of the container;
			+ the new element is initialized as a copy of value,
			+ increases the container size by one -- 
		 	in case no capasity , has to reallocate & increase it 
		*/
		void	push_back(const T &value)
		{
			if (_size == _capasity)
				empty() ? reserve(1) : reserve(_size * 2);
	/* 	if (_size >= _capasity)
		{
			ReAlloc((_capasity + _size) / 2); // growing by 50%
		}  */
			_allocType.construct(&_pointer_Arr[_size], value);
			_size += 1;
		};

		/* 
			remove the last element 
			+ reduces the container size by 1.
			+ destroys the removed element, 
			check the size; otherwise < 0 would be problem
		*/
		void	pop_back()
		{
			if (_size > 0)
			{
				_allocType.destroy(&_pointer_Arr[_size - 1]);
				_size -= 1;
			}
		};

		
		/*  inserts new elements with a value of value before the element at the 
			specified position
			+ incereases the size of the vector,
			+ needs to be reallocated if the capacity is not enough
			++ returns an iterator that points to the first of the newly inserted elements.
			-- iterator : random access iterator type
		*/
	/* 	iterator insert(iterator pos, const value_type& value)
		{
			difference_type difference = pos - begin();
			insert(pos, 1, value);
			return iterator(&_pointer_Arr[difference]);
		};
 */
		
	/* 	void insert (iterator pos, size_type n, const value_type& value)
		{
			difference_type idx = pos - begin();
			
			if (_size + n > _capasity)
				ReAlloc(_capasity + n);
			
			iterator newPosition(&_pointer_Arr[idx]);
			
			// need to movethe rest of the elements from the pos
			// moveElements();
		}; */
		
		/*  copies of the elements are inserted at position in the same order
			+ it includes all the elements btw first & last, but element pointed by first 
			not included.
		*/
	/* 	template <class InputIterator>    
		void insert (iterator pos, InputIterator first, InputIterator last)
		{
			
		}; */
		
		/* 
			removes from the vector either one element or a range of elements [first, last)  
			+ reduces the container size by the nb. of elements removed--destroyed
			++ return value : an iterator pointing to the new location of the element that
			followed the last element erased by the func call. 
			iterator is a random access iterator type that points to elements.
		*/
		iterator	erase( iterator pos )
		{
			/* if ( empty())
				return (end()); */
			iterator it = begin();
			std::cout << " start " << *it << std::endl;
			while (it != pos)
				it += 1;
			std::cout << " item to destroy " << *it << std::endl;
			std::cout << " address " << &(*it) << std::endl;
			_allocType.destroy(&(*it));
			while (it + 1 != end())
			{
				std::cout << " items after destroyed element " << *(it + 1) << std::endl;
				_allocType.construct(&(*it), *(it + 1));
				it += 1;
			}
			pop_back(); // otherwise the last element is added 2 times
			std::cout << " pos " << *(pos) << std::endl;
			return (pos);
		};
	
		iterator	erase( iterator first, iterator last )
		{
			/* if (empty())
				return (end()); */
			iterator it = begin();
			iterator pos = first;
			difference_type distance = last - first;
			std::cout << " distance " << (distance) << std::endl;
			while (it != first)
				it += 1;
			for (; first != last; first++)
				_allocType.destroy(&(*first));
			while (it + distance != end())
			{
				std::cout << " items after destroyed element " << *(it + distance) << std::endl;
				_allocType.construct(&(*it), *(it + distance));
				it += 1;
			}
			while (distance-- > 0)
				pop_back();
			return (pos);
		};
		
		/*
			exchanges the content of the container by the content of x,
			which is another vector object of the same type. Sizes may differ.
			all iterators & references remain valid.
		*/
		void	swap(vector &x)
		{
			allocator_type	temp_alloc = _allocType;
			pointer 		temp_pointer = _pointer_Arr;
			size_type		temp_capasity = _capasity;
			size_type 		temp_size = _size;
			
			_allocType =  x._allocType;
			_pointer_Arr = x._pointer_Arr;
			_capasity = _capasity;
			_size = x._size;

			x._allocType = temp_alloc;
			x._pointer_Arr = temp_pointer;
			x._capasity = temp_capasity;
			x._size = temp_size;
		};

		/*
			clears content -- removes all elements from the vector -- 
			+ leaving the container with a size of 0
			+ leaves the capasity of the vector unchanged 
		*/
		void	clear()
		{
			if (_size > 0)
			{
				for (iterator it = begin(); it != end(); it++)
					_allocType.destroy(&(*it));
				_size = 0;
			}
		};
		
		
		
		/* ##########################   ALLOCATOR  ##############################  */

		/* returns a copy of the allocator obj assosiated with the vector */
		//allocator_type get_allocator() const;

		
		/* ##########################    PRIVATE METHODS   ##############################  */

		private: 

		/* allocates a new block of memory 
			copies / moves old elements into new block
			deletes 
		*/
		void ReAlloc(size_t newCapasity)
		{
			pointer temp = _allocType.allocate(newCapasity);

			for (size_type i = 0; i < _size; i++)
				_allocType.construct(&temp[i], _pointer_Arr[i]);
			
			//this->~vector(); // delete the old mem
			_allocType.deallocate(_pointer_Arr, _capasity);
			_pointer_Arr = temp;
			_capasity = newCapasity;
		}
	};


	/* ##########################     NON-MEMBER FUNCTIONS OVERLOADS   ##############################  */
	
	/* 
		performs the appropriate comparison operation btw the vector containers lhs & rhs 
	*/
	
	template< class T, class Alloc >
	/* first compares its sizes ; if match then elements are compared sequentially; 
		stops at the first mismatch
	 */
	bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
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
	bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}

	template< class T, class Alloc >
	// true if the contents of the lhs are lexicographically less than the contents of rhs, false otherwise
	bool operator<(ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};
	
	template< class T, class Alloc >
	// true if the contents of the lhs are lexicographically less than or equal to the contents of rhs, false otherwise
	bool operator<=(ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		return !(lhs > rhs);
	};
	
	template< class T, class Alloc >
	// true if the contents of the lhs are lexicographically greater than the contents of rhs, false otherwise
	bool operator>(ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{ 
		return (rhs < lhs);
	};

	template< class T, class Alloc >
	// true if the contents of the lhs are lexicographically greater than or equal to the contents of rhs, false otherwise
	bool operator>=(ft::vector<T,Alloc>& lhs, ft::vector<T,Alloc>& rhs )
	{
		return !(lhs < rhs);
	};

	template< class T, class Alloc >
	void swap(vector<T, Alloc>&x, vector<T, Alloc>&y)
	{
		x.swap(y);
	};
	
}

#endif

// to dos :
// increase the capasity of the vector to a value that is greate or
// equal to new_cap  : void reserve(size_type new_cap);


/* 
 void construct ( pointer p, const_reference val ) :
 Constructs an element object on the location pointed by p.
*/
