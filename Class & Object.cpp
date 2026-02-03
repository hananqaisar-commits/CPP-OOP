#include <iostream>
using namespace std;

class Student
{
    string id;
    string name;
    int marks;

public:
    Student() {};//default
    Student(string id, string name, int marks)//parameterized
    {
        this->id = id;
        this->name = name;
        this->marks = marks;
    }
    Student(const Student &object)//copy
    {
        this->id = object.id;
        this->name = object.name;
        this->marks = object.marks;
    }
    void display()
    {
        cout << "Student name is: " << name << endl;
        cout << name << " ID is: " << id << endl;
        cout << "Marks is: " << marks << "\n"
             << endl;
    }
};
int main()
{
    Student s1("FA25-BSE-187", "Hanan Qaisar", 90);//it will invoke parameterized
    Student s2(s1);//it will invoke my copy constructor
    Student s3 = s1;//it will invoke my copy constructor
    Student s4;//it will invoke default constructor
    s4 = s3;////it will invoke default copy constructor of compiler 
    s1.display();
    s2.display();
    s3.display();
    s4.display();

    return 0;
}