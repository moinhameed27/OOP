#include <iostream>
using namespace std;
int DEFAULT_VALUES = -999;
int numberValidation(int &);

class IntArray
{
    int arraySize;
    int *aptr;

public:
    IntArray(int size)
    {
        arraySize = size;
        aptr = new int[size];
        for (size_t i = 0; i < arraySize; i++)
        {
            aptr[i] = 0;
        }
    }

    void setSize(int size)
    {
        arraySize = size;
    }

    int getSize() const
    {
        return arraySize;
    }

    // Copy Constructor
    IntArray(const IntArray &other)
    {
        arraySize = other.arraySize;
        aptr = new int[arraySize];
        for (size_t i = 0; i < arraySize; i++)
        {
            aptr[i] = other.aptr[i];
        }
    }

    void setArray(int *arr)
    {
        for (size_t i = 0; i < arraySize; i++)
        {
            aptr[i] = arr[i];
        }
    }

    // = Operator
    const IntArray &operator=(const IntArray &rhs)
    {
        // Self Assignment Case
        if (this == &rhs)
            return *this;

        arraySize = rhs.arraySize;
        if (aptr != nullptr)
        {
            delete[] aptr;
            aptr = nullptr;
        }

        aptr = new int[arraySize];
        for (size_t i = 0; i < arraySize; i++)
        {
            aptr[i] = rhs.aptr[i];
        }
        return *this;
    }

    int &operator[](int index) const
    {
        if (index >= arraySize)
            return DEFAULT_VALUES;
        else
            return aptr[index];
        // return aptr[index];
    }

    void display() const
    {
        for (size_t i = 0; i < arraySize; i++)
        {
            cout << aptr[i] << " ";
        }
        cout << endl;
    }

    IntArray operator+=(const IntArray &rhs)
    {
        int size = arraySize + rhs.arraySize;
        IntArray result(size);
        for (size_t i = 0; i < arraySize; i++)
        {
            result.aptr[i] = aptr[i];
        }
        for (size_t i = 0, j = arraySize; j < size; i++, j++)
        {
            result.aptr[j] = rhs.aptr[i];
        }
        return result;
    }
};

int main()
{
    int size1 = 4, size2 = 8;
    int arr1[size1] = {4, 5, 2, 1};
    int arr2[size2] = {6, 7, 8, 9, 3, 2, 6, 7};

    IntArray A(size1);
    A.setArray(arr1);
    cout << "A Array" << endl;
    A.display();

    // IntArray B(size2);
    // B.setArray(arr2);
    // cout << "B Array" << endl;
    // B.display();

    // IntArray C(A);
    // cout << "C Array" << endl;
    // C.display();

    // IntArray D;
    // D = B;
    // cout << "D Array" << endl;
    // D.display();

    // Subscript Operator
    cout << "Subscript Operator" << endl;
    cout << "A[2] : " << A[2] << " , A[7]" << A[7] << endl;

    // += Operator
    // cout << "+= Operator" << endl;
    // cout << "A += B" << endl;
    // IntArray E = A += B;
    // E.display();

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