#include <iostream>

int mult_add(int a, int b, int& times)
{
    int sum = a + b;
    times = a * b;

    return sum;
}

int main()
{

    int a;
    int b;
    int sum = 0;
    int times = 0;
    int& mult = times;

    std::cout << "Please enter an integer: ";
    std::cin >> a;
    std::cout << "Please enter another integer: ";
    std::cin >> b; 

    sum = mult_add(a, b, mult);

    std::cout << "The Sum of the numbers: " << sum << std::endl;
    std::cout << "The mult of the numbers: " << times << std::endl;

    return 0;
}