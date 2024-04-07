/*
Composer : Muhammad Moin U Din
Naming Convention : camelCase
Description : Flight header file of Flight Reservation System having all the functions of a Passenger's Flight.
*/

#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>
#include "validation.h"
#include <fstream>
using namespace std;

class Flight
{
    string flightNumber;
    int seatsAvailable;
    int reservedSeats;

public:
    // Friend Access
    friend class FMS;
    // Function prototypes
    Flight();
    void setFlight(string);
    void display();
    void inputData();
    void decrementSeats();
    void incrementReservedSeats();
    void writeToFile(ofstream &);
    void readFromFile(ifstream &);
};

// Default Constructor
Flight::Flight() : flightNumber("") {}

// Setter function for the member variables of a flight
void Flight::setFlight(string fN)
{
    flightNumber = fN;
}

// Display Function
void Flight::display()
{
    cout << "Flight Number : " << flightNumber << endl;
}

// Taking data from the user
void Flight::inputData()
{
    cout << "======Flight Input=====" << endl;
    cout << "Enter the Flight Number : ";
    // cin.ignore();
    getline(cin, flightNumber);
}

// Decreasing the seats Available
void Flight::decrementSeats()
{
    seatsAvailable--;
}

// Increasing the reserved seats
void Flight::incrementReservedSeats()
{
    reservedSeats++;
}

// Writing data to the file
void Flight::writeToFile(ofstream &fout)
{
    fout << flightNumber << endl;
}

// Reading Data from the file
void Flight::readFromFile(ifstream &fin)
{
    fin >> flightNumber;
}

#endif