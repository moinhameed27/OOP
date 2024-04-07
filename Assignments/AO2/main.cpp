/*
Composer : Muhammad Moin U Din
Naming Convention : camelCase
Description : Main file of Flight Reservation System performing all the functionalities.
*/

#include <iostream>
#include <iomanip>
#include "fms.h"
#include <fstream>
using namespace std;

// Function Prototypes
void displayLocalFlights();
void displayForeignFlights();
void writeToFile(string, int);
void seatAvailability(string, int);
void waitList(string, int);
void cancelSeat(string, string);
void flightDetails(string);
void displayPassengers(string);
void searchPassenger(string, string);
void updateInfo(string, string);
void changeSeatAndType(string, string,  int);
void airportInfo();

int main()
{
    int userOption, price;
    string flightNumber;
    do
    {
        cout << endl;
        cout << "------------TAYYAB INTERNATIONAL AIRLINES, ISLAMABAD------------" << endl;
        cout << "1.  Book a seat" << endl;
        cout << "2.  Cancel a seat" << endl;
        cout << "3.  Display passenger list" << endl;
        cout << "4.  Display flight details" << endl;
        cout << "5.  Search for a Passenger" << endl;
        cout << "6.  Update Passenger Information" << endl;
        cout << "7.  Seat Availability Check" << endl;
        cout << "8.  WaitList Functionality" << endl;
        cout << "9.  Change Seat Number and Class Type" << endl;
        cout << "10. List of Local Flights" << endl;
        cout << "11. List of Foreign Flights" << endl;
        cout << "12. Info" << endl;
        cout << "13. Exit" << endl;
        cout << "Enter your Choice : ";
        integerValidation(userOption);
        cout << endl;

        switch (userOption)
        {
        // Book a Seat
        case 1:
        {
            cout << "Flight Booking" << endl;
            cout << "Departure City : Islamabad" << endl;
            displayLocalFlights();
            displayForeignFlights();
            cout << "Enter 1 - 10 : " << endl;
            int option;
            integerValidation(option);
            while (option < 1 || option > 10)
            {
                cout << "Wrong Input. Enter 1 - 10" << endl;
                integerValidation(option);
            }
            switch (option)
            {
            case 1:
                writeToFile("TL101", 200);
                break;
            case 2:
                writeToFile("TL202", 250);
                break;
            case 3:
                writeToFile("TL303", 180);
                break;
            case 4:
                writeToFile("TL404", 220);
                break;
            case 5:
                writeToFile("TF101", 300);
                break;
            case 6:
                writeToFile("TF202", 500);
                break;
            case 7:
                writeToFile("TF303", 700);
                break;
            case 8:
                writeToFile("TF404", 600);
                break;
            case 9:
                writeToFile("TF505", 800);
                break;
            case 10:
                writeToFile("TF606", 900);
                break;
            }

            break;
        case 2:
            // Cancel a seat
            {
                displayLocalFlights();
                displayForeignFlights();
                cout << "Enter (Flight Reference) 1 - 10 : " << endl;
                int option;
                integerValidation(option);
                while (option < 1 || option > 10)
                {
                    cout << "Wrong Input. Enter 1 - 10" << endl;
                    integerValidation(option);
                }
                string name;
                cout << "Enter name of Passenger : " << endl;
                cin.ignore();
                getline(cin, name);
                switch (option)
                {
                case 1:
                    cancelSeat("TL101.txt", name);
                    break;
                case 2:
                    cancelSeat("TL202.txt", name);
                    break;
                case 3:
                    cancelSeat("TL303.txt", name);
                    break;
                case 4:
                    cancelSeat("TL404.txt", name);
                    break;
                case 5:
                    cancelSeat("TF101.txt", name);
                    break;
                case 6:
                    cancelSeat("TF202.txt", name);
                    break;
                case 7:
                    cancelSeat("TF303.txt", name);
                    break;
                case 8:
                    cancelSeat("TF404.txt", name);
                    break;
                case 9:
                    cancelSeat("TF505.txt", name);
                    break;
                case 10:
                    cancelSeat("TF606.txt", name);
                    break;
                }
            }
            break;
        case 3:
            // Display Passenger List
            {
                displayLocalFlights();
                displayForeignFlights();
                cout << "Enter (Flight Reference) 1 - 10 : " << endl;
                int option;
                integerValidation(option);
                while (option < 1 || option > 10)
                {
                    cout << "Wrong Input. Enter 1 - 10" << endl;
                    integerValidation(option);
                }
                switch (option)
                {
                case 1:
                    displayPassengers("TL101.txt");
                    break;
                case 2:
                    displayPassengers("TL202.txt");
                    break;
                case 3:
                    displayPassengers("TL303.txt");
                    break;
                case 4:
                    displayPassengers("TL404.txt");
                    break;
                case 5:
                    displayPassengers("TF101.txt");
                    break;
                case 6:
                    displayPassengers("TF202.txt");
                    break;
                case 7:
                    displayPassengers("TF303.txt");
                    break;
                case 8:
                    displayPassengers("TF404.txt");
                    break;
                case 9:
                    displayPassengers("TF505.txt");
                    break;
                case 10:
                    displayPassengers("TF606.txt");
                    break;
                }
            }
            break;
        case 4:
            // Display flight Details
            {
                displayLocalFlights();
                displayForeignFlights();
                cout << "Enter (Flight Reference) 1 - 10 : " << endl;
                int option;
                integerValidation(option);
                while (option < 1 || option > 10)
                {
                    cout << "Wrong Input. Enter 1 - 10" << endl;
                    integerValidation(option);
                }
                switch (option)
                {
                case 1:
                    flightDetails("TL101");
                    break;
                case 2:
                    flightDetails("TL202");
                    break;
                case 3:
                    flightDetails("TL303");
                    break;
                case 4:
                    flightDetails("TL404");
                    break;
                case 5:
                    flightDetails("TF101");
                    break;
                case 6:
                    flightDetails("TF202");
                    break;
                case 7:
                    flightDetails("TF303");
                    break;
                case 8:
                    flightDetails("TF404");
                    break;
                case 9:
                    flightDetails("TF505");
                    break;
                case 10:
                    flightDetails("TF606");
                    break;
                }
            }
            break;
        case 5:
            // Search for a Passenger
            {
                displayLocalFlights();
                displayForeignFlights();
                cout << "Enter (Flight Reference) 1 - 10 : " << endl;
                int option;
                integerValidation(option);
                while (option < 1 || option > 10)
                {
                    cout << "Wrong Input. Enter 1 - 10" << endl;
                    integerValidation(option);
                }
                string name;
                cout << "Enter name of Passenger : ";
                cin.ignore();
                getline(cin, name);
                switch (option)
                {
                case 1:
                    searchPassenger("TL101.txt", name);
                    break;
                case 2:
                    searchPassenger("TL202.txt", name);
                    break;
                case 3:
                    searchPassenger("TL303.txt", name);
                    break;
                case 4:
                    searchPassenger("TL404.txt", name);
                    break;
                case 5:
                    searchPassenger("TF101.txt", name);
                    break;
                case 6:
                    searchPassenger("TF202.txt", name);
                    break;
                case 7:
                    searchPassenger("TF303.txt", name);
                    break;
                case 8:
                    searchPassenger("TF404.txt", name);
                    break;
                case 9:
                    searchPassenger("TF505.txt", name);
                    break;
                case 10:
                    searchPassenger("TF606.txt", name);
                    break;
                }
            }
            break;
        case 6:
            // Update Passenger's Information
            {
                displayLocalFlights();
                displayForeignFlights();
                cout << "Enter (Flight Reference) 1 - 10 : " << endl;
                int option;
                integerValidation(option);
                while (option < 1 || option > 10)
                {
                    cout << "Wrong Input. Enter 1 - 10" << endl;
                    integerValidation(option);
                }
                string name;
                cout << "Enter name of Passenger : ";
                cin.ignore();
                getline(cin, name);
                switch (option)
                {
                case 1:
                    updateInfo("TL101", name);
                    break;
                case 2:
                    updateInfo("TL202", name);
                    break;
                case 3:
                    updateInfo("TL303", name);
                    break;
                case 4:
                    updateInfo("TL404", name);
                    break;
                case 5:
                    updateInfo("TF101", name);
                    break;
                case 6:
                    updateInfo("TF202", name);
                    break;
                case 7:
                    updateInfo("TF303", name);
                    break;
                case 8:
                    updateInfo("TF404", name);
                    break;
                case 9:
                    updateInfo("TF505", name);
                    break;
                case 10:
                    updateInfo("TF606", name);
                    break;
                }
            }
            break;
        case 7:
            // Check Seat Availability
            {
                int seat, option;
                displayLocalFlights();
                displayForeignFlights();
                cout << "Enter (Flight Reference) 1 - 10 : ";
                integerValidation(option);

                while (option < 1 || option > 10)
                {
                    cout << "Wrong Input. Enter (1 - 10) : ";
                    integerValidation(option);
                }
                cout << "Enter seat number to check(1 - 115) : ";
                integerValidation(seat);
                while (seat < 1 || seat > 115)
                {
                    cout << "Wrong Input. Enter (1 - 115) : ";
                    integerValidation(seat);
                }

                switch (option)
                {
                case 1:
                    seatAvailability("TL101.txt", seat);
                    break;
                case 2:
                    seatAvailability("TL202.txt", seat);
                    break;
                case 3:
                    seatAvailability("TL303.txt", seat);
                    break;
                case 4:
                    seatAvailability("TL404.txt", seat);
                    break;
                case 5:
                    seatAvailability("TF101.txt", seat);
                    break;
                case 6:
                    seatAvailability("TF202.txt", seat);
                    break;
                case 7:
                    seatAvailability("TF303.txt", seat);
                    break;
                case 8:
                    seatAvailability("TF404.txt", seat);
                    break;
                case 9:
                    seatAvailability("TF505.txt", seat);
                    break;
                case 10:
                    seatAvailability("TF606.txt", seat);
                    break;
                }
            }
            break;
        case 8:
            // Waitlist of a Reserved Seat
            {
                int seat, option;
                displayLocalFlights();
                displayForeignFlights();
                cout << "Enter (Flight Reference) 1 - 10 : ";
                integerValidation(option);

                while (option < 1 || option > 10)
                {
                    cout << "Wrong Input. Enter (1 - 10) : ";
                    integerValidation(option);
                }
                cout << "Enter seat number to check(1 - 115) : ";
                integerValidation(seat);
                while (seat < 1 || seat > 115)
                {
                    cout << "Wrong Input. Enter (1 - 115) : ";
                    integerValidation(seat);
                }
                switch (option)
                {
                case 1:
                    waitList("TL101.txt", seat);
                    break;
                case 2:
                    waitList("TL202.txt", seat);
                    break;
                case 3:
                    waitList("TL303.txt", seat);
                    break;
                case 4:
                    waitList("TL404.txt", seat);
                    break;
                case 5:
                    waitList("TF101.txt", seat);
                    break;
                case 6:
                    waitList("TF202.txt", seat);
                    break;
                case 7:
                    waitList("TF303.txt", seat);
                    break;
                case 8:
                    waitList("TF404.txt", seat);
                    break;
                case 9:
                    waitList("TF505.txt", seat);
                    break;
                case 10:
                    waitList("TF606.txt", seat);
                    break;
                }
            }
            break;
        case 9:
            // Update Class Type or Seat Number
            {
                displayLocalFlights();
                displayForeignFlights();
                cout << "Enter (Flight Reference) 1 - 10 : ";
                integerValidation(option);

                while (option < 1 || option > 10)
                {
                    cout << "Wrong Input. Enter (1 - 10) : ";
                    integerValidation(option);
                }
                string name;
                cout << "Enter name of Passenger : " << endl;
                cin.ignore();
                getline(cin, name);
                switch (option)
                {
                case 1:
                    changeSeatAndType("TL101.txt", name, 200);
                    break;
                case 2:
                    changeSeatAndType("TL202.txt", name, 250);
                    break;
                case 3:
                    changeSeatAndType("TL303.txt", name, 180);
                    break;
                case 4:
                    changeSeatAndType("TL404.txt", name, 220);
                    break;
                case 5:
                    changeSeatAndType("TF101.txt", name, 300);
                    break;
                case 6:
                    changeSeatAndType("TF202.txt", name, 500);
                    break;
                case 7:
                    changeSeatAndType("TF303.txt", name, 700);
                    break;
                case 8:
                    changeSeatAndType("TF404.txt", name, 600);
                    break;
                case 9:
                    changeSeatAndType("TF505.txt", name, 800);
                    break;
                case 10:
                    changeSeatAndType("TF606.txt", name, 900);
                    break;
                }
            }
            break;
        case 10:
            // List of Local Flights
            cout << "Departure City : Islamabad" << endl;
            displayLocalFlights();
            break;
        case 11:
            // List of Foreign flights
            cout << "Departure City : Islamabad" << endl;
            displayForeignFlights();
            break;
        case 12:
            // Information of Tayyab International Airlines
            airportInfo();
            break;
        case 13:
            // Exit from the Airport
            cout << "====== Airport Exit ======" << endl;
            break;
        default:
            // Validation Check
            cout << "Invalid Choice! Please enter a valid option." << endl;
        }
        }
    } while (userOption != 13);

    return 0;
}

