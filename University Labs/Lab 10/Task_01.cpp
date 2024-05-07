#include <iostream>
using namespace std;

template <typename T>
T numberValidation(T &);

const string months[12] = {"January", "Febraury", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

class Date
{
    int day;
    int month;
    int year;

public:
    // Constructor
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Getters
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Display Function
    void print() const
    {
        cout << day << "/" << month << "/" << year << " ";
    }
};

class Time
{
    int hour;
    int min;
    int sec;

public:
    // Constructor
    Time(int d, int m, int y) : hour(d), min(m), sec(y) {}

    // Getters
    int getHour() const { return hour; }
    int getMin() const { return min; }
    int getSec() const { return sec; }

    // Display Function
    void print() const
    {
        cout << hour << ":" << min << ":" << sec << endl;
    }
};

class DateTime : public Date, public Time
{
public:
    // Constructor
    DateTime(int d, int m, int y, int h, int mn, int sc) : Date(d, m, y), Time(h, mn, sc) {}

    // Display Function
    void printDateTime() const
    {
        Date::print();
        Time::print();
    }
    // Formatted Display
    void showFormatedDayTime() const
    {
        int d = getDay();
        int m = getMonth();
        int y = getYear();
        cout << months[m - 1] << " " << d << ", " << y << " ";
        Time::print();
    }
};

int main()
{
    int date, month, year;
    int hour, min, sec;

    cout << "Enter the Day (1-30) : ";
    numberValidation(date);
    while (date < 1 || date > 30)
    {
        cout << "Invalid input. Enter again (1 - 30)" << endl;
        numberValidation(date);
    }

    cout << "Enter the Month (1-12) : ";
    numberValidation(month);
    while (month < 1 || month > 12)
    {
        cout << "Invalid input. Enter again (1 - 12)" << endl;
        numberValidation(month);
    }

    cout << "Enter the Year (4-Digit) : ";
    numberValidation(year);
    while (year < 1000 || year > 9999)
    {
        cout << "Invalid input. Enter again (1000 - 9999)" << endl;
        numberValidation(year);
    }

    cout << "Enter the hour(1 - 24) : ";
    numberValidation(hour);
    while (hour < 1 || hour > 24)
    {
        cout << "Invalid input. Enter again (1 - 24)" << endl;
        cout << "Enter the hour : ";
        numberValidation(hour);
    }

    cout << "Enter the hour(1 - 60) : ";
    numberValidation(min);
    while (min < 1 || min > 60)
    {
        cout << "Invalid input. Enter again (1 - 60)" << endl;
        cout << "Enter the min : ";
        numberValidation(min);
    }

    cout << "Enter the sec(1 - 60) : ";
    numberValidation(sec);
    while (sec < 1 || sec > 60)
    {
        cout << "Invalid input. Enter again (1 - 60)" << endl;
        cout << "Enter the sec : ";
        numberValidation(sec);
    }

    DateTime DT(date, month, year, hour, min, sec);
    cout << endl;
    DT.printDateTime();
    cout << endl;
    DT.showFormatedDayTime();

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