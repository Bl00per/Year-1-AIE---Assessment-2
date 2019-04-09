#include <iostream>

#include "linked_list.h"
#include <crtdbg.h>
#include <Windows.h>


void clearInput() {
	std::cin.clear();
	std::cin.ignore(std::cin.rdbuf()->in_avail());
}

void linked_list_funct(linked_list<int> *my_list);

int main() {
	// Check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	system("title Linked List");

	linked_list<int> *my_list = new linked_list<int>();

	// Pushing default values for linked list
	my_list->pushBack(100);
	my_list->pushBack(200);
	my_list->pushBack(400);
	my_list->pushBack(600);
	my_list->pushBack(800);
	my_list->pushBack(1000);

	int Input;
	int userInput_linked;
	bool is_valid = false;

	while (!is_valid)
	{
	start:
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
			"[16] - Exit\n"
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
			goto start;
		}

		else if (userInput_linked == 2)
		{
			// pushFront(value)
			system("cls");
			std::cout << "Please enter the value you would like to add to the FRONT of the list: ";
			std::cin >> Input;
			clearInput();
			my_list->pushFront(Input);
			goto start;
		}

		else if (userInput_linked == 3)
		{
			// pushBack(value)
			system("cls");
			std::cout << "Please enter the value you would like to add to the END of the list: ";
			std::cin >> Input;
			clearInput();
			my_list->pushBack(Input);
			goto start;
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
			goto start;
		}

		else if (userInput_linked == 5)
		{
			// begin()
			system("cls");
			std::cout << "The iterator to the first element is: " << my_list->begin() << '\n';

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_linked == 6)
		{
			// end()
			system("cls");
			std::cout << "The iterator to the null element is: " << my_list->end() << '\n';

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_linked == 7)
		{
			// first()
			system("cls");
			std::cout << "The first element is: " << my_list->first() << '\n';

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_linked == 8)
		{
			// last()
			system("cls");
			std::cout << "The last element is: " << my_list->last() << '\n';

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_linked == 9)
		{
			// count()
			system("cls");
			std::cout << "The amount of elements in the list are: " << my_list->count() << '\n';

			std::cout << '\n';
			system("Pause");
			goto start;
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
			goto start;
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
			goto start;
		}

		else if (userInput_linked == 12)
		{
			// popBack()
			system("cls");
			my_list->popBack();

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_linked == 13)
		{
			// popFront()
			system("cls");
			my_list->popFront();

			std::cout << '\n';
			system("Pause");
			goto start;
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
			goto start;
		}

		else if (userInput_linked == 15)
		{
			// clear()
			system("cls");
			std::cout << "List cleared.\n";
			my_list->clear();

			std::cout << '\n';
			system("Pause");
			goto start;
		}

		else if (userInput_linked == 16)
		{
			is_valid = true;
			delete my_list;

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
			system("cls");
			goto start;
		}
	}

	return 0;
}