/*
Function Definitions
*/

// Displaying all Available Local Flights
void displayLocalFlights()
{
    cout << endl
         << "                ====== Local Flights =====                " << endl;
    cout << " #  " << left << setw(15) << "Flight Number" << setw(15) << " Destination" << setw(16) << "Departure Time" << setw(16) << "Destination Time" << setw(16) << "  Base Price" << endl;
    cout << " 1.  "
         << "  " << left << setw(15) << "TL101" << setw(15) << "Lahore" << setw(15) << " 09:00" << setw(15) << "  10:20" << setw(15) << "    200" << endl;
    cout << " 2.  "
         << "  " << left << setw(15) << "TL202" << setw(15) << "Karachi" << setw(15) << " 10:30" << setw(15) << "  11:50" << setw(15) << "    250" << endl;
    cout << " 3.  "
         << "  " << left << setw(15) << "TL303" << setw(15) << "Peshawar" << setw(15) << " 12:45" << setw(15) << "  13:55" << setw(15) << "    180" << endl;
    cout << " 4.  "
         << "  " << left << setw(15) << "TL404" << setw(15) << "Quetta" << setw(15) << " 14:20" << setw(15) << "  15:40" << setw(15) << "    220" << endl;
}

// Displaying all Available Foreign Flights
void displayForeignFlights()
{
    cout << endl
         << "                ====== Foreign Flights =====                " << endl;
    cout << " #  " << left << setw(15) << "Flight Number" << setw(15) << " Destination" << setw(16) << "Departure Time" << setw(16) << "Destination Time" << setw(16) << "  Base Price" << endl;
    cout << " 5.  "
         << "  " << left << setw(15) << "TF101" << setw(15) << "Dubai" << setw(15) << " 09:00" << setw(15) << "  12:10" << setw(15) << "    300" << endl;
    cout << " 6.  "
         << "  " << left << setw(15) << "TF202" << setw(15) << "London" << setw(15) << " 10:30" << setw(15) << "  15:40" << setw(15) << "    500" << endl;
    cout << " 7.  "
         << "  " << left << setw(15) << "TF303" << setw(15) << "New York" << setw(15) << " 12:45" << setw(15) << "  18:55" << setw(15) << "    700" << endl;
    cout << " 8.  "
         << "  " << left << setw(15) << "TF404" << setw(15) << "Paris" << setw(15) << " 14:20" << setw(15) << "  19:30" << setw(15) << "    600" << endl;
    cout << " 9.  "
         << "  " << left << setw(15) << "TF505" << setw(15) << "Tokyo" << setw(15) << " 16:00" << setw(15) << "  22:10" << setw(15) << "    800" << endl;
    cout << " 10. "
         << "  " << left << setw(15) << "TF606" << setw(15) << "Sydney" << setw(15) << " 18:30" << setw(15) << "  23:40" << setw(15) << "    900" << endl;
}

