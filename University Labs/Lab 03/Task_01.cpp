#include <iostream>
#include <limits>
using namespace std;

double numberValidationD(double &);
int numberValidation(int &);

class Student
{
    double cgpa;
    string name;
    int rollNo; 
    int noOfTests;
    int *testScores;
    double average;

public:
    // Constructor
    Student()
    {
        name = "";
        cgpa = 0.0;
        rollNo = 0;
        noOfTests = 0;
        testScores = new int[noOfTests];
        average = 0;
    }

    // CGPA
    void setcgpa(double x)
    {
        cgpa = x;
    }
    double getcgpa() const
    {
        return cgpa;
    }

    // Roll Number
    void setRollNo(int x)
    {
        rollNo = x;
    }
    int getRollNo() const
    {
        return rollNo;
    }

    // Average
    double getAverage() const
    {
        return average;
    }

    // Name
    void setname(string x)
    {
        name = x;
    }
    string getname() const
    {
        return name;
    }

    // Number of tests
    void setnoOfTests(int x)
    {
        noOfTests = x;
    }
    int getnoOfTests() const
    {
        return noOfTests;
    }

    // Test Scores
    void setTestScores(int *students)
    {

        for (size_t i = 0; i < noOfTests; i++)
        {
            testScores[i] = students[i];
        }
    }
    int *getTestScores() const
    {
        return testScores;
    }

    // Average
    double calculateAverage()
    {
        double sum = 0.0;
        for (int i = 0; i < noOfTests; i++)
        {
            sum += testScores[i];
        }
        average = sum / noOfTests;
        return average;
    }

    // Displaying all details
    void displayDetails() const
    {
        cout << endl << "Name : " << name << endl;
        cout << "CGPA : " << cgpa << endl;
        cout << "Roll No : " << rollNo << endl;
        cout << "No. Of Tests : " << noOfTests << endl;
        cout << "====== Test Score =====" << endl;
        for (int i = 0; i < noOfTests; i++)
        {
            cout << "Test " << i + 1 << " : " << testScores[i] << endl;
        }
        cout << "Average : " << average << endl
             << endl;
    }

    // Destructor
    ~Student()
    {
        if (testScores != nullptr)
        {
            delete[] testScores;
            testScores = nullptr;
        }
    }
};

// Global Functions
void takeInformation(Student *students, int numOfStudents)
{
    for (size_t i = 0; i < numOfStudents; i++)
    {
        int roll, numberOfTests;
        double cgpa;
        string name;
        cout << "===== Student " << i + 1 << "=====" << endl;
        // Name
        cout << "Enter the name of student" << endl;
        cin.ignore();
        getline(cin, name);
        students[i].setname(name);
        // CGPA
        cout << "Enter the cgpa of the Student" << endl;
        numberValidationD(cgpa);
        students[i].setcgpa(cgpa);
        // Roll Number
        cout << "Enter the Roll number of the student" << endl;
        numberValidation(roll);
        students[i].setRollNo(roll);
        // Number of Tests
        cout << "Enter the number of Tests" << endl;
        numberValidation(numberOfTests);
        students[i].setnoOfTests(numberOfTests);
        // Taking Each Test Score
        cout << "Enter the Test scores one by one" << endl;
        int *tests = new int[numberOfTests];
        for (size_t i = 0; i < numberOfTests; i++)
        {
            cout << "Test " << i + 1 << ": " << endl;
            numberValidation(tests[i]);
        }
        students[i].setTestScores(tests);
        students[i].calculateAverage();
        delete[] tests;
        tests = nullptr;
    }
}

// Display One Student
void displayOneStudent(Student *students, int noOfStudents, int studentNo)
{
    if (studentNo > noOfStudents)
    {
        cout << "Out of Bound" << endl;
        return;
    }
    students[studentNo - 1].displayDetails();
}

// Display All Students
void displayAllStudent(Student *students, int noOfStudents)
{
    for (size_t i = 0; i < noOfStudents; i++)
    {
        students[i].displayDetails();
    }
}

void findTopper(Student *students, int noOfStudents)
{
    int studentNo;
    int max = 0;
    for (size_t i = 0; i < noOfStudents; i++)
    {
        if (students[i].getAverage() > max){
            max = students[i].getAverage();
            studentNo = i;
        }
    }

    students[studentNo].displayDetails();
}

int main()
{
    int noOfStudents, userOption;
    cout << "Enter the number of students : ";
    numberValidation(noOfStudents);
    Student *std = new Student[noOfStudents];
    while (userOption != 5)
    {
        cout << "Student Management System" << endl;
        cout << "Enter from the following options" << endl;
        cout << "1. Take Information" << endl;
        cout << "2. Display One Student" << endl;
        cout << "3. Display All Students" << endl;
        cout << "4. Find Topper" << endl;
        cout << "5. Exit" << endl;
        cin >> userOption;
        switch (userOption)
        {
        case 1:
            takeInformation(std, noOfStudents);
            break;
        case 2:
            int studentNumber;
            cout << "Enter the student number" << endl;
            numberValidation(studentNumber);
            displayOneStudent(std, noOfStudents, studentNumber);
            break;
        case 3:
            displayAllStudent(std, noOfStudents);
            break;
        case 4:
            findTopper(std, noOfStudents);
            break;
        case 5:
            exit(0);
        default:
            cout << "Wrong command entered" << endl;
            break;
        }
    }

    delete[] std;
    std = nullptr;

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

double numberValidationD(double &number)
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
