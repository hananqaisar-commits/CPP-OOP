#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    int rollNumber;

    void inputDetail();
    void displayDetail();
};
void Student ::inputDetail()
{
    cin.ignore();
    cout << "\nEnter student name: ";
    getline(cin, name);
    cout << "Enter roll number: ";
    cin >> rollNumber;
}
void Student ::displayDetail()
{
    cout << "\nStudent name :" << name << endl;
    cout << name << " roll number is :" << rollNumber << endl;
}

class Exam : public Student
{
public:
    int subMarks[5] = {0};

    void calculateTotal(int a, int b, int c);
    void calculateTotal(int a, int b, int c, int d, int e);
    double percentage(int subNUm);
    void grade(double percent);
    void displayAll(double percent);
};
void Exam ::calculateTotal(int a, int b, int c)
{

    subMarks[0] = a;
    subMarks[1] = b;
    subMarks[2] = c;
}
void Exam ::calculateTotal(int a, int b, int c, int d, int e)
{

    subMarks[0] = a;
    subMarks[1] = b;
    subMarks[2] = c;
    subMarks[3] = d;
    subMarks[4] = e;
}
double Exam ::percentage(int subNum)
{
    int total = 0;
    for (int i = 0; i < subNum; i++)
    {
        total += subMarks[i];
    }
    if (subNum == 3)
    {
        return (total * 100.0) / 300;
    }
    if (subNum == 5)
    {
        return (total * 100.0) / 500;
    }
}

void Exam ::grade(double percent)
{
    if (percent >= 85)
        cout << name << " has A grade" << endl;
    else if (percent < 85 && percent >= 70)
        cout << name << " has B grade" << endl;
    else if (percent < 70 && percent >= 50)
        cout << name << " has C grade" << endl;
    else if (percent < 50)
        cout << name << " has F grade" << endl
             << "Fail" << endl;
}
void Exam ::displayAll(double percent)
{
    displayDetail();
    cout << "Percentage: " << percent << endl;
    grade(percent);
}
int main()
{
    int studNo; // to store number of student in classroom
    cout << "Enter class strenght: ";
    cin >> studNo;
    Exam student[studNo]; // array of Exam object
    int subNum;
    int subjects[5] = {0};
    double perc; // percentage
    for (int i = 0; i < studNo; i++)
    {
        student[i].inputDetail();

        cout << "Enter number of subjects (3 or 5): ";
        cin >> subNum;

        if (subNum == 3)
        {
            cout << "Enter 3 subject marks: " << endl;
            for (int i = 0; i < 3; i++)
            {
                cout << i + 1 << ". ";
                cin >> subjects[i];
            }
            student[i].calculateTotal(subjects[0], subjects[1], subjects[2]);
        }
        else if (subNum == 5)
        {
            cout << "Enter 5 subject marks: " << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << i + 1 << ". ";
                cin >> subjects[i];
            }
            student[i].calculateTotal(subjects[0], subjects[1], subjects[2], subjects[3], subjects[4]);
        }
        else
        {
            cout << "You type wrong number of subjects" << endl
                 << "Choose correct number of subject" << endl;
            if (i == 0)
            {
                i = 0;
            }
            else
            {
                --i;
            }

            continue;
        }
        perc = student[i].percentage(subNum); // float retun value which is store in perc and passing subNum which is enterd by user 3 or 5
        student[i].displayAll(perc);          // perc is percentage like 76.45 something
    }

    return 0;
}