// Writing a Passenger's Data to it's particular Flight file
void writeToFile(string fileName, int price)
{
    FMS f;
    f.setFlightName(fileName);
    fileName += ".txt";
    ofstream fout(fileName, ios::app);
    f.setTicketPrice(price);
    cin.ignore();
    f.inputData();

    ifstream fin(fileName);
    FMS f2;
    f2.readFromFile(fin);
    // Passport Number Validation
    string passportNumber = f.getPassport();
    if (!f2.passportValidation(passportNumber))
    {
        while (!f2.passportValidation(passportNumber))
        {
            cout << "Passport Number cannot be same as another person. Enter again : ";
            cin.ignore();
            getline(cin, passportNumber);
            while (passportNumber.size() != 9)
            {
                cout << "Invalid Input. Enter again(9-characters) : ";
                getline(cin, passportNumber);
            }
        }
        f.setPassport(passportNumber);
    }

    // Seat Number Validation
    int seat = f.getSeat();
    if (!f2.seatAvailability(seat))
    {
        while (!f2.seatAvailability(seat))
        {
            cout << "Seat is already Reserved. Choose Another : ";
            integerValidation(seat);
            while (seat < 1 || seat > 115)
            {
                cout << "Invalid Input. Choose 1 - 115 : ";
                integerValidation(seat);
            }
        }
        f.setSeat(seat);
    }

    fin.close();
    f.writeToFile(fout);
    fout.close();
    cout << "Seat Booked Successfully" << endl;
}

