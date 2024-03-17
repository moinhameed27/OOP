/*
Composer : Muhammad Moin U Din
Naming Convention : camelCase
Description : String Abstract Data Type with multiple operations which can be performed on strings.
*/

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int inputValidation(int &);

class MyString
{
    int length;
    char *data;

public:
    // Constructor
    MyString(int l = 0)
    {
        length = l;
        data = new char[length + 1]; // +1 for the Null terminator
        strcpy(data, "");            // Empty String
    }

    // Copy Constructor
    MyString(const MyString &orig)
    {
        length = orig.length;
        data = new char[length];
        strcpy(data, orig.data);
    }

    // Length Mutator
    void setLength(int l)
    {
        length = l;
    }

    // Length Accessor
    int getLength()
    {
        return length;
    }

    // Input Values : Taking values from the user
    void inputValues()
    {
        cout << "String Input" << endl;
        int l;
        cout << "Enter the length of string : ";
        inputValidation(l);
        setLength(l);

        delete[] data;
        data = new char[length + 1];
        strcpy(data, "");

        cout << "Enter the String : ";
        cin.ignore();
        cin.getline(data, length);
    }

    // Get Value : Returns the character at specific index
    char getValue(int index)
    {
        if (index > length)
        {
            return '-';
        }
        else
            return data[index - 1];
    }

    // Set Value : Sets the value at particular index
    void setValue(int index, char value)
    {

        data[index - 1] = value;
    }

    // Show : Display the String
    void show()
    {
        cout << "String : ";
        for (int i = 0; data[i] != '\0' && i < length; i++)
        {
            cout << data[i];
        }
        cout << endl;
    }

    // Concatenate : Append second string to the end of the first string
    void concatenate(const MyString &other)
    {
        int totalLength = length + other.length; // Total length of concatenated String
        MyString temp(totalLength + 1);          // Temp Array to store Data

        strcpy(temp.data, data);

        int size1 = strlen(data);
        int size2 = strlen(other.data);

        // Copy characters from the second string
        for (int i = 0; other.data[i] != '\0'; i++)
        {
            temp.data[size1 + i] = other.data[i];
        }

        temp.data[size1 + size2] = '\0';

        temp.show();
    }

    // Substring : Extract a substring
    void substring(int start, int len)
    {

        cout << "Substring : ";
        for (int i = 0; i < len; i++)
        {
            cout << data[start + i];
        }
        cout << endl;
    }

    // Copy String : Copy another string to current string
    void copyString(const MyString &other)
    {

        if (other.length > length)
        {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, "");
        }

        for (int i = 0; i < length; i++)
        {
            data[i] = other.data[i];
        }
        data[length] = '\0';
    }

    // to Upper : Convert the string to Uppercase
    void toUpper()
    {
        for (size_t i = 0; i < length; i++)
        {
            if (data[i] >= 'a' && data[i] <= 'z')
            {
                data[i] -= 32;
            }
        }
    }

    // to Lower : Convert the string to Lowercase
    void toLower()
    {
        for (size_t i = 0; i < length; i++)
        {
            if (data[i] >= 'A' && data[i] <= 'Z')
            {
                data[i] += 32;
            }
        }
    }

    // to Proper : Capitalize the first letter of each word
    void toProper()
    {
        if (isalnum(data[0]))
            data[0] -= 32;

        for (size_t i = 1; i < length; i++)
        {
            // If current index is a space and next index is a character, convert
            if (data[i] == ' ' && isalnum(data[i + 1]))
            {
                data[i + 1] -= 32;
                i++; // Already converted so increment i again
            }
            // If current index is a character and previous index was a space, convert
            else if (isalnum(data[i]) && data[i - 1] == ' ')
            {
                data[i] -= 32;
            }
        }
    }

    // to Sentence : Capitalize the first letter of the String (Modify Calling object)
    void toSentence()
    {
        toLower();
        for (size_t i = 0; i < length; i++)
        {
            if (isalnum(data[i]))
            {
                data[i] -= 32;
                break;
            }
        }
    }

    // Sentence : Capitalize the first letter of the String (Not Modifying Calling object)
    MyString Sentence()
    {
        MyString temp(length);
        temp.copyString(*this);
        temp.toLower();

        for (size_t i = 0; i < length; i++)
        {
            if (isalnum(temp.data[i]))
            {
                temp.data[i] -= 32;
                break;
            }
        }
        return temp;
    }

    // to Reverse : Reverse the String (Modify Calling object)
    void toReverse()
    {
        int size = strlen(data);
        for (int i = size - 1, j = 0; j < size / 2; i--, j++)
        {
            char tempC = data[i];
            data[i] = data[j];
            data[j] = tempC;
        }
    }

    // to Reverse : Reverse the String (Not Modifying Calling object)
    MyString reverse()
    {
        MyString temp(length);
        temp.copyString(*this);
        temp.toReverse();
        return temp;
    }

    // Destructor
    ~MyString()
    {
        delete[] data;
        data = nullptr;
    }
};

