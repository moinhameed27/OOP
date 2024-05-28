#include <iostream>
#include <iomanip>
using namespace std;

template <typename T>
T numberValidation(T &);

template <typename T>
void deallocateMatrix(T **, const int);

template <typename T>
T **allocateMatrix(const int);

template <typename T>
void inputMatrix(T **, const int);

template <typename T>
void displayMatrix(T **, const int);

template <typename T1, typename T2>
void addMatrix(const T1 *const *, const T2 *const *, const int);

template <typename T1, typename T2>
void subtractMatrix(const T1 *const *, const T2 *const *, const int);

template <typename T1, typename T2>
void multiplyMatrix(const T1 *const *, const T2 *const *, const int);

int main()
{
    cout << "****Different Data Types****" << endl;
    int n;
    cout << "Enter the size of the square matrices: ";
    numberValidation(n);

    float **Matrix1 = allocateMatrix<float>(n);
    int **Matrix2 = allocateMatrix<int>(n);

    cout << "Enter elements of the Float matrix:" << endl;
    inputMatrix(Matrix1, n);
    cout << "Enter elements of the Integer matrix:" << endl;
    inputMatrix(Matrix2, n);

    cout << "\nMatrix 1:" << endl;
    displayMatrix(Matrix1, n);
    cout << "Matrix 2:" << endl;
    displayMatrix(Matrix2, n);

    cout << endl;
    addMatrix<float, int>(Matrix1, Matrix2, n);
    cout << endl;
    subtractMatrix<float, int>(Matrix1, Matrix2, n);
    cout << endl;
    multiplyMatrix<float, int>(Matrix1, Matrix2, n);

    deallocateMatrix(Matrix1, n);
    deallocateMatrix(Matrix2, n);

    cout << "****Same Data Types****" << endl;
    cout << "Enter the size of the square matrices: ";
    numberValidation(n);

    int **Matrix3 = allocateMatrix<int>(n);
    int **Matrix4 = allocateMatrix<int>(n);

    cout << "Enter elements of the First matrix:" << endl;
    inputMatrix(Matrix3, n);
    cout << "Enter elements of the Second matrix:" << endl;
    inputMatrix(Matrix4, n);

    cout << "\nMatrix 1:" << endl;
    displayMatrix(Matrix3, n);
    cout << "Matrix 2:" << endl;
    displayMatrix(Matrix4, n);

    cout << endl;
    addMatrix<int, int>(Matrix3, Matrix4, n);
    cout << endl;
    subtractMatrix<int, int>(Matrix3, Matrix4, n);
    cout << endl;
    multiplyMatrix<int, int>(Matrix3, Matrix4, n);

    deallocateMatrix(Matrix3, n);
    deallocateMatrix(Matrix4, n);

    return 0;
}

template <typename T>
T **allocateMatrix(const int n)
{
    T **matrix = new T *[n];
    for (int i = 0; i < n; ++i)
    {
        matrix[i] = new T[n];
    }
    return matrix;
}

template <typename T>
void deallocateMatrix(T **matrix, const int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template <typename T>
void inputMatrix(T **matrix, const int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << "[" << i << "][" << j << "]: ";
            numberValidation(matrix[i][j]);
        }
    }
}

template <typename T>
void displayMatrix(T **matrix, const int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << setw(5) << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T1, typename T2>
void addMatrix(const T1 *const *Matrix1, const T2 *const *Matrix2, const int n)
{
    T1 **resultant = allocateMatrix<T1>(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            resultant[i][j] = Matrix1[i][j] + Matrix2[i][j];
        }
    }

    cout << "Resultant Matrix after Addition:" << endl;
    displayMatrix(resultant, n);
    deallocateMatrix(resultant, n);
}

template <typename T1, typename T2>
void subtractMatrix(const T1 *const *Matrix1, const T2 *const *Matrix2, const int n)
{
    T1 **resultant = allocateMatrix<T1>(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            resultant[i][j] = Matrix1[i][j] - Matrix2[i][j];
        }
    }

    cout << "Resultant Matrix after Subtraction:" << endl;
    displayMatrix(resultant, n);

    deallocateMatrix(resultant, n);
}

template <typename T1, typename T2>
void multiplyMatrix(const T1 *const *Matrix1, const T2 *const *Matrix2, const int n)
{
    T1 **resultant = allocateMatrix<T1>(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            resultant[i][j] = 0;
            for (int k = 0; k < n; ++k)
            {
                resultant[i][j] += Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }

    cout << "Resultant Matrix after Multiplication:" << endl;

    displayMatrix(resultant, n);
    deallocateMatrix(resultant, n);
}

// Number Validation
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
                cout << "Enter a positive number: ";
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
            cout << "Invalid input. Please enter a valid number: ";
        }
    }
    return number;
}
