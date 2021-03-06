#include <iostream>


struct Element
{
    int value;
    Element* next;
};

Element* global_list = NULL;

//  TODO: be able to add passed two elements
//        Code currents breaks after that point
void add_element(int element)
{
    Element* node = global_list;
    Element* previous = NULL;
    
    //  Add first element to list
    if (node == NULL)
    {
        std::cout << "First element of the list" << std::endl;
        Element* new_element = new Element;
        new_element->value = element;
        new_element->next = NULL;
        global_list = new_element;

        std::cout << "New node value: " << new_element->value << "\nNew node next: " << new_element->next << "\n" << std::endl;
    }
    
    else
    {
        //  Add second element to list
        if (node->next == NULL)
        {
            //  Add the element before the last node
            if (node->value >= element)
            {
                Element* new_element = new Element;
                new_element->value = element;
                new_element->next = node;
                node->next = NULL;
                global_list = new_element;
            }
            //  Add the element after the last node
            else if(node->value < element)
            {
                Element* new_element = new Element;
                new_element->value = element;
                new_element->next = NULL;
                node->next = new_element;
                global_list = node;
            }
        }
        else
        {
            while(node->next != NULL)
            {

                if((element >= previous->value) && (element <= node->value) || (element == node->value))
                {
                    Element* new_element = new Element;
                    new_element->value = element;
                    new_element->next = node;
                    std::cout << "New element value: " << new_element->value << "\nNext node value: " << new_element->next->value << "\n" << std::endl;
                    previous->next = new_element;
                    global_list = previous;
                    break;
                }
                else
                {
                    previous = node;
                    node = node->next;
                }
            }
        }   
    }
}   

void display_list(Element* list)
{
    Element* node = list;
    while(node->next != NULL)
    {
        std::cout << "Node value: " << node->value << std::endl;
        node = node->next;
    }
    std::cout << "Node value: " << node->value << std::endl;
}


int main()
{

    //  Instantiate variables
    int element_to_add;
    int size_of_list = 5;
    //  Add an element
    for(int i = 0; i < size_of_list; i++)
    {
        std::cout << "Enter a new element value: ";
        std::cin >> element_to_add;
        add_element(element_to_add);
        display_list(global_list);
    }
    return 0;
}