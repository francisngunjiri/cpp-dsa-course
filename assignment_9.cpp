#include <iostream>

/*Implement a class named Stack (you can use your internal Node structure or reuse the head-insertion concept):

Member variables: A pointer to the top of the stack (Node* top).

Constructor: Initializes top = nullptr.

Destructor (~Stack()): Safely deallocates all nodes to prevent memory leaks.

push(int val): Adds an element to the top of the stack (Hint: this is identical to insertAtHead!).

pop(): Removes the top element from the stack and frees its memory. Make sure to handle the empty stack case gracefully.

peek() const: Returns the value at the top of the stack without removing it. (If empty, handle or print an error message).

isEmpty() const: Returns true if the stack is empty, false otherwise.

In your main() function:

Instantiate your Stack.

Push several numbers onto it (e.g., 10, 20, 30).

Test peek() and pop(), showing that elements come out in LIFO order (30, then 20, then 10).

Verify isEmpty() when the stack becomes empty.
*/

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* top;
    
public:
    // Constructor: Initializes top = nullptr
    Stack() : top(nullptr) {}
    
    // Destructor: Safely deallocates all nodes to prevent memory leaks
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
    
    // push(int val): Adds an element to the top of the stack
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    
    // pop(): Removes the top element from the stack and frees its memory
    void pop() {
        if (isEmpty()) {
            std::cout << "Error: Cannot pop from an empty stack!" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    
    // peek() const: Returns the value at the top of the stack without removing it
    int peek() const {
        if (isEmpty()) {
            std::cout << "Error: Stack is empty!" << std::endl;
            return -1;  // Return a sentinel value (or could throw an exception)
        }
        return top->data;
    }
    
    // isEmpty() const: Returns true if the stack is empty, false otherwise
    bool isEmpty() const {
        return top == nullptr;
    }
};

int main() {
    Stack stack;
    
    // Test: Push several numbers onto the stack (10, 20, 30)
    std::cout << "Pushing 10, 20, 30 onto the stack..." << std::endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    
    // Test: peek() and pop() showing LIFO order
    std::cout << "\nTesting peek() and pop():" << std::endl;
    
    std::cout << "Peek: " << stack.peek() << std::endl;  // Should print 30
    stack.pop();
    std::cout << "After pop, peek: " << stack.peek() << std::endl;  // Should print 20
    
    std::cout << "Popping and printing elements in LIFO order:" << std::endl;
    while (!stack.isEmpty()) {
        std::cout << "Popping: " << stack.peek() << std::endl;
        stack.pop();
    }
    
    // Test: isEmpty() when stack becomes empty
    std::cout << "\nStack is empty: " << (stack.isEmpty() ? "true" : "false") << std::endl;
    
    // Test: Trying to pop from empty stack
    std::cout << "\nTrying to pop from empty stack:" << std::endl;
    stack.pop();
    
    // Test: Trying to peek at empty stack
    std::cout << "Trying to peek at empty stack:" << std::endl;
    stack.peek();
    
    return 0;
}
