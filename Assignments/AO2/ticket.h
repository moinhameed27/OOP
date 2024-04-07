/*
Composer : Muhammad Moin U Din
Naming Convention : camelCase
Description : Ticket header file of Flight Reservation System having all the functions of a Passenger's ticket record.
*/

#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "validation.h"
using namespace std;


class Ticket
{
    string ticketNumber;
    string flightNumber;
    int seatNumber;
    int classType;
    int ticketPrice;

public:
    friend class FMS;
    friend class Passenger;
    Ticket();
    void setTicket(string, string, int, int, int); // , string, char, int, int, string);
    void display();
    void inputData(string);
    void writeToFile(ofstream &);
    void readFromFile(ifstream &);
};

// Default Constructor
Ticket::Ticket() : ticketNumber(""), flightNumber(""), seatNumber(0), classType(0), ticketPrice(0) {} // ,  passenger()  {}

// Setter function for all member variables
void Ticket::setTicket(string tN, string fN, int sN, int cT, int tP) //, string pN, char pG, int pA, int pPN, string pC)
{
    ticketNumber = tN;
    flightNumber = fN;
    seatNumber = sN;
    classType = cT;
    ticketPrice = tP;
}

// Display function showing all details of a ticket
void Ticket::display()
{
    cout << "Ticket Number : " << ticketNumber << endl;
    cout << "Ticket Price : " << ticketPrice << endl;
    if (classType == 1)
        cout << "Class Type : Economy" << endl;
    else if (classType == 2)
        cout << "Class Type : Premium Economy" << endl;
    else if (classType == 3)
        cout << "Class Type : Bussiness" << endl;
    else
        cout << "Class Type : First Class" << endl;
    cout << "Seat Number : " << seatNumber << endl;
}

// Taking data of a ticket fromt the user
void Ticket::inputData(string fN)
{
    // cout << "======Ticket Input=====" << endl;
    // cout << "Enter Ticket Number : ";
    // integerValidation(ticketNumber);
    cout << "Enter class Type - 1. Economy, 2. Premium, 3. Bussiness, 4. First Class" << endl;
    integerValidation(classType);
    while (classType < 1 || classType > 4)
    {
        cout << "Wrong Input. Enter 1 - 4 : ";
        integerValidation(classType);
    }
    if(classType == 1)
        cout << "Economy Ticket Price is : " << ticketPrice << endl;
    if (classType == 2)
    {
        ticketPrice *= 2;
        cout << "Premium Economy Ticket Price is : " << ticketPrice << endl;;
    }
    if (classType == 3)
    {
        ticketPrice *= 4;
        cout << "Bussiness Class Ticket Price is : " << ticketPrice << endl;;
    }
    if (classType == 4)
    {
        ticketPrice *= 8;
        cout << "First Class Ticket Price is : " << ticketPrice << endl;;
    }
    cout << "Enter Seat Number : ";
    integerValidation(seatNumber);
    while (seatNumber < 1 || seatNumber > 115)
    {
        cout << "Wrong Input. Enter Again (1 - 115) : ";
        integerValidation(seatNumber);
    }
    ticketNumber = fN;
    ticketNumber += "-";
    ticketNumber += to_string(seatNumber);
    cout << "Your Ticket Number is : " << ticketNumber << endl;
}

// Writing ticket info to a file
void Ticket::writeToFile(ofstream &fout)
{
    fout << ticketNumber << endl;
    fout << ticketPrice << endl;
    fout << classType << endl;
    fout << seatNumber << endl;
}

// Reading ticket info from the file
void Ticket::readFromFile(ifstream &fin)
{
    fin >> ticketNumber;
    fin >> ticketPrice;
    fin >> classType;
    fin >> seatNumber;
}

#endif