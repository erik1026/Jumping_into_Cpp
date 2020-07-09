#include <iostream>

void create_mult_tables(int length, int width, int height);
void print_table(int** tables, int length, int width);

int main()
{
    int length;
    int width;
    int height;
    std::cout << "What is the length of the 3 dimensional array? ";
    std::cin >> length;

    std::cout << "What is the width? ";
    std::cin >> width;

    std::cout << "What is the height? ";
    std::cin >> height;

    create_mult_tables(length, width, height);

    return 0;
}


//  Creates the multiplication tables themselves
void create_mult_tables(int length, int width, int height)
{
    //  Create the "Height" of the 3d arrays
    int*** ptr_ptr_ptr_mult = new int**[height];

    //  Create the individual multiplication tables
    for (int i = 0; i < height; i++) 
    {   
        ptr_ptr_ptr_mult[i] = new int*[length];

        for(int j = 0; j < length; j++)
        {
            ptr_ptr_ptr_mult[i][j] = new int[width];
        }
    }

    // Populate the multipliocation tables
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < length; j++)
        {
            for(int k = 0; k < width; k++)
            {
                ptr_ptr_ptr_mult[i][j][k] = (j+1)*(k+1);
            }
        }
    }

    //  Print out each mulitplication table
    for (int i = 0; i < height; i ++)
    {
        print_table(ptr_ptr_ptr_mult[i], length, width);
    }

    delete[] ptr_ptr_ptr_mult;
}

void print_table(int **mult_table, int length, int width)
{
    for(int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << mult_table[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}
