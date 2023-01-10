/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:02:11 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/10 15:02:11 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP


#include <cstddef> // std::ptrdiff_t
#include "reverse_iterator.hpp"
#include "iterator_base.hpp"

namespace
{

	
	/*    ################ RANDOM ACCESS ITERATOR ###################### */

		/* random-access iterators can be used to access elements at an arbitrary offset position 
			relative to the element they point to, offering the same functionality as pointers
		*/
	template <typename T>
	class random_access_iterator : public iterator<random_access_iterator_tag, T>
	{

		public:
		
		typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

		protected: 
			pointer		_it_ptr;

		public:
		
		random_access_iterator() : _it_ptr(NULL) {};
		random_access_iterator(pointer ptr) : _it_ptr(ptr) {};
		random_access_iterator(const random_access_iterator<T> &src) : _it_ptr(src._it_ptr) {};
		random_access_iterator &operator=(const random_access_iterator<T> &src)
		{
			if (this != &src)
				_it_ptr = src._it_ptr;
			return (*this);
		};	
		
		virtual ~random_access_iterator() {};

		pointer base() const
		{
			return (_it_ptr);
		}

		/* ------------------------------ reference & dereference -------------------- */
		reference operator*() const
		{
			return (*_it_ptr);
		}		
		
		pointer operator->() const
		{
			return _it_ptr;
		}
	
		/* dereference with offset */
		reference operator[](difference_type n) const
		{
			return (_it_ptr + n);
		}
	
		/*  --------------------- increment & decrement ----------------------- */
		random_access_iterator operator++(int)
		{
			random_access_iterator temp(*this);
			_it_ptr += 1;
			return (temp);
		}

		random_access_iterator &operator++()
		{
			++_it_ptr;
			return (*this);
		}

		random_access_iterator operator--(int)
		{
			random_access_iterator temp(*this);
			_it_ptr -= 1;
			return (temp);
		}

		random_access_iterator &operator--()
		{
			--_it_ptr;
			return (*this);
		}

		/* ------------------- arithmetic operators --------------------- */

		/* returns a random access iterator pointing to the element located n positions away from the element the 
			iterator currently points to
		*/
		random_access_iterator operator+(difference_type n) const
		{
			return (_it_ptr + n);	
		}
	
		/* returns a reverse iterator pointing to the element located n positions before the element the 
			iterator currently points to
		*/
		random_access_iterator operator-(difference_type n)
		{
			return (_it_ptr - n);
		}

		/* advances the reverse_iterator by n elements positions */
		random_access_iterator operator+=(difference_type n)
		{
			_it_ptr += n;
			return (*this);	
		}

		/* decreases the reverse_iterator by n elements positions */
		random_access_iterator operator-=(difference_type n) const
		{
			_it_ptr -= n;
			return (*this);	
		}

	};

		/*    ################  non member function overloads for random access iterator ###################### */
	
	/* 	 Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs. */
	template <class Iterator>
	bool operator==(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs)
	{
		return ( lhs.base() == rhs.base() );
	};
	
	template <class Iterator>
	bool operator!=(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs)
	{
		return ( lhs.base() != rhs.base() );
	};
	
	template <class Iterator>
	bool operator<(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs)
	{
		return ( lhs.base() < rhs.base() );
	};
	
	template <class Iterator>
	bool operator<=(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs)
	{
		return ( lhs.base() <= rhs.base() );
	};
	
	template <class Iterator>
	bool operator>(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs)
	{
		return ( lhs.base() > rhs.base() );
	};

	template <class Iterator>
	bool operator>=(const ft::random_access_iterator<Iterator>& lhs, const ft::random_access_iterator<Iterator>& rhs)
	{
		return ( lhs.base() >= rhs.base() );
	};
	
	/* returns a reverse iterator pointing to the element located n positions away 
		from the element pointed to by rev_iter 
	*/
	template <class Iterator>
	random_access_iterator<Iterator> operator+(typename ft::random_access_iterator<Iterator>::difference_type n,
							const ft::random_access_iterator<Iterator>& rev_it)
	{
		return (rev_it.base() + n);
	};
	
	/* returns the distance between lhs & rhs */
	template <class Iterator>  
	typename random_access_iterator<Iterator>::difference_type operator-(const random_access_iterator<Iterator>& lhs,
					const random_access_iterator<Iterator>& rhs)
	{
		return (lhs.base() - rhs.base());
	};

}

#endif