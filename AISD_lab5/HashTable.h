#pragma once
#include <vector>
#include <list>
#include <iostream>

class HashTable
{
public:
	HashTable();
	HashTable(int size);
	~HashTable();

	int getHash(int K, int i) const
	{
		const double a = (-1.0) * (1.0 - sqrt(5)) / 2.0;


		if (i == 0)
			return (int)(K * a * m_size) % m_size;

		return (int)(getHash(K, i - 1) * a * m_size) % m_size;


	}


private:
	int m_size;
	std::vector<std::list <int>> m_table;




	

};

