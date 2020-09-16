#include <iostream>

int pow(int x, int y);

int main ()
{
    
    std::cout << pow(2, -5) << std::endl;
    return 0;
}

//  Use recursion to computer x^y
int pow(int x, int y)
{
    if(y == 0)
    {
        return 1;
    }
    else if (y < 0)
    {
        std::cout << "Negative exponent!!" << std::endl;
        return -1;
    }
    return x*pow(x, y-1);
}