#include <iostream>
#include <string>
using namespace std;

class SecurityLog
{
private:
    string id;
    string timeStamp;

public:
    void takeinput();
    void Analyze();
    void Display();
};

class LoginLog : public SecurityLog
{
public:
};
class NetworkLog : public SecurityLog
{
public:
};
class SystemErrorLog : public SecurityLog
{
public:
};
void SecurityLog ::takeinput()
{
    int choice;
    switch (choice)
    {
    case 0:
        exit;
        break;
    case 1:
        LoginLog();
        break;
    case 2:
        NetworkLog();
        break;
    case 3:
        SystemErrorLog();
        break;
    case 4:
        Analyze();
    case 5:
        Display();
    default:
        break;
    }
}
int main()
{

    return 0;
}