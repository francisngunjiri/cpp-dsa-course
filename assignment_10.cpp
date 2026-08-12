#include <iostream>
/*A Queue is an Abstract Data Type that follows the FIFO (First In, First Out) principle.
Think of a real-world line of people waiting at a movie ticket booth or a supermarket checkout: the person who arrives first gets served first, and new people join at the very back of the line.
Core Queue Operations:enqueue(val): Adds an element to the back (tail) of the queue ($\mathcal{O}(1)$ time).dequeue(): Removes the element from the front (head) of the queue ($\mathcal{O}(1)$ time).peek() / front(): Views the element at the front without removing it ($\mathcal{O}(1)$ time).isEmpty(): Checks if the queue has any elements ($\mathcal{O}(1)$ time).How to Implement a Queue using a Linked List:Just like our stack, implementing a queue with a linked list is clean and efficient if we maintain both a head (front) and a tail (back) pointer:enqueue(val): Appends a new node to the tail in $\mathcal{O}(1)$ time. (Just like your linked list append function!)dequeue(): Removes the node from the head in $\mathcal{O}(1)$ time. (Just like deleting the head node!)
*/

/*Implement a class named Queue:

Member variables: Node* front (points to the start of the queue) and Node* rear (points to the end of the queue).

Internal Node Struct: struct Node with int data and Node* next.

Constructor: Initializes both front = nullptr and rear = nullptr.

Destructor (~Queue()): Safely deallocates all nodes to prevent memory leaks.

enqueue(int val): Adds an element to the rear of the queue. Handles empty queue and non-empty queue cases properly.

dequeue(): Removes the front element from the queue and frees its memory. Handles the empty queue case gracefully.

peek() const: Returns the value at the front of the queue without removing it.

isEmpty() const: Returns true if the queue is empty, false otherwise.

In your main() function:

Instantiate your Queue.

Enqueue several numbers (e.g., 10, then 20, then 30).

Test peek() and dequeue(), showing that elements come out in strict FIFO order (10, then 20, then 30).

Test boundary conditions (e.g., trying to dequeue/peek from an empty queue).
*/
class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* front;
    Node* rear;
    void clear();
public:
    Queue();
    ~Queue();
    void enqueue(int val);
    void dequeue();
    int peek() const;
    bool isEmpty() const;
};

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue() {
    clear();
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int val) {
    Node* newNode = new Node(val);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Error: Cannot dequeue from an empty queue." << std::endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
}

int Queue::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Error: Cannot peek into an empty queue.");
    }
    return front->data;
}

bool Queue::isEmpty() const {
    return front == nullptr;
}

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Front element: " << q.peek() << std::endl; // Should print 10
    q.dequeue();
    std::cout << "Front element after dequeue: " << q.peek() << std::endl; // Should print 20
    q.dequeue();
    std::cout << "Front element after dequeue: " << q.peek() << std::endl; // Should print 30
    q.dequeue();

    if (q.isEmpty()) {
        std::cout << "Queue is empty." << std::endl;
    } else {
        std::cout << "Queue is not empty." << std::endl;
    }

    // Test boundary conditions
    q.dequeue(); // Should handle gracefully
    std::cout << "Trying to peek from an empty queue: ";
    try {
        std::cout << q.peek() << std::endl; // Should handle gracefully
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    /* Output: 
    Front element: 10
    Front element after dequeue: 20
    Front element after dequeue: 30
    Queue is empty.
    Error: Cannot dequeue from an empty queue.
    Trying to peek from an empty queue: Error: Cannot peek into an empty queue.
    */

    return 0;
}