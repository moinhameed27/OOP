#include <iostream>
// #include <Yasir Bhaii THe Debugger>
using namespace std;

int numberValidation(int &);

class IntArray
{
    int *arr;
    int size;

public:
    // Default Constructor
    IntArray()
    {
        size = 0;
        arr = nullptr;
    }

    // Overloaded Constructor
    IntArray(int s)
    {
        size = s;
        arr = new int[size];
    }

    // Copy Constructor
    IntArray(const IntArray &orig)
    {
        size = orig.size;
        arr = new int[size];
        for (int i = 0; i < size; i++)
        {
            arr[i] = orig.arr[i];
        }
    }

    // Size setter
    void setSize(int s)
    {
        size = s;
    }

    // Size getter
    int getSize() const
    {
        return size;
    }

    // Array Index Setter
    void setIndex(int index, int value)
    {
        arr[index] = value;
    }

    // Array Index Getter
    int getIndex(int index) const
    {
        return arr[index];
    }

    // Input Values for the Array
    void inputValues()
    {
        cout << "-----------Array Input-----------" << endl;
        int s;
        cout << "Enter the size of the array : ";
        numberValidation(s);
        setSize(s);
        delete[] arr;
        arr = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            numberValidation(arr[i]);
        }
    }

    // Display Function
    void display() const
    {
        // cout << "Array Display" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Add Arrays
    IntArray addArrays(const IntArray obj) const
    {
        if (size != obj.size)
        {
            cout << "Sizes are not same, so arrays cannot be added" << endl;
            return IntArray(0);
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] += obj.arr[i];
            }
        }
        return *this;
    }

    // Subtract Arrays
    IntArray subArrays(const IntArray obj) const
    {
        if (size != obj.size)
        {
            cout << "Sizes are not same, so arrays cannot be subtracted" << endl;
            return IntArray(0);
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] -= obj.arr[i];
            }
        }
        return *this;
    }

    // Multiply Arrays
    IntArray mulArrays(const IntArray obj) const
    {
        if (size != obj.size)
        {
            cout << "Sizes are not same, so arrays cannot be multiplied" << endl;
            return IntArray(0);
        }
        else
        {
            for (int i = 0; i < size; i++)
            {
                arr[i] *= obj.arr[i];
            }
        }
        return *this;
    }

    // Palindrome Check
    bool palindrome()
    {
        IntArray temp(size);
        int j = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            temp.arr[j] = arr[i];
            j++;
        }

        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] != temp.arr[i])
                return false;
        }

        return true;
    }

    // Inverse of the Array
    IntArray reverse()
    {
        IntArray temp(size);
        int j = 0;
        for (int i = size - 1; i >= 0; i--)
        {
            temp.arr[j] = arr[i];
            j++;
        }
        return temp;
    }

    IntArray cyclicRotate(int n)
    {
        if (n == size)
            return *this;
        n %= size;

        IntArray temp(size);
        int j = 0;
        for (size_t i = n + 1; i < size; i++)
        {
            temp.arr[j] = arr[i];
            j++;
        }

        int k = 0;
        for (size_t i = j; i < size; i++)
        {
            temp.arr[i] = arr[k];
            k++;
        }

        return temp;
    }

    // Destructor
    ~IntArray()
    {
        if (arr != nullptr)
        {
            delete[] arr;
            arr = nullptr;
        }
    }
};

int main()
{

    IntArray a1;
    a1.inputValues();

    int userOption;
    do
    {
        cout << "-----------IntArray Menu-----------" << endl;
        cout << "1. Input Array(Over-write previous array)" << endl;
        cout << "2. Display Array" << endl;
        cout << "3. Add Array" << endl;
        cout << "4. Subtract Array" << endl;
        cout << "5. Multiply Array" << endl;
        cout << "6. Check Palindrome" << endl;
        cout << "7. Reverse Array" << endl;
        cout << "8. Cyclic Rotation in Array" << endl;
        cout << "9. Exit" << endl;
        cout << "----------------------------" << endl;
        cout << "Select any option : ";
        numberValidation(userOption);

        switch (userOption)
        {
        case 1:
            a1.inputValues();
            break;
        case 2:
            a1.display();
            break;
        case 3:
        {
            IntArray a2;
            cout << "-----------Add Arrays-----------" << endl;
            a2.inputValues();
            cout << "First Array" << endl;
            a1.display();
            cout << "Second Array" << endl;
            a2.display();
            a1.addArrays(a2);
            cout << "Added Array" << endl;
            a1.display();
        }
        break;
        case 4:
        {
            IntArray a3;
            cout << "-----------Subtract Arrays-----------" << endl;
            a3.inputValues();
            cout << "First Array" << endl;
            a1.display();
            cout << "Second Array" << endl;
            a3.display();
            a1.subArrays(a3);
            cout << "Subtracted Array" << endl;
            a1.display();
        }
        break;
        case 5:
        {
            IntArray a3;
            cout << "-----------Multiply Arrays-----------" << endl;
            a3.inputValues();
            cout << "First Array" << endl;
            a1.display();
            cout << "Second Array" << endl;
            a3.display();
            a1.mulArrays(a3);
            cout << "Multiplied Array" << endl;
            a1.display();
        }
        break;

        case 6:
        {
            cout << "-----------Check Palindrome-----------" << endl;
            a1.display();
            int flag;
            flag = a1.palindrome();
            if (flag)
                cout << "Palindrome" << endl;
            else
                cout << "Not a Palindrome" << endl;
        }
        break;
        case 7:
        {
            cout << "-----------Reverse Arrays-----------" << endl;
            cout << "Original Array" << endl;
            a1.display();
            cout << "Reversed Array" << endl;
            IntArray a4 = a1.reverse();
            a4.display();
        }
        break;
        case 8:
        {
            cout << "-----------Rotation of Array-----------" << endl;
            int n;
            cout << "Enter the number of times you want to rotate" << endl;
            numberValidation(n);
            cout << "Original Array" << endl;
            a1.display();
            cout << "Rotated Array" << endl;
            IntArray a6(a1.cyclicRotate(n));
            a6.display();
        }
        break;
        case 9:
            cout << "-----------Exit-----------" << endl;
            break;

        default:
            cout << "Wrong Command Given. Enter 1 - 9" << endl;
            break;
        }
    } while (userOption != 9);

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