#include <iostream>
using namespace std;

template <typename T>
T numberValidation(T &);

class Ship
{
    string name;
    string year;

public:
    // Constructors
    Ship() : name(""), year("") {}
    Ship(string n, string y) : name(n), year(y) {}

    // Setters
    void setName(string n) { name = n; }
    void setYear(string y) { year = y; }

    // Getters
    string getName() { return name; }
    string getYear() { return year; }

    // Print
    virtual void print()
    {
        cout << "Name : " << name << endl;
        cout << "Year : " << year << endl;
    }
};

class CruiseShip : public Ship
{
    int noOfPassengers;

public:
    // Constructors
    CruiseShip() : noOfPassengers(0), Ship() {}
    CruiseShip(string n, string y, int no) : noOfPassengers(no), Ship(n, y) {}

    // Setter
    void setnoOfPassengers(int n) { noOfPassengers = n; }

    // Getter
    int getNoOfPassengers() { return noOfPassengers; }

    // Print
    void print() override
    {
        cout << "Name : " << Ship::getName() << endl;
        cout << "Number of Passengers : " << noOfPassengers << endl;
    }
};

class CargoShip : public Ship
{
    int capacity;

public:
    // Constructors
    CargoShip() : capacity(0), Ship() {}
    CargoShip(string n, string y, int c) : capacity(c), Ship(n, y) {}

    // Setter
    void setCapacity(int c) { capacity = c; }

    // Getter
    int getCapacity() { return capacity; }

    // Print
    void print() override
    {
        cout << "Name : " << Ship::getName() << endl;
        cout << "Cargo Capacity : " << capacity << endl;
    }
};

class BattleShip : public Ship
{
    int missiles;

public:
    // Constructors
    BattleShip() : missiles(0), Ship() {}
    BattleShip(string n, string y, int m) : missiles(m), Ship(n, y) {}

    // Setter
    void setmissiles(int m) { missiles = m; }

    // Getter
    int getmissiles() { return missiles; }

    // Print
    void print()
    {
        cout << "Name : " << Ship::getName() << endl;
        cout << "Missiles capacity : " << missiles << endl;
    }
};

int main()
{
    int N;
    cout << "Enter number of objects you want to create : ";
    numberValidation(N);
    Ship *ptr[N];
    for (size_t i = 0; i < N; i++)
    {
        int choice;
        cout << "Which Ship you want to create:" << endl;
        cout << "1. Cruise Ship" << endl;
        cout << "2. Cargo Ship" << endl;
        cout << "3. Battle Ship" << endl;
        numberValidation(choice);
        while (choice < 1 || choice > 3)
        {
            cout << "Wrong Input. Enter again." << endl;
            cout << "Which Ship you want to create:" << endl;
            cout << "1. Cruise Ship" << endl;
            cout << "2. Cargo Ship" << endl;
            cout << "3. Battle Ship" << endl;
            numberValidation(choice);
        }
        string name, year;
        cout << "Enter name of Ship : ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter year of Ship : ";
        getline(cin, year);
        if (choice == 1)
        {
            int passengers;
            cout << "Enter max number of passengers : ";
            numberValidation(passengers);
            ptr[i] = new CruiseShip(name, year, passengers);
        }
        else if (choice == 2)
        {
            int capacity;
            cout << "Enter capacity in tonnage : ";
            numberValidation(capacity);
            ptr[i] = new CargoShip(name, year, capacity);
        }
        else
        {
            int missiles;
            cout << "Enter number of missiles : ";
            numberValidation(missiles);
            ptr[i] = new BattleShip(name, year, missiles);
        }
    }

    for (size_t i = 0; i < N; i++)
    {
        cout << endl;
        ptr[i]->print();
        delete ptr[i];
        ptr[i] = nullptr;
    }

    delete[] *ptr;
    *ptr = nullptr;

    return 0;
}

// Input Validation
template <typename T>
T numberValidation(T &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number <= 0)
            {
                cout << "Enter positive number: " << endl;
            }
            else
            {
                validInput = true;
            }
        }
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
    return number;
}