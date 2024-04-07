/*
Composer : Muhammad Moin U Din
Naming Convention : camelCase
Description : Validation header file having a input validation check.
*/

#ifndef VALIDATION_H
#define VALIDATION_H
#include <iostream>
using namespace std;

// Input Validation for character type input and numbers less than zero
int integerValidation(int &number)
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

#endif