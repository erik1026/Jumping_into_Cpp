#include <iostream>
#include <cstdlib>

enum coin{
    heads = 0,
    tails = 1
};

void flip(int num_of_flips);

int main()
{
    int num_of_flips;
    std::cout << "Time to simiulate a coin flip!" << std::endl;
    std::cout << "Enter the number of coin flips: ";
    std::cin >> num_of_flips;

    // Pass in the number of flips into 
    flip(num_of_flips);
}

void flip(int num_of_flips)
{
    for (int i =0; i < num_of_flips; i++){
        int side_of_coin = rand() % 2;
        switch (side_of_coin)
        {
        case heads:
            std::cout << "Heads!" << std::endl;
            break;
        case tails:
            std::cout << "Tails!" << std::endl;
            break;
        default:
            std::cout << "How did we even get here??" << std::endl;
            break;
        }
    }
}