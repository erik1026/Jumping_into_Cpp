#include <iostream>

struct Element
{
    int value;
    Element* next_element;
};

Element* global_list = NULL;

void remove_element(int element)
{
    Element* node = global_list;
    Element* previous_node = NULL;
    while(node->next_element != NULL)
    {
        if(node->value == element)
        {
            previous_node->next_element = node->next_element;
            break;
        }
        else
        {
            previous_node = node;
            node = node->next_element;
        }
    }
}

void create_list(int size_of_list)
{
    for(int i = 0; i < size_of_list; i++)
    {
        Element* tmp = new Element;
        tmp->value = i;
        tmp->next_element = global_list;
        global_list = tmp;
    }
    
}

void display_list(Element* list)
{
    Element* node = list;
    while(node->next_element != NULL)
    {
        std::cout << "Node value: " << node->value << std::endl;
        node = node->next_element;
    }
    std::cout << "Node value: " << node->value << std::endl;
}

int main()
{
    // Instantiate variables
    int size_of_list;
    int element_to_remove;
    
    //  Get size of list
    std::cout << "Enter the size of list: ";
    std::cin >> size_of_list;

    //  Create and display list
    create_list(size_of_list);
    display_list(global_list);

    //  Time to remove an element based on the value
    std::cout << "Enter which value to remove: ";
    std::cin >> element_to_remove;
    remove_element(element_to_remove);
    display_list(global_list);

    return 0;
}