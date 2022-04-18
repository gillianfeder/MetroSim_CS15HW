/* 
 * Passenger.cpp
 * 
 * COMP 15 homework 2
 * by Gillian Feder, October 2021
 * 
 * Contains all necessary functions to work on indivual passenger objects 
 * 
 */

#include <iostream>
#include <string>
#include "Passenger.h"

/* print
 *    Purpose: To print out the description of a passenger
 * Parameters: an instance of std::ostream to inform where to print to
 *    Returns: N/A
 */
void Passenger::print(std::ostream &output)
{
    output << "[" << this->id << ", " << this->from << "->" << this->to << "]";
}
