#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    int accNo;
    string name;
    int balance;

public:
    BankAccount(int account, string name, int balance)
    {
        accNo = account;
        this->name = name;
        this->balance = balance;
    }
    void deposit(int deposit)
    {
        if (deposit <= 0)
        {
            cout << "Sorry! This amount is not deposited" << endl;
        }
        else
        {
            balance += deposit;
            cout << "You deposit " << deposit << " rs sucessfully" << endl;
        }
    }
    void withdraw(int withdraw)
    {
        if (withdraw > balance)
        {
            cout << "Sorry! " << withdraw << " amount is not in your account" << endl;
        }
        else
        {
            cout << withdraw << " rs is withdraw sucessfully" << endl;
            balance -= withdraw;
        }
    }
    void check()
    {

        char ch;
        cout << "Want to check account balance?((y or n): )" << endl;
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
        {
            cout << "Your balance is :" << balance << endl;
        }
        else if (ch == 'N' || ch == 'n')
        {
            cout << "Thanks for using ATM" << endl;
        }
        else
            cout << "Enter valid choice:" << endl;
    }
    void display()
    {
        cout << "Account Owner: " << name << endl;
        cout << "Account id " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
    void choice(int n)
    {
        int depositAmount;
        int withdrawAmount;
        switch (n)
        {

        case 1:
            cout << "Enter amount to deposit: ";
            cin >> depositAmount;
            deposit(depositAmount);
            break;
        case 2:
            cout << "Enter amount to Withdraw: ";
            cin >> withdrawAmount;
            withdraw(withdrawAmount);
            break;
        case 3:
            check();
            break;
        case 4:
            display();
            break;
        case 5:
            break;

        default:
            cout << "Enter valid choice" << endl;
        }
    }
};

int main()
{
    int choice;
    BankAccount account1(1198, "Hanan Qaisar", 10000.89);
    cout << "Choose one option:" << endl
         << "1. Deposit" << endl
         << "2. Withdraw" << endl
         << "3. Check Balabnce" << endl
         << "4. Display detail" << endl
         << "5. End" << endl;
    cin >> choice;
    while (choice != 5)
    {
        account1.choice(choice);
        cout << "Choose one option:" << endl
             << "1. Deposit" << endl
             << "2. Withdraw" << endl
             << "3. Check Balabnce" << endl
             << "4. Display detail" << endl
             << "5. End" << endl;
        cin >> choice;
    };

    return 0;
}