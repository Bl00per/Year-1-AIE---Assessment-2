#pragma once

class HashNode { 
public:
	HashNode(int m_key, int m_value) 
	{
		const int key = m_key;
		const int value = m_value;
	}

	// Get the key for the hash
	char getKey()
	{
		return key;
	}

	// Get the value of the hash
	int getValue()
	{
		return value;
	}

private:
	// Key and value pair
	int key;
	int value;
};