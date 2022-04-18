/* 
 * PassengerQueue.cpp
 * 
 * COMP 15 homework 2
 * by Gillian Feder, October 2021
 * 
 * The implementation of the PassengerQueue class, which contains an underlying 
 * vector of Passengers and a series of functions to operate on the vector.
 * An implementation of the Queue data structure.
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include "PassengerQueue.h"

using namespace std;

//default constructor
PassengerQueue::PassengerQueue()
{
    
}


bool PassengerQueue:: isEmpty()
{
    return size() == 0;
}

//returns but does not remove element at the front
Passenger PassengerQueue:: front() const
{
    return queue.front();
}

//removes element at the front
void PassengerQueue::dequeue()
{
    queue.erase(queue.begin());
}

//inserts a new passenger at the end
void PassengerQueue::enqueue(const Passenger &passenger)
{
    queue.push_back(passenger);
}

//returns the number of elements in the queue
int PassengerQueue::size()
{
    return queue.size();
}


//prints each passenger in the queue from front to back 
void PassengerQueue::print(ostream &output)
{
    for ( int i = 0; i < (int)queue.size(); i++)
    {
        queue[i].print(output);
    }
}



