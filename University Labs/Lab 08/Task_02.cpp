#include <iostream>
using namespace std;

double doubleValidation(double &);

class Complex
{
    double real;
    double imaginary;

public:
    // Default Constructor
    Complex()
    {
        real = 0.0;
        imaginary = 0.0;
    }

    // Single Parameter Constructor
    Complex(double a)
    {
        real = a;
        imaginary = 0.0;
    }

    // Double Parameter Constructor
    Complex(double a, double b)
    {
        real = a;
        imaginary = b;
        
    }

    // Copy Constructor
    Complex(Complex &rhs)
    {
        real = rhs.real;
        imaginary = rhs.imaginary;
    }

    // Setters
    void setReal(int a)
    {
        real = a;
    }

    void setImg(int b)
    {
        imaginary = b;
    }

    // Getters
    double getReal()
    {
        return real;
    }

    double getImg()
    {
        return imaginary;
    }

    // Add Complex Numbers
    Complex add(Complex c)
    {
        Complex result;
        result.real = real + c.real;
        result.imaginary = imaginary + c.imaginary;
        return result;
    }

    // + operator
    Complex operator+(const Complex c)
    {
        Complex result;
        result.real = real + c.real;
        result.imaginary = imaginary + c.imaginary;
        return result;
    }

    // Subtract Complex Numbers
    Complex subtract(Complex c)
    {
        Complex result;
        result.real = real - c.real;
        result.imaginary = imaginary - c.imaginary;
        return result;
    }

    // - operator
    Complex operator-(const Complex c)
    {
        Complex result;
        result.real = real - c.real;
        result.imaginary = imaginary - c.imaginary;
        return result;
    }

    // Multiply Complex Numbers
    // (a + bi)(c + di) = ac + adi + cbi - bd
    Complex multiply(Complex c)
    {
        Complex result;
        result.real = ( real * c.real ) - (imaginary * c.imaginary);
        result.imaginary = (real * c.imaginary) + (imaginary * c.real); 
        return result;
    }

    // * operator
    Complex operator*(const Complex c)
    {
        Complex result;
        result.real = ( real * c.real ) - (imaginary * c.imaginary);
        result.imaginary = (real * c.imaginary) + (imaginary * c.real); 
        return result;
    }

    // Conjugate of Complex Number
    Complex conjugate(Complex c)
    {
        c.real = real;
        c.imaginary = -imaginary;
        return c;
    }

    // Divide Complex Numbers
    Complex divide(Complex c)
    {
        Complex result;
        Complex conjC(c);
        conjugate(conjC);
        Complex num = this->multiply(conjC);
        Complex denum = c.multiply(conjC);
        num.real /= denum.real;
        num.imaginary = denum.real / num.imaginary;
        return num;
    }

    // / operator
    Complex operator/(Complex c)
    {
        Complex result;
        Complex conjC(c);
        conjugate(conjC);
        Complex num = this->multiply(conjC);
        Complex denum = c.multiply(conjC);
        num.real /= denum.real;
        num.imaginary = denum.real / num.imaginary;
        return num;
    }

    // Take input from user
    void takeInput()
    {
        cout << "Complex Number Input" << endl;
        cout << "Enter the real number : ";
        doubleValidation(real);
        cout << "Enter the imaginary number : ";
        doubleValidation(imaginary);
    }

    // Print Complex Number
    void print()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }

    // Destructor
    ~Complex()
    {
        real = 0.0;
        imaginary = 0.0;
    }
};

int main()
{

    Complex c1;
    c1.takeInput();

    double temp;
    int userOption;
    do
    {
        cout << "-----------Complex Menu-----------" << endl;
        cout << "1. Input Complex Number(Over-write previous one)" << endl;
        cout << "2. Display Complex Number" << endl;
        cout << "3. Add Complex Numbers" << endl;
        cout << "4. Subtract Complex Numbers" << endl;
        cout << "5. Multiply Complex Numbers" << endl;
        cout << "6. Divide Complex Numbers" << endl;
        cout << "7. Conjugate of Complex Number" << endl;
        cout << "8. Exit" << endl;
        cout << "----------------------------" << endl;
        cout << "Select any option : ";
        doubleValidation(temp);
        userOption = temp;

        switch (userOption)
        {
        case 1:
            c1.takeInput();
            break;
        case 2:
            c1.print();
            break;
        case 3:
        {
            Complex a2;
            cout << "-----------Add Complex Numbers-----------" << endl;
            a2.takeInput();
            cout << "First Complex Number" << endl;
            c1.print();
            cout << "Second Complex Number" << endl;
            a2.print();
            // Complex c5 = c1.add(a2);
            Complex c5 = c1 + a2;
            cout << "Added Complex Number" << endl;
            c5.print();
        }
        break;
        case 4:
        {
            Complex a3;
            cout << "-----------Subtract Complex Numbers-----------" << endl;
            a3.takeInput();
            cout << "First Complex Number" << endl;
            c1.print();
            cout << "Second Complex Number" << endl;
            a3.print();
            // Complex c4 = c1.subtract(a3);
            Complex c4 = c1 - a3;
            cout << "Subtracted Complex Number" << endl;
            c4.print();
        }
        break;
        case 5:
        {
            Complex a3;
            cout << "-----------Multiply Complex Numbers-----------" << endl;
            a3.takeInput();
            cout << "First Complex Number" << endl;
            c1.print();
            cout << "Second Complex Number" << endl;
            a3.print();
            // Complex result = c1.multiply(a3);
            Complex result = c1 * a3;
            cout << "Multiplied Complex Number" << endl;
            result.print();
        }
        break;

        case 6:
        {
            Complex a3;
            cout << "-----------Multiply Complex Numbers-----------" << endl;
            a3.takeInput();
            cout << "First Complex Number" << endl;
            c1.print();
            cout << "Second Complex Number" << endl;
            a3.print();
            // Complex c6 = c1.divide(a3);
            Complex c6 = c1 / a3;
            cout << "Multiplied Complex Number" << endl;
            c6.print();
        }
        break;
        case 7:
        {
            cout << "-----------Reverse Arrays-----------" << endl;
            cout << "Original Complex Number" << endl;
            c1.print();
            cout << "Conjugate Complex Number" << endl;
            Complex c2 = c1.conjugate(c2);
            c2.print();
        }
        break;
        case 8:
        {
            cout << "-----------Exit-----------" << endl;
        }
        break;
        
        default:
            cout << "Wrong Command Given. Enter 1 - 8" << endl;
            break;
        }
    } while (userOption != 8);

    return 0;
}

// Input Validation
double doubleValidation(double &number)
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