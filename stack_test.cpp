
#include <algorithm>
#include <numeric>
#include <iostream>
/* #include <vector>
#include <stack> */
#include "./containers/vector.hpp"
#include "./iterators/iterator_base.hpp"
#include "./iterators/random_access_iterator.hpp"
#include "./iterators/reverse_iterator.hpp"
#include "./std_functions/std_functions.hpp"
#include "./std_functions/is_integral.hpp"
#include "./std_functions/lexicographical_compare.hpp"


int main(void)
{

	std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Stack -- container vector " << RESET << std::endl;
	 
	std::stack<int, std::vector<int> > stdStack;
	ft::stack<int, ft::vector<int> > ftStack;

	std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " testing push() & top() " << RESET << std::endl;

	stdStack.push(5);
	ftStack.push(5);

	std::cout << "stdStack : " << "[ " << stdStack.top() << "]\n" 
	<< " ftStack : " << "[ " << ftStack.top() << "]" << std::endl;

	stdStack.push(50);
	ftStack.push(50);

	std::cout << "stdStack : " << "[ " << stdStack.top() << "]\n" 
	<< " ftStack : "  << "[ " << ftStack.top() << "]" << std::endl;

	std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " testing size() & empty() " << RESET << std::endl;

	std::cout << "stdStack empty?: " << stdStack.empty() << "\n" 
	<< " ftStack empty? : "  << ftStack.empty() << std::endl;

	std::cout << "stdStack size : " << stdStack.size() << "\n" 
	<< " ftStack size : " << ftStack.size() << std::endl;


	std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " testing pop() " << RESET << std::endl;

	stdStack.pop();
	ftStack.pop();

  	std::cout << "stdStack : " << "[ " << stdStack.top() << "]\n" 
	<< " ftStack : "  << "[ " << ftStack.top() << "]" << std::endl;

	return 0;

}