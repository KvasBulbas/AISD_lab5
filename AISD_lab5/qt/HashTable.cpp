#include "HashTable.h"



HashTable::HashTable()//правильно ли работет
{
    m_size = 0;


}

void HashTable::resize(int size)
{
    if(size > m_size)
    {

        m_items.resize(size);
        for (int i = m_size; i < size; i++)
            m_items[i] = nullptr;
        m_size = size;
    }
    else
        if(size < m_size)
        {
            for (int i = size; i < m_size; i++)
                delete m_items[i];

            m_items.resize(size);
            m_size = size;
        }
}


HashTable::HashTable(int size)//правильно ли работет
{
	m_size = size;
	m_items.resize(size);
	for (int i = 0; i < size; i++)
		m_items[i] = nullptr;

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
		if (table.m_items[i])
		{
			item->key = table.m_items[i]->key;
			item->value = table.m_items[i]->value;
		}
		else
			item = nullptr;
		m_items.push_back(item);
	}
}



HashTable::~HashTable()
{
	for (int i = 0; i < m_items.size(); i++)
	{
		delete m_items[i];
		m_items[i] = nullptr;
	}
}

void HashTable::clear()
{
	for (int i = 0; i < m_items.size(); i++)
	{
		delete m_items[i];
		m_items[i] = nullptr;
	}

}

int HashTable::addValue(int K, int value)//правильно ли работает
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
			int currHash = getHash(K, i);

			if (pastHashes[currHash])
                return -1;
			else
				pastHashes[currHash] = 1;

			//std::cout << currHash << '\n';

			if (m_items[currHash]==nullptr)
			{

				HashItem* item = new HashItem();
				item->key = K;
				item->value = value;


				m_items[currHash] = item;
                return currHash;
			}
			i++;
		}
	}
    return -1;
}


int HashTable::checkKey(int K)//посмотреть правильно ли работает
{	

	for (int i = 0; i < m_items.size(); i++)
		if (m_items[i] && m_items[i]->key == K)
            return i;
    return -1;

}

bool HashTable::tableIsFull()//правильно ли работет
{
	for (int i = 0; i < m_items.size(); i++)
		if (m_items[i] == nullptr)
			return false;
	
	return true;
}



void HashTable::printTable()
{
	for (int i = 0; i < m_items.size(); i++)
        if(m_items[i])
            std::cout << "hash = " << i << " key = " << m_items[i]->key << " value = " << m_items[i]->value << std::endl;
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
		if (table.m_items[i])
		{
			item->key = table.m_items[i]->key;
			item->value = table.m_items[i]->value;
		}
		else
			item = nullptr;
		m_items.push_back(item);
	}

	return *this;
}



bool HashTable::deleteTableByKey(int k)
{

	std::vector<HashItem*>::iterator it = m_items.begin();
	for (int i = 0; it != m_items.end(); it++, i++)
		if (m_items[i] && m_items[i]->key == k)
		{
			delete m_items[i];
			m_items[i] = nullptr;

			return true;
		}
	
	return false;
}


