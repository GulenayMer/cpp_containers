
#include <algorithm>
#include <numeric>
#include "vector.hpp"
#include "iterator.hpp"
#include "std_functions.hpp"
#include <iostream>

int main ()
{

	/* ############################  CAPASITY   ##############################  */

	ft::vector<int> myVec;
	myVec.push_back(0);
	myVec.push_back(1);
	myVec.push_back(2);
	myVec.push_back(3);

	ft::vector<int>::iterator it;
	it = myVec.begin();
	std::cout <<"Vector elements are: ";
	for (unsigned i = 0; i < myVec.size(); i++)
		std::cout <<myVec.at(i) <<" ";
	std::cout <<std::endl;

	std::cout << "it = " << *it <<std::endl;
	std::cout <<"Pre-increment operator ++it: " << *(++it) << std::endl;
	std::cout <<"Post-increment operator it++: " << *(it++) << " " << *it << std::endl;
	std::cout <<"Pre-decrement operator --it: " << *(--it) << std::endl;
	std::cout <<"Post-decrement operator it--: " << *(it--) << " " << *it << std::endl;


/* ft::vector<int>::iterator it2 = it + 3;
	std::cout <<std::endl <<"Testing equality operator ==" <<std::endl;
	std::cout <<"it = " <<*it <<",  it2 = " <<*it2 <<std::endl;
	std::cout <<"it == it2 is ";
	if (it2 == it)
		std::cout <<"true" <<std::endl;
	else 
		std::cout <<"false" <<std::endl;
	it2 = it;
	std::cout <<"it = " <<*it <<",  it2 = " <<*it2 <<std::endl;
	std::cout <<"it == it2 is ";
	if (it2 == it)
		std::cout <<"true" <<std::endl;
	else 
		std::cout <<"false" <<std::endl;

	std::cout <<std::endl <<"Testing inequality operator !=" <<std::endl;
	it2 = myVec.end() - 1;
	std::cout <<"it = " <<*it <<",  it2 = " <<*it2 <<std::endl;
	std::cout <<"it != it2 is ";
	if (it2 != it)
		std::cout <<"true" <<std::endl;
	else 
		std::cout <<"false" <<std::endl;
	it2 = it;
	std::cout <<"it = " <<*it <<",  it2 = " <<*it2 <<std::endl;
	std::cout <<"it != it2 is ";
	if (it2 != it)
		std::cout <<"true" <<std::endl;
	else 
		std::cout <<"false" <<std::endl;
	
	
 */
	return 0;
}