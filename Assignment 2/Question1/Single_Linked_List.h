//Author csk2q
#ifndef ASSIGNMENT_2_SINGLE_LINKED_LIST_H
#define ASSIGNMENT_2_SINGLE_LINKED_LIST_H

#include <cstdlib>
#include <iostream>

#include "Node.h"
using namespace std;

template<typename T>
class Single_Linked_List
{
private:
	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int num_items = 0;

public:
	Single_Linked_List();

	///Add a item to the front of the list.
	void push_front(T item);
	///Add a item to the back of the list.
	void push_back(T item);
	//Delete the item at the front of the list.
	void pop_front();
	///Delete the item at the end of the list.
	void pop_back();
	///Returns the item at the front of the list.
	T front();
	///Returns the item at the end of the list.
	T back();
	///Returns true if the list is empty.
	bool empty();

	///Inserts an item at given index. Inserts at the end if the index is beyond the end of the list.
	void insert(size_t index, const T& item);

	///Removes the item at given index. Returns true if successful; returns false if index is beyond the end of the list.
	bool remove(size_t index);

	///Returns the position of the first occurrence of item if it is found. Returns the size of the list if it is not found.
	size_t find(const T& item);

	///Prints the items to the cout.
	void display();
};
#include "Single_Linked_List.cpp"
#endif //ASSIGNMENT_2_SINGLE_LINKED_LIST_H
