// Slot's machine
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

enum matches{
    nothing = 0,
    ones = 1,
    twos = 2,
    threes = 3
};

enum user_input{
    spin = 'S',
    quit = 'X'
};

int random()
{
    srand(time(NULL));
    return rand() % 3 + 1;
}

void print_slots(int slot_one, int slot_two, int slot_three)
{
    std::cout << "Wheel 1\t" << "Wheel 2\t" << "Wheel 3" << std::endl;
    std::cout << slot_one << "\t" << slot_two << "\t" << slot_three << std::endl; 
}

int compare(int wheel1, int wheel2, int wheel3)
{
    print_slots(wheel1, wheel2, wheel3);
    int score = 0;
    int match = 0;

    if (wheel1 == wheel2)
    {
        if (wheel2 == wheel3)
        {
            match = wheel1;
        }
    }
    else 
    {
        match = 0;
    }

    switch(match)
    {
        case nothing:
            std::cout << "No matches :(\n" << std::endl;
            break;
        case ones:
            std::cout << "You have matching 1's!\n" << std::endl;
            score = 100;
            break;
        case twos:
            std::cout << "You have matching 2's!\n" << std::endl;
            score = 200;
            break;
        case threes:
            std::cout << "You have matching 3's!\n" << std::endl;
            score = 300;
            break;
        default:
            std::cout << "Great...You broke the machine!\n" << std::endl;
            break;
    }
    return score;
}

int main()
{
    char input = ' ';
    int wheel1;
    int wheel2;
    int wheel3;
    int score = 0;
    std::cout << "------------Time to play slots!------------" << std::endl;
    std::cout << "To take a turn enter the 'S' key for: Spin. Enter an 'X' to quit" << std::endl;
    
    while(input != 'X')
    {
        std::cout << "Take a spin?: ";
        std::cin >> input;
        switch (input){
            case spin:
                wheel1 = random(); wheel2 = random(); wheel3 = random();
                score += compare(wheel1, wheel2, wheel3);
                break;
            case quit:
                std::cout << "\nYour total winnings: " << score << std::endl;
                std::cout << "Thanks for playing!" << std::endl; 
                break;
            default:
                std::cout << "Entered an invalid character. Please re-enter: ";
                std::cin >> input;
                break;
        }
    }
    
}