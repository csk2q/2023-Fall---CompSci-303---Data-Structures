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

	//TODO Comment all functions.
	//	Refrence the assignment pdf & slides.
	//	Page 114 of Ch4 has a list of the list class' functions.

	void push_front(T item);
	void push_back(T item);
	void pop_front();
	void pop_back();
	T front();
	T back();
	///Returns true if the list is empty.
	bool empty();

	///Insert item at position index (starting at 0). Insert at the end if index is beyond the end of the list
	void insert(size_t index, const T& item);

	///Remove the item at position index. Return true if successful; return false if index is beyond the end of the list.
	bool remove(size_t index);

	///Return the position of the first occurrence of item if it is found. Return the size of the list if it is not found.
	size_t find(const T& item);

	void display();
};
#include "Single_Linked_List.cpp"
#endif //ASSIGNMENT_2_SINGLE_LINKED_LIST_H
