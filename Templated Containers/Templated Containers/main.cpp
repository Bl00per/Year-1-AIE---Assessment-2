#include <iostream>
#include "dynamic_array.h"
#include "linked_list.h"
#include <crtdbg.h>


int main() {
	// Check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

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
		int userInput = 0;
		int userInput_linked = 0;
		int userInput_dynamic = 0;
	
	start:
		std::cout << "Which container class would you like to test?\n"
			"[1] - Linked List class\n"
			"[2] - Dynamic Array class\n"
			"[3] - Exit\n"
			"\nInput: ";
		std::cin >> userInput;

	linked_list_menu:
		if (userInput == 1)
		{
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
			std::cin >> userInput_linked;

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
				int Input2 = 0;

				system("cls");
				std::cout << "Please enter the value you would like to add: ";
				std::cin >> Input2;
				my_list.pushBack(Input2);
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
		}
		else if (userInput == 2);
		{
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

			if (userInput_dynamic == 1)
			{
				PrintArray();
			}
		}
	}






	my_list->pushFront(50);
	// This value is going to the be the first one
	// because it was called last
	my_list->pushFront(123);

	// Inserts the value 500 at index 3
	my_list->insert(500, 3);

	my_list->remove(5);

	std::cout << "First element: " << my_list->first() << std::endl;
	std::cout << "Last element: " << my_list->last() << std::endl;

	std::cout << "Amount of elements: " << my_list->count() << std::endl;


	system("Pause");
	return 0;
}

