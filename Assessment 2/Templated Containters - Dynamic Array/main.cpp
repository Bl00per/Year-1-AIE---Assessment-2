#include <iostream>
#include "dynamic_array.h"
#include <crtdbg.h>
#include <Windows.h>


void clearInput() {
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

int main() {
	// Check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("title Dynamic Array");

	// Assigned vector for dynamic array
	dynamic_array<int> my_array;

	// Pushing default values for dynamic array
	my_array.push(10);
	my_array.push(20);
	my_array.push(30);
	my_array.push(40);
	my_array.push(50);
	my_array.push(100);

	int Input;
	int userInput_dynamic;
	bool is_valid = false;

	while (!is_valid)
	{
	start:
		system("cls");
		std::cout << "Select option:\n[1] - View array\n"
			"[2] - Add to end of array\n"
			"[3] - Remove from end of array\n"
			"[4] - Add 1 or more elements to array\n"
			"[5] - Remove elements from array\n"
			"[6] - Display amount of values in array\n"
			"[7] - Display capacity of array\n"
			"[8] - Exit\n"
			"\nInput: ";
		std::cin >> userInput_dynamic;
		clearInput();

		if (userInput_dynamic == 1)
		{
			system("cls");
			my_array.printArray();

			system("Pause");
			goto start;
		}
		else if (userInput_dynamic == 2)
		{
			system("cls");
			std::cout << "Please enter the value you would like to add: ";
			std::cin >> Input;
			clearInput();
			my_array.push(Input);

			std::cout << '\n';
			system("Pause");
			goto start;
		}
		else if (userInput_dynamic == 3)
		{
			system("cls");
			std::cout << "Removed value: " << my_array[my_array.count() - 1] << std::endl;
			my_array.pop();

			system("Pause");
			goto start;
		}

		else if (userInput_dynamic == 4)
		{
			int elementCount = 1;
			int Index = 0;

			system("cls");
			std::cout << "Please enter the value you would like to insert: ";
			std::cin >> Input;
			clearInput();
			std::cout << "How many of the values would you like to insert (default = 1): ";
			std::cin >> elementCount;
			clearInput();
			std::cout << "At what index would you like to put the values: ";
			std::cin >> Index;
			clearInput();

			dynamic_array<int> insert_array;
			for (int i = 0; i < elementCount; i++)
			{
				insert_array.push(Input);
			}
			my_array.insert(insert_array, Index);

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_dynamic == 5)
		{
			system("cls");
			std::cout << "Please enter the index you would like to remove: ";
			std::cin >> Input;
			clearInput();
			my_array.remove(Input);

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_dynamic == 6)
		{
			system("cls");
			std::cout << "There are " << my_array.count() << " values in the array\n";

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_dynamic == 7)
		{
			system("cls");
			std::cout << "The capacity of the array is currently: " << my_array.capacity() << '\n';

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_dynamic == 8)
		{
			is_valid = true;
			my_array.deleteData();

			system("cls");
			std::cout << "\nGoodbye!";
			Sleep(300);
			exit(0);
		}

		else
		{
			system("cls");
			std::cout << "Invalid input, please try again.\n";
			clearInput();

			std::cout << '\n';
			system("Pause");
			goto start;
		}
	}

	return 0;
}
