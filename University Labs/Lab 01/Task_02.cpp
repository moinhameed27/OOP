#include <iostream>
using namespace std;

class BankAccount
{
    int accountNumber;
    string name;
    int balance;

public:
    // Constructor
    BankAccount()
    {
        accountNumber = 0;
        name = "";
        balance = 0;
    }

    // Account Number
    void setAccountNumber(int x)
    {
        accountNumber = x;
    }
    int getAccountNumber()
    {
        return accountNumber;
    }

    // Name
    void setName(string x)
    {
        name = x;
    }
    string getName()
    {
        return name;
    }

    // Balance
    void setBalance(int x)
    {
        balance = x;
    }
    int getBalance()
    {
        return balance;
    }

    void depositMoney(int x)
    {
        balance += x;
    }

    void withdrawMoney(int x)
    {
        if(x > balance){
            cout << "Not sufficient balance" << endl;
        }
        else balance -= x;
    }

    // Displaying all details
    void displayDetails()
    {
        cout << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Name : " << name << endl;
        cout << "Balance : " << balance << endl;
        cout << endl;
    }
};

int main()
{
    BankAccount b1;
    b1.setAccountNumber(23);
    b1.setName("Moin");
    b1.setBalance(1700);
    int choice, x;

    while (choice != 3)
    {
        cout << "Enter your choice: " << endl;
        cout << "0. Deposit Money" << endl;
        cout << "1. Withdraw Money" << endl;
        cout << "2. Display Account Details Money" << endl;
        cout << "3. End" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Enter the amount you want to deposit : ";
            cin >> x;
            b1.depositMoney(x);
            break;
        case 1:
            cout << "Enter the amount you want to withdraw : ";
            cin >> x;
            b1.withdrawMoney(x);
            break;
        case 2:
            cout << "Account Details : " << endl;
            b1.displayDetails();
            break;
        case 3:
            cout << "End" << endl;
            break;
        default:
            cout << "Wrong Command selected" << endl;
            break;
        }
    }

    return 0;
}