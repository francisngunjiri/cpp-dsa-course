#include <iostream>
#include <vector>

/*Implement a custom class or struct named SimpleVector that manages a dynamic integer array internally:

Member variables: A pointer to the heap array (int* data), a variable for current size (size_t size), and a variable for total allocated capacity (size_t capacity).

Constructor: Initializes an empty vector with an initial capacity (e.g., capacity = 2).

Destructor (~SimpleVector()): Frees the dynamically allocated heap memory to prevent memory leaks!

A push_back(int val) function: * Checks if size == capacity. If it is, it triggers a resizing routine: allocates a new array of double the current capacity, copies the old elements over, deletes the old array data, and updates the pointer.

Inserts the new value and increments size.

A print() function: Loops through and prints all current elements.

In your main() function:

Instantiate your SimpleVector.

Push back several numbers (e.g., 5, 10, 15, 20, 25) to force multiple resizing operations.

Print the vector contents and verify that it expands cleanly without crashing or leaking memory.
*/

struct SimpleVector {
    int* data;          // Pointer to the dynamic array
    size_t size;       // Current number of elements
    size_t capacity;   // Total allocated capacity

    // Constructor
    SimpleVector() : size(0), capacity(2) {
        data = new int[capacity]; // Allocate initial capacity
    }

    // Destructor
    ~SimpleVector() {
        delete[] data; // Free the allocated memory
    }

    // Push back function
    void push_back(int val) {
        if (size == capacity) {
            resize(); // Resize if needed
        }
        data[size++] = val; // Insert the new value and increment size
    }

    // Resize function to double the capacity
    void resize() {
        capacity *= 2; // Double the capacity
        int* newData = new int[capacity]; // Allocate new array
        for (size_t i = 0; i < size; ++i) {
            newData[i] = data[i]; // Copy old elements to new array
        }
        delete[] data; // Delete old array
        data = newData; // Update pointer to new array
    }

    // Print function to display current elements
    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " "; // Print each element
        }
        std::cout << std::endl;
    }
};

int main(){
    SimpleVector vec; // Instantiate SimpleVector

    // Push back several numbers to force resizing
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(25);

    // Print the vector contents
    std::cout << "Contents of SimpleVector: ";
    vec.print(); // Verify that it expands cleanly without crashing or leaking memory

    /* Output:
    Contents of SimpleVector: 5 10 15 20 25 
    */

    return 0;
}