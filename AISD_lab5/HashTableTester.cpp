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
			if (table.addValue(rand() % max_size, rand() % 500))
				countOfItems++;
			//std::cout << "Count of items:" << countOfItems << '\n';

			//table.printTable();
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
	int count = 0;
	for (int i = 0; i < max_size; i++)
		if (table.getItems()[i])
			count++;
	//std::cout << "Count: " << count << '\n';

	assert(count == countOfItems);
}

void HashTableTester::checkDestructor(HashTable table)
{
	int count = 0;
	for (int i = 0; i < max_size; i++)
		if (table.getItems()[i])
			count++;
	assert(count == 0);
}


void HashTableTester::search()
{
	HashTable table(max_size);
	int j = 0;
	for(int i = 0; i < max_size; i++)
		table.addValue(i, rand() % 500);

	//std::cout << "asasdasd";
	//table.printTable();

	for (int i = 0; i < max_size; i++)
		assert(table.checkKey(i) == true);

	std::cout << "HashTableTester::search ended. Press any key to continue..." << std::endl;
	getchar();

}


void HashTableTester::remove()
{
	HashTable table(max_size);

	for (int i = 0; i < max_size; i++)
		table.addValue(i, rand() % 500);


	

	for (int i = 0; i < max_size; i++)
	{
		assert(table.deleteTableByKey(i) == true);
		assert(table.checkKey(i) == false);
	}
	/*std::cout << "new table: \n";
	table.printTable();*/
	for (int i = 0; i < max_size; i++)
		assert(table.getItems()[i] == nullptr);


	for (int i = 0; i < max_size; i++)
		table.addValue(i, rand() % 500);

	//table.printTable();
	
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
		table1.addValue(rand() % 300, rand() % 500);

	HashTable table2 = table1;

	

	assert(table1.getItems().size() == table2.getItems().size());


	for (int i = 0; i < table1.getItems().size(); i++)
	{
		if (table1.getItems()[i])
		{
			assert(table1.getItems()[i]->key == table2.getItems()[i]->key);
			assert(table1.getItems()[i]->value == table2.getItems()[i]->value);
		}
		else
			assert(table1.getItems()[i] == table2.getItems()[i]);
	}

	table1.clear();
	table2.clear();

	for (int i = 0; i < max_size; i++)
		table1.addValue(rand() % 300, rand() % 500);

	table2 = table1;


	assert(table1.getItems().size() == table2.getItems().size());


	for (int i = 0; i < table1.getItems().size(); i++)
	{
		if (table1.getItems()[i])
		{
			assert(table1.getItems()[i]->key == table2.getItems()[i]->key);
			assert(table1.getItems()[i]->value == table2.getItems()[i]->value);
		}
		else
			assert(table1.getItems()[i] == table2.getItems()[i]);
	}


	std::cout << "HashTableTester::assign ended. Press any key to continue..." << std::endl;
	getchar();
}