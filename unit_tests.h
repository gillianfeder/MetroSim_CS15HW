/* 
 * unit_tests.h
 * 
 * CS 15 homework 2
 * by Gillian Feder, October 2021
 * 
 * Uses Matt Russell's unit_test framework to test the metroSim program and
 * all related components.
 * More information on this testing framework can be found in the Lab 1
 * handout
 */
#include "Passenger.h"
#include "PassengerQueue.h"
#include "MetroSim.h"

#include <cassert>
#include <iostream>
#include <fstream>
#include <string>

/********************************************************************\
*                       PASSENGER TESTS                        *
\********************************************************************/

/* passenger default constructor test
 * Run the Passenger default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void Passenger_default_constructor()
{
    Passenger test;
}

/* initializer constructor test
 * Run the Passenger constructor to make sure there are no runtime
 * errors or memory leaks
 */
void Passenger_constructor()
{
    Passenger newPass (1, 1, 1);
    assert(newPass.id == 1);
}

/* Passenger print test
* Prints a passenger in accordance to the spec requirement to cout 
*/
void Passenger_print()
{
    Passenger test;
    //should print the passenger details according to the spec
    test.print(std::cout);                                       
}

/********************************************************************\
*                       PASSENGER QUEUE TESTS                        *
\********************************************************************/

/* passenger queue default constructor test
 * Run the PassengerQueue default constructor to make sure there are no runtime
 * errors or memory leaks
 */
void PQ_default_constructor()
{
    PassengerQueue test;
}


/* PassengerQueue size() test 
* Creates a PQ using the default constructor and then tests that the size is 0
*/
void PQ_size()
{
    PassengerQueue test;
    assert(test.size() == 0);
}

/* PassengerQueue isEmpty() test 
* Creates a PQ using the default constructor and then checks that it is empty
*/
void PQ_isEmpty()
{
    PassengerQueue test;
    assert (test.size() == 0);
}

/* PassengerQueue enqueue() test 
* Creates a PQ using the default constructor and adds a passenger to it
* checks that the passenger was added by checking that the size was correctly
* updated
*/
void PQ_enqueue()
{
    Passenger newPass (1, 1, 2);
    PassengerQueue test;
    test.enqueue(newPass);
    assert(test.size() == 1);
}

/* PassengerQueue dequeue() test 
* Creates a PQ using the default constructor and then adds a passenger to it
* Then removes the passenger from the queue and checks that it is
* now empty
*/
void PQ_dequeue()
{
    Passenger newPass (1, 1, 2);
    PassengerQueue test;
    test.enqueue(newPass);
    test.dequeue();
    assert(test.size() == 0);
}

/* PassengerQueue dequeue() second test 
* Creates a PQ using the default constructor and then adds 2 Passengers
* Then removes both passengers and checks that it is now empty
*/
void PQ_dequeue2()
{
    Passenger newPass (1, 1, 2);
    Passenger newPass2 (2, 1, 2);
    PassengerQueue test;
    test.enqueue(newPass);
    test.enqueue(newPass2);
    test.dequeue();
    assert(test.size() == 1);
    test.dequeue();
    assert(test.size() == 0);
}

/* PassengerQueue dequeue3() test 
* Creates a PQ using the default constructor so that the size = 0
* Then removes the passenger from the queue and checks that it is
* now empty
*/
void PQ_dequeue3()
{
    PassengerQueue test;
    test.dequeue();
    assert(test.size() == 0);
}

/* PassengerQueue front() test 
* Creates a PQ using the default constructor and then adds a passenger
* Then checks that the front function works by asserting that it is equal
* to the passenger object known to be at the front of the queue
*/
void PQ_front()
{
    Passenger newPass (1, 1, 2);
    PassengerQueue test;
    test.enqueue(newPass);
    test.front().print(std::cout);
}


/* PassengerQueue print() test 
* Creates a PQ and then adds two passengers to it and then prints it out 
*/
void PQ_print()
{
    Passenger newPass (1, 1, 2);
    Passenger newPass2 (1, 2, 3);
    PassengerQueue test;
    test.enqueue(newPass);
    test.enqueue(newPass2);
    test.print(std::cout);
}
/********************************************************************\
*                       METRO SIM TESTS                        *
\********************************************************************/

/* MetroSim default constructor() test 
* Creates an instance of the metroSim class 
*/
void MS_constructor()
{
    MetroSim program;
}


