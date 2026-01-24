#include <iostream>
#include <string>
using namespace std;

class Item
{
private:
    string name;
    double price;

public:
    // constructor

    Item(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
    ~Item()
    {
        cout << name << " object is destroying..." << endl;
    }
    // Method declaration only inside my class this is allowed:
    void show();
    void show(bool showprice);

    void set_name(string name)
    {
        this->name = name;
    }
    string get_name()
    {
        return name;
    }
    void set_price(double price)
    {
        this->price = price;
    }
    double get_price()
    {
        return price;
    }
};
class Beverage : public Item
{
private:
    string size;  // small,medium,large
    string state; // Hot or Cold
public:
    Beverage(string name, double price, string size, string state) : Item(name, price)
    {
        this->size = size; // this mean property size is assinged parameter size
        this->state = state;
    }
    void displayBeverage();
};
class Snacks : public Item
{
private:
    int calories;

public:
    Snacks(string name, double price, int calories) : Item(name, price)
    {
        this->calories = calories;
    }
    void displaySnack();
};
// here i use :: bcz i am making method outside class this is 2nd way of initilizing method
void Item ::show()
{
    cout << "Item name is " << name << endl;
}
void Item ::show(bool showprice)
{
    if (showprice)
    {
        cout << "Item name is " << name << endl;
        cout << "Price: " << price << endl; // here price is accessible bcz it is same as method is writtin inside class
    }
}
void Beverage ::displayBeverage()
{
    show(true);
    cout << "Beverage Size is :" << size << endl;
    cout << "Temperature is :" << state << endl;
}
void Snacks ::displaySnack()
{
    show(true);
    cout << "Snack calories is " << calories << endl;
}

int main()
{
    Item i1("Beef Burger", 979.99);
    Item i2("Pizza", 1989.99);
    // Burger.show();
    i1.show(true);
    i2.show(true);

    Beverage b1("Tea", 120, "Medium", "Hot"); // Beverage(string name, double price,string size, string state)
    Beverage b2("Milkshake", 130, "Large", "Cold");

    cout << "<\n---Beverages list---> \n"
         << endl;
    b1.displayBeverage();
    b2.displayBeverage();

    Snacks s1("Dora cake", 270, 187.59);
    Snacks s2("Pancake", 190, 236.76);

    cout << "\n<---Snacks list is---> \n"
         << endl;
    s1.displaySnack();
    s2.displaySnack();

    cout << endl;
    
    return 0;
}