#include <iostream>
#include <string>
using namespace std;

class Account
{

    string accountNumber; // by default it will be 0 if i will not explicitly change it before main programme
    string holderName;
    double balance;

public:
    Account(string accountNumber, string holderName, double balance) // constructor
    {
        this->accountNumber = accountNumber;
        this->holderName = holderName;
        this->balance = balance;
    }

    static int countAcoount; // by default it will be 0 if i will not explicitly change it before main programme

    virtual void deposit();
    virtual void withdraw();
    virtual void display();
    virtual int calculateIntrest();
    virtual ~Account() {} // virtual destructor
};

class SavingAccounts : public Account
{
    int intrestRate = 11;

public:
    SavingAccounts(string accountNumber, string holderName, double balance, int intrestRate) : Account(accountNumber, holderName, balance)
    {
        this->intrestRate = intrestRate;
    }
};
class CurrentAccount : public Account
{
    int overDraft = 1000000;

public:
};
void Account::deposit()
{
    int depositAmount;
    cout << "Enter amount to deposit: ";
    cin >> depositAmount;
    if (depositAmount > 0)
    {
        cout << depositAmount << " rupees deposit sucessfully" << endl;
    }
    else
    {
        balance += depositAmount;
        cout << "Transaction failed" << endl;
    }
}
void Account::withdraw()
{
    int withdrawAmount;
    cout << "Enter amount to withdraw: ";
    cin >> withdrawAmount;
    if (withdrawAmount < balance)
    {
        balance -= withdrawAmount;
        cout << withdrawAmount << " rupees withdraw sucessfully" << endl;
    }
    else
    {
        cout << "Balance is not available" << endl;
    }
}
void Account::display()
{
    cout << "\nTotal Account exists: " << countAcoount << endl;
    cout << "Acount owner is: " << holderName << endl;
    cout << "Acount id is: " << accountNumber << endl;
    cout << "Available balance is: " << balance << endl;
}
int Account::calculateIntrest()
{
    float intrest;
    intrest = balance * 0.11;
    return intrest;
}

int Account::countAcoount = 1; // static varialble here i initilized it with 1.Explicitly.
int main()
{
    SavingAccounts *C1 = new SavingAccounts("HQ1493", "Hanan Qaisar", 1000.00, 11);
    SavingAccounts *C2 = new SavingAccounts("AQ42323", "Ahtisham Qaisar", 1056.00, 17);
    C1->deposit();
    C1->withdraw();
    C1->display();

    C2->deposit();
    C2->withdraw();
    C2->display();

    return 0;
}