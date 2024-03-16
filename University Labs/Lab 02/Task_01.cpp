#include <iostream>
using namespace std;

int numberValidation(int &);


class Date
{
    int Day;
    int Month;
    int Year;

public:
    // Constructor
    Date()
    {
        Day = 0;
        Month = 0;
        Year = 0;
    }

    // Day
    void setDay(int x)
    {
        Day = x;
    }
    int getDay() const
    {
        return Day;
    }

    // Month
    void setMonth(int x)
    {
        Month = x;
    }
    int getMonth() const
    {
        return Month;
    }

    // Year
    void setYear(int x)
    {
        Year = x;
    }
    int getYear() const
    {
        return Year;
    }
    // Set all member variables
    void setDMY(int a, int b, int c)
    {
        Day = a;
        Month = b;
        Year = c;
    }

    // Displaying all details
    void displayDate() const
    {
        cout << Day << "/" << Month << "/" << Year << endl;
    }
};

int main()
{
    // Setting all the Given Dates
    Date arr[5];
    arr[0].setDMY(25, 12, 1876);
    arr[1].setDMY(9, 11, 1877);
    arr[2].setDMY(21, 4, 1938);
    arr[3].setDMY(14, 8, 1947);
    arr[4].setDMY(11, 9, 1948);

    // Displaying all deyails;
    arr[0].displayDate();
    arr[1].displayDate();
    arr[2].displayDate();
    arr[3].displayDate();
    arr[4].displayDate();

    // Dynamic Memory Allocation
    int size;
    cout << "Enter the size of the dynamic array" << endl;
    numberValidation(size);
    Date *ptr = new Date[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Date " << i + 1 << endl;
        cout <<  "==========================" << endl;
        int temp;
        cout << "Enter the Day (1-30)" << endl;
        numberValidation(temp);
        while (temp < 1 || temp > 30)
        {
            cout << "Invalid input. Enter again (1 - 30)" << endl;
            numberValidation(temp);
        }
        ptr[i].setDay(temp);
        cout << "Enter the Month (1-12)" << endl;
        numberValidation(temp);
        while (temp < 1 || temp > 12)
        {
            cout << "Invalid input. Enter again (1 - 12)" << endl;
            numberValidation(temp);
        }
        ptr[i].setMonth(temp);
        cout << "Enter the Year (4-Digit)" << endl;
        numberValidation(temp);
        while (temp < 1000 || temp > 9999)
        {
            cout << "Invalid input. Enter again (1000 - 9999)" << endl;
            numberValidation(temp);
        }
        ptr[i].setYear(temp);
    }

    for(int i = 0; i < size; i++){
        ptr[i].displayDate();
    }

    // Deallocation
    delete[] ptr;
    return 0;
}

// Input Validation
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

