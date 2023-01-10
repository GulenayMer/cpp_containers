/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:59:45 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/10 14:59:45 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP


#include <cstddef> // std::ptrdiff_t
#include "random_access_iterator.hpp"
#include "iterator_base.hpp"

namespace ft 
{

/*    ################ REVERSE ITERATOR -- stl_iterator.h ###################### */
	template <class Iterator>
	class reverse_iterator
	{
		protected:
			Iterator	_it_current; // called current in stl_iterator.h
		
		public:
		
		typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iterator>::value_type			value_type;
		typedef typename iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename iterator_traits<Iterator>::pointer				pointer;
		typedef typename iterator_traits<Iterator>::reference			reference;
		typedef Iterator												iterator_type;

		/* constructors */
		reverse_iterator(): _it_current() {}; // iterator_type()
		
		explicit reverse_iterator(iterator_type it): _it_current(it) {};
		
		reverse_iterator(const reverse_iterator<iterator_type> &rev_it): _it_current(rev_it.base()) {}; // rev_it._it_current
		
		reverse_iterator &operator=(const reverse_iterator<iterator_type> &rev_it) 
		{
			if (*this != rev_it)
				_it_current = rev_it.base();
			return (*this);
		};

		/* returns a copy of the base iterator */
		iterator_type base() const
		{
			return _it_current;
		};

		~reverse_iterator() {};
		
		
		/* dereference operator , returns a reference to the element pointed by the iterator  */
		reference operator*() const
		{
			iterator_type temp(_it_current); // temp == _it_current;
			return *(--temp);
		};

		/* dereference operator, returns a pointer to the element pointed to by the iterator  
			(in order to access one of its members) 
		*/
		pointer operator->() const
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
			_it_current -= 1; // ++(*this)?
			return (temp);
		}
		
		reverse_iterator &operator++(void) // pre-increment version returns *this
		{
			--_it_current;
			return (*this);
		}
		
		/* decreases the reverse_iterator by one position */
		reverse_iterator operator--(int)
		{
			reverse_iterator temp(*this);
			_it_current += 1;
			return (temp);
		}

		reverse_iterator &operator--(void)
		{
			++_it_current;
			return (*this);
		}

		/*  ------------------------------ arithmetic operators ----------------------- */
		
		/* returns a reverse iterator pointing to the element located n positions away from the element the 
			iterator currently points to
			underlying iterator must be a random access iterator
		*/
		reverse_iterator operator+(difference_type n) const
		{
			return ( base() - n ); // _it_current - n
		};

		/* returns a reverse iterator pointing to the element located n positions before the element the 
			iterator currently points to
		*/
		reverse_iterator operator-(difference_type n) const
		{
			return ( base() + n ); // _it_current + n
		};

		/* advances/moves the reverse_iterator by n elements positions / backwards n steps
		*/
		reverse_iterator operator+=(difference_type n) const
		{
			_it_current -= n;
			return (*this);
		};

		/* decreases the reverse_iterator by n elements positions */
		reverse_iterator operator-=(difference_type n) const
		{
			_it_current += n;
			return (*this);
		};
	};

		/*    ################  non member function overloads for reverse-iterator ###################### */
	
	/* 	 Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs. */
	template <class Iterator>
	bool operator==(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() == rhs.base() );
	};
	
	template <class Iterator>
	bool operator!=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( !(lhs.base() == rhs.base()) );
	};
	
	template <class Iterator>
	bool operator<(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() > rhs.base() );
	};
	
	template <class Iterator>
	bool operator<=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() >= rhs.base() );
	};
	
	template <class Iterator>
	bool operator>(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() < rhs.base() );
	};

	template <class Iterator>
	bool operator>=(const ft::reverse_iterator<Iterator>& lhs, const ft::reverse_iterator<Iterator>& rhs)
	{
		return ( lhs.base() <= rhs.base() );
	};
	
	/* returns a reverse iterator pointing to the element located n positions away 
		from the element pointed to by rev_iter 
	*/
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n,
							const ft::reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it.base() - n);
	};
	
	/* returns the distance between lhs & rhs */
	template <class Iterator>  
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{
		return (rhs.base() - lhs.base());
	};

}

#endif