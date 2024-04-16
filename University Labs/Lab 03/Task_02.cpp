#include <iostream>
#include <string>
using namespace std;

class Book
{
    string title;
    string author;
    int publicationYear;
    float price;
    int pageCount;
    char **contents;
    int characters = 26; // Characters per page
public:
    // Constructor
    Book(string t = "", string a = "", int pY = 0, float p = 0.0, int pC = 0, char **c = nullptr)
    {
        title = t;
        author = a;
        publicationYear = pY;
        price = p;
        pageCount = pC;
        contents = new char *[pageCount];
        for (int i = 0; i < pageCount; i++)
            contents[i] = new char[characters];
    }

    // Title
    void setTitle(string t) { title = t; };
    string getTitle() { return title; }

    // Author
    void setAuthor(string a) { author = a; };
    string getAuthor() { return author; }

    // Publication Year
    void setPYear(int pY) { publicationYear = pY; }
    int getPYear() { return publicationYear; }

    // Price
    void setPrice(float p) { price = p; }
    float getPrice() { return price; }

    // Page Count
    void setPCount(int pC) { pageCount = pC; }
    int getPCount() { return pageCount; }

    // Set the contents of a specific page
    void setContent(int page, const string &content)
    {
        for (int i = 0; i < characters; i++)
        {
            contents[page][i] = content[i];
        }
    }

    // Display the contents of the page
    void displayPage(int page)
    {
        cout << "Title : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Publication Year : " << publicationYear << endl;
        cout << "Price : " << price << endl;
        cout << "-----------Contents-----------" << endl;

        for (int i = 0; i < characters; i++)
        {
            cout << contents[page][i];
        }
        cout << endl;
    }

    // Destructor
    ~Book()
    {
        for (int i = 0; i < pageCount; i++)
            delete[] contents[i];
        delete[] contents;
        contents = nullptr;
    }
};

int main()
{

    Book b1("King of Kings", "Martin Luther", 2004, 2650, 20);
    string content = "";
    for (int i = 0; i < 26; i++)
    {
        content += (char) i + 65;   
    }
    
    b1.setContent(2, content);
    b1.displayPage(2);

    return 0;
}
