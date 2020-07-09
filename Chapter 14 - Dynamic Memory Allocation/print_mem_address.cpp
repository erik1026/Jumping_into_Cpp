#include <iostream>

int main()
{
    int size = 3;
    //  Create the 2 dimensional array
    //  Populate it with zeros
    // Array is of size 3x3
    int** array = new int*[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = new int[size];
    }

    for (int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            array[i][j] = 0;
        }
    }

    //  Print out the memory address of each value in the array
    for (int i = 0; i < size; i ++)
    {
        for(int j = 0; j < size; j++)
        {
            std::cout << &array[i][j] << "\t";
        }
        std::cout << "\n";
    }

    return 0;
}