#include <iostream>
#include <string>

// Return the names using references
void ref_first_last_name(std::string& first, std::string& last)
{
    std::string first_name;
    std::string last_name;

    std::cout << "Please enter your first name: ";
    std::cin >> first_name;
    std::cout << "Please enter you last name: ";
    std::cin >> last_name;
    
    first = first_name;
    last = last_name;
}

// Return the names using pointers
void ptr_first_last_name(std::string* first, std::string* last)
{
    std::string first_name;
    std::string last_name;

    if (last == NULL)
    {
        std::cout << "Please enter your first name: ";
        std::cin >> first_name;  
        *first = first_name;
    }
    else
    {
        std::cout << "Please enter your first name: ";
        std::cin >> first_name;
        std::cout << "Please enter you last name: ";
        std::cin >> last_name;
        *first = first_name;
        *last = last_name;
    }
}

int main()
{

    // Using pointers
    std::string first_name = "Something";
    std::string *first = NULL;
    first = &first_name;
    std::string last_name = "Doens't matter";
    std::string *last = NULL;
    //last = &last_name;

    std::cout << "Original first name: " << first_name << "\nThe orignal last name: " << last_name << std::endl;
    ptr_first_last_name(first, last);

    std::cout << "New first name: " << first_name << "\nNew last name: " << last_name << std::endl; 
    
    // Using References
    std::string ref_first_name = "Nothing";
    std::string &ref_first = ref_first_name;
    std::string ref_last_name = "Still nothing";
    std::string ref_last = ref_last_name;
    std::cout << "Original first name: " << ref_first_name << "\nThe orignal last name: " << ref_last_name << std::endl;
    ref_first_last_name(ref_first, ref_last);

    std::cout << "New first name: " << ref_first_name << "\nNew last name: " << ref_last_name << std::endl; 
    


    return 0;
}