// ~~~*Reference*~~~
//
// Title: C++ Program to Implement Hash Tables
// Author: Karthikeya Boyini
// Date: 2019
// Availablity: https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables
//


#include <iostream>
#include <string>
#include "HashFunction.h"
#include "HashTable.h"


int main()
{
	HashTable<int, int> *hash_table = new HashTable<int, int>;

	std::string userInputHash;
	int userInput_key = 0;
	int userInput_value = 0;

	hash_table->insertNode(1, 1);
	hash_table->insertNode(2, 2);
	hash_table->insertNode(3, 5);


	std::cout << "Enter characters to convert to Hash:\n";
	std::getline(std::cin, userInputHash);
	const char* convertedData = userInputHash.c_str();

	auto hashData = HashFunction::defaultHash(convertedData, sizeof(convertedData));

	std::cout << "Please enter the key where you would like to place the Hashed data: " << std::endl;
	std::cin >> userInput_key;

	hash_table->insertNode(userInput_key, hashData);

	//hash_table->display();

	std::cout << hash_table->get(5) << std::endl;

	//std::cout <<  << std::endl;
	//std::cout << hashData << std::endl;

	system("Pause");
	return 0;
}