/* 
 * MetroSim.cpp
 * 
 * COMP 15 homework 2
 * by Gillian Feder, October 2021
 * 
 * The implementation of the MetroSim class, which contains two vectors of  
 * PassengerQueue objects: the vector of stations and the train vector which
 * holds the passengers currently on the train seperated by destination.
 * 
 */

#include "MetroSim.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <typeinfo>

using namespace std;

/*  MetroSim constructor
*   sets the current station to 1 (first station) and the first passenger ID 
*   to 1
*/
MetroSim::MetroSim()
{
    currStation = 1;
    passengerID = 1;
}

/* initializeQueues()
*  Purpose: initializes the two vectors of the metroSim class based on the  
*             input file
* Parameters: the input file with all included station information
*/
void MetroSim::initializeQueues(istream &input)
{
    //fills the two queues with the stations from a file 
    string currentLine;
    while (getline(input, currentLine))
    {
        //create a new passenger queue w name from file
        PassengerQueue newStation;   
        stationNames.push_back(currentLine);
        
        //add the station to the next spot in both vectors
        train.push_back(newStation); 
        stationLines.push_back(newStation);
    }
}

/* printMetSim()
*  Purpose: prints out the current state of the metro simulation 
* Parameters: the output stream to be printed to
*/
void MetroSim::printMetSim(ostream &output)
{
    //prints according to spec; use currstation for where to place train
    //keep in mind; station number = index of station + 1 (because starts at 1)
        
    //first, print out all the passengers on the train
    output << "Passengers on the train: {";
    for (int i = 0; i < (int)train.size(); i++){
        train[i].print(output);
    }
    output << "}\n";
    
    //then print out all the stations
    for (int i = 0; i < (int)stationLines.size(); i++){
        if (currStation - 1 == i){
            output << "TRAIN: ";
        }
        else {
            output << "       ";
        }
        
        output << "[" << i + 1 << "] " << stationNames[i] << " ";
        output << "{";
        stationLines[i].print(output);
        output << "}" << "\n";
    }
}

/* addNewPassengerStation()
*  Purpose: creates and adds a new passenger to queue at a station 
*           result of command:[p Arrival Departure}
* Parameters: the arrival and departure stations as integers for new passenger
*/
void MetroSim::addNewPassengerStation(int arrival, int departure)
{
    //passes in newly created passenger to add to corresponding station queue 
    
    //creates new passenger with given info from command
    Passenger newPassenger = createPassenger(arrival, departure);
    
    //puts them in the back of the queue at their arrival station
    stationLines[arrival - 1].enqueue(newPassenger);
}

/* createPassenger()
*  Purpose: creates a new passenger and increments the passengerID
*  Parameters: the arrival and departure stations as ints for the new passenger
*/Passenger MetroSim::createPassenger(int arrival, int departure)
{
    //initializes and returns new passenger from input 
    Passenger newPass(passengerID, arrival, departure);     
    passengerID++; //after new passenger has been created, increment current ID
    return newPass;
}


/* addNewPassengersTrain()
*  Purpose: adds passengers from departure station onto train b/f train moves 
*           part of the result of command: m m
* Parameters: N/A
*/
void MetroSim::addNewPassengersTrain()
{
    //go through the current station and add each passenger in the queue 
    //to the back of their corresponding destination station queue
    
    // ** remember that current station = the station's index+1 **
    
    int queueSize = stationLines[currStation - 1].size();
    for (int i = 0; i < queueSize; i++)
    {
        //gets the passenger at the front of the line at the current station
        Passenger currPass = stationLines[currStation-1].front();
        
        //determines the passengers destination station
        int destinationStation = currPass.to;            
        
        //places the passenger in the back of the 
        //queue in the train based on destination
        train[destinationStation - 1].enqueue(currPass);
        
        //removes passenger at the front of the station line b/c just boarded 
        stationLines[currStation - 1].dequeue();
    }

}

/* moveTrain()
*  Purpose: moves the train: handles everything to do in m m command including
*           calling necessary helper functions
* Parameters: output file to print out the completed passengers to
*/
void MetroSim::moveTrain(ostream &outputFile)
{     
    //call addNewPassengerTrain to take all passengers in current station
    //queue and move them onto train to their specific destination queue
    if (stationLines[currStation - 1].size() != 0)
    {
        addNewPassengersTrain();
    }
    //increment current station
    //if currently at the last one, move to first
    if (currStation == (int)train.size()){
        currStation = 1;
    }
    else {
        currStation++;
    }
    
    //call removePassengers() to get rid of those whos current
    //destination is here
    removePassengers(outputFile);
}


/* removePassengers()
*  Purpose: removes passenger from front of queue of the passengers whose
*           destination is the current station
*  Parameters: output file to print out the completed passengers to
*/
void MetroSim::removePassengers(ostream &outputFile)
{
    
    // ** remember that current station = the station's index+1 **
    int lineSize = train[currStation - 1].size();
    //go through each passenger in the destination queue in the train 
    //to get off at this station
    for (int i = 0; i < lineSize; i++)
    {
        //gets the passenger at the front of the line at the current station
        Passenger currPass = train[currStation - 1].front();
        string currName = stationNames[currStation - 1];
        //send info to output file
        printDeboardedPassenger(outputFile, currPass, currName);  
        train[currStation-1].dequeue(); //remove the passenger
    }
    
}

/* printDeboardedPassenger()
*  Purpose: print function for when passengers exit the train
*  Parameters: output file to print out the passengers to and the passenger to
*              print
*/

void MetroSim::printDeboardedPassenger(ostream &outputFile, Passenger pass, 
    string name)
{
    //string currStationName = stationLines[currStation-1].getStationName();
    outputFile << "Passenger " << pass.id << " left train at station ";
    outputFile << name << "\n";
    
}

