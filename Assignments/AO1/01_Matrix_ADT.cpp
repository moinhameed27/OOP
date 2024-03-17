/*
Composer : Muhammad Moin U Din
Naming Convention : camelCase
Description : Matrix Abstract Data Type with multiple operations which can be performed on matrices.
*/

#include <iostream>
using namespace std;

int inputValidation(int &);
int inputValidationNums(int &);

class Matrix
{
private:
    int rows;
    int cols;
    int **data;

public:
    // Constructor
    Matrix(int r = 2, int c = 2)
    {
        rows = r;
        cols = c;
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
        }
    }

    // Copy Constructor
    Matrix(const Matrix &rhs)
    {
        rows = rhs.rows;
        cols = rhs.cols;
        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = rhs.data[i][j];
            }
        }
    }

    // Assignment Operator(This function was needed in my Code)
    Matrix &operator=(const Matrix &rhs)
    {
        // In case of Self-Assignment
        if (this == &rhs)
        {
            return *this;
        }

        // Deallocate existing data
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;

        rows = rhs.rows;
        cols = rhs.cols;

        data = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = rhs.data[i][j];
            }
        }
        return *this;
    }

    // Rows Mutator
    void setRows(int r)
    {
        rows = r;
    }

    // Rows Accessor
    int getRows()
    {
        return rows;
    }

    // Columns Mutator
    void setCols(int c)
    {
        cols = c;
    }

    // Columns Accessor
    int getCols()
    {
        return cols;
    }

    // Input Values : Taking values from the user
    void inputValues()
    {

        cout << "MATRIX INPUT" << endl;
        int r, c;
        cout << "Enter the number of rows : ";
        inputValidation(r);
        cout << "Enter the number of columns : ";
        inputValidation(c);

        if (r != rows || c != cols)
        {
            for (int i = 0; i < rows; i++)
            {
                delete[] data[i];
            }
            delete[] data;

            data = new int *[r];
            for (int i = 0; i < r; i++)
            {
                data[i] = new int[c];
            }
        }

        setRows(r);
        setCols(c);
        cout << "Matrix " << rows << " X " << cols << endl;
        cout << "Enter the elements one by one" << endl;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << "[" << i + 1 << "," << j + 1 << "] : ";
                inputValidationNums(data[i][j]);
            }
        }
    }

    // Setting Values of calling object same as receiving in parameter
    void setValues(const Matrix &mat)
    {

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = mat.data[i][j];
            }
        }
    }

    // Get Value : Returns the value at particular row and column
    int getValue(int r, int c)
    {
        return data[r - 1][c - 1];
    }

    // Set Value : Sets the value at particular row and column
    void setValue(int r, int c, int value)
    {

        data[r - 1][c - 1] = value;
    }

    // Show : Display the whole matrix
    void show()
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Transpose of a Matrix
    Matrix transpose()
    {
        Matrix transMatrix(cols, rows);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                transMatrix.data[j][i] = data[i][j];
            }
        }

        return transMatrix;
    }

    // Add Scalar : Adding a scalar to all elements of the matrix
    void addScalar(int scalar)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] += scalar;
            }
        }
    }

    // Add Matrix : Add a matrix to another matrix
    void addMatrix(const Matrix &other)
    {
        if (rows == other.rows && cols == other.cols)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    data[i][j] += other.data[i][j];
                }
            }
        }
        else
        {
            cout << "Matrices don't have same dimensions. Can't be Added." << endl;
        }
    }

    // Subtract Scalar : Subtract a number from all the elements of the matrix
    void subtractScalar(int scalar)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] -= scalar;
            }
        }
    }

    // Subtract Matrix : Subtract a matrix from another matrix
    void subtractMatrix(const Matrix &other)
    {
        if (rows == other.rows && cols == other.cols)
        {
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    data[i][j] -= other.data[i][j];
                }
            }
        }
        else
        {
            cout << "Matrices don't have same dimensions. Can't be Subtracted" << endl;
        }
    }

    // Multiply Scalar : Multiply a number with all the elements of the matrix
    void multiplyScalar(int scalar)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                data[i][j] *= scalar;
            }
        }
    }

    // Multiply Matrix : Multiply a matrix with another matrix
    Matrix multiplyMatrix(const Matrix &mat)
    {

        Matrix result(rows, mat.cols);

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < mat.cols; ++j)
            {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; ++k)
                {
                    result.data[i][j] += data[i][k] * mat.data[k][j];
                }
            }
        }
        return result;
    }

    // Determinant : Calculate the determinant of 2X2 and 3X3 matrix using math rules
    double determinant()
    {
        if (rows == cols && rows <= 3)
        {
            double determinant;
            if (rows == 2)
            {
                double a = data[0][0], b = data[0][1], c = data[1][0], d = data[1][1];
                determinant = (a * d) - (b * c);
            }
            else
            {
                double a = data[0][0], b = data[0][1], c = data[0][2],
                       d = data[1][0], e = data[1][1], f = data[1][2],
                       g = data[2][0], h = data[2][1], i = data[2][2];

                determinant = a * ((e * i) - (f * h)) - b * ((d * i) - (f * g)) + c * ((d * h) - (e * g));
            }
            return determinant;
        }
        else if (rows == cols && rows > 3)
        {
            cout << "As of now, Determinant of Matrices with dimensions 2X2 and 3X3 are calculated" << endl;
            return 0;
        }
        else
        {
            cout << "Invalid. Determinant can only be calculated for Square matrices" << endl;
            return 0;
        }
    }

    // Adjoint : Calculating the adjoint of the matrix
    Matrix adjoint()
    {
        if (rows == cols && rows == 2)
        {
            Matrix adjMatrix(2, 2);
            adjMatrix.data[0][0] = data[1][1];
            adjMatrix.data[0][1] = -data[0][1];
            adjMatrix.data[1][0] = -data[1][0];
            adjMatrix.data[1][1] = data[0][0];
            return adjMatrix;
        }
        else if (rows == cols && rows > 2)
        {
            cout << "As of now, Adjoint of Matrices with dimensions 2X2 is calculated" << endl;
            return Matrix(0, 0);
        }
        else
        {
            cout << "Invalid. Adjoint can only be calculated for Square matrices" << endl;
            return Matrix(0, 0);
        }
    }

    // Inverse : Calculating the inverse of a 2X2 matrix
    Matrix inverse()
    {
        if (rows == cols && rows == 2)
        {
            Matrix result = *this;
            double determinant = result.determinant();

            result = result.adjoint();
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    result.data[i][j] /= determinant;
                }
            }
            return result;
        }

        else if (rows == cols && rows > 2)
        {
            cout << "As of now, Inverse of Matrices with dimensions 2X2 is calculated" << endl;
            return Matrix(0, 0);
        }
        else
        {
            cout << "Invalid. Inverse can only be calculated for Square matrices" << endl;
            return Matrix(0, 0);
        }
    }

    // Symmetric Matrix : Check if a matrix is equal to its transpose or not
    bool isSymmetric()
    {
        if (rows != cols)
        {
            cout << "Only sqaure matrices can be symmetric" << endl;
            return false;
        }

        Matrix transposeMat = *this;
        transposeMat = transposeMat.transpose();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (data[i][j] != transposeMat.data[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    // Destructor
    ~Matrix()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] data[i];
        }
        delete[] data;
    }
};

