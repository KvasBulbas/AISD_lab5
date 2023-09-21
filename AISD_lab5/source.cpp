#include "HashTable.h"


int main()
{
	HashTable obj1(50);

	//obj1.getHash(5, 1);
	//
	//std::cout << (int)((-1.0) * (1.0 - sqrt(5.0)) / 2.0);
	//std::cout << "i = " << 3 << " hash = " << obj1.getHash(6, 3) << '\n';
	for (int i = 0; i < 300; i++)
		obj1.addValue(i);


	obj1.printTable();


	obj1.deleteTableByKey(23);
	obj1.printTable();


}