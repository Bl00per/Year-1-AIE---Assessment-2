#include <iostream>
#include "dynamic_array.h"
#include "linked_list.h"
#include <crtdbg.h>

void clearInput() {
	std::cin.clear();
	std::cin.ignore(SHRT_MAX, '\n');
}

int main() {
	// Check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	system("title Templated Containers");

	// Assign the vectors for dynamic array and linked list
	dynamic_array<int> my_array;
	linked_list<int> *my_list = new linked_list<int>();

	bool is_valid = false;

	// Pushing default values for dynamic array
	my_array.push(10);
	my_array.push(20);
	my_array.push(30);
	my_array.push(40);
	my_array.push(50);
	my_array.push(100);

	// Pushing default values for linked list
	my_list->pushBack(100);
	my_list->pushBack(200);
	my_list->pushBack(400);
	my_list->pushBack(600);
	my_list->pushBack(800);
	my_list->pushBack(1000);

	while (!is_valid)
	{
		int menuInput;
		int userInput_linked;
		int userInput_dynamic;
		int Input;
	
	start:
		std::cout << "Which container class would you like to test?\n"
			"[1] - Linked List class\n"
			"[2] - Dynamic Array class\n"
			"[3] - Exit\n"
			"\nInput: ";
		std::cin >> menuInput;
		clearInput();

	linked_list_menu:
		if (menuInput == 1)
		{
			is_valid = true;
			system("cls");
			std::cout << "Select option:\n[1] - View array\n"
				"\nInput: ";
			std::cin >> userInput_linked;
			clearInput();

			if (userInput_linked == 1)
			{
				system("cls");
				// Auto 'automatically' figures out which 
				//identifier (int, char, etc.) or class to use
				for (auto* iter = my_list->begin()->m_next; iter != my_list->end(); iter = iter->m_next)
				{
					std::cout << iter->m_data << '\n';
				}
				
				std::cout << '\n';
				system("Pause");
				goto linked_list_menu;
			}

			if (userInput_linked == 2)
			{
				system("cls");
				std::cout << "Please enter the value you would like to add: ";
				std::cin >> Input;
				clearInput();
				my_list->pushBack(Input);
			}

			if (userInput_linked == 3)
			{

			}

			if (userInput_linked == 4)
			{

			}

			if (userInput_linked == 5)
			{

			}

			if (userInput_linked == 6)
			{

			}

			if (userInput_linked == 7)
			{

			}

			if (userInput_linked == 8)
			{
				system("cls");
				goto start;
			}
		}

	dynamic_array_menu:
		if (menuInput == 2);
		{
			is_valid = true;
			system("cls");
			std::cout << "Select option:\n[1] - View array\n"
				"[2] - Add to end of array\n"
				"[3] - Remove from end of array\n"
				"[4] - Add 1 or more elements to array\n"
				"[5] - Remove elements from array\n"
				"[6] - Display amount of values in array\n"
				"[7] - Display capacity of array\n"
				"[8] - Return to start\n"
				"\nInput: ";
			std::cin >> userInput_dynamic;
			clearInput();

			if (userInput_dynamic == 1)
			{
				system("cls");
				my_array.printArray();
				
				system("Pause");
				goto dynamic_array_menu;
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
				goto dynamic_array_menu;
			}
			else if (userInput_dynamic == 3)
			{
				system("cls");
				std::cout << "Removed value: " << my_array[my_array.count() - 1] << std::endl;
				my_array.pop();

				system("Pause");
				goto dynamic_array_menu;
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
				goto dynamic_array_menu;
			}




			else if (userInput_dynamic == 7)
			{
				system("cls");
				std::cout << "The capacity of the array is currently: " << my_array.capacity();
				
				std::cout << '\n';
				system("Pause");
				goto dynamic_array_menu;
			}

			else if (userInput_dynamic == 8)
			{
				system("cls");
				goto start;
			}
		}

	exit:
		if (menuInput == 3)
		{
			
		}
	}

	return 0;
}

