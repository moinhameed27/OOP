#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
T numberValidation(T &);

template <typename T>
void inputArray(T *, const int);

template <typename T>
void displayArray(T *, const int);

template <typename T>
void sumOfArrays(const T *, const T *, const int);

int main()
{
    int n;
    cout << "****Integer Arrays****" << endl;

    cout << "Enter the size of the integer arrays : ";
    numberValidation(n);
    int arr1[n], arr2[n];

    cout << "\nEnter Array 1 Elements:" << endl;
    inputArray(arr1, n);
    cout << "\nEnter Array 2 Elements:" << endl;
    inputArray(arr2, n);

    sumOfArrays(arr1, arr2, n);

    cout << "****Float Arrays****" << endl;

    cout << "\nEnter the size of the float arrays : ";
    numberValidation(n);
    float arr3[n], arr4[n];

    cout << "\nEnter Array 1 Elements:" << endl;
    inputArray(arr3, n);
    cout << "\nEnter Array 2 Elements:" << endl;
    inputArray(arr4, n);

    sumOfArrays(arr3, arr4, n);

    return 0;
}

template <typename T>
void inputArray(T *arr, const int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << '[' << i + 1 << "]: ";
        numberValidation(arr[i]);
    }
}

template <typename T>
void displayArray(T *arr, const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(5) << arr[i] << "  ";
    cout << endl;
}

// Sum of Arrays Function Template
template <typename T>
void sumOfArrays(const T *arr1, const T *arr2, const int n)
{
    T sum[n];
    for (int i = 0; i < n; i++)
        sum[i] = arr1[i] + arr2[i];

    cout << "\nArrays:" << endl;
    displayArray(arr1, n);
    displayArray(arr2, n);

    cout << "\nAddition:" << endl;
    displayArray(sum, n);
    cout << endl;
}

// Character Validation
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
