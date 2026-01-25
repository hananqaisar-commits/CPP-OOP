#include <iostream>
#include <string>
using namespace std;

class LibraryItem
{
private:
    int itemid;
    string title;

public:
    static int totalcount; // static variable
    static void getTotal()
    {
        cout << "Total Items " << totalcount << endl;
    }
    LibraryItem()
    {
        itemid = ++totalcount; // bcz first it is increased so it become 1 then use this value
    }
    ~LibraryItem()
    {
        cout << "Item " << title << " is destroyed" << endl;
    }
    void setTitle();
    string getTitle()
    {
        return title;
    }
    int getid()
    {
        return itemid;
    }
};
int LibraryItem ::totalcount = 0;
void LibraryItem ::setTitle()
{
    cout << "Enter name of Book:";
    getline(cin, title);
}

class Book : public LibraryItem
{
    string author;
    int price;

public:
    Book(string author, int price) : LibraryItem()
    {
        this->author = author;
        this->price = price;
    }

    void displayBookInfo();
};
void Book ::displayBookInfo()
{

    cout << "Book Title is " << getTitle() << endl;
    cout << "Book Author is " << author << endl;
    cout << "Book Id is " << getid() << endl;
    cout << "Book Price is " << price << endl;
}
int main()
{
    
    Book b1("Hanan Qaisar", 7099), b2("Ali Hamza", 5789);
    b1.setTitle();
    b2.setTitle();
    b1.displayBookInfo();
    b2.displayBookInfo();

    LibraryItem ::getTotal();

    return 0;
}