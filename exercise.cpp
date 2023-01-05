#include <iostream>
#include <iterator>
#include <vector>

using namespace std;


int main()
{

	std::vector<string> planets = {"Mercury", "Venus", "Earth", "Mars", "Saturn", "Neptun"};

/* 	for (int i = 0; i < planets.size(); i++)
	{
		cout << planets[i] << endl;
	} */

	// ranged-based for loop , as of c11
	/* for (string planet : planets)
		cout << planet << endl; */

	for (vector<string>::iterator it = planets.begin(); it != planets.end(); it++)
		cout << *it << endl;

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