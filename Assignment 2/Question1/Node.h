//Author csk2q

#ifndef ASSIGNMENT_2_NODE_H
#define ASSIGNMENT_2_NODE_H

template<typename T>
class Node
{
public:
    
    T item;
    Node* next = nullptr;
    
    Node(T item);
    Node(T item, Node<T>* next);
};


#include "Node.cpp"
#endif //ASSIGNMENT_2_NODE_H
