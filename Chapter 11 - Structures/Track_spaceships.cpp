#include <iostream>
#include <ctime>
#include <cstdlib>

struct ship{
    int x_coordinate;
    int y_coordinate;
    bool off_screen = false;
};

void create_ships(ship array [], int size, int x, int y)
{
    srand(time(NULL));
    for(int i = 0; i < size; i++)
    {
        array[i].x_coordinate = rand() % int(x/2);
        array[i].y_coordinate = rand() % int(y/2);       
    }
}

void is_the_ship_off_screen(ship array [], int size, int x_size, int y_size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i].x_coordinate > x_size)
        {
            array[i].off_screen = true;
        }
        else if(array[i].y_coordinate > y_size)
        {
            array[i].off_screen = true;
        }
    }
}

void move_ships(ship array[], int size)
{
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        if(array[i].off_screen == false)
        {
            array[i].x_coordinate = array[i].x_coordinate + (rand() % 50);
            array[i].y_coordinate = array[i].y_coordinate + (rand() % 50);
        }
    }
}

bool all_off_screen(ship array[], int size)
{
    bool all_off_screen = true;
    for(int i = 0; i < size; i++)
    {
        if(array[i].off_screen == false)
        {
            all_off_screen = false;
            return all_off_screen;
        }
    }
    
    return all_off_screen;
}

int main()
{
    bool off_screen = false;
    std::cout << off_screen << std::endl;
    int x_axis = 1024;
    int y_axis = 768;
    int const number_of_ships = 5;
    ship enemyships [number_of_ships];
    create_ships(enemyships, number_of_ships, x_axis, y_axis);

    while(off_screen == false)
    {
        move_ships(enemyships, number_of_ships);
        is_the_ship_off_screen(enemyships, number_of_ships, x_axis, y_axis);
        off_screen = all_off_screen(enemyships, number_of_ships);
    }
    
    for(int i = 0; i < number_of_ships; i++)
    {
        std::cout << "Ship " << i+1 << "\nX Coordinate: " << enemyships[i].x_coordinate << "\nY Coordinate: " << enemyships[i].y_coordinate << "\nOff Screen : " << enemyships[i].off_screen << std::endl;
    }

    return 0;
}