#include <iostream>
#include <cstring>
using namespace std;

int numberValidation(int &);
double numberValidation(double &);

class Employee
{
    char name[50];
    int number;

public:
    // Default Constructor
    Employee() : number(0)
    {
        strcpy(name, "");
    }
    // Overloaded Constructor
    Employee(char *arr, int num) : number(num)
    {
        strcpy(name, arr);
    }

    // Copy Constructor
    Employee(const Employee &obj) : number(obj.number)
    {
        strcpy(name, obj.name);
    }

    // Setters
    void setName(char *arr) { strcpy(name, arr); }
    void setNumber(int num) { number = num; }

    // Getters
    const char *getName() const { return name; }
    int getNumber() const { return number; }

    // Display Function
    void display() const
    {
        cout << "Name : " << name << endl;
        cout << "Number : " << number << endl;
    }

    // Assignment Operator
    Employee &operator=(const Employee &other)
    {
        // Self-Assignment
        if (this == &other)
            return *this;

        number = other.number;
        strcpy(name, other.name);

        return *this;
    }
};

class ProductionWorker : public Employee
{
    int shift;
    double hourlyPayRate;

public:
    // Default Constructor
    ProductionWorker() : shift(0), hourlyPayRate(0.0) {}

    // Overloaded Constructor
    ProductionWorker(char *name, int number, int s, double pR) : Employee(name, number), shift(s), hourlyPayRate(pR) {}

    // Copy Constructor
    ProductionWorker(const ProductionWorker &obj) : Employee(obj)
    {
        shift = obj.shift;
        hourlyPayRate = obj.hourlyPayRate;
    }

    // Setters
    void setShift(int s) { shift = s; }
    void setPayRate(double p) { hourlyPayRate = p; }

    // Getters
    int getShift() const { return shift; }
    double getPayRate() const { return hourlyPayRate; }

    // Display Function
    void display() const
    {
        Employee::display();
        shift == 1 ? cout << "Shift : Day" << endl : cout << "Shift : Night" << endl;
        cout << "Hourly Pay Rate : " << hourlyPayRate << endl;
    }

    // Assignment Operator
    ProductionWorker &operator=(const ProductionWorker &other)
    {
        Employee::operator=(other);
        // Self-Assignment
        if (this == &other)
            return *this;

        shift = other.shift;
        hourlyPayRate = other.hourlyPayRate;
        return *this;
    }
};

class TeamLeader : public ProductionWorker
{
    double bonus;
    int requiredHours;
    int hoursAttended;

public:
    // Default Constructor
    TeamLeader() : bonus(0.0), requiredHours(0), hoursAttended(0) {}

    // Overloaded Constructor
    TeamLeader(char *name, int number, int shift, double pR, double b, int rH, int hA) : ProductionWorker(name, number, shift, pR)
    {
        bonus = b;
        requiredHours = rH;
        hoursAttended = hA;
    }

    // Copy Constructor
    TeamLeader(const TeamLeader &obj) : ProductionWorker(obj)
    {
        bonus = obj.bonus;
        requiredHours = obj.requiredHours;
        hoursAttended = obj.hoursAttended;
    }

    // Setters
    void setBonus(int b) { bonus = b; }
    void setRH(double RH) { requiredHours = RH; }
    void setHA(double HA) { hoursAttended = HA; }

    // Getters
    int getBonus() const { return bonus; }
    double getRH() const { return requiredHours; }
    double getHA() const { return hoursAttended; }

    // Display Function
    void display() const
    {
        ProductionWorker ::display();
        cout << "Monthly Bonus Amount : " << bonus << endl;
        cout << "Required Hours : " << requiredHours << endl;
        cout << "Hours Attended : " << hoursAttended << endl;
    }

    // Assignment Operator
    TeamLeader &operator=(const TeamLeader &other)
    {
        // Self-Assignment
        if (this == &other)
            return *this;

        ProductionWorker::operator=(other);

        bonus = other.bonus;
        requiredHours = other.requiredHours;
        hoursAttended = other.hoursAttended;

        return *this;
    }
};

