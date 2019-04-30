#pragma once
#include "HashNode.h"

// Constant table size of 100
const int table_size = 100;

class HashTable {
public:
	HashTable()
	{
		// Create a new table with a pointer to the table size
		table = new HashNode*[table_size];
		// Set all the values in the table to NULL
		for (int i = 0; i < table_size; i++)
		{
			table[i] = NULL;
		}
	}

	~HashTable()
	{
		for (int i = 0; i < table_size; i++)
		{
			if (table[i] != NULL)
			{
				delete table[i];
			}
			delete[] table;
		}
	}

	// Get the value from a hash key
	int get(int key)
		{
			int hash = (key % table_size);
			while (table[hash] != NULL && table[hash]->getKey() != key)
			{
				hash = (hash + 1) % table_size;
			}

			if (table[hash] == NULL)
			{
				return -1;
			}
			else
			{
				return table[hash]->getValue();
			}
		}

	// Input data into the table
	void put(int key, int value)
	{
		int hash = (key % table_size);
		while (table[hash] != NULL && table[hash]->getKey() != key)
		{
			hash = (hash + 1) % table_size;
		}

		if (table[hash] != NULL)
		{
			delete table[hash];
		}

		table[hash] = new HashNode(key, value);
	}

private:
	HashNode **table;
};