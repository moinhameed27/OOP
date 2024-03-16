#include <iostream>
using namespace std;

class Car
{
    int yearModel;
    string make;
    int speed;

public:
    // Constructor
    Car()
    {
        yearModel = 0;
        make = "";
        speed = 0;
    }

    Car(int a, string b, int c){
        yearModel = a;
        make = b;
        speed = c;
    }

    // Year Model
    void setYearModel(int x)
    {
        yearModel = x;
    }
    int getYearModel() const
    {
        return yearModel;
    }

    // Make
    void setmake(string x)
    {
        make = x;
    }
    string getMake() const
    {
        return make;
    }

    // Speed
    void setSpeed(int x)
    {
        speed = x;
    }
    int getSpeed()  const
    {
        return speed;
    }


    void accelerate(){
        speed += 5;
    }

    void brake(){
        speed -= 5;
    }



    // Displaying all details
    void displayDetails() const
    {
        cout << "Year Model : " << yearModel << endl;
        cout << "Make : " << make << endl;
        cout << "Speed : " << speed << endl;
    }
};

int main()
{
    Car *ptr = new Car(1990, "Toyota", 120);


    cout << "Accelerate" << endl;
    cout << "===================" << endl;
    cout << "Speed : " << ptr->getSpeed() << endl;
    (*ptr).accelerate();
    cout << "Speed : " << ptr->getSpeed() << endl;
    ptr->accelerate();
    cout << "Speed : " << ptr->getSpeed() << endl;
    ptr->accelerate();
    cout << "Speed : " << ptr->getSpeed() << endl;
    ptr->accelerate();
    cout << "Speed : " << ptr->getSpeed() << endl;
    ptr->accelerate();
    cout << "Speed : " << ptr->getSpeed() << endl;

    cout << endl << "Brake" << endl;
    cout << "===================" << endl;
    
    cout << "Speed : " << ptr->getSpeed() << endl;
    ptr->brake();
    cout << "Speed : " << ptr->getSpeed() << endl;
    ptr->brake();
    cout << "Speed : " << ptr->getSpeed() << endl;
    ptr->brake();
    cout << "Speed : " << ptr->getSpeed() << endl;
    ptr->brake();
    cout << "Speed : " << ptr->getSpeed() << endl;
    ptr->brake();
    cout << "Speed : " << ptr->getSpeed() << endl;


    delete ptr;

    return 0;
}