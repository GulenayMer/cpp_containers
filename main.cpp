/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:00 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/07 13:11:55 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <iterator>
#include "vector.hpp"
//#include "iterator.hpp"
#include "std_functions.hpp"
#include <iostream>


int main()
{
	/* ############################  CAPASITY   ##############################  */

	/* ft::vector<int> ftVec(5, 1);

 	std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing size() " << RESET << std::endl;
	std::cout << ftVec.size() << std::endl;

	std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing empty() " << RESET << std::endl;
	std::cout << ftVec.empty() << std::endl;
	
	std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing capasity() " << RESET << std::endl;
	std::cout << ftVec.capacity() << std::endl; */
	
	std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing resize() " << RESET << std::endl;
	ft::vector<int> myvector;

  // set some initial content:
  	for (unsigned i=1; i < 10; i++) 
		myvector.push_back(i);
  	std::cout << " Before resize() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < myvector.size(); i++)
		std::cout << myvector[i] << " ";
	std::cout << "]\n";
  
  	myvector.resize(5);
 	myvector.resize(8,100);
  	myvector.resize(12);

  	std::cout << " After resize() ----> ft::vector : " << "[ ";
 	for (unsigned i=0; i < myvector.size(); i++)
    	std::cout << myvector[i] << " ";
  	std::cout << "]\n";
  
	/* ############################ METHODS  ##############################  */
/* 	ft::vector<int> ftVec1;
	
	std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing push_back() & pop_back() " << RESET << std::endl;
	ftVec1.push_back(5);
	ftVec1.push_back(10);
	ftVec1.push_back(1);
	ftVec1.push_back(-40);
	ftVec1.push_back(3);
	
	std::cout << " ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftVec1.size(); i++)
		std::cout << ftVec1[i] << " ";
	std::cout << "]\n";
	std::cout << " size : " << ftVec1.size() << std::endl;
	ftVec1.pop_back();
	std::cout << " ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftVec1.size(); i++)
		std::cout << ftVec1[i] << " "; 
	std::cout << "]\n";
	std::cout << " new size : " << ftVec1.size() << std::endl; */

	/* std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing clear() " << RESET << std::endl;
	ft::vector<int> ftVec2;
	ftVec2.push_back(5);
	ftVec2.push_back(10);
	ftVec2.push_back(1);
	std::cout << " Before clear() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftVec2.size(); i++)
		std::cout << ftVec2[i] << " ";
	std::cout << "]\n";
	std::cout << " Before clear() ----> size : " << ftVec2.size() << std::endl;
	std::cout << " Before clear() ----> capasity : " << ftVec2.capacity() << std::endl;
	ftVec2.clear();
	std::cout << " After clear() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftVec2.size(); i++)
		std::cout << ftVec2[i] << " "; 
	std::cout << "]\n";
	std::cout << " After clear() ----> size : " << ftVec2.size() << std::endl;
	std::cout << " After clear() ----> capasity : " << ftVec2.capacity() << std::endl;
 */
	
	/* std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing erase(...) " << RESET << std::endl;
	ft::vector<int> ftVec3;
	ftVec3.push_back(58);
	ftVec3.push_back(100);
	ftVec3.push_back(13);
	ftVec3.push_back(1);
	ftVec3.push_back(-20);
	std::cout << " Before erase() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftVec3.size(); i++)
		std::cout << ftVec3[i] << " ";
	std::cout << "]\n";
	std::cout << " Before erase() ----> size : " << ftVec3.size() << std::endl;

	ftVec3.erase(ftVec3.begin() + 2);
	std::cout << " After erase() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftVec3.size(); i++)
		std::cout << ftVec3[i] << " ";
	std::cout << "]\n";
	std::cout << " After erase() ----> size : " << ftVec3.size() << std::endl;

	ftVec3.erase(ftVec3.begin() + 1, ftVec3.begin() + 3);
	std::cout << " erase() with a range ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftVec3.size(); i++)
		std::cout << ftVec3[i] << " "; 
	std::cout << "]\n";
	std::cout << " After erase() ----> size : " << ftVec3.size() << std::endl; */


	/* std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing swap() " << RESET << std::endl;
	ft::vector<int> ftObj(3, 100);
	ft::vector<int> ftXobj(4, 200);
	std::cout << " Before swap() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftObj.size(); i++)
		std::cout << ftObj[i] << " ";
	std::cout << "]\n";
	ftObj.swap(ftXobj);
	std::cout << " After swap() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftObj.size(); i++)
		std::cout << ftObj[i] << " ";
	std::cout << "]\n"; */

	
	/* std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing assign() " << RESET << std::endl;
	ft::vector<int> ftObj2;
	ft::vector<int> ftObj3;
	ftObj2.assign(9, 7);
	ftObj.assign(2, 5);
	std::cout << " After assign() ----> ft::vector : " << "[ ";
	for (unsigned i = 0; i < ftObj2.size(); i++)
		std::cout << ftObj2[i] << " ";
	std::cout << "]\n";

	std::cout << " After assign() ----> ft::vector : " << "[ ";
	for (unsigned i = 0; i < ftObj.size(); i++)
		std::cout << ftObj[i] << " ";
	std::cout << "]\n";

	ft::vector<int>::iterator it;
	it = ftObj2.begin() + 4;
	ftObj.assign(it, ftObj2.end() - 1);
	std::cout << " After assign() ----> ft::vector : " << "[ ";
	for (unsigned i = 0; i < ftObj.size(); i++)
		std::cout << ftObj[i] << " ";
	std::cout << "]\n"; */


	/* ############################ ELEMENT ACCESS  ##############################  */
	
	/* std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing at[] " << RESET << std::endl;
	ft::vector<int> myvector (10);

  // assign some values:
	for (unsigned i=0; i < myvector.size(); i++)
		myvector.at(i)=i;

  	std::cout << "myvector contains:";
  	for (unsigned i=0; i < myvector.size(); i++)
    	std::cout << ' ' << myvector.at(i);
  	std::cout << '\n'; */
	
/* 	std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing front() & back() " << RESET << std::endl;

	ft::vector<int> myvector2;

	myvector2.push_back(78);
  	myvector2.push_back(16);

	myvector2.front() -= myvector2.back();

  	std::cout << "myvector2.front() is now " << myvector2.front() << '\n'; */
  
	return 0;
}