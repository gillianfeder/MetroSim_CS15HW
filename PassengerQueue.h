/* 
 * PassengerQueue.h
 * 
 * COMP 15 homework 2
 * by Gillian Feder, October 2021
 * 
 * The interface of the passengerQueue class, which contains an underlying 
 * vector and a series of functions to operate on the vector available to the
 * client in order to create a restricted vector class, thus forming an 
 * implementation of the queue 
 * 
 */

#ifndef PASSENGER_QUEUE_H
#define PASSENGER_QUEUE_H

#include "Passenger.h"
#include <vector>
#include <string>
#include <iostream>

class PassengerQueue {
    public:
        
        //default constructor
        PassengerQueue();

        
        //FUNCTIONS
        
        //returns but does not remove element at the front
        Passenger front() const;
        //removes element at the front
        void dequeue();
        //inserts a new passenger at the end
        void enqueue(const Passenger &passenger);
        //returns the number of elements in the queue
        int size();
        //prints each passenger in the queue from front to back 
        void print(std::ostream &output);
        

    private:
        std::vector <Passenger> queue;
        
        //checks if queue is empty and returns t/f 
        bool isEmpty();    
    
};

#endif