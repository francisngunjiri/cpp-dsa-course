#include <iostream>
#include <vector>
#include <chrono>

/*Let's write a C++ program that compares the speed of an $\mathcal{O}(N)$ linear search versus a hypothetical operation, and practice calculating complexity.
Write a program that:Creates a std::vector<int> and populates it with $N$ elements (e.g., $N = 1,000,000$).
Implements a function linearSearch(const std::vector<int>& arr, int target) that loops through the vector to find a target value and returns its index (or -1 if not found). 
This is an $\mathcal{O}(N)$ operation.Uses C++'s <chrono> library to measure how long the search takes in milliseconds or microseconds.Prints the search result and the execution time.In a comment block at the top or bottom of assignment_4.cpp, write a short analysis explaining:What the Time Complexity of your search function is and why.What the Space Complexity is and why.
*/

/* Short Analysis:
Time Complexity: The time complexity of the linearSearch function is O(N) because in the worst case, the function may need to iterate through all N elements of the vector to find the target value. This means that the execution time grows linearly with the size of the input vector.
Space Complexity: The space complexity of the linearSearch function is O(1) because it uses a constant amount of additional space regardless of the size of the input vector. The function only uses a few variables (like the index and the target value) and does not allocate any additional data structures that depend on the size of the input vector. Therefore, the space used remains constant as N increases.

*/
template<typename T>
int linearSearch(const std::vector<T>& arr, T target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return static_cast<int>(i); // Return the index if found
        }
    }
    return -1; // Return -1 if not found
}

int main() {
    const int N = 1000000; // Size of the vector
    std::vector<int> arr(N);
    
    // Populate the vector with values from 0 to N-1
    for (int i = 0; i < N; ++i) {
        arr[i] = i;
    }

    int target = N - 1; // Target value to search for

    // Measure the time taken for linear search
    auto start = std::chrono::high_resolution_clock::now();
    int index = linearSearch(arr, target);
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;

    // Print the result and execution time
    if (index != -1) {
        std::cout << "Target found at index: " << index << std::endl;
    } else {
        std::cout << "Target not found." << std::endl;
    }
    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;


    /* Short Analysis:
    Time Complexity: The time complexity of the linearSearch function is O(N) because in the worst case, the function may need to iterate through all N elements of the vector to find the target value. This means that the execution time grows linearly with the size of the input vector.
    Space Complexity: The space complexity of the linearSearch function is O(1) because it uses a constant amount of additional space regardless of the size of the input vector. The function only uses a few variables (like the index and the target value) and does not allocate any additional data structures that depend on the size of the input vector. Therefore, the space used remains constant as N increases.
    */  
   /* Output:
   Target found at index: 999999
   Execution time: 13.844 ms
   */

    return 0;
}

