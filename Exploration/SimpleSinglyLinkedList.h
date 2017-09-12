#pragma once

#include <memory>
#include <iostream>

// Simple singly linked list implementation
template <typename T>
class SimpleSinglyLinkedList
{

private:

	// Inner struct for the ListNode
	struct ListNode {

		// The data the node holds
		T data;

		// pointer to this node's next ListNode
		std::shared_ptr<ListNode> next;

		// Constructors / Destructor
		ListNode(T data) : data(data), next(nullptr)
		{
		};

		ListNode(T data, std::shared_ptr<ListNode>& next) : data(data), next(next)
		{
		};

		~ListNode()
		{
		};

	};

	// Pointer to the front of the list
	std::shared_ptr<ListNode> front;

	// The size of the list
	size_t size;

public:

	// Constructor / Destructor
	SimpleSinglyLinkedList() : size(0), front(nullptr)
	{
	};

	~SimpleSinglyLinkedList()
	{
	};

	// Adds the value to the back of the list
	void add(T value)
	{
		if (!front) {
			front = std::make_shared<ListNode>(value);
		}
		else {
			std::shared_ptr<ListNode> current = front;
			while (current->next)
				current = current->next;

			current->next = std::make_shared<ListNode>(value);
		}
		size++;
	};

	// Adds the value to the list at the given index
	void add(int index, T value)
	{
		if (index < 0 || index > static_cast<int>(size))
			return;

		if (index == 0) {
			// Add to the front of the list
			front = std::make_shared<ListNode>(value, front);
		}
		else {
			// Insert into existing list, stop before index to add at
			std::shared_ptr<ListNode> current = front;
			for (int i = 0; i < index - 1; ++i)
				current = current->next;
			current->next = std::make_shared<ListNode>(value, current->next);
		}
		size++;
	};

	// Removes the value at the index given, if the index is valid
	void remove(int index)
	{
		if (index < 0 || index > static_cast<int>(size))
			return;

		if (index == 0) {
			front = front->next;
		}
		else {
			std::shared_ptr<ListNode> current = front;
			for (int i = 0; i < index - 1; ++i)
				current = current->next;
			current->next = current->next->next;
		}
	};

	// Returns the size of the list
	size_t getSize()
	{
		return size;
	}

	// Gets the data at the given index
	int get(int index)
	{
		if (index >= 0 && index < static_cast<int>(size)) {

			std::shared_ptr<ListNode> current = front;
			for (int i = 0; i < index; ++i)
				current = current->next;
			return current->data;

		}

		return -1;
	};

	// Checks to see if the list is empty
	bool isEmpty()
	{
		return size <= 0;
	}

	// Prints the list to the console
	void printList()
	{
		std::shared_ptr<ListNode> current = front;
		while (current) {
			std::cout << current->data << " " << std::flush;
			current = current->next;
		}
	};

};

