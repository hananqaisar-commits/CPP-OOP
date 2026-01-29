#include <iostream>
using namespace std;

class Vehicle//abstract class 
{
public:
    virtual void start() = 0;//pure abstract 
};
class Car : virtual public Vehicle
{ // use of virtual here is optional
public:
    void start()
    {
        cout << "Car engine start.." << endl;
    }
};
class Bike : virtual public Vehicle
{ // use of virtual here is optional
public:
    void start()
    {
        cout << "Bike engine start.." << endl;
    }
};
int main()
{
    // Car car1;
    // car1.start();   this is one way ther is also another way

    Vehicle *v1; // 1. now v1 is pointer of Vehicle type is abstract
    Vehicle *v2; // 2. abstract class object is not allowed but pointer is allowed

    v1 = new Car;  // v1 pointer points to new Car object
    v2 = new Bike; // v2 pointer points to new Bike object

    v1->start(); // v1->start() calls Car start() because the pointer points to a Car object and start() is virtual (runtime polymorphism).
    v2->start(); // similarly like upper one

    return 0;
}