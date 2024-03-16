#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

#define NAME_SIZE 31
#define DEPT_NAME_SIZE 41

class Employee
{
    int id;
    char name[NAME_SIZE];
    char deptName[DEPT_NAME_SIZE];

public:
    Employee()
    {
        id = 0;
        strcpy(name, "");
        strcpy(deptName, "");
    }

    Employee(int a, char *n, char *dN)
    {
        id = a;
        strcpy(name, n);
        strcpy(deptName, dN);
    }

    // ~Employee()
    // {
    //     id = 0;
    //     strcpy(name, "");
    //     strcpy(deptName, "");
    // }

    void setID(int a)
    {
        id = a;
    }

    int getID() const
    {
        return id;
    }

    void setName(char *n)
    {
        strcpy(name, n);
    }


    const char *getName() const
    {
        return name;
    }

    void setDeptName(char *n)
    {
        strcpy(deptName, n);
    }

    const char *getDeptName() const
    {
        return deptName;
    }


    void display() const
    {
        cout << "ID : " << id << endl;
        cout << "Name : " << name << endl;
        cout << "Department Name : " << deptName << endl;
    }

    void writeToFile(ofstream &fout)
    {
        fout << id;
        fout << endl;
        fout << name;
        fout << endl;
        fout << deptName;
        fout << endl;
    }

    void readFromFile(ifstream &fin) 
    {
        fin >> id;
        fin.ignore();
        fin.getline(name, NAME_SIZE);
        fin.getline(deptName, DEPT_NAME_SIZE);
    }
};

int main()
{
    // Writing data to a file
    int size;
    cout << "Enter the size of Objects array\n";
    cin >> size;
    Employee *pts = new Employee[size];

    for (size_t i = 0; i < size; i++)
    {
        int id;
        char temp1[NAME_SIZE];
        char temp2[DEPT_NAME_SIZE];
        cout << "Employee " << i + 1 << endl;
        cout << "Enter the User ID" << endl;
        cin >> id;
        cin.ignore();
        cout << "Enter the name of the employee" << endl;
        cin.getline(temp1, NAME_SIZE);
        cout << "Enter the Department name of the employee" << endl;
        cin.getline(temp2, DEPT_NAME_SIZE);
        pts[i].setID(id);
        pts[i].setName(temp1);
        pts[i].setDeptName(temp2);
    }

    ofstream fout;
    fout.open("Emps.txt");
    if (!fout)
    {
        cout << "Error: File could not be created" << endl;
    }

    else
    {

        fout << size << endl;
        for (size_t i = 0; i < size; i++)
        {
            pts[i].writeToFile(fout);
        }

        fout.close();
        delete[] pts;
        pts = nullptr;
    }




    // Reading Data from a file
    ifstream fin;
    fin.open("Emps.txt");
    if (!fin)
    {
        cout << "Error: File could not be opened\n";
    }
    else
    {
        int size;
        fin >> size;
        Employee *pts = new Employee[size];
        for (size_t i = 0; i < size; i++)
        {
            pts[i].readFromFile(fin);
        }

        fin.close();

        cout << "Displaying Data from the file" << endl;
        for (size_t i = 0; i < size; i++)
        {
            pts[i].display();
        }

        delete[] pts;
        pts = nullptr;

    }

    return 0;
}