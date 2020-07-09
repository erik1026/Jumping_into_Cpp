#include <iostream>
#include <string>
//  This program creates a list of friends and the last time that you talked to them, recorded in days
//  It is supposed to also sort the list by asscending days

enum Options
{
    add = 'A',
    print = 'P',
    display = 'D',
    exit_program = 'E'
};

struct Friend
{
    std::string name = "";
    int day_since_last_spoke = 0;
};

void add_friend(Friend* &list, int &size);  //  Add a friend to the list
void sort_list(Friend* list, int size);   //  Sort the friends list by the days since you last spoke
void swap(Friend *xp, Friend *yp);  //  Swap the two people in the list
void print_list(Friend* list, int size);  //  Print the friends list
void display_options(); //  Display the options to the user

int main()
{
    //  Users option choices:
    //  A: Add a friend
    //  P: Print the list of friends
    //  E: Exit the program
    //  D: Display the options 
    
    //  Initialize the friends list with 10 slots
    int size = 1;
    Friend* list = new Friend[size];

    char option;
    std::cout << "Select an option:\n"<< "A: Add a friend\n" << "P: Print the friends list\n" << "D: Display options\n" << "E: Exit the program\n" << "Option: ";
    std::cin >> option;

    while(option != exit_program)
    {
        switch (option)
        {
        case add:
            std::cout << "User selected to add a friend." << std::endl;
            add_friend(list, size);
            break;
        
        case print:
            std::cout << "User selected to print the friends list" << std::endl;
            print_list(list, size);
            break;
        
        case display:
            std::cout << "User selected to display the options" << std::endl;
            display_options();
            break;
        
        default:
            std::cout << "An invalid option was entered. Please re-enter. ";
            break;
        }
        std::cout << "Enter another option: ";
        std::cin >> option;
    }

    std::cout << "\nExiting program" << std::endl;

    return 0;
}

void add_friend(Friend* &list, int &size)
{
    std::string name;
    int days;
    Friend* tmp;
    bool slot_found = true;
    for (int i = 0; i < size; i++)
    {
        if (list[i].name == "")
        {
            std::cout << "Enter your friend's name: ";
            std::cin >> name;
            std::cout << "Enter the number of days since you last spoke: ";
            std::cin >> days;
            while(days < 0)
            {
                std::cout << "Days since you last spoke must be a positive number of zero. Re-enter: ";
                std::cin >> days;
            }
            list[i].name = name;
            list[i].day_since_last_spoke = days;
            break;    
        }
        else
        {
            slot_found = false;
        } 
    }

    if(slot_found == false)
    {
        Friend* temp = new Friend[size*2];
        for (int j = 0; j < size; j++)
        {
            temp[j].name = list[j].name;
            temp[j].day_since_last_spoke = list[j].day_since_last_spoke;
        }
        std::cout << "Enter your friend's name: ";
        std::cin >> name;
        std::cout << "Enter the number of days since you last spoke: ";
        std::cin >> days;
        while(days < 0)
        {
            std::cout << "Days since you last spoke must be a positive number of zero. Re-enter: ";
            std::cin >> days;
        }
        temp[size].name = name;
        temp[size].day_since_last_spoke = days;
        size = size*2;
        list = temp;
        delete temp;
    }
    sort_list(list, size);
}

void sort_list(Friend* list, int size)
{
    int length = 0;
    for(int k = 0; k < size; k ++)
    {
        if(list[k].name != "")
        {
            length++;
        }
    }

    int smallest;
    for (int i = 0; i < length-1; i++)
    {
        smallest = i;
        for(int j = i+1; j < length; j++)
        {
            if(list[j].day_since_last_spoke < list[smallest].day_since_last_spoke)
            {
                smallest = j;
            }
        }
        swap(&list[smallest], &list[i]);
    }
}

void swap(Friend *xp, Friend *yp)
{
    Friend tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

void print_list(Friend* list, int size)
{
    std::cout << "\n";
    for(int i = 0; i < size; i++)
    {
        std::cout << "Name: " << list[i].name << "\t |\tDays since we last spoke: " << list[i].day_since_last_spoke << std::endl;
    }
    std::cout << "\n";
}

void display_options()
{
    std::cout << "A: Add a friend\n" << "P: Print the friends list\n" << "D: Display options" << "E: Exit the program\n" << std::endl;
}