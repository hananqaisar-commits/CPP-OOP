#include <iostream>
#include <string>
using namespace std;

class Account
{
    string accountNumber = "HQ1493"; // by default it will be 0 if i will not explicitly change it before main programme
    string holderName = "Hanan Qaisar";
    double balance = 0;

public:
    Account(string accountNumber, string holderName, double balance) // constructor
    {
        this->accountNumber = accountNumber;
        this->holderName = holderName;
        this->balance = balance;
    }

    static int countAcoount;
    virtual void deposit();
    virtual void withdraw();
    virtual void display();
    virtual int calculateIntrest();
    virtual ~Account(){} // virtual destructor
};

class SavingAccounts : public Account
{
    int intrestRate = 11;

public:
    SavingAccounts(string accountNumber, string holderName, double balance, int intrestRate) : Account(accountNumber, holderName, balance, intrestRate)
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
    cout<<"Enter amount to deposit: ";
    cin>>depositAmount;
    if (depositAmount > 0)
    {
        cout << depositAmount << " rupees deposit sucessfully" << endl;
    }
    else{
        cout<<"Transaction failed"<<endl;
    }
}
void Account::withdraw() 
{
    int withdrawAmount;
    if (withdrawAmount<balance)
    {
        cout<<withdrawAmount<<" rupees withdraw sucessfully"<<endl;
    }
    else{
        cout<<"Balance is not available"<<endl;
    }
}
void Account::display() 
{
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
    C1->deposit();
    C1->withdraw();
    C1->display();

    return 0;
}