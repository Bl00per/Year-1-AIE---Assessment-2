#include <iostream>
#include <string>
#include <vector>
#include "HashFunction.h"
#include "HashTable.h"
#include "main.h"

namespace HashFunction {
	unsigned int badHash(const char* data, unsigned int length)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < length; i++)
		{
			hash += data[i];
		}
		return hash;
	}

	unsigned int BKDRHash(const std::string& str)
	{
		unsigned int hash = 0;
		for (unsigned int i = 0; i < str.length(); ++i)
		{
			hash = (hash * 1313) + str[i];
		}
		return(hash & 0x7FFFFFFF);
	}
}



int main()
{
	HashTable hash_table;
	std::string str;

	std::cin >> str;
	const char* c = str.c_str();
	int userInput_size = sizeof(c);

	std::cout << HashFunction::defaultHash(c, userInput_size) << std::endl;


	int hashTable_key = HashFunction::defaultHash("Will", 4);
	hash_table.put(15, 123901209);
	





	// get the char* using &writable[0] or &*writable.begin()


	return 0;
}