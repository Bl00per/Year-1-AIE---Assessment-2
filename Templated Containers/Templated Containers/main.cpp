#include <iostream>
#include "dynamic_array.h"
#include "linked_list.h"
#include <crtdbg.h>
#include <Windows.h>


linked_list<int> *my_list = nullptr;

void clearInput() {
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

void main_menu_funct();
void dynamic_array_funct(dynamic_array<int>& my_array);
void linked_list_funct(linked_list<int> *my_list);

int main() {
	// Check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("title Templated Containers");

	// If I want it to not reset array on menu
	//main_menu_funct(my_array);
	main_menu_funct();

	delete my_list;
	return 0;
}

void main_menu_funct()
{
	int menuInput;
	bool is_valid = false;
	
	while (!is_valid) {
		system("cls");
		std::cout << "Which container class would you like to test?\n"
			"[1] - Linked List class\n"
			"[2] - Dynamic Array class\n"
			"[3] - Exit\n"
			"\nInput: ";
		std::cin >> menuInput;

		if (menuInput == 3)
		{
			system("cls");
			std::cout << "\nGoodbye!";
			Sleep(300);
			exit(0);
		}

		else if (menuInput == 1)
		{
			// Assigned vector for linked list
			if (my_list)
			{
				delete my_list;
			}

			my_list = new linked_list<int>();

			// Pushing default values for linked list
			my_list->pushBack(100);
			my_list->pushBack(200);
			my_list->pushBack(400);
			my_list->pushBack(600);
			my_list->pushBack(800);
			my_list->pushBack(1000);

			linked_list_funct(my_list);
		}

		else if (menuInput == 2)
		{
			// Assigned vector for dynamic array
			dynamic_array<int> my_array;

			// Pushing default values for dynamic array
			my_array.push(10);
			my_array.push(20);
			my_array.push(30);
			my_array.push(40);
			my_array.push(50);
			my_array.push(100);

			dynamic_array_funct(my_array);
		}


		if (menuInput != 1 || menuInput != 2)
		{
			system("cls");
			std::cout << "Invalid input, please try again.\n";
			clearInput();

			std::cout << '\n';
			system("Pause");
			main_menu_funct();
		}
	}
}

void dynamic_array_funct(dynamic_array<int>& my_array)
{
	int Input;
	int userInput_dynamic;
	
	system("cls");
	std::cout << "Select option:\n[1] - View array\n"
		"[2] - Add to end of array\n"
		"[3] - Remove from end of array\n"
		"[4] - Add 1 or more elements to array\n"
		"[5] - Remove elements from array\n"
		"[6] - Display amount of values in array\n"
		"[7] - Display capacity of array\n"
		"[8] - Return to start (Resets array)\n"
		"\nInput: ";
	std::cin >> userInput_dynamic;
	clearInput();

	if (userInput_dynamic == 1)
	{
		system("cls");
		my_array.printArray();

		system("Pause");
		dynamic_array_funct(my_array);
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
		dynamic_array_funct(my_array);
	}
	else if (userInput_dynamic == 3)
	{
		system("cls");
		std::cout << "Removed value: " << my_array[my_array.count() - 1] << std::endl;
		my_array.pop();

		system("Pause");
		dynamic_array_funct(my_array);
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
		dynamic_array_funct(my_array);
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
		dynamic_array_funct(my_array);
	}

	else if (userInput_dynamic == 6)
	{
		system("cls");
		std::cout << "There are " << my_array.count() << " values in the array\n";

		std::cout << '\n';
		system("Pause");
		dynamic_array_funct(my_array);
	}

	else if (userInput_dynamic == 7)
	{
		system("cls");
		std::cout << "The capacity of the array is currently: " << my_array.capacity() << '\n';

		std::cout << '\n';
		system("Pause");
		dynamic_array_funct(my_array);
	}

	else if (userInput_dynamic == 8)
	{
		my_array.clear();
		clearInput();
	}

	else
	{
		system("cls");
		std::cout << "Invalid input, please try again.\n";
		clearInput();

		std::cout << '\n';
		system("Pause");
		dynamic_array_funct(my_array);
	}
}

void linked_list_funct(linked_list<int> *my_list)
{
	int Input;
	int userInput_linked;

	system("cls");
	std::cout << "Select option:\n[1] - View list\n"
		"[2] - pushFront(value)\n"
		"[3] - pushBack(value)\n"
		"[4] - insert(Iterator, value)\n"
		"[5] - begin()\n"
		"[6] - end()\n"
		"[7] - first()\n"
		"[8] - last()\n"
		"[9] - count()\n"
		"[10] - erase(iterator)\n"
		"[11] - remove(value)\n"
		"[12] - popBack()\n"
		"[13] - popFront()\n"
		"[14] - empty()\n"
		"[15] - clear()\n"
		"[16] - Return to start (Resets list)\n"
		"\nInput: ";
	std::cin >> userInput_linked;
	clearInput();

	if (userInput_linked == 1)
	{
		system("cls");
		// Auto 'automatically' figures out which 
		// identifier (int, char, etc.) or class to use
		for (auto* iter = my_list->begin()->m_next; iter != my_list->end(); iter = iter->m_next)
		{
			std::cout << iter->m_data << '\n';
		}

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 2)
	{
		// pushFront(value)
		system("cls");
		std::cout << "Please enter the value you would like to add to the FRONT of the list: ";
		std::cin >> Input;
		clearInput();
		my_list->pushFront(Input);
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 3)
	{
		// pushBack(value)
		system("cls");
		std::cout << "Please enter the value you would like to add to the END of the list: ";
		std::cin >> Input;
		clearInput();
		my_list->pushBack(Input);
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 4)
	{
		// insert(iterator, value)
		int Index = 0;

		system("cls");
		std::cout << "Please enter the value you would like to insert (data): ";
		std::cin >> Input;
		clearInput();
		std::cout << "Please enter the index you would like to insert (" << Input << "): ";
		std::cin >> Index;
		clearInput();
		my_list->insert(Input, Index);
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 5)
	{
		// begin()
		system("cls");
		std::cout << "The iterator to the first element is: " << my_list->begin() << '\n';

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 6)
	{
		// end()
		system("cls");
		std::cout << "The iterator to the null element is: " << my_list->end() << '\n';

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 7)
	{
		// first()
		system("cls");
		std::cout << "The first element is: " << my_list->first() << '\n';

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 8)
	{
		// last()
		system("cls");
		std::cout << "The last element is: " << my_list->last() << '\n';

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 9)
	{
		// count()
		system("cls");
		std::cout << "The amount of elements in the list are: " << my_list->count() << '\n';

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 10)
	{
		// erase(iterator)
		system("cls");
		std::cout << "Please enter the index you would like to erase: ";
		std::cin >> Input;
		my_list->erase(Input);

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 11)
	{
		// erase(iterator)
		system("cls");
		std::cout << "Please enter the element you would like to remove: ";
		std::cin >> Input;
		my_list->remove(Input);

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 12)
	{
		// popBack()
		system("cls");
		my_list->popBack();

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 13)
	{
		// popFront()
		system("cls");
		my_list->popFront();

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 14)
	{
		// empty()
		system("cls");
		if (my_list->empty() == true)
			std::cout << "The list has elements\n";
		else
			std::cout << "The list is empty\n";

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 15)
	{
		// clear()
		system("cls");
		std::cout << "List cleared.\n";
		my_list->clear();

		std::cout << '\n';
		system("Pause");
		linked_list_funct(my_list);
	}

	else if (userInput_linked == 16)
	{
		my_list->clear();
		for (int i = 0; i < my_list->count(); i++)
		{
			my_list->remove(i);
		}
		clearInput();
	}

	else
	{
		system("cls");
		std::cout << "Invalid input, please try again.\n";
		clearInput();

		std::cout << '\n';
		system("cls");
		linked_list_funct(my_list);
	}
}