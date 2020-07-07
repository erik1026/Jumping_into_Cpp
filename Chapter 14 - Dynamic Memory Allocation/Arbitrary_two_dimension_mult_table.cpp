#include <iostream>

int** create_mult_table(int number);
void print_table(int **mult_table, int number);

int main()
{
    int number_of_rows;
    std::cout << "Enter the number of rows for the multiplication table: ";
    std::cin >> number_of_rows;
    
    int **mult_table;
    mult_table = create_mult_table(number_of_rows);
    print_table(mult_table, number_of_rows);

    delete[] mult_table;
    mult_table = NULL;

    return 0;
}

int** create_mult_table(int number)
{
    //  Create the pointers to the rows
    int **ptr_ptr_mult = new int*[number];

    //  Create the arrays for each row
    for (int i = 0; i < number; i++)
    {
        ptr_ptr_mult[i] = new int[number];
    }

    //  Time to populate the rows with values
    for(int i = 0; i < number; i++)
    {
        for(int j = 0; j < number; j++)
        {
            ptr_ptr_mult[i][j] = (i+1)*(j+1);
        }
    }
    return ptr_ptr_mult;
}

void print_table(int **mult_table, int number)
{
    for(int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            std::cout << mult_table[i][j] << " ";
        }
        std::cout << "\n";
    }
}