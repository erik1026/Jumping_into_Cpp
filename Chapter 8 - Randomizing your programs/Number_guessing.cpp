// Number guessing
#include <iostream>
#include <cstdlib>
#include <ctime>

int random()
{
    srand(time (NULL));
    int whats_the_number = (rand() % 100) + 1;

    return whats_the_number;
}

bool compare(int generated, int guess)
{
    bool correct;
    if (guess < 100 && guess > 1)
    {
       if (guess < generated){
            std::cout << "Your guess is too low!\n" << std::endl;
            correct = false;
        } 
        else if (guess > generated) 
        {
            std::cout << "Your guess is too high!\n" << std::endl;
            correct = false;
        }
        else if (guess == generated)
        {
            std::cout << "You guessed correctly!\n" << std::endl;
            correct = true;
        }
    }
    else
    {
        std::cout << "Your guess is out of range!\n" << std::endl;
        correct = false;
    }
    return correct;
}

int main()
{
    int guess;
    bool correct;
    std::cout << "A number between 1-100 will be generated." << std::endl;
    int whats_the_number = random();
    std::cout << "This is the guess: " << whats_the_number << std::endl;
    std::cout << "A number has been chosen, can you guess what it is?" << "\nGuess: ";
    std::cin >> guess;
    correct = compare(whats_the_number, guess);

    while (correct == false)
    {
        std::cout << "Please enter another guess: ";
        std::cin >> guess;
        correct = compare(whats_the_number, guess);
    }

    return 0;
}