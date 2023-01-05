/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgulenay <mgulenay@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 14:56:00 by mgulenay          #+#    #+#             */
/*   Updated: 2023/01/05 14:50:08 by mgulenay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <iterator>
#include "vector.hpp"
#include "iterator.hpp"
#include "std_functions.hpp"
#include <iostream>


int main()
{
	std::vector<int> stlVec(5, 1);
	
	/*   reference operator    */
	std::cout << "std operator[] in stl : " << std::endl;
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
	std::cout << std::endl;
	

	/* ############################  CAPASITY   ##############################  */
	std::cout << "std size() in stl : " << std::endl;
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
	std::cout << std::endl;
	
	ft::vector<int> ftVec1;
	ftVec1.push_back(5);
	ftVec1.push_back(10);
	std::cout <<std::endl <<"ft::Vec1: ";
	for (unsigned long int i = 0; i < ftVec1.size(); i++)
		std::cout <<ftVec1.at(i) <<" ";
		
	return 0;
}