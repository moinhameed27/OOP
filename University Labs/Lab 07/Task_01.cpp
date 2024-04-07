#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int integerValidation(int &);

class ObjectTracker
{
    static int var;

public:
    ObjectTracker()
    {
        var++;
    }
    static void display()
    {
        cout << "Var : " << var << endl;
    }

    ~ObjectTracker()
    {
        var--;
    }
};

int ObjectTracker::var;

int main()
{

    srand(time(NULL));
    int size = rand() % 20 + 1;
    cout << "Size : " << size << endl;
    ObjectTracker **arr = new ObjectTracker *[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = new ObjectTracker;
    }
    cout << "After Creation of Array" << endl;
    ObjectTracker::display();

    // for (size_t i = 0; i < size; i++)
    // {
    //     delete arr[i];
    // }
    int userOption;
    cout << "Enter which index to delete : " << endl;
    integerValidation(userOption);
    while (userOption > size)
    {
        cout << "Wrong command entered. Enter again : " << endl;
        cout << "Enter which index to delete : " << endl;
        integerValidation(userOption);
    }
    delete arr[userOption];
    // delete []arr;
    arr = nullptr;
    cout << "After Deletion of Object" << endl;
    ObjectTracker::display();

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