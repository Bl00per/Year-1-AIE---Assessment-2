#pragma once
#include <functional>

namespace HashFunction {
	typedef std::function<unsigned int(const std::string& str)> HashFunc;
	//typedef unsigned int(*HashFunction)(const std::string&);

	unsigned int badHash(const char* data, unsigned int length);

	// Add functions here
	unsigned int BKDRHash(const std::string& str);


	static HashFunc defaultHash = BKDRHash;
}

