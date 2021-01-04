#include <map>
#include <string>
#include <iostream>

struct Input 
{
    int add = 1;
    int remove = 2;
    int list = 3;
    int end = 0;
};

bool check_for_entry(std::map<std::string, std::string>& map, std::string key)
{
    auto itr = map.end();
    auto exists = map.find(key);

    //  if map.find returns an iterator to the end, then the key does not exist
    if(exists == itr)
    {
        return false;
    }
    
    return true;
}

void add_entry(std::map<std::string, std::string>& map, std::string key, std::string email)
{
    bool exists = check_for_entry(map, key);

    if(exists)
    {
        std::cout << "Entry already EXISTS in the address book!\n";
        return;
    }
    map.insert( std::pair<std::string, std::string>(key, email) );
}

void remove_entry(std::map<std::string, std::string>& map, std::string key)
{
    bool exists = check_for_entry(map, key);

    if(!exists)
    {
        std::cout << "Entry DOES NOT EXIST in the address book!\n";
        return;
    }
    map.erase(map.find(key));
}

void list_entries(std::map<std::string, std::string>& map)
{

    if(map.empty())
    {
        std::cout << "Address Book is empty!" << std::endl;
        
        return;
    }

    for(auto itr = map.begin(); itr != map.end(); ++itr)
    {
        std::cout << itr->first << ": " << itr->second << "\n";
    }
}

int main(int argc, char* argv[])
{
    std::map<std::string, std::string> address_book;    //  Map that stores names(key) and associated emails(value)
    Input input_struct;
    int input;
    std::string key;
    std::string email;

    std::cout << "Select an Address Book Option:\n1.Add an Entry\n2.Remove an Entry\n3.List all Entries\n0. End Program" << std::endl; 
    std::cin >> input;
    
    while(input != 0)
    {
        if(input == 1)
        {
            std::cout << "Enter Name: " << std::endl;
            std::cin >> key;
            std::cout << "Enter Email: " << std::endl;
            std::cin >> email;
            add_entry(address_book, key, email);
        }
        else if(input == 2)
        {
            std::cout << "Enter a Name to remove: " << std::endl;
            std::cin >> key;
            remove_entry(address_book, key);
        }
        else if(input == 3)
        {
            list_entries(address_book);
        }
        else
        {
            std::cout << "An Invalid option was chosen!" << std::endl;
        }
        std::cout << "Please enter another option: " << std::endl;
        std::cin >> input;
    }

    std::cout << "Closing Address Book!" << std::endl;

    return 0;
}