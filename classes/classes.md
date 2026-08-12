# Classes, Constructors and Structs

* Members of a struct are public by default
* Members of a class are private by default
* A constructor, a function inside a class/struct that automatically runs when you create an instance of that object. 

```C++
#include <iostream>
//Node structure for a linked list
struct Node {
    int data; // Value stored in the node
    Node* next; // pointer to next node in memory

    // constructor to easily initialize a node
    Node(int val) {
        data = val;
        next = nullptr; // By default, it points to nothing.
    }
};

int main(){
    // Create nodes dynamically on the heap

    Node* first = new Node(10);
    Node* second = new Node(20);

    // linking them together
    first->next = second;

    //printing the data using pointers
    std::cout << "First node data: " << first->data << "\n";
    std::cout << "Second node data via first->next: " << first->next->data <<"\n";
    
    // clean up memory to prevent leaks

    delete first;
    delete second;

    first = nullptr;
    second = nullptr;

    return 0;
}

```
