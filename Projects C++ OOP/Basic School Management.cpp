#include <iostream>
#include <string>
using namespace std;
class person
{
private:
    string name;
    int age;

public:
    // constructor:Parameterized
    person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    ~person()
    {
        cout << "Destructor destroy person object properties...\n";
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

class student : public person
{
private:
    int roll_no;
    float grade;

public:
    // constructor:
    student(string name, int age, float grade, int roll_no) : person(name, age)
    {
        this->grade = grade;
        this->roll_no = roll_no;
    }
    ~student()
    {
        cout << "Destructor destroy the properties of student object...\n";
    }
    void set_rollno(int n)
    {
        roll_no = n;
    }
    int get_rollno()
    {
        return roll_no;
    }
    void set_grade(float n)
    {
        grade = n;
    }
    float get_grade()
    {
        return grade;
    }
};
class teacher : public person
{
private:
    int id;
    string sub; // sub is properties of teacher class
public:
    // constructor:
    teacher(string name, int age, string subject, int id) : person(name, age)
    {
        this->id = id;
        this->sub = subject;
    }
    ~teacher()
    {
        cout << "Destructor destroy the properties of teacher object...\n";
    }
    void set_id(int n)
    {
        id = n; // here id is properties of class
    }
    int get_id()
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
};

void show_info(int age, string name, float grade, int rollno)
{
    cout << "\n--- Student INFO ---\n";
    cout << "Name is " << name << endl;
    cout << "His age is " << age << endl;
    cout << "Grade is " << grade << endl;
    cout << "Roll_no is " << rollno << endl;
}
void show_info_classteacher(string subject, int id)
{
    cout << "\n--- Teacher INFO ---\n";
    cout << "class teacher id is: " << id << endl;
    cout << "Class teacher subject is :\n"
         << subject << endl;
}

int main()
{
    string name;
    string subject;
    int age, rollno, id;
    float grade;
    // Input
    cout << "Enter name:";
    getline(cin, name);
    cout << "Enter age:";
    cin >> age;
    cout << "Enter grade:";
    cin >> grade;
    cout << "Enter roll number:";
    cin >> rollno;
    cout << "Enter teacher id:";
    cin >> id;
    cout << "Enter Teacher subject:";
    cin.ignore();
    getline(cin, subject);

    // Objects with parameterized constructor
    person p1(name, age);
    student s1(name, age, grade, rollno);
    teacher t1(name, age, subject, id);

    // Functions
    show_info(age, name, grade, rollno);
    show_info_classteacher(subject, id);

    return 0;
}