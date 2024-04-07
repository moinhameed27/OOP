#include <iostream>
using namespace std;

int integerValidation(int &);

class Rectangle;
class Square
{
    int side;
public:
    friend class Rectangle;
};

class Rectangle
{
    int height;
    int width;
public:
    Square sq;
    void setHWS(int a, int b, int c)
    {
        height = a;
        width = b;
        sq.side = c;
    }
    void display()
    {
        cout << "Height : " << height << endl;
        cout << "Width : " << width << endl;
    }
    void area()
    {
        cout << "Rectangle area : " << height* width << endl;
        cout << "Sqaure area : " << sq.side* sq.side << endl;
    }

};

int main()
{
    Rectangle r;
    r.setHWS(3,4,5);
    r.area();
    
return 0;
}


// Input Validation
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

