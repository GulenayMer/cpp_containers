#ifndef STACK_HPP
#define STACK_HPP

#include "./vector.hpp"
/*
	stack, container adaptors, 
	LIFO , last in first out
	elements are inserted & extracted from one end of the container

	they are classes that use an encapsulated obj of a specific container class
	as its underlying container, providing a specific set of member func. to access 
	its elements.
	+ pushed/popped from the back (--top) of the specific container
*/

namespace ft 
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{

		protected:

			Container c; // underlying container

		public:

			typedef Container 							container_type;
			typedef typename Container::value_type		value_type;
			typedef typename Container::size_type		size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

			explicit stack(const Container &c_type = Container())
				: c(c_type)
			{};

			stack(const stack &other) : c(other.c){};

			~stack(){};

			stack &operator=(const stack &other)
			{
				if (this != other)
					c = other.c;
				return (*this);
			}

			/* ######### element access ################## */

			/* return reference to the top element in the stack --
				 which is the recently pushed element
				 effectively calls c.back()
			*/
			reference	top()
			{
				return (c.back());
			};

			const reference	top() const
			{
				return (c.back());
			};

			/* ######### capasity ################## */

			/* true if underlying container is empty */
			bool	empty() const
			{
				return (c.empty());
			};

			/* returns the nb. of elements in the underlying container */
			size_type	size() //const
			{
				return (c.size());
			};

			/* ######### modifiers ################## */
			void	push(const value_type &value)
			{
				return (c.push_back(value));
			};

			void	pop()
			{
				return (c.pop_back());
			}

			friend
			bool operator==( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
			{
				return (lhs.c == rhs.c);
			};

			friend
			bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
			{
				return (lhs.c < rhs.c);
			};
	};

		/* ######### non-member functions ################## */
		template< class T, class Container >
		bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{
			return !(lhs == rhs);
		};

		template< class T, class Container >
		bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{
			return !(rhs < lhs);
		};

		template< class T, class Container >
		bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{
			return (rhs < lhs);
		};

		template< class T, class Container >
		bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{
			return !(lhs < rhs);
		};
}


#endif