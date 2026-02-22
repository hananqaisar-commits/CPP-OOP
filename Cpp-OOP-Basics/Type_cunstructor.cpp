#include <iostream>
using namespace std;

// Ther are three type of constructor
// 1)Non-Parameterizes
// 2)Parameterized
// 3)copy constructor

// Rules of constructor:
// A constructor is a special function that:
// 1.Has same name as class
// 2.Runs automatically when an object is created
// 3.Is used to initialize data
// 4.had no returntype
class Car
{

public:
    string company;
    // 1st type is default in c++:
    Car() {} // here i write default constructor bcz i create obj like Car car1,car2
    // 2nd type is:
    Car(string name)
    {
        company = name;
    }
    // 3 type is:
    Car(const Car &carProp)
    {
        cout << "This is manually made copy constructor" << endl;
        this->company = carProp.company;
    }
    void output();
};

void Car ::output()
{
    cout << "Company name is : " << company << endl;
}
int main()
{
    int n;
    Car car1("Toyota"), car2;
    car2 = car1;    // This is copy constructor made by me
    Car car3(car1); // This is also called copy constructor but in this compiler invokes their own copy constructor
    Car car4("Honda");
    Car car5 = car4; // here copy constructor is invoked made by me

    car1.output();
    car2.output();
    car3.output();
    car4.output();
    car5.output();
}