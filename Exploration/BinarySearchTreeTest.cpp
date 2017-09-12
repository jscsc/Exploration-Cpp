#include <iostream>
#include <memory>
#include "SimpleBinarySearchTree.h"
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::shared_ptr<SimpleBinarySearchTree<int>> tree = std::make_shared<SimpleBinarySearchTree<int>>(15);
	tree->add(8);
	tree->add(22);
	tree->add(4);
	tree->add(12);
	tree->add(19);
	tree->add(24);
	tree->add(5);
	tree->add(9);
	tree->add(13);
	tree->add(18);
	tree->add(23);
	tree->add(25);
	tree->add(6);


	tree->inOrderTraversal();
	std::endl(std::cout);

	std::cout << "Removing 22" << std::endl;

	tree->remove(22);

	tree->inOrderTraversal();
	std::endl(std::cout);

	std::cout << "Tree contains 18: " << (tree->contains(18) == true ? "true" : "false") << std::endl;

	std::cout << "Tree contains 7: " << (tree->contains(7) == true ? "true" : "false") << std::endl;

	std::cout << "Press anything to exit" << std::endl;

	std::getchar();

	return 0;
}