#include <iostream>
using namespace std;

// Input Validation
double numberValidation(double &);

// Class Circle
class Circle
{
    double radius;
    double pi = 3.14159;

public:
    // Default Constructor
    Circle()
    {
        radius = 0;
    }
    // Overloaded Constructor
    Circle(int a)
    {
        radius = a;
    }

    // radius
    void setradius(double x)
    {
        radius = x;
    }
    double getradius() const
    {
        return radius;
    }

    // Area Member Function
    double getArea() const
    {
        double area;
        area = pi * radius * radius;
        return area;
    }

    // Diameter
    double getDiameter() const
    {
        double diameter;
        diameter = radius * 2;
        return diameter;
    }

    // Circumference
    double getCircumference() const
    {
        double circumference;
        circumference = 2 * pi * radius;
        return circumference;
    }

    // Displaying Area, Diameter, Circumferene
    void displayADC() const
    {
        cout << "Radius : " << radius << endl;
        cout << "Area : " << getArea() << endl;
        cout << "Diameter : " << getDiameter() << endl;
        cout << "Circumference : " << getCircumference() << endl;
    }
};

int main()
{
    double radius;
    cout << "Enter the radius : " << endl;
    numberValidation(radius);
    Circle c1(radius);
    // c1.setradius(radius);
    c1.displayADC();

    return 0;
}

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