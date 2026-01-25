#include <iostream>
#include <string>
using namespace std;

class Student
{
    string name;
    int rollNo;
    int marks;

public:
    Student()
    {
        totalStudents++;
    }
    static int totalStudents; // static is initiallized with 0 by default
    friend void compareMarks(Student s1, Student s2);
    void setname();
    string getname();
    void setrollNo();
    void setmarks();
    void display(void);
};

int Student ::totalStudents;
//  void Student :: totalStudents=1; //but if i want to initilize then this is method

void Student ::setname()
{

    cout << "Enter name: ";
    getline(cin, name);
}
string Student ::getname()
{
    return name;
}
void Student ::setrollNo()
{
    cout << "Enter Roll number: ";
    cin >> rollNo;
    cin.ignore();
}
void Student ::setmarks()
{
    cout << "Enter marks: ";
    cin >> marks;
}

void compareMarks(Student s1, Student s2)
{
    if (s1.marks > s2.marks)
    {
        cout << "Student " << s1.name << " has more marks then Student " << s2.name << endl;
    }
    else if (s1.marks < s2.marks)
    {
        cout << "Student " << s1.name << " has less marks then Student " << s2.name << endl;
    }
    else
        cout << "Both have equal marks" << endl;
}
void Student ::display(void)
{
    cout << "Student " << totalStudents << " name " << name << endl;
    cout << "Student " << totalStudents << " has marks " << marks << endl;
    cout << "Student " << totalStudents << " Roll number " << rollNo << endl;
}
int main()
{

    Student s1, s2;
    s1.setname();
    s1.setmarks();
    s1.setrollNo();

    s2.setname();
    s2.setmarks();
    s2.setrollNo();

    s1.display();
    s2.display();

    compareMarks(s1, s2);

    cout<<"Total studens is "<<Student :: totalStudents <<endl;//it is way to access freind function in main bode

    return 0;
}