


#include <map>
#include <iostream>

using namespace std;

int main()
{
	std::map<int, std::string> m;

	m.insert( std::pair<int, string>(1, "Lola") );
	m.insert( std::pair<int, string>(2, "Nona") );

	std::cout << "map Contains:\n";
	std::map<int, string>::iterator itr;
	for ( itr = m.begin(); itr != m.end(); ++itr)
	{
		cout << "Key =>" << itr->first << ", Value => " << itr->second.c_str() <<endl;
	}


	return 0; 
}