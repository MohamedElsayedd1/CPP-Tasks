#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

int num{300}; // Global variable - declared outside any function or class

void local_example(int x);
void global_example();
void static_local_example();

int main()
{
    int num1{100}; // local to main
    int num2{500}; // local to main
    cout << "Local num1 in main block = " << num1 << endl;
    cout << "Local num2 in main block = " << num2 << endl;

    // Creates a new level of scope
    {
        int num1{200}; // local to inner block
        cout << "\nLocal num1 in inner block = " << num1 << endl;
        cout << "Local num2 in inner block = " << num2 << " ===> main block can be seen by inner block" << endl;
    }

    cout << "\nLocal num1 in main block = " << num1 << endl;

    local_example(10);
    local_example(20);

    global_example();
    global_example();

    static_local_example();
    static_local_example();
}

void local_example(int x)
{
    int num{1000};
    cout << "\nLocal num in local_example->start = " << num << endl;
    num = x;
    cout << "Local num in local_example->end = " << num << endl;
}

void global_example()
{
    cout << "\nGlobal num in global_example->start = " << num << endl;
    num *= 2;
    cout << "Global num in global_example->end = " << num << endl;
}

void static_local_example()
{
    static int num = 400; // Preserved in .Data segment & Intialized only one time
    cout << "\nStatic Local num in static_local_example->start = " << num++ << endl;
    cout << "Static Local num in static_local_example->end = " << num << endl;
}