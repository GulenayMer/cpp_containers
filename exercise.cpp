
#include "vectorExample.hpp"

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

}