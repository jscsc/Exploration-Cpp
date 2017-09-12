#pragma once

#include <memory>

// Simple singly linked list implementation
class SimpleSinglyLinkedList
{


private:

	// Inner struct for the ListNode
	struct ListNode {

		// The data the node holds
		int data;

		// pointer to this node's next ListNode
		std::shared_ptr<ListNode> next;

		// Constructors / Destructor
		ListNode(int data);
		ListNode(int data, std::shared_ptr<ListNode>& next);
		~ListNode();

	};

	// Pointer to the front of the list
	std::shared_ptr<ListNode> front;

	// The size of the list
	size_t size;

public:

	// Constructor / Destructor
	SimpleSinglyLinkedList();
	~SimpleSinglyLinkedList();

	// Adds the value to the back of the list
	void add(int value);

	// Adds the value to the list at the given index
	void add(int index, int value);

	// Removes the value at the index given, if the index is valid
	void remove(int index);

	// Returns the size of the list
	size_t getSize();

	// Gets the data at the given index
	int get(int index);

	// Checks to see if the list is empty
	bool isEmpty();

	// Prints the list to the console
	void printList();

};

