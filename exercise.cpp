#include <iostream>
#include <iterator>
#include <vector>

using namespace std;


int main()
{


	std::vector<int> ftObj(3, 100);
	std::vector<int> ftObj2;
	ftObj2.assign(9, 7);

	std::cout << " After assign() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftObj2.size(); i++)
		std::cout << ftObj2[i] << " ";
	std::cout << "]\n";

	/* std::vector<int>::iterator it;
	it = ftObj2.begin() + 4;
	ftObj.assign(it, ftObj2.end() - 1); */
	std::cout << " After assign() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftObj.size(); i++)
		std::cout << ftObj[i] << " ";
	std::cout << "]\n";
	
	/* std::vector<int> ftVec3;
	std::cout << " Before erase() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftVec3.size(); i++)
		std::cout << ftVec3[i] << " ";
	std::cout << "]\n";
	std::cout << " Before erase() ----> size : " << ftVec3.size() << std::endl;

	ftVec3.erase(ftVec3.begin());
	std::cout << " After erase() ----> ft::vector : " << "[ ";
	for (unsigned long int i = 0; i < ftVec3.size(); i++)
		std::cout << ftVec3[i] << " "; 
	std::cout << "]\n";
	std::cout << " After erase() ----> size : " << ftVec3.size() << std::endl; */

	//std::vector<string> planets = {"Mercury", "Venus", "Earth", "Mars", "Saturn", "Neptun"};

/* 	for (int i = 0; i < planets.size(); i++)
	{
		cout << planets[i] << endl;
	} */

	// ranged-based for loop , as of c11
	/* for (string planet : planets)
		cout << planet << endl; */

	/* for (vector<string>::iterator it = planets.begin(); it != planets.end(); it++)
		cout << *it << endl; */

	return 0;
}












/* #include "vectorExample.hpp"

template<typename T>
void PrintData(const vectorExample<T> &myvector)
{
	for (size_t i = 0; i < myvector.Size(); i++)
		std::cout << myvector[i] << "\n";
}

int main()
{
	vectorExample<int> myvector(2);

  for (int i=0; i<4; i++) myvector.PushBack(i);

  std::cout << "size: " << myvector.Size() << "\n";
  std::cout << "capacity: " << myvector.Capasity() << "\n";

  PrintData(myvector);
  return 0;

} */