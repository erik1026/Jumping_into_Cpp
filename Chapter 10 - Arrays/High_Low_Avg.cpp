#include <ctime>
#include <cstdlib>
#include <iostream>

int high(int array[])
{
    int high = array[0];
    for (int i = 0; i < 50; i++)
    {
        if (array[i] > high)
        {
            high = array[i];
        }
    }
    return high;
}

int low(int array[])
{
    int low = array[0];
    for (int i = 0; i < 50; i++)
    {
        if (array[i] < low)
        {
            low = array[i];
        }
    }
    return low;
}

double average(int array[])
{
    int sum = 0;
    double avg = 0.0;
    for (int i = 0; i < 50; i++)
    {
        sum += array[i];
    }
    avg = sum/50;

    return avg;
}

int main ()
{
    int array [50];
    srand(time(NULL));
    for(int i =0; i < 50; i++)
    {
        array[i] = rand() % 100;
    }
    int highest_value = high(array);
    int lowest_value = low(array);
    double avg = average(array);

    std::cout << "Highest Value: " << highest_value << "\nLowest Value: " << lowest_value << "\nAverage: " << avg << std::endl;


    return 0;
}