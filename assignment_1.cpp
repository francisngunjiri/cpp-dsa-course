#include <iostream>

/*
Write a program that:

Declares an integer variable, creates a pointer to it, prints its value and address, and modifies it using the dereference operator.

Dynamically allocates a single integer on the heap using the new keyword, assigns a value to it, prints it, and then safely frees that memory using delete (setting the pointer to nullptr afterward).

Dynamically allocates an array of 5 integers on the heap, populates it with values in a loop, prints them out, and properly frees the memory using delete[].
*/

int main() {
    int number = 20;
    int* ptr = &number;
    std::cout << "Value of number: " << number << "\n";
    std::cout << "Address of number: " << &number << "\n";

    *ptr = 50;
    std::cout << "Value of number after modification through pointer: " << number << "\n";

    // Dynamically allocate a single integer
    int* dynamicInt = new int;
    *dynamicInt = 100;
    std::cout << "Dynamically allocated integer value: " << *dynamicInt << "\n";
    delete dynamicInt;
    dynamicInt = nullptr;   

    // Dynamically allocate an array of 5 integers
    int* dynamicArray = new int[5];
    for (int i = 0; i < 5; ++i) {
        dynamicArray[i] = i * 10; // Populate the array with values
        std::cout << "Value at index " << i << ": " << dynamicArray[i] << "\n";
    }
    delete[] dynamicArray;
    dynamicArray = nullptr;
    /* Output:
    Value of number: 20
    Address of number: 0x7fff2814c4e8
    Value of number after modification through pointer: 50
    Dynamically allocated integer value: 100
    Value at index 0: 0
    Value at index 1: 10
    Value at index 2: 20
    Value at index 3: 30
    Value at index 4: 40
*/

    return 0;
}