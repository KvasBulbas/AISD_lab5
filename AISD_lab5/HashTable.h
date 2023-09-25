#pragma once
#include <vector>
#include <list>
#include <iostream>


struct HashItem
{
	int value;
	int key;

};


class HashTable
{
public:
	HashTable(int size);
	HashTable(const HashTable& table);
	~HashTable();
	void clear();


	bool addValue(int K, int value);

	bool checkKey(int K);

	bool tableIsFull();

	void printTable();
	HashTable& operator=(const HashTable& table);

	bool deleteTableByKey(int k);

	int getHash(int K, int i)
	{
		const double a = (-1.0) * (1.0 - sqrt(5.0)) / 2.0;
		if (i == 0)
			return K % m_size;

		return  (int)(getHash(K, i - 1) * a * m_size) % m_size;

	}

	std::vector<HashItem*> getItems()
	{
		return m_items;
	}


private:
	int m_size;
	std::vector<HashItem*> m_items;
		

};

