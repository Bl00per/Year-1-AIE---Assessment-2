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
	my_array.push(78);
	my_array.push(13);
	my_array.push(2);
	my_array.push(448);
	my_array.push(101);


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
			"[4] - Sort the array\n"
			"[5] - Exit\n"
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
			system("cls");
			std::cout << "Array Sorted." << '\n';
			my_array.selectionSort(my_array);

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_dynamic == 5)
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
