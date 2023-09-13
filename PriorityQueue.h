
#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <iostream>
#include <vector>
#include "Process.h"

using namespace std;

// Node data type that holds the data and
// priority of the item.

template<class T>
class PQNode
{
  public:
    T data;
    int priority;

    PQNode(T Data)
    {
        data = Data;
        priority = 1;
    }

    PQNode(T Data, int Priority)
    {
        data = Data;
        if (Priority < 1)
            Priority = 1;

        priority = Priority;
    }
};

template<class T>
class PriorityQueue
{
  private:
    vector<PQNode<T> > queue; // The vector holding all of the items in the queue.

  public:
// Constructors and Destructor
    PriorityQueue();
    PriorityQueue(const PriorityQueue &obj);
    ~PriorityQueue();

// Acessors and Mutators
    void enqueue(T Data, int Priority = 1);
    T dequeue();

// Other Functions
    void print();
    bool isEmpty();
    void clear();
    int size();
    T operator[](const int &sub);
};

template<class T>
PriorityQueue<T>::PriorityQueue()
{
    // undeeded constructor
}

template<class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue &obj)
{
    // undeeded copy constructor
}

template<class T>
PriorityQueue<T>::~PriorityQueue()
{
    // uneeded destructor
}
/*
    Description: Mutator function adds a PQNode object to the priority queue with defaulted priority of 1
    Parameters: T Data, int Prior
    Return: None
*/
template<class T>
void PriorityQueue<T>::enqueue(T Data, int Prior)
{
    PQNode<T> node(Data, Prior);
    queue.push_back(node);
}
/*
    Description: Mutator function deletes a PQNode object to the priority queue depending on its level of priority and displays the data that was removed
    Parameters: None
    Return: T variable
*/
template<class T>
T PriorityQueue<T>::dequeue()
{
    T res;
    int prior = 0;
    int k = 0;

    if (isEmpty() == true)
    {
        return res;
    }
    else
    {
    }

    for (unsigned int i = 0; i < queue.size(); i++)
    {
        if (prior < queue[i].priority)
        {
            res = queue[i].data;
            prior = queue[i].priority;
            k = i;
        }
    }

    queue.erase(queue.begin() + k);
    return res;
}
/*
    Description: Print function which displays the contents of the queue
    Parameters: None
    Return: None
*/
template<class T>
void PriorityQueue<T>::print()
{
    for (unsigned int i = 0; i < queue.size(); i++)
    {
        cout << queue[i].data << " --- " << queue[i].priority << endl;
    }
}
/*
    Description: Function checks to see if the queue is empty
    Parameters: None
    Return: bool
*/
template<class T>
bool PriorityQueue<T>::isEmpty()
{
    if (queue.size() == 0)
        return true;
    else
        return false;
}
/*
    Description: Clears the queue of all elements
    Parameters: None
    Return: None
*/
template<class T>
void PriorityQueue<T>::clear()
{
    while (queue.size() > 0)
    {
        queue.pop_back();
    }
}
/*
    Description: Accessor retrieves the size of the queue
    Parameters: None
    Return: int
*/
template<class T>
int PriorityQueue<T>::size()
{
    return queue.size();
}
/*
    Description: Overload [] operator
    Parameters: const int &sub
    Return: T
*/
template<class T>
T PriorityQueue<T>::operator[](const int &sub)
{
    if (sub >= 0 || sub < queue.size())
        return queue[sub].data;
    if (sub < 0)
        return queue[0].data;
    else
        return queue[queue.size() - 1].data;
}
#endif
