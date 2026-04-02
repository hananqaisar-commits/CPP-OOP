#include <iostream>
#include <fstream>
#include <string>

void print(std::string name, int age); // declaration

int main()
{
    std::string name;
    int age;

    std::cout << "=======Welcome=======\n";

    std::cout << "Enter name: ";
    getline(std::cin, name);

    std::cout << "Enter age: ";
    std::cin >> age;

    print(name, age);

    // Writing
    std::ofstream outfile("Record.txt");

    if (!outfile)
    {
        std::cout << "Error opening file\n";
        return 1;
    }

    outfile << name << std::endl;
    outfile << age << std::endl;

    outfile.close();

    // Reading
    std::ifstream infile("Record.txt");

    if (!infile)
    {
        std::cout << "Error reading file\n";
        return 1;
    }

    std::string line;

    while (std::getline(infile, line))
    {
        std::cout << line << std::endl;
    }

    infile.close();

    return 0;
}

void print(std::string name, int age)
{
    std::cout << "Name: " << name << " Age: " << age << std::endl;
}