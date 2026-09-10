#include <iostream>
#include <fstream>

using namespace std;

struct inventory_data
{
    int recordNo;
    string toolName;
    int quantity;
    double cost;
};

void menu();
void writeData();
void readData();

int main()
{
    menu();
    return 0;
}
void menu()
{
    int choice = -1;
    while (choice != 0)
    {
        cout << "\n Enter (int)choice (1. Write_Data   2.Read_Data): ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exit...\n";
            exit();
        case 1:
            writeData();
            break;
        case 2:
            readData();
            break;
        default:
            cout << "Invalid number\n";
            break;
        }
    }
}

void writeData()
{
    inventory_data data;
    ofstream file("inventory_data", ios::app);

    if (file.is_open())
    {
        cout << "Enter recordNo: ";
        cin >> data.recordNo;
        cout << "Enter toolName: ";
        getline(cin >> ws, data.toolName);
        cout << "Enter quantity: ";
        cin >> data.quantity;
        cout << "Enter cost: ";
        cin >> data.cost;

        file << data.recordNo << ","
             << data.toolName << ","
             << data.quantity << ","
             << data.cost << "\n";

        file.close();
    }
    else
        cout << "File not Openend\n";
}
void readData()
{
    string line;
    ifstream in("inventory_data");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            cout << line << "\n";
        }
        in.close();
    }
    else
        cout << "File not opened\n";
}