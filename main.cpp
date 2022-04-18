/* 
 * main.cpp
 * 
 * COMP 15 homework 2
 * by Gillian Feder, October 2021
 * 
 * The main class, which is where files are read from and printed to and/or 
 * input is taken from cin and printed to cout. Handles improper number
 * of command line arguments and running the program using a query loop 
 * with a MetroSim object called program. Quits when number of arguments is
 * incorrect, it runs out of commands or the command m f is given.
 * 
 */

#include <iostream>
#include <fstream>
#include <string>

#include "MetroSim.h"

using namespace std;

template <typename streamtype>
void open_or_quit(streamtype &stream, string fileName);

void queryLoop(istream &input, ofstream &output, MetroSim program);

int main(int argc, char *argv[])
{
    //if incorrect amount of command line arguments
    if (argc != 3 and argc != 4){
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]";
        exit(EXIT_FAILURE);
    }
    //open Files, and create and open an output file
    //give error messages if files cant be opened
    ifstream stationsFile;
    ofstream outputFile;
    ifstream commandsFile;
    
    open_or_quit(stationsFile, argv[1]);
    open_or_quit(outputFile, argv[2]);
    
    //initialize metro sim and then close the file 
    MetroSim program;
    program.initializeQueues(stationsFile);
    stationsFile.close();
    
    if (argc == 3){    //if no commands file provided 
        queryLoop(cin, outputFile, program);
    }
    else {  //if commands file is provided
        open_or_quit(commandsFile, argv[3]); 
        queryLoop(commandsFile, outputFile, program);
        commandsFile.close();
    }
    
    return 0;
}

template <typename streamtype>
void open_or_quit(streamtype &stream, string fileName)
{
    stream.open(fileName);
    if (! stream.is_open())
    {
        cerr << "Error: could not open file " << fileName;
        exit(EXIT_FAILURE);
    }
}

void queryLoop(istream &input, ofstream &output, MetroSim program)
{
    //print program before starting
    program.printMetSim(cout);

    string command;
    cout << "Command? ";
    while (getline(input, command))
    {
        if (command[0] == 'p')
        {
            int arrival, departure;
            int depIndexStart = 4;
            arrival = command[2] - '0';
            if (command [3] != ' ')
            {
                arrival *= 10;
                arrival += (command[3] - '0');
                depIndexStart++;
            }
            departure = command[depIndexStart] - '0';
            if ((int)command.length() > depIndexStart+1)
            {
                departure *= 10;
                departure += (command[depIndexStart+1] - '0');
            }
            program.addNewPassengerStation(arrival, departure);
        }
        else if (command == "m m")
        {
            program.moveTrain(output);
        }
        else //command == m f; terminate simulation 
        { 
            output.close();                                 
            cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
            exit(EXIT_SUCCESS);
        }
    
        program.printMetSim(cout);
    
        cout << "Command? ";
    }
}

 


