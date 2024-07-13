#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int global_x = 1000; // A global variable that can be accessed from anywhere in the code

class Lambda{
private : 
    int y;
public : 
    Lambda(int my_y) : y{my_y}{};
    ~Lambda() = default;
    void operator()(int x){
        cout << x + y << endl;
    }
};

// Test functions to demonstrate various uses of lambda expressions in C++

void test1(void){
    cout << "Test1 =============================\n";
    int local_x{100};
    auto l = [local_x](){ // Capture by value, local_x can't be modified within the lambda
        cout << local_x << endl; // Prints the value of local_x (100)
        cout << global_x << endl; // Prints the value of global_x (1000)
    };
    l();
}

void test2(void){
    cout << "Test2 =============================\n";
    int x{100};
    auto l = [x]() mutable{ // Capture by value, must add mutable keyword to modify x within the lambda
        x += 100;
        cout << x << endl; // Prints 200
    };
    l();
    cout << x << endl; // x value didn't change because we captured by value -> 100

    l(); // Calling the lambda again, x within lambda now becomes 300
    cout << x << endl; // Still 100, original x remains unchanged
}

void test3(void){
    cout << "Test3 ===============================\n";
    int x {100};
    auto l = [&x](){ // Capture by reference, we are passing the actual x, and we can modify x within the lambda
        x += 100;
        cout << x << endl; // Prints 200
    };
    l();
    cout << x << endl; // Prints 200

    l(); 
    cout << x << endl; // Prints 300
}

void test4(void){
    cout << "Test4 ===============================\n";
    int x {100};
    int y{200};
    int z{300};
    auto l = [=]() mutable{ // Capturing all variables by value
        x += 100;
        y += 100;
        z += 100;
        cout << x << endl; // Prints 200
        cout << y << endl; // Prints 300
        cout << z << endl; // Prints 400
    };
    l();
    cout << x << endl; // Prints 100, original x remains unchanged
    cout << y << endl; // Prints 200, original y remains unchanged
    cout << z << endl; // Prints 300, original z remains unchanged
}

void test5(void){
    cout << "Test5 ===============================\n";
    int x {100};
    int y{200};
    int z{300};
    auto l = [&]() { // Capturing all variables by reference
        x += 100;
        y += 100;
        z += 100;
        cout << x << endl; // Prints 200
        cout << y << endl; // Prints 300
        cout << z << endl; // Prints 400
    };
    l();
    cout << x << endl; // Prints 200, original x is modified
    cout << y << endl; // Prints 300, original y is modified
    cout << z << endl; // Prints 400, original z is modified
}

void test6(void){
    cout << "Test6 ===============================\n";
    int x {100};
    int y{200};
    int z{300};
    auto l = [=, &y]() mutable{ // Capturing all variables by value except y by reference
        x += 100;
        y += 100;
        z += 100;
        cout << x << endl; // Prints 200
        cout << y << endl; // Prints 300
        cout << z << endl; // Prints 400
    };
    l();
    cout << x << endl; // Prints 100, original x remains unchanged
    cout << y << endl; // Prints 300, original y is modified
    cout << z << endl; // Prints 300, original z remains unchanged
}

void test7(void){
    cout << "Test7 ===============================\n";
    int x {100};
    int y{200};
    int z{300};
    auto l = [&, x, z]() mutable{ // Capturing all variables by reference except x and z by value
        x += 100;
        y += 100;
        z += 100;
        cout << x << endl; // Prints 200
        cout << y << endl; // Prints 300
        cout << z << endl; // Prints 400
    };
    l();
    cout << x << endl; // Prints 100, original x remains unchanged
    cout << y << endl; // Prints 300, original y is modified
    cout << z << endl; // Prints 300, original z remains unchanged
}

void test8(void){
    cout << "Test8 ===============================\n";
    int y{200};
    Lambda my_lambda(y);
    auto gen_lambda = [y](int x){ cout << x + y << endl; };

    my_lambda(100);
    gen_lambda(100);
}


int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    return 0;
}