int main()
{

    cout << "--------String ADT--------" << endl;
    MyString m1;
    m1.inputValues();
    int userOption;
    do
    {
        cout << "--------String Operations Menu--------" << endl;
        cout << "1. Input Values(Over-write previous entered Values)" << endl;
        cout << "2. Get Value" << endl;
        cout << "3. Set Value" << endl;
        cout << "4. Display String" << endl;
        cout << "5. Concatenate" << endl;
        cout << "6. Substring" << endl;
        cout << "7. Copy String" << endl;
        cout << "8. To Upper" << endl;
        cout << "9. To Lower" << endl;
        cout << "10. To Proper" << endl;
        cout << "11. to Sentence" << endl;
        cout << "12. Sentence" << endl;
        cout << "13. to Reverse" << endl;
        cout << "14. Reverse" << endl;
        cout << "15. Exit" << endl;
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
            cout << "---------Get Value---------" << endl;
            int index;
            cout << "Enter the index : " << endl;
            inputValidation(index);
            if (m1.getValue(index) == '-')
                cout << "Given index is out of bound" << endl;
            else
                cout << "Value at Index " << index << " is : " << m1.getValue(index) << endl;
        }
        break;

        case 3:
            cout << "---------Set Value---------" << endl;
            int index2;
            char c;
            cout << "Original String" << endl;
            m1.show();
            cout << "Enter the index : ";
            inputValidation(index2);
            if (index2 > m1.getLength())
                cout << "Given index is out of bound" << endl;
            else
            {
                cout << "Enter the character you want to replace : ";
                cin >> c;
                m1.setValue(index2, c);
                cout << "New String" << endl;
                m1.show();
            }
            break;

        case 4:
            cout << "---------Display String---------" << endl;
            m1.show();
            break;

        case 5:
        {
            cout << "---------Concatenate---------" << endl;
            MyString m2;
            m2.inputValues();
            cout << "First String" << endl;
            m1.show();
            cout << "Second String" << endl;
            m2.show();
            cout << "Concatenated String" << endl;
            m1.concatenate(m2);
        }
        break;

        case 6:
            cout << "---------Substring---------" << endl;
            int start, len;
            cout << "Enter the Start value : " << endl;
            inputValidation(start);
            cout << "Enter the Length value from the start : " << endl;
            inputValidation(len);
            if (start > m1.getLength() || start + len > m1.getLength())
            {
                cout << "Given Input is out of bound" << endl;
            }
            else
            {
                cout << "Original String" << endl;
                m1.show();
                m1.substring(start, len);
            }
            break;

        case 7:
        {
            cout << "---------Copy String---------" << endl;
            MyString m3;
            m3.inputValues();
            cout << "First String" << endl;
            m1.show();
            cout << "Second String" << endl;
            m3.show();
            m1.copyString(m3);
            cout << "Copied String" << endl;
            m1.show();
        }
        break;

        case 8:
            cout << "---------To Upper---------" << endl;
            cout << "Original String" << endl;
            m1.show();
            m1.toUpper();
            cout << "New String" << endl;
            m1.show();
            break;

        case 9:
        {
            cout << "---------To Lower---------" << endl;
            cout << "Original String" << endl;
            m1.show();
            m1.toLower();
            cout << "New String" << endl;
            m1.show();
        }
        break;

        case 10:
            cout << "---------To Proper---------" << endl;
            cout << "Original String" << endl;
            m1.show();
            m1.toProper();
            cout << "New String" << endl;
            m1.show();
            break;

        case 11:
        {
            cout << "---------To Sentence---------" << endl;
            cout << "Original String" << endl;
            m1.show();
            m1.toSentence();
            cout << "New String" << endl;
            m1.show();
        }
        break;

        case 12:
        {
            cout << "---------Sentence---------" << endl;
            cout << "Original String" << endl;
            m1.show();
            MyString m4 = m1.Sentence();
            cout << "New String" << endl;
            m4.show();
        }
        break;

        case 13:
            cout << "---------To Reverse---------" << endl;
            cout << "Original String" << endl;
            m1.show();
            m1.toReverse();
            cout << "New String" << endl;
            m1.show();
            break;

        case 14:
        {
            cout << "---------Reverse---------" << endl;
            cout << "Original String" << endl;
            m1.show();
            MyString m5 = m1.reverse();
            cout << "New String" << endl;
            m5.show();
        }
        break;

        case 15:
            cout << "---------Successfully Exited the Program---------" << endl;
            exit(0);
            break;

        default:
            cout << "Wrong Command Entered. Enter between 1-15" << endl;
            break;
        }
    } while (userOption != 15);

    return 0;
}

// Number validation to take the valid number for the user(basically character validation)
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
            // cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
    return number;
}