#include "SimpleSinglyLinkedList.h"
#include <iostream>


SimpleSinglyLinkedList::SimpleSinglyLinkedList() : size(0), front(nullptr)
{
}

SimpleSinglyLinkedList::~SimpleSinglyLinkedList()
{
}

void SimpleSinglyLinkedList::add(int value)
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
}

void SimpleSinglyLinkedList::add(int index, int value)
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
}

void SimpleSinglyLinkedList::remove(int index)
{
	//std::cout << size << std::endl;
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
}

size_t SimpleSinglyLinkedList::getSize()
{
	return size;
}

int SimpleSinglyLinkedList::get(int index)
{
	if (index >= 0 && index < static_cast<int>(size)) {

		std::shared_ptr<ListNode> current = front;
		for (int i = 0; i < index; ++i)
			current = current->next;
		return current->data;

	}

	return -1;
}

bool SimpleSinglyLinkedList::isEmpty()
{
	return size <= 0;
}

void SimpleSinglyLinkedList::printList()
{
	std::shared_ptr<ListNode> current = front;
	while (current) {
		std::cout << current->data << " " << std::flush;
		current = current->next;
	}
}

SimpleSinglyLinkedList::ListNode::ListNode(int data) : data(data), next(nullptr)
{
}

SimpleSinglyLinkedList::ListNode::ListNode(int data, std::shared_ptr<ListNode>& next)
	: data(data), next(next)
{
}

SimpleSinglyLinkedList::ListNode::~ListNode()
{
}
