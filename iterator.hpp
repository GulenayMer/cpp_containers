/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:16:43 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/09 13:31:33 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <cstddef> // std::ptrdiff_t


namespace ft
{
	
	/*    ################ ITERATOR TRAITS (feature/attribute) ###################### */
	/*
		used to distinguish different iterators, built for different abilities.
		Iterator Categories : iterator_category :  
	*/
	
	class input_iterator_tag {}; // identifies the category of an iterator as an input iter.
	class output_iterator_tag {}; // identifies the category of an iterator as an output iter.
	class forward_iterator_tag : public input_iterator_tag {}; // identifies the category of an iterator as a forward iter.
	class bidirectional_iterator_tag : public forward_iterator_tag {}; // identifies the category of an iterator as a bidirectional iter.
	class random_access_iterator_tag : public bidirectional_iterator_tag {}; // identifies the category of an iterator as a rand-acc. iter.
	
	/*    ################ ITERATOR BASE CLASS -- std::iterator ###################### */

		/* 
			# iterator base class template can be used to derive iterator classes from it.
			# simplifies definitions of the required types for iterators.
			# does not provide any of the functionality an iterator is expected to have.
		*/
	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
  	class iterator
	{
		public : 
    		typedef Category  iterator_category;
    		typedef T         value_type; // the type pointed to by the iterator
    		typedef Distance  difference_type; // distance btw iterators is represented as this type
    		typedef Pointer   pointer; // represents a pointer to value_type
    		typedef Reference reference; // represents a reference to value_type
  	};
  

	/* 
		traits class defining properties of iterators
		Iterator stands for the type of the iterator. Thus, we can write code that
		uses for any iterator in its category, the types of its elements, etc. 
		# this structure has 2 advantages: 
		1) it ensures that an iterator provides all type definition.
		2) It can be (partially) specialized for (sets of) special iterators. This is done
		for ordinary iterators that also can be used as iterators.
	*/
	template<class Iterator> // iterator type, can be also T
	class iterator_traits
	{
		public:
		typedef typename Iterator::iterator_category	iterator_category; 
		typedef typename Iterator::value_type			value_type; // the type of the element the iterator can point to
		typedef typename Iterator::difference_type		difference_type; // type to express the result of substracting one iterator from another
		typedef typename Iterator::pointer 				pointer; // the type of the pointer to an element the iterator can point to
		typedef typename Iterator::reference 			reference; // the type of the reference to an element the iterator can point to
	};

	/* 
		partial specialization for pointer & const pointer types
		# for any type "pointer to T", it is defined that it has the random acc. iter. category.
	*/
	template<class T>
	class iterator_traits<T*>
	{
		public: 
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T 								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*         						pointer;
		typedef T&								reference;
	};

	template <class T> 
	class iterator_traits<const T*>
	{
		public:
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T 								value_type;
		typedef ptrdiff_t						difference_type;
		typedef const T*         				pointer;
		typedef const T&						reference;
	};



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