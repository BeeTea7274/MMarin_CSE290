#pragma once
#include "DoublyLinkedListNode.h"

class DoublyLinkedList {

public:
	DoublyLinkedListNode* head;
	DoublyLinkedListNode* tail;
	int identifyingNum;
	std::string subject;

	DoublyLinkedList(int IdentifyingNum, std::string Subject) 
	{
		this->identifyingNum = IdentifyingNum;
		this->subject = Subject;
		this->head = nullptr;
		this->tail = nullptr;
	}

	void appendNode(DoublyLinkedListNode* newNode) {
		if (head == nullptr)
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
		std::cout << "List of " << this->subject << " ISBN codes)" << std::endl;
		if (head == nullptr) 
		{
			std::cout << "No valid ISBN codes for this subject" << std::endl;
		}
		else {
			while (currNode != nullptr)
			{
				std::cout << currNode->name << std::endl;
				currNode = currNode->next;
			}
		}
		std::cout << std::endl;
	}
};