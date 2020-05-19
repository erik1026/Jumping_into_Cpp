#include <iostream>
#include <string>

struct personal_info{
    std::string name;
    std::string address;
    std::string phone_number;
};

int main()
{

    personal_info person;

    std::cout << "Please enter your name: ";
    std::cin >> person.name;
    std::cout << "Please enter your address: ";
    std::cin >> person.address;
    std::cout << "Please enter your phone number: ";
    std::cin >> person.phone_number;

    std::cout << "Name: " << person.name << std::endl;
    std::cout << "Address: " << person.address << std::endl;
    std::cout << "Phone Number: " << person.phone_number << std::endl;
    
    return 0;
}