#include <iostream>
using namespace std;

class TollBooth
{
    string shift;
    string collector_name;
    double totalcash;

public:
    static int totalcars; // by default it is asinged to 0
    int type;             // vehcle type

    TollBooth()
    {
        totalcash = 0;
    }
    void set_name(string name)
    {
        collector_name = name;
    }
    string get_name()
    {
        return collector_name;
    }
    void set_shift(string shift)
    {
        this->shift = shift;
    }
    string get_shift()
    {
        return shift;
    }
    bool payingcar();
    void nopaycar();
    void report();
    void inputCarType();
    void vehcleType();
    void Rates_chart();
    void choice();
};
int TollBooth::totalcars;

bool TollBooth ::payingcar()
{

    ++totalcars;
}
void TollBooth ::nopaycar()
{
    ++totalcars;
    totalcash = totalcash; // remain same
}

void TollBooth ::report()
{
    cout << "\n====== Toll Booth Report ======\n";
    cout << "Collector name: : " << get_name() << endl;
    cout << "Shift: : " << get_shift() << endl;
    cout << "Total cash: " << totalcash << endl;
    cout << "Total cars: " << totalcars << endl;
    cout << "Average tax on every car: " << totalcash / totalcars << endl;
}
void TollBooth ::vehcleType()
{
    cout << "Enter vechile (e.g:1. car,2. truck,3. bus): ";
    cin >> type;
}
void TollBooth ::Rates_chart()

{

    cout << "Bike Parking--------->0.00 rs/-\n";
    cout << "Car Parking---------->0.35 rs/-\n";
    cout << "Vagonn-------->0.45 rs/-\n";
    cout << "Bus---------->0.50 rs/-\n";
    cout << "Truck-------->0.80 rs/-\n";
    cout << "Others------->0.15 rs/-\n";
}

void TollBooth ::inputCarType()
{

    if (type == 1)
    {
        totalcash += 0.00;
    }
    else if (type == 2)
    {
        totalcash += 0.35;
    }
    else if (type == 3)
    {
        totalcash += 0.45;
    }
    else if (type == 4)
    {
        totalcash += 0.50;
    }
    else if (type == 5)
    {
        totalcash += 0.80;
    }
    else if (type == 6)
    {
        totalcash += 0.15;
    }
    else
    {
        totalcash += 0;
    }
}

void TollBooth ::choice()
{

    cout << "Enter: " << endl
         << "0.  Exit\n1.  Bike\n2.  Car\n3.  Vagon\n4.  Bus\n5.  Truck\n6.  Others\n->";
    cin >> type;

    while (type != 0)
    {
        if (payingcar())
        {
            inputCarType();
            cout << "Enter next (0 to exit): ";
            cin >> type;
        }
        else
        {
            return;
        }
    }
}
int main()
{
    string name;
    string shift;
    cout << "Enter collector name: ";
    getline(cin, name);

    cout << "Enter shift: ";
    cin >> shift;

    // object
    TollBooth tool1, tool2, tool3; // total 3 tools on motorway
    // This code will calculate all day charges of all 3 tolls
    cout << "Enter collector name: "; // Enter collector name
    tool1.set_name(name);
    cout << "Enter shift: "; // shift e.g: Morning, Afternoon, Evening, night
    tool1.set_shift(shift);
    tool2.Rates_chart();
    tool2.choice();

    cout << "Enter details in 2 Toll: " << endl;

    tool2.Rates_chart();
    tool2.choice();
    tool2.report();

    cout << "Enter details in 3 Toll: " << endl;
    tool3.Rates_chart();
    tool3.choice();
    tool3.report();

    return 0;
}
