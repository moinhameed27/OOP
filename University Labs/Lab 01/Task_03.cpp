#include <iostream>
using namespace std;

class Book
{
    int year;
    string title;
    string author;
    string genre;
    int price;

public:
// Constructor
    Book(){
        year = 0;
        title = "";
        author = "";
        genre = "";
        price = 0;
    }
    // Year
    void setYear(int x)
    {
        year = x;
    }
    int getYear()
    {
        return year;
    }
    // Title
    void setTitle(string x)
    {
        title = x;
    }
    string getTitle()
    {
        return title;
    }
    // Author
    void setAuthor(string x)
    {
        author = x;
    }
    string getAuthor()
    {
        return author;
    }
    // Genre
    void setGenre(string x)
    {
        genre = x;
    }
    string getGenre()
    {
        return genre;
    }
    // Price
    void setPrice(int x)
    {
        price = x;
    }
    int getPrice()
    {
        return price;
    }

    // Discounted Price
    void discountedPrice(){
        price *= 0.90;
        cout << "Discounted Price : " << price << endl;
    }
    // Displaying all details
    void displayDetails()
    {
        cout << "Title : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Genre : " << genre << endl;
        cout << "Year : " << year << endl;
        cout << "Price : " << price << endl;
    }
};

int main()
{
    Book b1;
    b1.setTitle("Exams");
    b1.setAuthor("Moin");
    b1.setGenre("Comedy");
    b1.setYear(2004);
    b1.setPrice(1800);
    b1.displayDetails();
    cout << endl;
    b1.discountedPrice();
     b1.displayDetails();
    return 0;
}