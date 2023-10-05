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
	Node<T>* node = new Node<T>(item, head);
	head = node;
	if (tail == nullptr)
		tail = head;

	num_items++;
}

template<typename T>
void Single_Linked_List<T>::push_back(T item)
{
	if (tail == nullptr)
	{
		push_front(item);
		return;
	}

	Node<T>* node = new Node<T>(item);
	tail->next = node;
	tail = node;

	num_items++;
}

template<typename T>
void Single_Linked_List<T>::pop_front()
{
	if (head == nullptr)
		return;

	if (head == tail)
		tail = nullptr;

	Node<T>* newHead = head->next;
	delete head;
	head = newHead;

	num_items--;
}

template<typename T>
void Single_Linked_List<T>::pop_back()
{
	if (head == nullptr)
		return;

	if (num_items == 1)
	{
		pop_front();
		return;
	}

	Node<T>* curNode = head;
	while (curNode->next != tail)
	{
		curNode = curNode->next;
	}
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

	if (index >= num_items)
	{
		push_back(item);
		return;
	}
	if (index == 0)
	{
		push_front(item);
		return;
	}

	Node<T>* curNode = head;
	for (int i = 0; i < index - 1; i++)
	{
		curNode = curNode->next;
	}

	Node<T>* newNode = new Node<T>(item, curNode->next);
	curNode->next = newNode;
	num_items++;
}

template<typename T>
bool Single_Linked_List<T>::remove(size_t index)
{
	if (index >= num_items)
		return false;

	if (index == 0)
	{
		pop_front();
		return true;
	}

	Node<T>* curNode = head;
	for (int i = 0; i < index - 1; i++)
		curNode = curNode->next;

	Node<T>* nodeToRemove = curNode->next;

	curNode = curNode->next->next;
	delete nodeToRemove;
	num_items--;
	return true;
}

template<typename T>
size_t Single_Linked_List<T>::find(const T& item)
{
	if (!empty()) {
		int i = 0;
		Node<T>* curNode = head;
		while (curNode != nullptr)
		{
			if (curNode->item == item)
			{
				return i;
			}

			curNode = curNode->next;
			i++;
		}
	}


	return num_items;
}

template<typename T>
void Single_Linked_List<T>::display()
{
	cout << "The list has a length of " << num_items <<" and contains:\n";
	Node<T>* curNode = head;
	int i = 0;

	//Convert to for loop?
	while (curNode != nullptr)
	{
		cout << i << ": " << curNode->item << "\n";
		curNode = curNode->next;
		i++;
	}
}

#endif //ASSIGNMENT_2_SINGLE_LINKED_LIST_CPP
