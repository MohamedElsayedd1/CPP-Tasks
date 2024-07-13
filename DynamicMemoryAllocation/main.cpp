#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int *int_ptr{nullptr};
    int_ptr = new int;
    cout << int_ptr << endl; // random address in the heap

    int size{};
    double *array_ptr{nullptr};
    cout << "Enter size of the list : ";
    cin >> size;
    array_ptr = new double[size];
    cout << array_ptr << endl; // random address in the heap
    delete[] array_ptr;
}