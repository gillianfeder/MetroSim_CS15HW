/* 
 * MetroSim.h
 * 
 * COMP 15 homework 2
 * by Gillian Feder, October 2021
 * 
 * The interfance of the MetroSim class
 * 
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"

// Put any other necessary includes here
#include "PassengerQueue.h"

#include <vector>
#include <iostream>
#include <fstream>

// Put any other structs you need here

class MetroSim
{
    public:
        
        //constructor
        MetroSim();
        
        //FUNCTIONS
        //fills the two queues with the stations from a file 
        void initializeQueues(std::istream &input);
        
        //adds a new passenger to queue: result of command:[p Arrival Departure]
        void addNewPassengerStation(int arrival, int departure);
        
        //adds passengers from departure station onto train b/f moving
        void addNewPassengersTrain();

        //moves the train: handles everything to do in m m command
        void moveTrain(std::ostream &outputFile);
        
        //prints out the wholoe simulation
        void printMetSim(std::ostream &output);
        
        //removes passenger from front of queue    
        void removePassengers(std::ostream &outputFile);
        
        //print function for when passengers exit the train
        void printDeboardedPassenger(std::ostream &outputFile, Passenger pass, 
            std::string name);
        
        
    private:
        std::vector<PassengerQueue> train;
        std::vector<PassengerQueue> stationLines;
        std::vector<std::string>stationNames;
        int currStation;
        int passengerID;
        
        //creates a new passenger from input; may need istream parameter 
        Passenger createPassenger(int arrival, int departure);
};

#endif
