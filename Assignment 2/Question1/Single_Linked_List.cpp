//Author csk2q
#ifndef ASSIGNMENT_2_SINGLE_LINKED_LIST_CPP
#define ASSIGNMENT_2_SINGLE_LINKED_LIST_CPP

#include "Single_Linked_List.h"
#include "Node.h"
#include <iostream>

using namespace std;

//TODO Double check that there is no logic errors or random crashes.

template<typename T>
inline Single_Linked_List<T>::Single_Linked_List()
{
}

template<typename T>
void Single_Linked_List<T>::push_front(T item)
{
	//Create new node and set next item to the header
	Node<T>* node = new Node<T>(item, head);
	head = node;

	//If tail is nullptr then update it
	if (tail == nullptr)
		tail = head;

	num_items++;
}

template<typename T>
void Single_Linked_List<T>::push_back(T item)
{
	//If the list is empty push_front instead
	if (tail == nullptr)
	{
		push_front(item);
		return;
	}

	//Add item to tail
	Node<T>* node = new Node<T>(item);
	tail->next = node;
	tail = node;

	num_items++;
}

template<typename T>
void Single_Linked_List<T>::pop_front()
{
	//Cannot pop an empty list
	if (head == nullptr)
		return;

	//If the list has only one item,
	//	then update tail pointer as well.
	if (head == tail)
		tail = nullptr;

	//Update links and delete old node
	Node<T>* newHead = head->next;
	delete head;
	head = newHead;

	num_items--;
}

template<typename T>
void Single_Linked_List<T>::pop_back()
{
	//Cannot pop an empty list
	if (head == nullptr)
		return;

	//Fallback to pop_front if there is only one item
	if (num_items == 1)
	{
		pop_front();
		return;
	}

	//Navigate to the last node
	Node<T>* curNode = head;
	while (curNode->next != tail)
	{
		curNode = curNode->next;
	}

	//Delete node and update links
	delete curNode->next;
	curNode->next = nullptr;
	tail = curNode;

	num_items--;
}

template<typename T>
T Single_Linked_List<T>::front()
{
	return head->item;
}

template<typename T>
T Single_Linked_List<T>::back()
{
	return tail->item;
}

template<typename T>
bool Single_Linked_List<T>::empty()
{
	return num_items == 0;
}

template<typename T>
void Single_Linked_List<T>::insert(size_t index, const T& item)
{
	//size_t is always >= 0 so only indices greater than the num_items needs checked

	//Push back if index is greater than length
	if (index >= num_items)
	{
		push_back(item);
		return;
	}
	//Push front if index is 0
	if (index == 0)
	{
		push_front(item);
		return;
	}

	//Navigate to the node
	Node<T>* curNode = head;
	for (int i = 0; i < index - 1; i++)
	{
		curNode = curNode->next;
	}

	//Add node into list
	Node<T>* newNode = new Node<T>(item, curNode->next);
	curNode->next = newNode;

	num_items++;
}

template<typename T>
bool Single_Linked_List<T>::remove(size_t index)
{
	//Only able to remove valid indexes
	if (index >= num_items)
		return false;

	//Pop front if index is 0
	if (index == 0)
	{
		pop_front();
		return true;
	}

	//Navigate to node
	Node<T>* curNode = head;
	for (int i = 0; i < index - 1; i++)
		curNode = curNode->next;

	//Delete node and update links
	Node<T>* nodeToRemove = curNode->next;
	curNode->next = curNode->next->next;
	delete nodeToRemove;
	num_items--;
	return true;
}

template<typename T>
size_t Single_Linked_List<T>::find(const T& item)
{
	//While not empty
	if (!empty()) {

		//Navigate to node
		int i = 0;
		Node<T>* curNode = head;
		while (curNode != nullptr)
		{
			//If node matches return index
			if (curNode->item == item)
			{
				return i;
			}

			curNode = curNode->next;
			i++;
		}
	}

	//Return list length if item not found
	return num_items;
}

template<typename T>
void Single_Linked_List<T>::display()
{
	//Print preamble and list length
	cout << "The list has a length of " << num_items <<" and contains:\n";
	Node<T>* curNode = head;
	int i = 0;

	//List each item
	while (curNode != nullptr)
	{
		cout << i << ": " << curNode->item << "\n";
		curNode = curNode->next;
		i++;
	}
}

#endif //ASSIGNMENT_2_SINGLE_LINKED_LIST_CPP
