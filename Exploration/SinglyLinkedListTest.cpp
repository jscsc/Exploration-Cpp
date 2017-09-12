#include <iostream>
#include <memory>
#include "SimpleSinglyLinkedList.h"
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int singly_linked_list_test_main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::shared_ptr<SimpleSinglyLinkedList> list = std::make_shared<SimpleSinglyLinkedList>();

	std::cout << "List is empty: " << (list->isEmpty() == true ? "true" : "false") << std::endl;

	std::cout << "Adding values" << std::endl;

	list->add(1);
	list->add(5);
	list->add(3);
	list->add(19);
	list->add(20);
	list->add(55);
	list->add(42);
	list->add(83);

	list->printList();
	std::cout << std::endl;

	std::cout << "List is empty: " << (list->isEmpty() == true ? "true" : "false") << std::endl;

	std::cout << "Removing 55" << std::endl;
	list->remove(5);

	list->printList();
	std::cout << std::endl;

	std::cout << "List size is: " << list->getSize() << std::endl;

	std::cout << "Adding value 7 at index 3" << std::endl;

	list->add(3, 7);

	list->printList();
	std::cout << std::endl;

	std::cout << "Press anything to exit" << std::endl;
	std::getchar();

	return 0;
}