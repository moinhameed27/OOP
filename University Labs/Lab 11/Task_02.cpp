#include <iostream>
using namespace std;

template <typename T>
T numberValidation(T &);

class Account
{
    int accNumber;
    int balance;

protected:
    int interest;

public:
    Account() : accNumber(0), balance(0), interest(0) {}
    Account(int n, int b) : accNumber(n), balance(b), interest(0) {}

    int getBalance() { return balance; }
    int getAcc() { return accNumber; }

    void depositMoney(int m) { balance += m; }

    void withdrawMoney(int m)
    {
        if (m > balance)
            cout << "Not Sufficient Balance" << endl;
        else
            balance -= m;
    }

    virtual void calculateInterest() {}

    void display()
    {
        cout << "Account Number : " << accNumber << endl;
        cout << "Current Balance : " << balance << endl;
        cout << "Interest : " << interest << endl;
    }
};

class SavingAccount : public Account
{
public:
    SavingAccount(int no, int b) : Account(no, b) {}
    void calculateInterest() override
    {
        interest = getBalance() * 0.20;
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(int no, int b) : Account(no, b) {}
    void calculateInterest() override
    {
        interest = getBalance() * 0.10;
    }
};

class Customer
{
    int ID, num = 0, N;
    Account **acc;

public:
    Customer(int id, int n) : ID(id), N(n)
    {
        acc = new Account *[N];
    }
    ~Customer()
    {
        for (int i = 0; i < num; i++)
        {
            delete acc[i];
        }
        delete[] acc;
    }
    void createAccount()
    {
        int choice;
        cout << "Which Account you want to create: " << endl;
        cout << "1. Saving" << endl;
        cout << "2. Checking" << endl;
        cout << "Choice : ";
        numberValidation(choice);
        while (choice < 1 || choice > 2)
        {
            cout << "Wrong Input. Enter Again." << endl;
            cout << "Which Account you want to create : ";
            numberValidation(choice);
        }
        int no, b;
        cout << "Enter Account Number : ";
        numberValidation(no);
        cout << "Enter Balance : ";
        numberValidation(b);
        if (choice == 1)
            acc[num] = new SavingAccount(no, b);
        else
            acc[num] = new CheckingAccount(no, b);
        num++;
    }

    void depositMoney()
    {
        if (num == 0)
        {
            cout << "No accounts to deposit money into." << endl;
            return;
        }
        int b;
        cout << "Enter Money to Deposit : ";
        numberValidation(b);
        acc[num - 1]->depositMoney(b);
        acc[num - 1]->calculateInterest();
    }

    void withdrawMoney()
    {
        if (num == 0)
        {
            cout << "No accounts to withdraw money from." << endl;
            return;
        }
        int b;
        cout << "Enter Money to Withdraw : ";
        numberValidation(b);
        acc[num - 1]->withdrawMoney(b);
        acc[num - 1]->calculateInterest();
    }

    void display()
    {
        cout << endl;
        cout << "Customer ID : " << ID << endl
             << endl;
        for (size_t i = 0; i < num; i++)
        {
            cout << "--> Account " << i + 1 << endl;
            acc[i]->display();
            cout << endl;
        }
    }
};

int main()
{
    int m;
    int N, id;
    cout << "Enter ID : ";
    numberValidation(id);
    cout << "Enter Number of accounts you want to create : ";
    numberValidation(N);
    cout << endl;

    Customer C(id, N);
    for (int i = 0; i < N; i++)
    {
        C.createAccount();
        C.depositMoney();
        C.withdrawMoney();
        cout << endl;
    }

    C.display();

    return 0;
}

// Input Validation
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
