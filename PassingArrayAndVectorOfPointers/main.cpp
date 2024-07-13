#include <vector>
#include <iostream>
using namespace std;

// Function that takes a vector of pointers as an argument
void processVector(const std::vector<int*>& ptrVector) {
    // Access and use the pointers in ptrVector
    for (int* ptr : ptrVector) {
        // Example: dereference the pointer and print its value
        if (ptr != nullptr) {
            std::cout << *ptr << std::endl;
        }
    }
}


// Function that takes an array of pointers as an argument
void processArray(int* ptrArray[], int size) {
    // Access and use the pointers in ptrArray
    for (int i = 0; i < size; ++i) {
        if (ptrArray[i] != nullptr) {
            std::cout << *ptrArray[i] << std::endl;
        }
    }
}



int main() {

    cout << "==== Passing vector of pointers to function =======\n";
    // Example usage
    std::vector<int*> ptrVector;

    // Add some pointers to the vector (just an example)
    int a = 10, b = 20;
    ptrVector.push_back(&a);
    ptrVector.push_back(&b);

    // Call the function with the vector of pointers
    processVector(ptrVector);

    cout << "==== Passing array of pointers to function =======\n";

    // Example usage
    const int size = 3;
    int* ptrArray[size];  // Array of pointers

    // Example: Initialize array with pointers
    int x = 5, y = 10, z = 15;
    ptrArray[0] = &x;
    ptrArray[1] = &y;
    ptrArray[2] = &z;

    // Call the function with the array of pointers
    processArray(ptrArray, size);

    return 0;

    return 0;
}
