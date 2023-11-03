
#ifndef QUESTION2_MYQUEUE_H
#define QUESTION2_MYQUEUE_H

#include <list>

using namespace std;

class MyQueue
{
private:
    list<string> queue;
    
public:
    //Inserts a new element at the rear of the queue.
    void enqueue(const string& text);
    
    //Removes the front element of the queue and returns it.
    string dequeue();
    
    //Returns the front element present in the queue without removing it.
    string top();
    
    //Returns true if empty, and false if not empty.
    bool isEmpty();

    //Returns the total number of elements present in the queue
    int getCount();

};


#endif //QUESTION2_MYQUEUE_H
