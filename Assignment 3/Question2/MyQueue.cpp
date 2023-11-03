#include <iostream>

#include "MyQueue.h"

void MyQueue::enqueue(const string &text)
{//Inserts a new element at the rear of the queue.
    queue.push_back(text);
}

string MyQueue::dequeue()
{//Removes the front element of the queue and returns it.
    string value = queue.front();
    queue.pop_front();
    return value;
}

string MyQueue::top()
{//Returns the front element present in the queue without removing it.
    return queue.front();
}

bool MyQueue::isEmpty()
{//Checks if the queue is empty
    return queue.empty();
}

int MyQueue::getCount()
{//Returns the total number of elements present in the queue
    return queue.size();
}
