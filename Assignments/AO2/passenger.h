/*
Composer : Muhammad Moin U Din
Naming Convention : camelCase
Description : Passenger header file of Flight Reservation System having all the functions of a Passenger's record.
*/

#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include "validation.h"
#include "ticket.h"
using namespace std;

class Passenger
{
    string name;
    char gender;
    int age;
    string passportNumber;
    string nationality;
    Ticket ticket;

public:
    friend class FMS;
    Passenger();
    Passenger(string, char, int, string, string, string, string, int, int, int);
    void setNGAPN(string, char, int, string, string, string, string, int, int, int);
    void display();
    void inputData(string fN);
    void writeToFile(ofstream &);
    void readFromFile(ifstream &);
    void deleteRecord();
    void changeSeatAndType(int);
};

// Default Constructor
Passenger::Passenger() : name(""), gender(' '), age(0), passportNumber(""), nationality(""), ticket() {}

// Overloaded Constructor
Passenger::Passenger(string nm, char g, int a, string p, string n, string tN, string tFN, int sN, int cT, int tP) : name(nm), gender(g), age(a), passportNumber(p), nationality(n)
{
    ticket.setTicket(tN, tFN, sN, cT, tP);
}

// Setter Function for all member Variables
void Passenger::setNGAPN(string nm, char g, int a, string p, string n, string tN, string tFN, int sN, int cT, int tP)
{
    name = nm;
    gender = g;
    age = a;
    passportNumber = p;
    nationality = n;
    ticket.setTicket(tN, tFN, sN, cT, tP);
}

// Display function of passenger details
void Passenger::display()
{
    cout << "Name : " << name << endl;
    cout << "Gender : " << gender << endl;
    cout << "Age : " << age << endl;
    cout << "Passport Number : " << passportNumber << endl;
    cout << "Nationality : " << nationality << endl;
    // cout << "Ticket Details" << endl;
    ticket.display();
}

// Taking data of a Passenger from the user
void Passenger::inputData(string fN)
{
    // cout << "Passenger Input" << endl;
    cout << "Enter name : ";
    getline(cin, name);
    cout << "Enter Gender(M/F) : ";
    cin >> gender;
    while (gender != 'M' && gender != 'F')
    {
        cout << "Wrong Input. Enter the Gender again : ";
        cin >> gender;
    }
    cout << "Enter age : ";
    integerValidation(age);
    cout << "Enter Passport Number(9-characters) : ";
    cin.ignore();
    getline(cin, passportNumber);
    while (passportNumber.size() != 9)
    {
        cout << "Invalid Input. Enter again(9-characters) : ";
        getline(cin, passportNumber);
    }
    cout << "Enter Nationality : ";
    getline(cin, nationality);
    ticket.inputData(fN);
}

// Writing the Passenger's data to it's specific flight file
void Passenger::writeToFile(ofstream &fout)
{
    fout << name << endl;
    fout << gender << endl;
    fout << age << endl;
    fout << passportNumber << endl;
    fout << nationality << endl;
    ticket.writeToFile(fout);
}

// Reading the Passenger's data from it's specific flight file
void Passenger::readFromFile(ifstream &fin)
{
    getline(fin, name);
    fin >> gender;
    fin >> age;
    fin.ignore();
    fin >> passportNumber;
    fin.ignore();
    getline(fin, nationality);
    ticket.readFromFile(fin);
    fin.ignore();
}

// Deleting record of a Passenger from it's specific Flight file
void Passenger::deleteRecord()
{
    name = "";
    gender = ' ';
    age = 0;
    passportNumber = "";
    nationality = "";
    ticket.setTicket("", "", 0, 0, 0);
}

// Update class type or seat number of a passenger
void Passenger::changeSeatAndType(int bP)
{
    int option;
    cout << "Enter -> 1. Change Class Type, 2. Change Seat Number, 3. Change Both" << endl;
    integerValidation(option);
    while (option < 1 || option > 3)
    {
        cout << "Invalid Input. Enter (1 - 3) : ";
        integerValidation(option);
    }
    if (option == 1)
    {
        cout << "Enter class Type - 1. Economy, 2. Premium, 3. Bussiness, 4. First Class" << endl;
        integerValidation(ticket.classType);
        while (ticket.classType < 1 || ticket.classType > 4)
        {
            cout << "Wrong Input. Enter 1 - 4 : ";
            integerValidation(ticket.classType);
        }
        if (ticket.classType == 1)
        {
            ticket.ticketPrice = bP;
            cout << "Economy Ticket Price is : " << bP << endl;
        }
        if (ticket.classType == 2)
        {
            ticket.ticketPrice = bP * 2;
            cout << "Premium Economy Ticket Price is : " << ticket.ticketPrice << endl;
        }
        if (ticket.classType == 3)
        {
            ticket.ticketPrice = bP * 4;
            cout << "Bussiness Class Ticket Price is : " << ticket.ticketPrice << endl;
        }
        if (ticket.classType == 4)
        {
            ticket.ticketPrice = bP * 8;
            cout << "First Class Ticket Price is : " << ticket.ticketPrice << endl;
        }
        cout << "Class Type Changed Successfully" << endl;
    }
    else if (option == 2)
    {
        cout << "Enter Seat Number : ";
        integerValidation(ticket.seatNumber);
        while (ticket.seatNumber < 1 || ticket.seatNumber > 115)
        {
            cout << "Wrong Input. Enter Again (1 - 115) : ";
            integerValidation(ticket.seatNumber);
        }
        cout << "Seat Number Changed Successfully" << endl;
    }
    else
    {
        cout << "Enter class Type - 1. Economy, 2. Premium, 3. Bussiness, 4. First Class" << endl;
        integerValidation(ticket.classType);
        while (ticket.classType < 1 || ticket.classType > 4)
        {
            cout << "Wrong Input. Enter 1 - 4 : ";
            integerValidation(ticket.classType);
        }
        if (ticket.classType == 1)
        {
            ticket.ticketPrice = bP;
            cout << "Economy Ticket Price is : " << bP << endl;
        }
        if (ticket.classType == 2)
        {
            ticket.ticketPrice = bP * 2;
            cout << "Premium Economy Ticket Price is : " << ticket.ticketPrice << endl;
        }
        if (ticket.classType == 3)
        {
            ticket.ticketPrice = bP * 4;
            cout << "Bussiness Class Ticket Price is : " << ticket.ticketPrice << endl;
        }
        if (ticket.classType == 4)
        {
            ticket.ticketPrice = bP * 8;
            cout << "First Class Ticket Price is : " << ticket.ticketPrice << endl;
        }
        cout << "Enter Seat Number : ";
        integerValidation(ticket.seatNumber);
        while (ticket.seatNumber < 1 || ticket.seatNumber > 115)
        {
            cout << "Wrong Input. Enter Again (1 - 115) : ";
            integerValidation(ticket.seatNumber);
        }
        cout << "Seat Number and Class Type changed successfully" << endl;
    }
}

// End of Program

#endif