// Checking the availability of a seat in a flight
void seatAvailability(string fileName, int seat)
{
    ifstream fin(fileName);
    FMS f;
    f.readFromFile(fin);
    if (!f.seatAvailability(seat))
    {
        cout << "Seat Number " << seat << " is Reserved" << endl;
    }
    else
        cout << "Seat Number " << seat << " is not Reserved" << endl;
    fin.close();
}

// If a seat is reserved, entering a passenger to it's waitlist until it becomes available
void waitList(string fileName, int seat)
{
    ifstream fin(fileName);
    FMS f;
    f.readFromFile(fin);
    if (!f.seatAvailability(seat))
    {
        cout << "Seat Number " << seat << " is Reserved. You'll get an update if seat becomes available." << endl;
    }
    else
        cout << "Seat Number " << seat << " is not Reserved. You can book it now." << endl;
    fin.close();
}

// Cancel a seat in a any particular flight
void cancelSeat(string filename, string name)
{
    FMS f;
    ifstream fin(filename);
    f.readFromFile(fin);
    f.deleteRecord(name);
    fin.clear();
    ofstream fout(filename);
    f.writeToFile(fout);
    fout.close();
    fin.close();
    cout << "Seat Cancelled Successfully" << endl;
}

// Display details of any particular flight
void flightDetails(string flightName)
{
    FMS f;
    ifstream fin;
    if (flightName == "TL101")
    {
        flightName += ".txt";
        fin.open(flightName);
        f.readFromFile(fin);
        cout << "Flight Number : TL101" << endl;
        cout << "Destination : Lahore" << endl;
        cout << "Departure Time : 09:00" << endl;
        cout << "Destination Time : 10:20" << endl;
        cout << "Seating Capacity : 115" << endl;
        cout << "Reserved Seats : " << f.getRS() << endl;
        cout << "Economy Seat Price : " << 200 << endl;
    }
    else if (flightName == "TL202")
    {
        flightName += ".txt";
        fin.open(flightName);
        f.readFromFile(fin);
        cout << "Flight Number : TL202" << endl;
        cout << "Destination : Karachi" << endl;
        cout << "Departure Time : 10:30" << endl;
        cout << "Destination Time : 11:50" << endl;
        cout << "Seating Capacity : 115" << endl;
        cout << "Reserved Seats : " << f.getRS() << endl;
        cout << "Economy Seat Price : " << 250 << endl;
    }
    else if (flightName == "TL303")
    {
        flightName += ".txt";
        fin.open(flightName);
        f.readFromFile(fin);
        cout << "Flight Number : TL303" << endl;
        cout << "Destination : Peshawar" << endl;
        cout << "Departure Time : 12:45" << endl;
        cout << "Destination Time : 13:55" << endl;
        cout << "Seating Capacity : 115" << endl;
        cout << "Reserved Seats : " << f.getRS() << endl;
        cout << "Economy Seat Price : " << 180 << endl;
    }
    else if (flightName == "TL404")
    {
        flightName += ".txt";
        fin.open(flightName);
        f.readFromFile(fin);
        cout << "Flight Number : TL404" << endl;
        cout << "Destination : Quetta" << endl;
        cout << "Departure Time : 14:20" << endl;
        cout << "Destination Time : 16:00" << endl;
        cout << "Seating Capacity : 115" << endl;
        cout << "Reserved Seats : " << f.getRS() << endl;
        cout << "Economy Seat Price : " << 220 << endl;
    }
    else if (flightName == "TF101")
    {
        flightName += ".txt";
        fin.open(flightName);
        f.readFromFile(fin);
        cout << "Flight Number : TF101" << endl;
        cout << "Destination : Dubai" << endl;
        cout << "Departure Time : 09:00" << endl;
        cout << "Destination Time : 12:10" << endl;
        cout << "Seating Capacity : 115" << endl;
        cout << "Reserved Seats : " << f.getRS() << endl;
        cout << "Economy Seat Price : " << 300 << endl;
    }
    else if (flightName == "TF202")
    {
        flightName += ".txt";
        fin.open(flightName);
        f.readFromFile(fin);
        cout << "Flight Number : TF202" << endl;
        cout << "Destination : London" << endl;
        cout << "Departure Time : 10:30" << endl;
        cout << "Destination Time : 15:40" << endl;
        cout << "Seating Capacity : 115" << endl;
        cout << "Reserved Seats : " << f.getRS() << endl;
        cout << "Economy Seat Price : " << 500 << endl;
    }
    else if (flightName == "TF303")
    {
        flightName += ".txt";
        fin.open(flightName);
        f.readFromFile(fin);
        cout << "Flight Number : TF303" << endl;
        cout << "Destination : New York" << endl;
        cout << "Departure Time : 12:45" << endl;
        cout << "Destination Time : 18:55" << endl;
        cout << "Seating Capacity : 115" << endl;
        cout << "Reserved Seats : " << f.getRS() << endl;
        cout << "Economy Seat Price : " << 700 << endl;
    }
    else if (flightName == "TF404")
    {
        flightName += ".txt";
        fin.open(flightName);
        f.readFromFile(fin);
        cout << "Flight Number : TF404" << endl;
        cout << "Destination : Paris" << endl;
        cout << "Departure Time : 14:20" << endl;
        cout << "Destination Time : 19:30" << endl;
        cout << "Seating Capacity : 115" << endl;
        cout << "Reserved Seats : " << f.getRS() << endl;
        cout << "Economy Seat Price : " << 600 << endl;
    }
    else if (flightName == "TF505")
    {
        flightName += ".txt";
        fin.open(flightName);
        f.readFromFile(fin);
        cout << "Flight Number : TF505" << endl;
        cout << "Destination : Tokyo" << endl;
        cout << "Departure Time : 16:00" << endl;
        cout << "Destination Time : 22:10" << endl;
        cout << "Seating Capacity : 115" << endl;
        cout << "Reserved Seats : " << f.getRS() << endl;
        cout << "Economy Seat Price : " << 800 << endl;
    }
    else if (flightName == "TF606")
    {
        flightName += ".txt";
        fin.open(flightName);
        f.readFromFile(fin);
        cout << "Flight Number : TF606" << endl;
        cout << "Destination : Sydney" << endl;
        cout << "Departure Time : 18:30" << endl;
        cout << "Destination Time : 23:40" << endl;
        cout << "Seating Capacity : 115" << endl;
        cout << "Reserved Seats : " << f.getRS() << endl;
        cout << "Economy Seat Price : " << 900 << endl;
    }
    fin.close();
}