int main()
{
    cout << "--------Matrix ADT--------" << endl;
    Matrix m1;
    m1.inputValues();
    int userOption;
    double det = 0.0;
    bool symmetric = false;
    do
    {
        cout << "--------Matrix Operations Menu--------" << endl;
        cout << "1. Input Values(Over-write previous entered Values)" << endl;
        cout << "2. Set Values" << endl;
        cout << "3. Get Value" << endl;
        cout << "4. Set Value" << endl;
        cout << "5. Display Matrix" << endl;
        cout << "6. Transpose" << endl;
        cout << "7. Add Scalar to Matrix" << endl;
        cout << "8. Add Matrix to other Matrix" << endl;
        cout << "9. Subtract Scalar from Matrix" << endl;
        cout << "10. Subtract Matrix from another Matrix" << endl;
        cout << "11. Multiply Scalar with Matrix" << endl;
        cout << "12. Mulitply Matrix with another Matrix" << endl;
        cout << "13. Determinant of the Matrix" << endl;
        cout << "14. Adjoint of Matrix" << endl;
        cout << "15. Inverse of Matrix" << endl;
        cout << "16. Check if Matrix is Symmetrix" << endl;
        cout << "17. Exit" << endl;
        cout << "------------------------------------" << endl;
        cout << "Select any option : ";
        inputValidation(userOption);
        switch (userOption)
        {
        case 1:
            m1.inputValues();
            break;

        case 2:
        {
            cout << "---------Set Values---------" << endl;
            Matrix m2;
            cout << "Second Matrix" << endl;
            m2.inputValues();
            cout << "Original Matrix" << endl;
            m1.show();
            if (m1.getRows() != m2.getRows() && m1.getCols() != m2.getCols())
                cout << "Matrices must have same dimensions for setting values" << endl;
            else
            {
                m1.setValues(m2);
                cout << "New Matrix" << endl;
                m1.show();
            }
        }
        break;

        case 3:
            cout << "---------Get Value---------" << endl;
            int r1, c1;
            cout << "Enter the Row number : ";
            inputValidation(r1);
            cout << "Enter the Column number : ";
            inputValidation(c1);
            if (r1 > m1.getRows() || c1 > m1.getCols())
            {
                cout << "Invalid row and column. Current Matrix is " << m1.getRows() << "X" << m1.getCols() << endl;
            }
            else
                cout << "Value at [" << r1 << "," << c1 << "] is " << m1.getValue(r1, c1) << endl;
            break;

        case 4:
            cout << "---------Set Value---------" << endl;
            int r2, c2, value;
            cout << "Enter the Row number : ";
            inputValidation(r2);
            cout << "Enter the Column number : ";
            inputValidation(c2);
            if (r2 > m1.getRows() || c2 > m1.getCols())
            {
                cout << "Invalid row and column. Current Matrix is " << m1.getRows() << "X" << m1.getCols() << endl;
            }
            else
            {
                cout << "Value at [" << r2 << "," << c2 << "] is " << m1.getValue(r2, c2) << endl;
                cout << "Enter the value you want to set : ";
                inputValidation(value);
                cout << "Original Matrix" << endl;
                m1.show();
                m1.setValue(r2, c2, value);
                cout << "New Matrix" << endl;
                m1.show();
            }
            break;

        case 5:
            cout << "---------Display Matrix---------" << endl;
            m1.show();
            break;

        case 6:
            cout << "---------Transpose---------" << endl;
            cout << "Original Matrix" << endl;
            m1.show();
            m1 = m1.transpose();
            cout << "Transpose Matrix" << endl;
            m1.show();
            break;

        case 7:
            cout << "---------Add Scalar---------" << endl;
            int scalar1;
            cout << "Enter the Scalar value : " << endl;
            inputValidation(scalar1);
            cout << "Original Matrix" << endl;
            m1.show();
            m1.addScalar(scalar1);
            cout << "New Matrix" << endl;
            m1.show();
            break;

        case 8:
        {
            cout << "---------Add Matrix---------" << endl;
            Matrix m3;
            cout << "Second Matrix" << endl;
            m3.inputValues();
            cout << "First Matrix" << endl;
            m1.show();
            cout << "Second Matrix" << endl;
            m3.show();
            m1.addMatrix(m3);
            cout << "Resultant Matrix" << endl;
            m1.show();
        }
        break;

        case 9:
            cout << "---------Subtract Scalar---------" << endl;
            int scalar2;
            cout << "Enter the Scalar value : " << endl;
            inputValidation(scalar2);
            cout << "Original Matrix" << endl;
            m1.show();
            m1.subtractScalar(scalar2);
            cout << "New Matrix" << endl;
            m1.show();
            break;

        case 10:
        {
            cout << "---------Subtract Matrix---------" << endl;
            Matrix m4;
            cout << "Second Matrix" << endl;
            m4.inputValues();
            cout << "First Matrix" << endl;
            m1.show();
            cout << "Second Matrix" << endl;
            m4.show();
            m1.subtractMatrix(m4);
            cout << "Resultant Matrix" << endl;
            m1.show();
        }
        break;

        case 11:
            cout << "---------Multiply Scalar---------" << endl;
            int scalar3;
            cout << "Enter the Scalar value : " << endl;
            inputValidation(scalar3);
            cout << "Original Matrix" << endl;
            m1.show();
            m1.multiplyScalar(scalar3);
            cout << "New Matrix" << endl;
            m1.show();
            break;

        case 12:
        {
            cout << "---------Multiply Matrix---------" << endl;
            Matrix m5;
            cout << "Second Matrix" << endl;
            m5.inputValues();
            if (m1.getCols() != m5.getRows())
                cout << "According to rules, these matrices cannot be multiplied." << endl;
            else
            {
                cout << "First Matrix" << endl;
                m1.show();
                cout << "Second Matrix" << endl;
                m5.show();
                m1 = m1.multiplyMatrix(m5);
                cout << "Resultant Matrix" << endl;
                m1.show();
            }
        }
        break;

        case 13:
            cout << "---------Determinant---------" << endl;
            det = m1.determinant();
            m1.show();
            cout << "Determinant : " << det << endl;
            break;

        case 14:
            cout << "---------Adjoint---------" << endl;
            cout << "Original Matrix" << endl;
            m1.show();
            m1 = m1.adjoint();
            cout << "Adjoint Matrix" << endl;
            m1.show();
            break;

        case 15:
            cout << "---------Inverse---------" << endl;
            cout << "Original Matrix" << endl;
            m1.show();
            if (m1.determinant() == 0)
                cout << "Determinant is zero. Inverse cannot be calculated" << endl;
            else
            {
                m1 = m1.inverse();
                cout << "Inverse Matrix" << endl;
                m1.show();
                cout << "Some values might be zero because they are actually zero but\nsome might be due to conversion of data type (Values < 1 and > 0 will be rounded off to zero as well)" << endl;
            }
            break;

        case 16:
            cout << "---------Symmetric---------" << endl;
            cout << "Original Matrix" << endl;
            m1.show();
            symmetric = m1.isSymmetric();
            if (symmetric)
                cout << "Given Matrix is symmetric" << endl;
            else
                cout << "Given Matrix is not symmetric" << endl;
            break;

        case 17:
            cout << "---------Exiting the Program---------" << endl;
            exit(0);
            break;

        default:
            cout << "Wrong Command Entered. Enter between 1-17" << endl;
            break;
        }
    } while (userOption != 17);

    return 0;
}

// Character and negative number validation
int inputValidation(int &number)
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

// Only character type validation for Entering elements
int inputValidationNums(int &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            validInput = true;
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