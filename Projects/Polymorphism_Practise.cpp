#include <iostream>
#include <string>
using namespace std;

// polymorphism:(Definition)
//  Polymorphism means “many forms”.
//  In programming, it allows a single function, method, or operator
//  to work in different ways depending on how it’s used.
//  Types:
//  1: Compile-time(overloading) e.g->Function overloading, Operator overloading
//  2: Run time(over riding)     e.g->Function overriding with virtual functions

// Compile time:
// Check this it is same function name it is decided by its parameters only
// it is differ by only type(int,string,float) or number of parameters
// It does not depend upon return type of function

// Function Polymorphism:
void done(int x)
{
    cout << "Value is :" << x << endl;
}
void done(string name)
{
    cout << "Value is :" << name << endl;
}
void done()
{
    cout << "Hello World\n";
}

class calculator
{
public:
    int add(int a, int b) { return a + b; }       // int a and int b
    float mult(int a, float b) { return a * b; }  // herer int a nad float b parameter are different
    float div(float a, float b) { return a / b; } // float a and float b they are different parameter
};

// Run time polymorphism:
// 1. Overriding with virtual functions

class Animal
{
public:
    virtual void voice() = 0; // pure virtual
};
class Cat : public Animal
{
public:
    void voice() override
    {
        cout << "Cat voice.." << endl;
    }
};
class Dog : public Animal
{
public:
    void voice() override
    {
        cout << "dog voice.." << endl;
    }
};
class Parrot : public Animal
{
public:
    void voice() override
    {
        cout << "parrot voice.." << endl;
    }
};

int main()
{
    calculator c1;
    done(10);
    done("Hanan Qaisar");
    done();

    cout << c1.div(8, 5) << endl;
    cout << c1.mult(13, 5.2) << endl;

    // this is over riding:  Function overriding with virtual functions
    Dog dog1;
    dog1.voice();

    Parrot p1;
    p1.voice();

    Animal *a1 = new Parrot();
    a1->voice(); // classic runtime polymorphism,I use base class pointer

    Animal *a2 = new Dog();
    a2->voice();
    return 0;
}