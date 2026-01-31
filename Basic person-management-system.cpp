#include <iostream>
#include <string>
using namespace std;
class Person // Base Class
{
private:
    string name;
    int age;

public:
    Person() {}
    // constructor:Parameterized
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    ~Person()
    {
        cout << "Destructor destroy Person object properties...\n";
    }

    void set_name(string n)
    {
        name = n;
    }
    string get_name()
    {
        return name;
    }
    void set_age(int a)
    {
        age = a;
    }
    int get_age()
    {
        return age;
    }
};

class Student : public Person
{
private:
    int roll_no;
    string grade; // A+, B+ etc

public:
    // constructor:
    Student() {} // default
    Student(string name, int age, int roll_no, string grade) : Person(name, age)
    {
        this->grade = grade;
        this->roll_no = roll_no;
    }
    ~Student()
    {
        cout << "Destructor destroy the properties of Student object...\n";
    }
    void set_rollno(int n)
    {
        roll_no = n;
    }
    int get_rollno()
    {
        return roll_no;
    }
    void set_grade(string n)
    {
        grade = n;
    }
    string get_grade()
    {
        return grade;
    }
    void show_info();
    void input_student();
};
class Teacher : public Person
{
private:
    string id;
    string sub; // sub is properties of teacher class
public:
    Teacher() {} // default constructor
    // constructor:
    Teacher(string name, int age, string subject, string id) : Person(name, age)
    {
        this->id = id;
        this->sub = subject;
    }
    ~Teacher()
    {
        cout << "Destructor destroy the properties of teacher object...\n";
    }
    void set_id(string n)
    {
        id = n; // here id is properties of class
    }
    string get_id()
    {
        return id; // property
    }

    void set_subject(string n)
    {            // Here subject is function name
        sub = n; // here sub is properties of class
    }
    string get_subject()
    {
        return sub; // sub is property
    }
    void input_teacher();
    void show_info_classteacher();
};
void Student ::show_info()
{
    cout << "\n--- Student INFO ---\n";
    cout << "Name is " << get_name() << endl;
    cout << "His age is " << get_age() << endl;
    cout << "Grade is " << get_grade() << endl;
    cout << "Roll_no is " << get_rollno() << endl;
}

void Teacher ::show_info_classteacher()
{
    cout << "\n--- Teacher INFO ---\n";
    cout << "class teacher id is: " << get_id() << endl;
    cout << "Class teacher subject is :\n"
         << get_subject() << endl;
}

void Student::input_student()
{
    string name, grade;
    int rollno, age;
    cout << "\nEnter Student name:";
    getline(cin, name);
    set_name(name);

    cout << get_name() << " age:";
    cin >> age;
    set_age(age);

    cout << get_name() << " grade:";
    cin >> grade;
    set_grade(grade);

    cout << get_name() << " roll number:";
    cin >> rollno;
    set_rollno(rollno);
}
void Teacher::input_teacher()
{
    string id, subject, name;
    int age;
    cout << "\nEnter Teacher name:";
    cin.ignore();
    getline(cin, name);
    set_name(name);

    cout << get_name() << " age:";
    cin >> age;
    set_age(age);

    cout << "Enter teacher id:";
    cin >> id;
    set_id(id);

    cout << "Enter Teacher subject: ";
    cin.ignore();
    getline(cin, subject);
    set_subject(subject);
}
int main()
{

    Student s1;
    Teacher t1;
    // Input
    s1.input_student();
    s1.show_info();

    t1.input_teacher();
    t1.show_info_classteacher();

    // Functions
    // show_info(age, name, grade, rollno);  //it will invoke my constructor
    // show_info_classteacher(subject, id);

    return 0;
}