// Display Passengers of a particular flight
void displayPassengers(string fileName)
{
    FMS f;
    ifstream fin(fileName);
    f.readFromFile(fin);
    f.display();
    fin.close();
}

// Search Passengers in a particular flight
void searchPassenger(string fileName, string name)
{
    FMS f;
    ifstream fin(fileName);
    f.readFromFile(fin);
    f.searchPassenger(name);
    fin.close();
}

// Updating information of a passenger in a particular flight
void updateInfo(string fN, string name)
{
    FMS f;
    string fileName = fN;
    fileName += ".txt";
    ifstream fin(fileName);
    f.readFromFile(fin);
    f.updateInfo(name, fN);
    ofstream fout(fileName);
    f.writeToFile(fout);
    fout.close();
    fin.close();
    cout << "Passenger Information updated Successfully" << endl;
}

// Updating the Class type or seat number of a passenger in a particular flight
void changeSeatAndType(string fileName, string name, int bP)
{
    FMS f;
    ifstream fin(fileName);
    f.readFromFile(fin);
    f.changeSeatAndType(name, bP);
    ofstream fout(fileName);
    f.writeToFile(fout);
    fout.close();
    fin.close();
}

void airportInfo()
{
    cout << "Information About Tayyab International Airlines:" << endl;
    cout << "In Islamabad, Tayyab International Airlines operates a diverse range of flights, both " << endl
         << "nationally and internationally. The airline is known for its exceptional service and " << endl
         << "punctuality, catering to passengers traveling to various destinations within Pakistan " << endl
         << "and beyond. With its modern facilities and efficient operations, Tayyab International " << endl
         << "Airlines serves as a crucial hub for both domestic and international travel, providing " << endl
         << "passengers with a seamless and enjoyable experience throughout their journey." << endl;
}

/* End of Program*/