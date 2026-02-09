// Mostly 5 types of inheritance:
// 1: Single Inheritance e.g: class B : public A { ... };
// 2: Multiple Inheritance e.g: class C : public A, public B { ... };
// 3: Multilevel Inheritance e.g: Class B: Public A, class C : Public B (B is inherited from A, and C is inherited from B.)
// 4: Hierarchical Inheritance e.g: B : A, C : A (both B and C inherit from A)
// 5: Hybrid Inheritance e.g: A combination of two or more types of inheritance (like multiple + multilevel).

#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person
{
public:
    string name;
    int age;

    // Constructor of Person
    Person(int age, string name)
    {
        this->age = age;
        this->name = name;
    }
};

// Student inherits from Person (Single/Multilevel Inheritance)
// Using virtual inheritance to avoid diamond problem in Hybrid Inheritance
class Student : public virtual Person
{
public:
    string rollNo;
    string schoolName;

    // Constructor of Student
    Student(int age, string name, string rollNo, string schoolName)
        : Person(age, name) // Call Person constructor
    {
        this->rollNo = rollNo;         // Initialize roll number
        this->schoolName = schoolName; // Initialize school name
    }
};

// Matric inherits from Student
// Hybrid Inheritance (Multilevel + Single)
class Matric : public Student
{
public:
    string registration_Number;
    string board;

    // Constructor of Matric
    Matric(int age, string name, string rollNo, string schoolName,
           string rn, string board)
        : Person(age, name),                     // Call virtual base class constructor
          Student(age, name, rollNo, schoolName) // Call Student constructor
    {
        this->registration_Number = rn; // Correct assignment
        this->board = board;            // Assign board
    }
};

int main()
{
    // Create Matric object
    Matric m(16, "Hanan", "S123", "Comsat School", "RN456", "Punjab Board");

    // Access all members
    cout << "Name: " << m.name << endl;                           // Person
    cout << "Age: " << m.age << endl;                             // Person
    cout << "Roll No: " << m.rollNo << endl;                      // Student
    cout << "School: " << m.schoolName << endl;                   // Student
    cout << "Registration No: " << m.registration_Number << endl; // Matric
    cout << "Board: " << m.board << endl;                         // Matric

    return 0;
}

/*
Inheritance Types in this code:
- Single Inheritance: Person -> Student
- Multilevel Inheritance: Person -> Student -> Matric
- Hybrid Inheritance: Using virtual inheritance to avoid diamond problem
*/
