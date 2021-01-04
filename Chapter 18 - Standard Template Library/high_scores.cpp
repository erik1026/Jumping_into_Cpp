#include <iostream>
#include <vector>   //  Container storing the high scores
#include <algorithm>    // Sorts the vector of high scores
#include <tuple>
#include <string>

void print(std::vector< std::tuple<std::string, int> > &high_scores)
{
    std::cout << "\n";
    for(auto& score : high_scores)
    {
        std::cout << std::get<0>(score) << ": " << std::get<1>(score) << "\n";
    }
    std::cout << "\n";
}

void insert(std::vector< std::tuple<std::string, int> > &high_scores)
{
    std::string user_name;
    int user_score = 0;
    
    std::cout << "Enter Name for high score: ";
    std::cin >> user_name;
    std::cout << "Enter Score: ";
    std::cin >> user_score;
    std::cout << "\n";
    auto exists = std::find_if(high_scores.begin(), high_scores.end(), [user_name](std::tuple<std::string, int> new_score)
    {
        if (std::get<0>(new_score) == user_name)
        {
            return true;
        }
        else
        {
            return false;
        }
    });

    if(exists != high_scores.end())
    {
        std::get<1>(high_scores.at(std::distance(high_scores.begin(), exists))) = user_score;
    }
    else
    {
        high_scores.push_back(std::make_tuple(user_name, user_score) );
    }

    std::sort(high_scores.begin(), high_scores.end(), [](std::tuple<std::string, int> score_one, std::tuple<std::string, int> score_two)
    {
        return std::get<1>(score_one) >= std::get<1>(score_two);
    });
}

int main(int argc, char* argv[])
{
    std::vector< std::tuple<std::string, int> > high_scores;
    int user_input = 0;

    while(user_input != 3)
    {
        std::cout << "Please select one of the following options:\n1. Insert a new high score\n2. Print the list of high scores\n3. End Program\n";
        std::cin >> user_input;
        std::cout << "\n";
        switch(user_input)
        {
            case 1 :
                insert(high_scores);
                break;
            case 2: 
                print(high_scores);
                break;
            case 3:
                std::cout << "Exiting Program\n";
                break;
            default:
                std::cout << "Please re-enter a valid option\n";
        }
    }


    return 0;
}