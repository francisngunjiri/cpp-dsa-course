#include <iostream>

/*
Upgrade your LinkedList class to include:

An deleteByValue(int val) function: Finds the first occurrence of val in the list, removes it, updates pointers properly (including updating head or tail if necessary), and frees the memory. If the value isn't found, it should handle it gracefully without crashing.

All your existing methods (append, search, display, destructor, etc.).

In your main() function:

Instantiate your LinkedList.

Append elements (e.g., 10, 20, 30, 40).

Display the initial list.

Test deleting a node in the middle (e.g., delete 20).

Test deleting the head node (e.g., delete 10).

Test deleting a node that doesn't exist (e.g., delete 99).

Display the final list after deletions to verify the structure remains intact.
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

    bool deleteByValue(int val) {
        if (head == nullptr) return false;

        // If head needs to be deleted
        if (head->data == val) {
            Node* toDelete = head;
            head = head->next;
            if (head == nullptr) tail = nullptr; // list became empty
            delete toDelete;
            return true;
        }

        Node* prev = head;
        Node* current = head->next;
        while (current != nullptr) {
            if (current->data == val) {
                prev->next = current->next;
                if (current == tail) tail = prev;
                delete current;
                return true;
            }
            prev = current;
            current = current->next;
        }
        return false; // not found
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
    list.append(40);

    // Display the initial list
    std::cout << "Initial list: ";
    list.display();

    // Delete a node in the middle (20)
    std::cout << "delete(20): " << (list.deleteByValue(20) ? "deleted" : "not found") << std::endl;
    std::cout << "After deleting 20: ";
    list.display();

    // Delete the head node (10)
    std::cout << "delete(10): " << (list.deleteByValue(10) ? "deleted" : "not found") << std::endl;
    std::cout << "After deleting 10: ";
    list.display();

    // Delete a node that doesn't exist (99)
    std::cout << "delete(99): " << (list.deleteByValue(99) ? "deleted" : "not found") << std::endl;
    std::cout << "After attempting to delete 99: ";
    list.display();

    /*
    Output:
    Initial list: 10 -> 20 -> 30 -> 40 -> nullptr
    delete(20): deleted
    After deleting 20: 10 -> 30 -> 40 -> nullptr
    delete(10): deleted
    After deleting 10: 30 -> 40 -> nullptr
    delete(99): not found
    After attempting to delete 99: 30 -> 40 -> nullptr
    */

    return 0;
}