#include <iostream>

/*

Define a class or struct named LinkedList that manages a chain of Node elements:

Internal Node Struct: struct Node with int data and Node* next.

Member variable: A pointer to the head of the list (Node* head).

Constructor: Initializes an empty list (head = nullptr).

Destructor (~LinkedList()): Walks through the list and safely deletes every node on the heap to prevent memory leaks!

A insertAtHead(int val) function: Creates a new node and puts it at the very beginning of the list.

A display() function: Traverses the list from the head to the end, printing out each node's value (e.g., 10 -> 20 -> 30 -> nullptr).

In your main() function:

Instantiate your LinkedList.

Insert several numbers at the head (e.g., push 30, then 20, then 10).

Call display() to print the list structure.

Let the destructor clean up automatically when main exits.
*/

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void insertAtHead(int val) {
        Node* newNode = new Node{val, head};
        head = newNode;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main() {
    LinkedList list;

    // Insert numbers at the head
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);

    // Display the list
    list.display();

    // Destructor will automatically clean up when main exits

    /* Output:
    10 -> 20 -> 30 -> nullptr
    */

    return 0;
}