#include <iostream>
using namespace std;

class Student{
    int rollNumber;
    string name;
    string address;
    string phoneNumber;
    char grade;
    public:
    // Roll Number
    void setRollNumber(int x){
        rollNumber = x;
    }
    int getRollNumber(){
        return rollNumber;
    }
    // Name
    void setName(string x){
        name = x;
    }
    string getName(){
        return name;
    }
    // Address
    void setAddress(string x){
        address = x;
    }
    string getAddress(){
        return address;
    }
    // Phone Number
    void setPhoneNumber(string x){
        phoneNumber = x;
    }
    string getPhoneNumber(){
        return phoneNumber;
    } 
    // Grade
    void setGrade(char x){
        grade = x;
    }
    char getGrade(){
        return grade;
    }
    // Displaying all details
    void displayDetails(){
        cout << "Roll Number : " << rollNumber << endl;
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
        cout << "Phone Number : " << phoneNumber << endl;
        cout << "Grade : " << grade << endl;
    }

};

int main()
{
    Student s1;
    s1.setRollNumber(23);
    s1.setName("Muhammad Moin U Din");
    s1.setAddress("Nawab Town");
    s1.setPhoneNumber("03001234567");
    s1.setGrade('A');
    s1.displayDetails();    
    return 0;
}