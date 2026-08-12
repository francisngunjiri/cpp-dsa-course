#include <iostream>

/*Define a struct or class named StudentNode that contains:

Data members: int id and std::string name.

A pointer member: StudentNode* next.

A constructor that accepts an ID and a name, initializing the data members and setting next to nullptr.

A member function named display() that prints out the student's ID and name neatly.

In your main() function:

Dynamically create two StudentNode objects on the heap using your constructor.

Link the first node's next pointer to the second node.

Call the display() function on both nodes (directly and/or by traversing via the pointer).

Properly clean up and delete your heap-allocated nodes (setting pointers to nullptr).
*/

struct StudentNode {
    int id;
    std::string name;
    StudentNode* next;

    // Constructor
    StudentNode(int studentId, const std::string& studentName) : id(studentId), name(studentName), next(nullptr) {}

    // Member function to display student information
    void display() const {
        std::cout << "Student ID: " << id << ", Name: " << name << "\n";
    }
};

int main() {
    // Dynamically create two StudentNode objects
    StudentNode* student1 = new StudentNode(1, "Alice");
    StudentNode* student2 = new StudentNode(2, "Bob");

    // Link the first node's next pointer to the second node
    student1->next = student2;

    // Call the display() function on both nodes
    student1->display();
    if (student1->next) {
        student1->next->display();
    }

    // Properly clean up and delete heap-allocated nodes
    delete student1;
    delete student2;
    student1 = nullptr;
    student2 = nullptr;

    /* Output:
    Student ID: 1, Name: Alice
    Student ID: 2, Name: Bob
    */

    return 0;
}