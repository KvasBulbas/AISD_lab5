#include "HashTableTester.h"
#include <ctime>
#include <cassert>

HashTableTester::HashTableTester(const bool useConsoleOutput)
	: m_useConsoleOutput(useConsoleOutput)
{}

void HashTableTester::test(int maxSize)
{
	srand(time(NULL));
	max_size = maxSize;
	addAndClear();
	search();
	remove();
	assign();
}


void HashTableTester::addAndClear()
{
	HashTable table(max_size);
	
	for (int j = 0; j < 20; j++)
	{
		int countOfItems = 0;

		for (int i = 0; i < max_size; i++)
		{
			if (table.addValue(rand() % 300))
				countOfItems++;

			checkAdd(table, countOfItems);

		}
		/*table.printTable();
		std::cout << "New table:\n";*/

		table.clear();
		checkDestructor(table);
	}
	std::cout << "HashTableTester::addAndDestructor ended. Press any key to continue..." << std::endl;
	getchar();
}


void HashTableTester::checkAdd(HashTable table, int countOfItems)
{
	assert(table.getItems().size() == countOfItems);
}

void HashTableTester::checkDestructor(HashTable table)
{
	assert(table.getItems().size() == 0);
}


void HashTableTester::search()
{
	HashTable table(max_size);

	while (table.getItems().size() != max_size)
		table.addValue(rand() % 500);

	for (int i = 0; i < max_size; i++)
		assert(table.checkKey(i) == true);

	std::cout << "HashTableTester::search ended. Press any key to continue..." << std::endl;
	getchar();

}


void HashTableTester::remove()
{
	HashTable table(max_size);

	while (table.getItems().size() != max_size)
		table.addValue(rand() % 500);

	

	for (int i = 0; i < max_size; i++)
	{
		assert(table.deleteTableByKey(i) == true);
		assert(table.checkKey(i) == false);
	}
	/*std::cout << "new table: \n";
	table.printTable();*/

	assert(table.getItems().size() == 0);


	while (table.getItems().size() != max_size)
		table.addValue(rand() % 500);

	assert(table.deleteTableByKey(table.getItems()[max_size - 1]->key) == true);
	assert(table.deleteTableByKey(table.getItems()[max_size / 2]->key) == true);
	assert(table.deleteTableByKey(table.getItems()[0]->key) == true);

	std::cout << "HashTableTester::remove ended. Press any key to continue..." << std::endl;
	getchar();

}

void HashTableTester::assign()
{
	HashTable table1(max_size);
	for (int i = 0; i < max_size; i++)
		table1.addValue(rand() % 300);

	HashTable table2 = table1;

	

	assert(table1.getItems().size() == table2.getItems().size());


	for (int i = 0; i < table1.getItems().size(); i++)
	{
		assert(table1.getItems()[i]->key == table2.getItems()[i]->key);
		assert(table1.getItems()[i]->value == table2.getItems()[i]->value);
	}

	table1.clear();
	table2.clear();

	for (int i = 0; i < max_size; i++)
		table1.addValue(rand() % 300);

	table2 = table1;


	assert(table1.getItems().size() == table2.getItems().size());


	for (int i = 0; i < table1.getItems().size(); i++)
	{
		assert(table1.getItems()[i]->key == table2.getItems()[i]->key);
		assert(table1.getItems()[i]->value == table2.getItems()[i]->value);
	}


	std::cout << "HashTableTester::assign ended. Press any key to continue..." << std::endl;
	getchar();
}