int main()
{
    // Task - 3

    // Employee and Production Worker User Input (1) - Stack

    int number1;
    char name1[50];

    // Name
    cout << "Enter the name : ";
    cin.getline(name1, 50);

    // Number
    cout << "Enter the number : ";
    numberValidation(number1);
    cin.ignore();

    Employee E1(name1, number1);
    // E1.display();

    int shift1;
    double payRate1;

    // Shift
    cout << "Enter the shift - 1(Day), 2(Night) : ";
    numberValidation(shift1);
    while (shift1 != 1 && shift1 != 2)
    {
        cout << "Invalid Input. Enter only 1 or 2." << endl;
        cout << "Enter the shift - 1(Day), 2(Night) : ";
        numberValidation(shift1);
    }

    // Hourly Pay Rate
    cout << "Enter the Hourly Pay Rate : ";
    numberValidation(payRate1);
    cin.ignore();

    ProductionWorker P1(name1, number1, shift1, payRate1);

    // Employee and Production Worker User Input (2) - Heap

    int number2;
    char name2[50];

    // Name
    cout << endl << "Enter the name : ";
    cin.getline(name2, 50);

    // Number
    cout << "Enter the number : ";
    numberValidation(number2);
    cin.ignore();

    Employee *E2 = new Employee(name2, number2);
    // E2->display();

    int shift2;
    double payRate2;

    // Shift
    cout << "Enter the shift - 1(Day), 2(Night) : ";
    numberValidation(shift2);
    while (shift2 != 1 && shift2 != 2)
    {
        cout << "Invalid Input. Enter only 1 or 2." << endl;
        cout << "Enter the shift - 1(Day), 2(Night) : ";
        numberValidation(shift2);
    }

    // Hourly Pay Rate
    cout << "Enter the Hourly Pay Rate : ";
    numberValidation(payRate2);

    ProductionWorker *P2 = new ProductionWorker(name2, number2, shift2, payRate2);

    // Displaying All Details
    cout << endl;
    P1.display();
    cout << endl;
    P2->display();
    cout << endl;

    // Deallocation of Dynamically Allocated Objects
    delete E2;
    E2 = nullptr;

    delete P2;
    P2 = nullptr;

/*--------------------------------------------------------------------------------------------------------------------------------------*/

    // Task - 5

    int N;
    cout << "How many objects you want to create : ";
    numberValidation(N);
    cout << endl;

    // Creating 2D Array on Heap where one array is an array of pointers pointing to a single object
    TeamLeader **T = new TeamLeader *[N];

    // Taking input from the User
    for (int i = 0; i < N; i++)
    {
        int number;
        char name[50];

        cin.ignore();

        // Name
        cout << "Enter the name : ";
        cin.getline(name, 50);

        // Number
        cout << "Enter the number : ";
        numberValidation(number);
        cin.ignore();

        int shift;
        double payRate;

        // Shift
        cout << "Enter the shift - 1(Day), 2(Night) : ";
        numberValidation(shift);
        while (shift != 1 && shift != 2)
        {
            cout << "Invalid Input. Enter only 1 or 2." << endl;
            cout << "Enter the shift - 1(Day), 2(Night) : ";
            numberValidation(shift);
        }

        // Hourly Pay Rate
        cout << "Enter the Hourly Pay Rate : ";
        numberValidation(payRate);
        cin.ignore();

        // Bonus
        double bonus;
        cout << "Enter Monthly Bonus Amount : ";
        numberValidation(bonus);

        // Required Hours
        int rH;
        cout << "Enter Required Hours : ";
        numberValidation(rH);

        // Hours Attended
        int hA;
        cout << "Enter Hours Attended : ";
        numberValidation(hA);

        while (hA > rH)
        {
            cout << "Hours attended cannot be greater than Required hours" << endl;
            cout << "Enter Hours Attended : ";
            numberValidation(hA);
        }

        // Creating an object on each Pointer Array with Overloaded Constructor
        T[i] = new TeamLeader(name, number, shift, payRate, bonus, rH, hA);

        cout << endl;
    }

    // Displaying details of all Team Leaders
    for (int i = 0; i < N; i++)
    {
        T[i]->display();
        cout << endl;
    }

    // Deallocation of Array
    for (int i = 0; i < N; i++)
    {
        delete[] T[i];
        T[i] = nullptr;
    }

    delete[] T;
    T = nullptr;

    return 0;
}

// Character Validation(integer)
int numberValidation(int &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number < 0)
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

// Character Validation(double)
double numberValidation(double &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number < 0)
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