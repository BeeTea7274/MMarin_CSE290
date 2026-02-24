#pragma once
#include "DoublyLinkedListNode.h"

class DoublyLinkedList {

public:
	DoublyLinkedListNode* head;
	DoublyLinkedListNode* tail;
	int identifyingNum;
	std::string subject;

	DoublyLinkedList(int IdentifyingNum) 
	{
		this->identifyingNum = IdentifyingNum;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void appendNode(DoublyLinkedListNode* newNode) {
		if (head = nullptr) 
		{
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}

	void printList() 
	{
		DoublyLinkedListNode* currNode = head;
		while (currNode != nullptr) 
		{
			std::cout << currNode->name << std::endl;
			currNode = currNode->next;
		}
	}
};