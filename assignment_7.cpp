#include <iostream>

/*

Define a class or struct named LinkedList that manages a chain of Node elements:

Internal Node Struct: struct Node with int data and Node* next.

Member variable: A pointer to the head of the list (Node* head).
Upgrade your LinkedList class to include:

Member variables: Node* head and Node* tail.

Constructor: Initializes both head = nullptr and tail = nullptr.

An append(int val) function: Adds a new node to the end of the list. Make sure it correctly handles both the empty list case (where both head and tail become the new node) and the non-empty list case (where tail->next points to the new node and tail updates).

A search(int target) function: Traverses the list and returns true if the target value exists in the list, or false otherwise.

The existing display() and destructor (~LinkedList()) functions.

In your main() function:

Instantiate your LinkedList.

Append several numbers to the tail (e.g., append 10, then 20, then 30).

Call display() (which should output 10 -> 20 -> 30 -> nullptr).

Test your search() function for a value that exists (e.g., 20) and one that doesn't (e.g., 99), printing out the search outcomes.
*/

/*
 Upgrade LinkedList to support head and tail, append, and search.
*/

class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

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
        if (tail == nullptr) {
            tail = newNode;
        }
    }

    void append(int val) {
        Node* newNode = new Node{val, nullptr};
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    bool search(int target) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == target) return true;
            current = current->next;
        }
        return false;
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

    // Append numbers to the tail
    list.append(10);
    list.append(20);
    list.append(30);

    // Display the list
    list.display();

    // Test search()
    std::cout << "search(20): " << (list.search(20) ? "found" : "not found") << std::endl;
    std::cout << "search(99): " << (list.search(99) ? "found" : "not found") << std::endl;

    return 0;
}