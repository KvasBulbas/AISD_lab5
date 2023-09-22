#include "HashTable.h"




HashTable::HashTable(int size)
{
	m_size = size;

	
}

HashTable::HashTable(const HashTable& table)
{
	m_size = table.m_size;

	for (int i = 0; i < m_items.size(); i++)
		delete m_items[i];

	m_items.clear();

	for (int i = 0; i < table.m_items.size(); i++)
	{
		HashItem* item = new HashItem();
		item->key = table.m_items[i]->key;
		item->value = table.m_items[i]->value;
		m_items.push_back(item);
	}
}



HashTable::~HashTable()
{
	for (int i = 0; i < m_items.size(); i++)
		delete m_items[i];
}

void HashTable::clear()
{
	for (int i = 0; i < m_items.size(); i++)
		delete m_items[i];
	m_items.clear();

}

bool HashTable::addValue(int value)
{
	if (!tableIsFull())
	{
		std::vector<bool> pastHashes;
		pastHashes.resize(m_size);

		for (int i = 0; i < pastHashes.size(); i++)
			pastHashes[i] = 0;

		int i = 0;
		while (1)
		{			
			int currHash = getHash(value, i);

			if (pastHashes[currHash])
				return false;
			else
				pastHashes[currHash] = 1;

			//std::cout << currHash << '\n';

			if (!checkKey(currHash))
			{

				HashItem* item = new HashItem();
				item->key = currHash;
				item->value = value;

				m_items.push_back(item);
				return true;
			}
			i++;
		}
	}
	return false;
}


bool HashTable::checkKey(int K)
{	
	if(m_items.size() != 0)
		for (int i = 0; i < m_items.size(); i++)
			if (m_items[i]->key == K)
				return true;
	return false;

}

bool HashTable::tableIsFull()
{
	if (m_items.size() == m_size)
		return true;
	return false;
}



void HashTable::printTable()
{
	for (int i = 0; i < m_items.size(); i++)
		std::cout << "key = " << m_items[i]->key << " value = " << m_items[i]->value << '\n';
}


HashTable& HashTable::operator=(const HashTable& table)
{
	m_size = table.m_size;

	for (int i = 0; i < m_items.size(); i++)
		delete m_items[i];

	m_items.clear();

	for (int i = 0; i < table.m_items.size(); i++)
	{
		HashItem* item = new HashItem();
		item->key = table.m_items[i]->key;
		item->value = table.m_items[i]->value;
		m_items.push_back(item);
	}

	return *this;
}



bool HashTable::deleteTableByKey(int k)
{

	std::vector<HashItem*>::iterator it = m_items.begin();
	for (int i = 0; it != m_items.end(); it++, i++)
		if (m_items[i]->key == k)
		{
			m_items.erase(it);
			return true;
		}
	
	return false;
}


