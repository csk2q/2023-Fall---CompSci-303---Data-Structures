//Author csk2q
#ifndef ASSIGNMENT_2_NODE_CPP
#define ASSIGNMENT_2_NODE_CPP

#include "Node.h"

template<typename T>
Node<T>::Node(T item) : item(item)
{

}

template<typename T>
Node<T>::Node(T item, Node* next) : item(item), next(next)
{

}

#endif //ASSIGNMENT_2_NODE_CPP