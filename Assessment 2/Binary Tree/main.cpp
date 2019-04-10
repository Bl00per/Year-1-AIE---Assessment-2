#include <iostream>
#include "binary_tree.h"

int main()
{
	binary_tree<int> my_tree;
	my_tree.insert(10);
	my_tree.insert(6);
	my_tree.insert(15);
	my_tree.insert(14);
	my_tree.insert(5);

	std::cout << my_tree.find(8) << std::endl;
	std::cout << my_tree.find(10) << std::endl;
	std::cout << my_tree.find(6) << std::endl;
	std::cout << my_tree.find(15) << std::endl;
	std::cout << my_tree.find(14) << std::endl;
	std::cout << my_tree.find(5) << std::endl;

	my_tree.remove(6);

	std::cout << my_tree.find(6) << std::endl;



	return 0;
}