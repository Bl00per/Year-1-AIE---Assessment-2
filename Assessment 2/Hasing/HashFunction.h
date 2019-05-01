#pragma once
#include <functional>

namespace HashFunction {
	typedef std::function<unsigned int(const char* data, unsigned int length)> HashFunc;
	//typedef unsigned int(*HashFunction)(const std::string&);

	unsigned int badHash(const char* data, unsigned int length);

	// Add functions here
	unsigned int BKDRHash(const char* data, unsigned int length);


	static HashFunc defaultHash = BKDRHash;

	// Bad Hash
	unsigned int badHash(const char* data, unsigned int length)
	{
		unsigned int hash = 0;

		for (unsigned int i = 0; i < length; i++)
		{
			hash += data[i];
		}
		return hash;
	}

	// Good Hash
	unsigned int BKDRHash(const char* data, unsigned int length)
	{
		unsigned int hash = 0;
		for (unsigned int i = 0; i < length; ++i)
		{
			hash = (hash * 1313) + data[i];
		}
		return(hash & 0x7FFFFFFF);
	}
}

