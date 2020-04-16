// Number guessing but the computer guesses instead
#include <iostream>
#include <cstdlib>
#include <ctime>

enum result_of_guess{
    low = -1,
    high = 1,
    correct = 0,
};

int random()
{
    srand(time (NULL));
    int whats_the_number = (rand() % 100) + 1;

    return whats_the_number;
}

int guess(int low, int high)
{
    srand(time(NULL));
    int range = low - high;
    int compooters_guess = (rand() % (range+2)) + low;
    
    return compooters_guess; 
}

int compare(int generated, int guess)
{
    int result; 
    if (guess < generated){
        result = -1;
    } 
    else if (guess > generated) 
    {
        result = 1;
    }
    else if (guess == generated)
    {
        result = 0;
    }

    return result;
}

int main()
{
    int number_of_guesses = 0;
    int result = 45;
    int top = 100;
    int bottom = 1;
    bool is_correct = false;

    std::cout << "Time to make the computer guess the number!" << std::endl;
    int number = random();
    
    while(!is_correct)
    {
        int compooter_guess = guess(bottom, top);
        number_of_guesses ++;
        int result = compare(number, compooter_guess);
        switch(result){
            case low:
                std::cout << "The guess was too low!" << std::endl;
                bottom = compooter_guess + 1;
                break;
            case high:
                std::cout << "The guess was too high!" << std::endl;
                top = compooter_guess - 1;
                break;
            case correct:
                std::cout << "The computer took " << number_of_guesses << " guesses!" << std::endl;
                std::cout << "The correct guess was: " << compooter_guess << std::endl;
                is_correct = true;
                break;
            default:
                std::cout << "How did we get here?!" << std::endl;
                break;
        } 
    }

    return 0;
}