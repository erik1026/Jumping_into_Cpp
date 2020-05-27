#include <iostream>

void compare_mem_address(int* first, int* second)
{
    if (first < second)
    {
        std::cout << "The order now: " << *first << " and " << *second << std::endl;
    }
    else
    {
        std::cout << "The order now: " << *second << " and " << *first << std::endl;
    }
}

int main()
{
    int a = 5;
    int* first;
    first = &a;
    int b = 0;
    int* second;
    second = &b;

    std::cout << "The order of initialized variables: " << a << " and " << b << std::endl;

    compare_mem_address(first, second);

    return 0;
}