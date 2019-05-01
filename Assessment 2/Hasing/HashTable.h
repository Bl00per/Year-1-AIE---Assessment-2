#pragma once
#include "HashNode.h"


template<typename K, typename V>
class HashTable {
public:
	HashTable()
	{
		// Initial capacity of the hash table
		capacity = 20;
		size = 0;
		table = new HashNode<K, V>*[capacity];

		// Initalise the elements of table as NULL
		for (int i = 0; i < capacity; i++)
		{
			table[i] = NULL;
		}

		// Temp node with value and key -1
		dummy = new HashNode<K, V>(-1, -1);
	}

	~HashTable()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (table[i] != NULL)
			{
				delete table[i];
			}
			delete[] table;
		}
	}


	// Function to add key and value pair
	void insertNode(K key, V value)
	{
		HashNode<K,V> *temp = new HashNode<K,V>(key, value);

		// Apply hash function to find index for given key
		int hashIndex = HashCode(key);

		// Find the next free space
		while (table[hashIndex] != NULL && table[hashIndex]->key != key && table[hashIndex]->key != -1)
		{
			hashIndex++;
			hashIndex %= capacity;
		}

		// If a new node is to be inserted, increase the current size
		if (table[hashIndex] == NULL || table[hashIndex]->key == -1)
		{
			size++;
		}

		table[hashIndex] = temp;
	}

	// Function to delete a key and value pair
	V deleteNode(int key)
	{
		// Apply hash function to find index for given key
		int hashIndex = HashCode(key);

		// Find the node with the given key
		while (table[hashIndex] != NULL)
		{
			// If the node is found
			if (table[hashIndex]->key == key)
			{
				HashNode<K, V> *temp = table[hashIndex];

				// Insert dummy node here for further use
				table[hashIndex] = dummy;

				// Reduce size of table
				size--;

				return temp->value;
			}
			hashIndex++;
			hashIndex %= capacity;
		}
		// If not found, return NULL
		return NULL;
	}

	// Function tp search the value for a given key
	V get(int key)
	{
		// Apply hash function to find index for given key
		int hashIndex = HashCode(key);
		int counter = 0;

		// Fiding the node with the given key
		while (table[hashIndex] != NULL)
		{
			int counter = 0;
			if (counter++ > capacity) // to avoid infinite loop
			{
				return NULL;
			}

			// If node found, return its value
			if (table[hashIndex]->key == key)
			{
				return table[hashIndex]->value;
			}
			
			hashIndex++;
			hashIndex %= capacity;
		}
		// If not found return NULL
		return NULL;
	}

	int HashCode(K key)
	{
		return key % capacity;
	}

	// Return current size of table
	int sizeofTable()
	{
		return size;
	}

	// Return true if size is 0
	bool isEmpty()
	{
		return size == 0;
	}

	// Display the stored key value pairs
	void display()
	{
		for (int i = 0; i < capacity; i++)
		{
			if (table[i] != NULL && table[i]->key != -1)
			{
				std::cout << "Key = " << table[i]->key << " Value = " << table[i]->value << std::endl;
			}
		}
	}

private:
	HashNode<K, V> **table;
	int capacity;

	// size of table
	int size;

	// dummy node
	HashNode<K, V> *dummy;

};