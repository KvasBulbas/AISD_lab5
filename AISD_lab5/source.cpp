#include "HashTable.h"


int main()
{
	HashTable obj1(9);

	//obj1.getHash(5, 1);
	//
	//std::cout << (int)((-1.0) * (1.0 - sqrt(5.0)) / 2.0);
	//std::cout << "i = " << 3 << " hash = " << obj1.getHash(6, 3) << '\n';
	obj1.addValue(11);
	for (int i = 3; i < 50; i++)
	{
		std::cout << "i = " << i << '\n';
		obj1.addValue(i);

	}
	obj1.printTable();



}