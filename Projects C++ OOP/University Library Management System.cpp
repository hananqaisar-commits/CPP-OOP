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

    void setTitle()
    {
        cout << "Enter name of Book: ";
        getline(cin, title);
    }
    string getTitle()
    {
        return title;
    }
    void setId()
    {
        cout << "Enter Student registration ID: : ";
        cin >> itemid;
    }
    int getid()
    {
        return itemid;
    }
};
int LibraryItem ::totalcount = 0; // initilizing static totalCount to 0.And remember static belong to class itself it is not object of class
// Every object of LibraryItem shares the same totalcount.

class Book : public LibraryItem
{
    string author;
    int price;

public:
    void input();
    void setPrice()
    {
        cout << "Enter price: ";
        cin >> price;
    }
    void setowner()
    {
        cin.ignore();//this remove the last newline from buffer which will come from owner name line
        cout << "\nEnter owner name: ";
        getline(cin, author);
    }
    string getowner()
    {
        return author;
    }
    void displayBookInfo();
};
void Book ::displayBookInfo()
{

    cout << "\nBook Title is " << getTitle() << endl;
    cout << "Book Author is " << author << endl;
    cout << "Student registration ID is " << getid() << endl;
    cout << "Book Price is " << price << endl;
}

void Book ::input()
{
    setowner();
    setTitle();
    setId();
    setPrice();
}

int main()
{
    int book;
    cout << "How many book? ";
    cin >> book;

    Book **bptr = new Book *[book];

    for (int i = 0; i < book; i++)
    {
        bptr[i] = new Book(); 
        bptr[i]->input();
        
    }
    for (int i = 0; i < book; i++)
    {
        bptr[i]->displayBookInfo();
        delete bptr[i];
    }
    

    LibraryItem ::getTotal();

    return 0;
}