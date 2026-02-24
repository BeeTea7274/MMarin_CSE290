#pragma once
#include <string>
#include <vector>

class DoublyLinkedListNode {
public:
	std::vector<int> data;
	std::string name;
	std::string subject;
	DoublyLinkedListNode* next;
	DoublyLinkedListNode* prev;
	DoublyLinkedListNode(std::vector<int> initialVect, std::string name, std::string subject) 
	{
		this->data = initialVect;
		this->next = nullptr;
		this->prev = nullptr;
		this->name = name;
		this->subject = subject;
	}
};