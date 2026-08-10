#include <iostream>

/*
Write a program that: contains two separate swap functions:

Function 1: void swapUsingPointers(int* a, int* b) that takes two integer pointers and swaps their values.

Function 2: void swapUsingReferences(int &a, int &b) that takes two integer references and swaps their values.

In your main() function:

Declare two integers (e.g., x = 5, y = 10), call swapUsingPointers, and print the results.

Declare two new integers (e.g., a = 20, b = 40), call swapUsingReferences, and print the results.
*/

void swapUsingPointers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapUsingReferences(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    // Test swapUsingPointers
    int x = 5, y = 10;
    std::cout << "Before swapping (pointers): x = " << x << ", y = " << y << std::endl;
    swapUsingPointers(&x, &y);
    std::cout << "After swapping (pointers): x = " << x << ", y = " << y << std::endl;

    // Test swapUsingReferences
    int a = 20, b = 40;
    std::cout << "Before swapping (references): a = " << a << ", b = " << b << std::endl;
    swapUsingReferences(a, b);
    std::cout << "After swapping (references): a = " << a << ", b = " << b << std::endl;


    /* Output:
    Before swapping (pointers): x = 5, y = 10
    After swapping (pointers): x = 10, y = 5
    Before swapping (references): a = 20, b = 40
    After swapping (references): a = 40, b = 20
    */

    return 0;
}