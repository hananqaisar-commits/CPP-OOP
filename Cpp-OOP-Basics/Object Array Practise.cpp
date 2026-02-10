#include <iostream>
using namespace std;

// Classes are created beafore our main function
class car
{
private:
    int price; // this is private not accessible untill use setter and getter
    string owner;

public:
    // Classes
    string move;
    string color;
    int number;

    // Setter         // it is used to set values or data for private details
    void setprice(int n)
    {
        price = n;
    }
    void setowner(string n)
    {
        owner = n;
    }

    // Getter         // this is to get that setter value
    int getprice()
    {
        return price;
    }
    string getowner()
    {
        return owner;
    }

    // Methods (It is basically functions which is used in classes)
    void display(int i)
    {
        cout << "Car" << i + 1 << " Wheel Movement is " << move.c_str() << endl; // .c_str() this is to print string in C++
        cout << "Car" << i + 1 << " Color is " << color.c_str() << endl;
        cout << "Car" << i + 1 << " Number is " << number << endl;
        cout << "This car Price is " << getprice() << endl; // here getprice is function call
        cout << "Owner is " << getowner().c_str() << endl;
    }; // This was method

    // This is constructor
    car()
    {
        cout << "This is Constructor" << endl;
    }
};
// Enum is optional here, but kept for increase understanding and readability
enum CARS
{
    Car1 = 0, // Start from 0 and automatically increamented bt 1
    Car2
};

int main()
{
    car car[2]; // car is class and car[0], car[1] are objects bcz car[2] is array
    int price[2];
    string owner[2];

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter car " << i + 1 << " Price: " << endl;
        cin >> price[i];
        cout << "Enter car " << i + 1 << " Owner: " << endl;
        cin >> owner[i];
    }
    // Objects: access class by using dot(.) Operator or also by arrow operator

    car[0].move = "Front";
    car[0].color = "White";
    car[0].number = 2037;

    car[1].move = "Rear";
    car[1].color = "Black";
    car[1].number = 5861;

    for (int i = Car1; i <= Car2; i++) // car1 vale is 0 and car2 value is 1 so, car2 is condition
    {
        car[i].setprice(price[i]); //first i will set price and owner then call display function. This is setter function call; passing argument
        car[i].setowner(owner[i]);
        car[i].display(i); // objectName.methodName(arguments); // it is SYNTAX for function call in classes and objects
        cout << endl;      // extra line for readability in output
    }
}