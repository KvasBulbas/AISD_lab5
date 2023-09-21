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



	bool addValue(int value);

	bool checkKey(int K);

	bool tableIsFull();

	void printTable();



	int getHash(int K, int i)
	{
		const double a = (-1.0) * (1.0 - sqrt(5.0)) / 2.0;
		//std::cout << K << ' ' << i << '\n';



		if (i == 0)
		{
			int c = (int)(K * a * m_size) % m_size;
			//std::cout << "C = " << c << '\n';
			return c;
		}


		int b = ((int)(getHash(K, i - 1) * a * m_size)) % m_size;
		//std::cout << "b = " << b << '\n';


		return b;

		//return (int)(getHash(K, i - 1) * a * m_size) % m_size;


	}


private:
	int m_size;

	std::vector<HashItem*> m_items;
		

};

