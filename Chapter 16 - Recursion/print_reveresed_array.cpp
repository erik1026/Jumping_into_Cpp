#include <iostream>

void print_reversed_array(int arr [], int start, int end);

int main(){
    int length_of_array = 5;
    int array [5] = {1, 2, 3, 4, 5};
    print_reversed_array(array, 0, 5);

    return 0;
}

void print_reversed_array(int arr [], int start, int end)
{
    std::cout << "Start: " << start << std::endl;
    std::cout << int(start>=end) << std::endl;
    if (start >= end);
    {
        std::cout << "Start: " << start << std::endl;
       return;
    }
    print_reversed_array(arr, start, end);
    std::cout << arr[start] << std::endl;
}