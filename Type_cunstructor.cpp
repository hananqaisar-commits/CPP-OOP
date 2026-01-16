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

class car
{

public:
    string company;
    // 1 type is default in c++:
    // car()
    // {
    //     cout << "This  is non parameterized constructor";
    // }

    //2 type is:
    car(string name)
    {
        company = name;
    }

    //3 type is:
    car()
};

int main()
{
    int n;
    car car1("Toyota");
    cout<<"Company name is :"<<car1.company<<endl;
    
}