#include <iostream>
int summation(int start, int end);
int Power(int value, int Power);
int main()
{
    int value, upto, start, end;
    std::cout << "Enter starting value: ";
    std::cin >> start;
    std::cout << "Enter ending value: ";
    std::cin >> end;

    std::cout << "This is the summation: " << summation(start, end) << std::endl;

    return 0;
}
int summation(int start, int end)
{
    int sum = 0;
    int num = start;

    for (int i = 0; i < end; i++)
    {
        sum += num * num;
        num++;
    }
    return sum;
}
int Power(int value, int Power) // to find power of value
{
    int constant = value;
    int total = value;
    for (int i = 1; i <= Power; i++)
    {
        total = total * constant;
    }
    return total;
}
