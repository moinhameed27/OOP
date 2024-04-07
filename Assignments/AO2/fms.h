/*
Composer : Muhammad Moin U Din
Naming Convention : camelCase
Description : Main header file of Flight Reservation System doing all the functionalities.
*/

#ifndef FMS_H
#define FMS_H

#include <iostream>
#include <limits>
#include "flight.h"
#include "passenger.h"
#include "time.h"
#include "ticket.h"
using namespace std;

const int N = 115;
class FMS
{
    Flight flight;
    Passenger passenger[N];
    int seats[N];

public:
    // Function prototypes
    FMS();
    void setFMS(string, string, char, int, string, string, string, string, int, int, int);
    void display();
    void inputData();
    void writeToFile(ofstream &);
    void readFromFile(ifstream &);
    void inputPassenger(string);
    void deleteRecord(string);
    void setTicketPrice(int);
    int getTicketPrice();
    void setFlightName(string);
    string getFlightName();
    void searchPassenger(string);
    void updateInfo(string, string);
    bool seatAvailability(int);
    void setSeat(int);
    int getSeat();
    int getRS();
    void changeSeatAndType(string, int);
    bool passportValidation(string);
    void setPassport(string);
    string getPassport();
};

// Default Constructor
FMS::FMS() : flight(), passenger()
{
    flight.seatsAvailable = N;
    flight.reservedSeats = 0;
}

// Setter Function
void FMS::setFMS(string fN, string nm, char g, int a, string p, string n, string tN, string tFN, int sN, int cT, int tP)
{

    flight.setFlight(fN);
    passenger->setNGAPN(nm, g, a, p, n, tN, tFN, sN, cT, tP);
    flight.reservedSeats = 0;
    flight.seatsAvailable = N;
}

// Setter function for flight name
void FMS::setFlightName(string fN)
{
    flight.setFlight(fN);
}

string FMS::getFlightName()
{
    return flight.flightNumber;
}

// Display Function showing details of flight and Passenger
void FMS::display()
{
    // flight.display();
    for (size_t i = 0; i < N; i++)
    {
        if (passenger[i].age != 0)
        {
            cout << "------Passenger " << i + 1 << "------" << endl;
            passenger[i].display();
        }
    }
}

// Taking data from the user of the member variables
void FMS::inputData()
{
    // flight.inputData();
    int rS = flight.reservedSeats;
    cout << "------Passenger " << rS + 1 << "------" << endl;
    inputPassenger(flight.flightNumber);
    cin.ignore();
}

// Writing all the data to a file
void FMS::writeToFile(ofstream &fout)
{
    // flight.writeToFile(fout);
    for (int i = 0; i < N; i++)
    {
        if (passenger[i].age != 0)
            passenger[i].writeToFile(fout);
    }
}

// Reading data from the file
void FMS::readFromFile(ifstream &fin)
{
    // flight.readFromFile(fin);
    int i = 0;
    while (i < N && !fin.eof())
    {
        passenger[i].ticket.flightNumber = flight.flightNumber;
        passenger[i].readFromFile(fin);
        if (passenger[i].age == 0)
            break;
        passenger[i].ticket.ticketPrice = getTicketPrice();
        flight.incrementReservedSeats();
        flight.decrementSeats();
        i++;
    }
}

// Passenger Input
void FMS::inputPassenger(string fN)
{
    int n = flight.reservedSeats;
    passenger[n].inputData(flight.flightNumber);
    flight.incrementReservedSeats();
    flight.decrementSeats();
}

// Deleting a record(In case of cancellation of a seat)
void FMS::deleteRecord(string nm)
{
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        if (passenger[i].name == nm)
        {
            passenger[i].deleteRecord();
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << "Name " << nm << " is not present in the Passenger's list" << endl;

    flight.reservedSeats--;
    flight.seatsAvailable++;
}

// Setter function for ticket price
void FMS::setTicketPrice(int price)
{
    passenger->ticket.ticketPrice = price;
}

// Getter function for ticket Price
int FMS::getTicketPrice()
{
    return passenger->ticket.ticketPrice;
}

// Searching the passenger in the data
void FMS::searchPassenger(string nm)
{
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        if (passenger[i].name == nm)
        {
            passenger[i].display();
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << "Name " << nm << " is not present in the Passenger's list" << endl;
}

// Updating the information of a passenger
void FMS::updateInfo(string nm, string fN)
{
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        if (passenger[i].name == nm)
        {
            passenger[i].inputData(fN);
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << "Name " << nm << " is not present in the Passenger's list" << endl;
}

// Updating the seat number and class type
void FMS::changeSeatAndType(string nm, int bP)
{
    bool flag = false;
    for (int i = 0; i < N; i++)
    {
        if (passenger[i].name == nm)
        {
            passenger[i].changeSeatAndType(bP);
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << "Name " << nm << " is not present in the Passenger's list" << endl;
}

// Setter function for seat number
void FMS::setSeat(int seat)
{
    passenger->ticket.seatNumber = seat;
}

// Getter function for seat number
int FMS::getSeat()
{
    return passenger->ticket.seatNumber;
}

// Checking the Availability of the seat
bool FMS::seatAvailability(int seatNumber)
{
    for (int i = 0; i < N; i++)
    {
        if (passenger[i].ticket.seatNumber == seatNumber)
            return false;
    }
    return true;
}

// Validation of Passport Number (Passengers cannot have same passport Number)
bool FMS::passportValidation(string pN)
{
    for (size_t i = 0; i < N; i++)
    {
        if (passenger[i].passportNumber == pN)
            return false;
    }
    return true;
}

// Setter function for Passport Number
void FMS::setPassport(string pN)
{
    passenger->passportNumber = pN;
}

// Getter Function for Passport Number
string FMS::getPassport()
{
    return passenger->passportNumber;
}

// Getter function for reserved seats
int FMS::getRS()
{
    return flight.reservedSeats;
}

#endif