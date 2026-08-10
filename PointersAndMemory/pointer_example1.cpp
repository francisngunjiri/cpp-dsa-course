#include <iostream>

int main () {
    int score = 95;
    int* ptr = &score; //store the memory address of score

    std::cout << "Value of Score: "<< score <<"\n";
    std::cout << "Address of score: "<< &score << "\n";
    std::cout << "Value stored inside ptr: "<< ptr << "\n";
    std::cout << "Value at the address ptr points to (Dereferencing): "<< *ptr << "\n";

    // Change the value of score using pointer
    *ptr = 100; //dereferencing ptr to change the value of score
    std::cout << "New value of Score after changing through pointer: "<< score <<"\n";
    /* Output:
    * Value of Score: 95
    * Address of score: 0x7ffcbb0d055c
    * Value stored inside ptr: 0x7ffcbb0d055c
    * Value at the address ptr points to (Dereferencing): 95New value of Score after changing through pointer: 100
    */
    return 0;
}