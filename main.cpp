/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:00 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/06 22:55:08 by mgulenay         ###   ########.fr       */
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
	/* std::vector<int> stlVec(5, 1) */
	
	/* std::cout << "std operator[] in stl : " << std::endl;
	for (long unsigned int i = 0; i < stlVec.size(); i++)
		std::cout << stlVec[i] << " ";
	std::cout << std::endl;
	
	std::cout << GREEN << " ####################### " << RESET << std::endl;
	
	stlVec[4] = 10;
	std::cout << "stlVec[4] = " << stlVec[4] <<std::endl;
	for (long unsigned int i = 0; i < stlVec.size(); i++)
		std::cout << stlVec[i] <<" ";
	std::cout << std::endl;
	
	std::cout << GREEN << " ####################### " << RESET << std::endl;
	ft::vector<int> ftVec(5, 1);
	
	std::cout << "std operator[] in ft : " << std::endl;
	for (long unsigned int i = 0; i < ftVec.size(); i++)
		std::cout << ftVec[i] <<" ";
	std::cout << std::endl;
	
	ftVec[4] = 80;
	std::cout <<"ftVec[4] = " << ftVec[4] <<std::endl;
	for (long unsigned int i = 0; i < ftVec.size(); i++)
		std::cout << ftVec[i] <<" ";
	std::cout << std::endl; */
	

	/* ############################  CAPASITY   ##############################  */
/* 	std::cout << "std size() in stl : " << std::endl;
	std::cout << stlVec.size() << " ";
	std::cout << std::endl;
	
	std::cout << GREEN << " ####################### " << RESET << std::endl;

	std::cout << "std size() in ft : " << std::endl;
	std::cout << ftVec.size() << " ";
	std::cout << std::endl;

	std::cout << GREEN << " ---------------- " << RESET << std::endl;

	std::cout << "std empty() in stl : " << std::endl;
	std::cout << stlVec.empty() << " ";
	std::cout << std::endl;
	
	std::cout << GREEN << " ####################### " << RESET << std::endl;

	std::cout << "std empty() in ft : " << std::endl;
	std::cout << ftVec.empty() << " ";
	std::cout << std::endl;  */
	

	/* ############################ METHODS  ##############################  */
	/* ft::vector<int> ftVec1;
	
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
	std::cout << " new size : " << ftVec1.size() << std::endl;

	std::cout << GREEN << " ---------------- " << RESET << std::endl;
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

	
	std::cout << GREEN << " ---------------- " << RESET << std::endl;
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
	std::cout << " After erase() ----> size : " << ftVec3.size() << std::endl;

 */
	std::cout << GREEN << " ---------------- " << RESET << std::endl;
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
	std::cout << "]\n";

	
	std::cout << GREEN << " ---------------- " << RESET << std::endl;
	std::cout << YELLOW << " Testing assign() " << RESET << std::endl;
	ft::vector<int> ftObj2;
	ft::vector<int> ftObj3;
	ftObj2.assign(9, 7);
	ftObj.assign(2, 5);
	std::cout << " After assign() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftObj2.size(); i++)
		std::cout << ftObj2[i] << " ";
	std::cout << "]\n";

	std::cout << " After assign() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftObj.size(); i++)
		std::cout << ftObj[i] << " ";
	std::cout << "]\n";

	ft::vector<int>::iterator it;
	it = ftObj2.begin() + 4;
	ftObj.assign(it, ftObj2.end() - 1);
	std::cout << " After assign() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftObj.size(); i++)
		std::cout << ftObj[i] << " ";
	std::cout << "]\n";
	
	return 0;
}