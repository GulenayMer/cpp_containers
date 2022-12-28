/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:16:43 by mgulenay          #+#    #+#             */
/*   Updated: 2022/12/28 20:12:19 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <stddef.h>

/* Template paramater Iterator :
	 the iterator type to retrieve properties for 
*/
namespace ft
{
	/*    ################ ITERATOR BASE CLASS ###################### */
	template <class Category, class T, class Distance = ptrdiff_t,
        		class Pointer = T*, class Reference = T&>
  	struct iterator 
	{
    	typedef T         value_type;
    	typedef Distance  difference_type;
    	typedef Pointer   pointer;
    	typedef Reference reference;
    	typedef Category  iterator_category;
  	};
  
	/*    ################ ITERATOR TRAITS ###################### */
	/*
		Iterator Categories :  
	*/
	struct input_iterator_tag {}; // empty class to identify the category of an iterator as an input iter.
	struct output_iterator_tag {}; // empty class to identify the category of an iterator as an output iter.
	struct forward_iterator_tag {}; // empty class to identify the category of an iterator as a forward iter.
	struct bidirectional_iterator_tag {}; // empty class to identify the category of an iterator as a bidirectional iter.
	struct random_access_iterator_tag {}; // empty class to identify the category of an iterator as a rand-acc. iter.

	/* 
		traits class defining properties of iterators
	*/
	template<class Iterator>
	class iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type; // type to express the result of substracting one iterator from another
		typedef typename Iterator::value_type			value_type; // the type of the element the iterator can point to
		typedef typename Iterator::pointer 				pointer; // the type of the pointer to an element the iterator can point to
		typedef typename Iterator::reference 			reference; // the type of the reference to an element the iterator can point to
		typedef typename Iterator::iterator_category	iterator_category; 
	};

	/* 
		specilizetion for pointer & const pointer types
	*/
	template<class T>
	class iterator_traits<T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T 								value_type;
		typedef T*         						pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template <class T> 
	class iterator_traits<const T*>
	{
		typedef ptrdiff_t						difference_type;
		typedef T 								value_type;
		typedef const T*         				pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	/*    ################ REVERSE ITERATOR ###################### */
	template <class Iterator>
	class reverse_iterator
	{
		protected:
			Iterator	_it_base;
		
		public:
		
		typedef Iterator												iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;

		/* constructors */
		reverse_iterator(): _it_base(iterator_type()) {};
		explicit reverse_iterator(iterator_type it): _it_base(it) {};
		reverse_iterator(const reverse_iterator<iterator_type> &rev_it): _it_base(rev_it.base()) {};
		reverse_iterator &operator=(const reverse_iterator<iterator_type> &rev_it) 
		{
			if (*this != rev_it)
				_it_base = rev_it.base();
			return (*this);
		};

		/* returns a copy of the base iterator */
		iterator_type base(void) const
		{
			return _it_base;
		};

		~reverse_iterator() {};
		
		
		/* dereference operator , returns a reference to the element pointed by the iterator  */
		reference operator*(void) const
		{
			iterator_type temp(_it_base);
			return *(--temp);
		};

		/* dereference operator , returns a pointer to the element pointed to by the iterator  
			(in order to access one of its members) 
		*/
		pointer operator->(void) const
		{
			return ( &(operator*()) );	
		};

		/* dereference operator with offset, accesses the element located n postions away from the element 
			currently pointed to by the iterator
		*/
		reference operator[](difference_type n) const
		{
			return ( base()[-n - 1] );
		}		
		
		/*  ------------------- increment & decrement operators ------------------ */

		/* advances the reverse_iterator by one position */
		reverse_iterator operator++(int) // post-increment version returns the value *this before the call
		{
			reverse_iterator temp = *this; // temp(*this)
			_it_base -= 1; // ++(*this)?
			return (temp);
		}
		
		reverse_iterator &operator++(void) // pre-increment version returns *this
		{
			--_it_base;
			return (*this);
		}
		
		/* decreases the reverse_iterator by one position */
		reverse_iterator operator--(int)
		{
			reverse_iterator temp(*this);
			_it_base += 1;
			return (temp);
		}

		reverse_iterator &operator--(void)
		{
			++_it_base;
			return (*this);
		}

		/*  ------------------------------ arithmetic operators ----------------------- */
		
		/* returns a reverse iterator pointing to the element located n positions away from the element the 
			iterator currently points to
		*/
		reverse_iterator operator+(difference_type n) const
		{
			return ( base() - n );
		};

		/* returns a reverse iterator pointing to the element located n positions before the element the 
			iterator currently points to
		*/
		reverse_iterator operator-(difference_type n) const
		{
			return ( base() + n );
		};

		/* advances the reverse_iterator by n elements positions */
		reverse_iterator operator+=(difference_type n) const
		{
			_it_base -= n;
			return (*this);
		};

		/* decreases the reverse_iterator by n elements positions */
		reverse_iterator operator-=(difference_type n) const
		{
			_it_base += n;
			return (*this);
		};
	}

		/*    ################  non member function overloads for reverse-iterator ###################### */
	
	/* 	 Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs. */
	template <class Iterator>
	bool operator==(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() == rhs.base() );
	};
	
	bool operator!=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() != rhs.base() );
	};
	
	bool operator<(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() > rhs.base() );
	};
	
	bool operator<=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() >= rhs.base() );
	};
	
	bool operator>(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() < rhs.base() );
	};

	bool operator>=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() <= rhs.base() );
	};
	
	/* returns a reverse iterator pointing to the element located n positions away 
		from the element pointed to by rev_iter 
	*/
	template <class Iterator>
	reverse_iterator<iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n,
							const ft::reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	};
	
	/* returns the distance between lhs & rhs */
	template <class Iterator>  
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	};


	/*    ################ RANDOM ACCESS ITERATOR ###################### */

		/* random-access iterators can be used to access elements at an arbitrary offset position 
			relative to the element they point to, offering the same functionality as pointers
		*/
	template <typename T>
	class random_access_iterator
	{

		public:
		
		typedef typename iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

		protected: 
			pointer		_it_ptr;

		public:
		
		random_access_iterator() : _it_ptr(NULL) {};

		random_access_iterator(pointer ptr) : _it_ptr(ptr) {};
		
		random_access_iterator(const random_access_iterator<T> &src) : _it_ptr(src._it_ptr) {};

		random_access_iterator &operator=(const random_access_iterator<T> &src)
		{
			if (this != src)
				_it_ptr = src._it_ptr;
			return (*this);
		};
			
		virtual ~random_access_iterator() {};
	}


} 



#endif