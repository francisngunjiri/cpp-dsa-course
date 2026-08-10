# References vs. Pointers and Pass-by-Reference

* A **reference** (& in a type declaraton) is an alias for an existing variable.
  Unlike a pointer, a reference cannot be null and cannot be  reassigned to point to something else once initialized.

  ```c++
  #include <iostream>

  void increment(int& ref){ // pass by reference
  ref++; // modifies original variable directly
  }

  int main() {
    int x = 10;

    increment(x);

    std::cout <<x << "\n";
    /* output:
    11
    */

   return 0;
  }

  ```

## Why does this matter for DSA?

Why does this matter for DSA?
When we build data structures like Linked Lists or pass large vectors/objects into recursive functions (like Tree Traversals), passing by value makes a heavy copy of the data, destroying your time and space efficiency. Passing by reference lets functions manipulate the real data structure efficiently without duplicating it.
