#pragma once

template<typename K, typename V>
class HashNode { 
public:
	HashNode(K key, V value) 
	{
		this->key = key;
		this->value = value;
	}

	// Key and value pair
	K key;
	V value;
};