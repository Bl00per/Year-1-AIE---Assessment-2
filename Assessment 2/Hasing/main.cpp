/*
~~~*Reference*~~~

Title: C++ Program to Implement Hash Tables
Author: Karthikeya Boyini
Date: 2019
Availablity: https://www.tutorialspoint.com/cplusplus-program-to-implement-hash-tables
*/

#include <iostream>
#include <string>
#include <Windows.h>
#include "HashFunction.h"
#include "HashTable.h"


void clearInput() {
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}
void clearScreen();

int main()
{
	// Check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("title Hashing");

	HashTable<int, int> *hash_table = new HashTable<int, int>;

	bool is_valid = false;
	int userInput_menu = 0;
	int userInput_key = 0;
	int userInput_value = 0;
	std::string userInputHash;

	//std::getline(std::cin, userInputHash);

	int hashData;
	////Convert the string into a const char*
	//const char* convertedData = userInputHash.c_str();
	//// Use that converted data to hash the data
	//auto hashData = HashFunction::defaultHash(convertedData, sizeof(convertedData));

	//std::cout << hashData << std::endl;



	while (!is_valid)
	{
	start:
		clearScreen();
		std::cout << "Select option:\n"
			"[1] - Add Hash data\n"
			"[2] - Insert data to Hash Table\n"
			"[3] - Remove data from Hash Table\n"
			"[4] - Size of Table\n"
			"[5] - Check if empty\n"
			"[6] - Display Hash Table\n"
			"[7] - Exit\n"
			"\nInput: ";
		std::cin >> userInput_menu;
		clearInput();

		if (userInput_menu == 1)
		{
			clearScreen();
			std::cout << "Enter the string you would like to hash:\n";
			std::getline(std::cin, userInputHash);

			// Convert the string into a const char*
			const char* convertedData = userInputHash.c_str();
			// Use that converted data to hash the data
			hashData = HashFunction::defaultHash(convertedData, sizeof(convertedData));
			std::cout << "\nYour data hashed with BKDR Hash:\n" << hashData << std::endl;


			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_menu == 2)
		{
			clearScreen();
			std::cout << "Please enter the key where you would like to place the Hashed data [" << hashData << "]: " << std::endl;
			std::cin >> userInput_key;
			hash_table->insertNode(userInput_key, hashData);
			clearInput();

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_menu == 3)
		{
			clearScreen();
			std::cout << "Please enter the key of the data you would like to remove: " << std::endl;
			std::cin >> userInput_key;
			clearInput();

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_menu == 4)
		{
			clearScreen();
			std::cout << "The size of the table is currently: " << hash_table->sizeofTable() << '\n';

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_menu == 5)
		{
			clearScreen();
			if (hash_table->isEmpty())
				std::cout << "The table is currently empty.\n";
			else
				std::cout << "The table has values.\n";

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_menu == 6)
		{
			clearScreen();
			hash_table->display();

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_menu == 7)
		{
			is_valid = true;

			clearScreen();
			std::cout << "\nGoodbye!";
			Sleep(300);
			exit(0);
		}

		else
		{
			clearScreen();
			std::cout << "Invalid input, please try again.\n";
			clearInput();

			std::cout << '\n';
			system("Pause");
			goto start;
		}
	}

	system("Pause");
	return 0;
}

// Function to clear the screen
void clearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}