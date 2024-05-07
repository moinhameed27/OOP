#include <iostream>
using namespace std;

template <typename T>
T numberValidation(T &);

class Employee
{
    string name;
    string ssn;
    double net_pay;

public:
    // Constructors
    Employee() : name(""), ssn(""), net_pay(0.0){};
    Employee(string the_name, string the_ssn) : name(the_name), ssn(the_ssn) {}

    // Getters
    string getName() const { return name; }
    string getSSN() const { return ssn; }
    double getNetPay() const { return net_pay; }

    // Setters
    void setName(string n) { name = n; }
    void setSSN(string s) { ssn = s; }
    void setNetPay(double nP) { net_pay = nP; }

    // Input Function
    void takeInput()
    {
        cout << "Enter name of the Employee : ";
        getline(cin, name);

        cout << "Enter ssn of the Employee : ";
        getline(cin, ssn);

        cout << "Enter net pay of the Employee : ";
        numberValidation(net_pay);
    }

    // Display
    void print_check() const
    {
        cout << "Name : " << name << endl;
        cout << "SSN : " << ssn << endl;
        cout << "Net Pay : " << net_pay << endl;
    }
};

class SalariedEmployee : public Employee
{
    double salary;

public:
    // Constructors
    SalariedEmployee() : salary(0.0) {}
    SalariedEmployee(string the_name, string the_ssn, double netPay, double the_week_salary) : Employee(the_name, the_ssn), salary(the_week_salary)
    {
        Employee::setNetPay(netPay);
    }

    // Getter
    double getSalary() const { return salary; }

    // Setter
    void setSalary(double new_salary) { salary = new_salary; }

    // Input Function
    void takeInput()
    {
        Employee::takeInput();
        cout << "Enter Weekly Salary of the Employee : ";
        numberValidation(salary);
    }

    // Print
    void print_check()
    {
        Employee::print_check();
        cout << "Weekly Salary : " << salary << endl;
    }
};

class Administrator : public SalariedEmployee
{
    string title;
    string AOR;
    string supervisor;

protected:
    double salary;

public:
    // Constructors
    Administrator() : title(""), AOR(""), supervisor("") {}
    Administrator(string name, string ssn, double pR, double wS) : SalariedEmployee(name, ssn, pR, wS) {}

    // Setter
    void set_supervisor(string s) { supervisor = s; }

    // Input Function
    void takeInput()
    {
        SalariedEmployee::takeInput();

        cout << "Enter the title : ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter the area of responsibility : ";
        getline(cin, AOR);
        cout << "Enter the name of supervisor : ";
        getline(cin, supervisor);
    }

    // Class Display
    void print()
    {
        cout << "Title : " << title << endl;
        cout << "Area of responsibility : " << AOR << endl;
        cout << "Name of supervisor : " << supervisor << endl;
        salary = SalariedEmployee::getSalary() * 48;
        cout << "Annual Salary : " << salary << endl;
    }

    // Inherited Display
    void print_check()
    {
        SalariedEmployee::print_check();
        print();
    }
};

int main()
{
    // Employee
    Employee E1;
    E1.takeInput();
    cout << endl;
    E1.print_check();
    cout << endl;

    // Salaried Employee
    SalariedEmployee S;
    cin.ignore();
    S.takeInput();
    cout << endl;
    S.print_check();
    cout << endl;

    // Administrator
    Administrator A;
    cin.ignore();
    A.takeInput();
    cout << endl;
    A.print_check();
    cout << endl;

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