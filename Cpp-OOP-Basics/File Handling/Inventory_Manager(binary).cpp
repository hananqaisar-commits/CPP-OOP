#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct inventory_data
{
    int recordNo;
    char toolName[100]; // we can use string directly for binary files
    int quantity;
    double cost;
};

void menu();
bool writeData();
void sampleData();
void readData();
void deleteData();
void updateData();

int main()
{

    menu();
    return 0;
}

void menu()
{
    cout << "\n===== Inventory Manager =====\n";
    int choice = -1;
    while (choice != 0)
    {
        cout << "Enter (int)choice \n\t1.Write_Data\n\t2.List_Data\n\t3.Sample Data\n\t4.Delete Data\n\t5.Update Data\n\t0.Exit: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exit...\n";
            return;
        case 1:
            if (writeData())
            {
                cout << "Data written";
            }
            else
                sampleData();
            break;
        case 2:
            readData();
            break;
        case 3:
            sampleData();
            break;
        case 4:
            deleteData();
            break;
        case 5:
            updateData();
            break;
        default:
            cout << "Invalid number\n";
            break;
        }
    }
}
void sampleData()
{
    inventory_data emptyData = {0, "", 0, 0.0};
    ofstream out("inventory_data.dat", ios::binary);

    if (out)
    {
        for (int i = 0; i < 100; i++)
        {
            out.write(reinterpret_cast<char *>(&emptyData), sizeof(inventory_data));
        }
        out.close();
    }
    else
        cout << "File not opened\n";

    cout << "\n100 Empty rows entered\n";
}
bool writeData()
{

    fstream file("inventory_data.dat", ios::binary | ios::in | ios::out);
    inventory_data data;
    if (file.is_open())
    {
        int recordNo;
        cout << "Enter recordNo(1-100): ";
        cin >> recordNo;
        if (recordNo >= 1 && recordNo <= 100)
            data.recordNo = recordNo;
        else
            cout << "Invalid range\n";

        cout << "Enter toolName: ";
        cin >> ws;
        cin.getline(data.toolName, 100);
        cout << "Enter quantity: ";
        cin >> data.quantity;
        cout << "Enter cost: ";
        cin >> data.cost;

        file.seekp((data.recordNo - 1) * sizeof(inventory_data));            // to move pointer in bytes in writing to .dat file
        file.write(reinterpret_cast<char *>(&data), sizeof(inventory_data)); // now write in that line in which the writing pointer is moved to
        file.close();                                                        // close the file to save resources
        cout << "Successful!\n";
    }
    else
    {
        cout << "File not Opened\n";
        return false;
    }
    return true;
}
void readData()
{
    ifstream in("inventory_data.dat", ios::binary);
    inventory_data data;
    while (in.read(reinterpret_cast<char *>(&data), sizeof(inventory_data))) // reference of data and cast it into char pointer
    {
        cout << data.recordNo << "," << data.toolName << "," << data.quantity << "," << data.cost << "\n";
    }
}
void deleteData()
{

    fstream fileDlt("inventory_data.dat", ios::in | ios::out);
    inventory_data dltData;

    int recordNoDlt;
    cout << "Enter recordNo to delete(1-100): ";
    cin >> recordNoDlt;
    if (recordNoDlt >= 1 && recordNoDlt <= 100)
        dltData.recordNo = recordNoDlt;
    else
        cout << "Invalid range\n";

    strcpy(dltData.toolName, "");
    dltData.recordNo = 0;
    dltData.quantity = 0;
    dltData.cost = 0.0;

    fileDlt.seekp((recordNoDlt - 1) * sizeof(inventory_data));
    fileDlt.write(reinterpret_cast<char *>(&dltData), sizeof(inventory_data));
    cout << "Deleted!";
}

void updateData()
{

    fstream file("inventory_data.dat", ios::binary | ios::in | ios::out);
    inventory_data updData;
    if (file.is_open())
    {

        int recordNo;
        cout << "Enter recordNo(1-100): ";
        cin >> recordNo;
        if (recordNo >= 1 && recordNo <= 100)
            updData.recordNo = recordNo;
        else
            cout << "Invalid range\n";

        // first we have to read the already stored data by moving the reading pointer to the recordNo
        file.seekg((updData.recordNo - 1) * sizeof(inventory_data));
        file.read(reinterpret_cast<char *>(&updData), sizeof(inventory_data));

        int columnNo;
        cout << "which column value:\n\t0.Back\n\t1.Tool Name\n\t2.Quantity\n\t3.Cost: ";
        cin >> columnNo;
        switch (columnNo)
        {
        case 0:
            menu();
        case 1:
            cout << "Update toolName: ";
            cin >> ws;
            cin.getline(updData.toolName, 100);

            break;
        case 2:
            cout << "Update quantity: ";
            cin >> updData.quantity;
            break;
        case 3:
            cout << "Update cost: ";
            cin >> updData.cost;
            break;
        }

        file.seekp((updData.recordNo - 1) * sizeof(inventory_data));            // to move pointer in bytes in writing to .dat file
        file.write(reinterpret_cast<char *>(&updData), sizeof(inventory_data)); // now write in that line in which the writing pointer is moved to
        file.close();                                                           // close the file to save resources
        cout << "Successfully Updated!\n";
    }
    else
        cout << "File not Opened\n";
}