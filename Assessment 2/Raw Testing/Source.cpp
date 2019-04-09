#include <iostream>
#include <crtdbg.h>

#include "../Templated Containers/dynamic_array.h"
#include "../Templated Containers/linked_list.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	dynamic_array<int> da;
	da.push(5);
	da.pop();
	da.push(5);
	da.insert(19, 3);
	da.clear();
	da.push(5);
	da.remove(5);
	da.push(6);
	da.count();
	da.capacity();
	linked_list<int> ll;
	ll.pushFront(10);
	ll.pushBack(11);
	ll.insert(2, 5);
	ll.begin();
	ll.end();
	ll.first();
	ll.last();
	ll.count();
	ll.erase(1);
	ll.remove(11);
	ll.pushFront(10);
	ll.pushBack(11);
	ll.popBack();
	ll.popFront();
	ll.empty();
	ll.pushBack(11);
	ll.clear();

	return 0;
}