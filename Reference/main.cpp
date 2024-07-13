// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Write C++ code here
    int num = 100;
    int &ref = num;
    cout << num << endl;
    cout << ref << endl;
    num = 200;
    cout << num << endl;
    cout << ref << endl;
    ref = 300;
    cout << num << endl;
    cout << ref << endl;

    
    
    cout << "\n===========================\n";
    
    vector<string> stooges {"larry", "Moe", "Curly"};
    for(auto v : stooges){
        v = "Funny";  // No change, v is copy of stooges 
    }
    for(auto v : stooges){
        cout << v << endl; // No change
    }
    
    cout << "\n===========================\n";
    
    
    for(auto &v : stooges){
        v = "Funny";  // v is an alias and reference of stooges 
    }
    for(auto const &v : stooges){
        cout << v << endl; // change
    }

    return 0;
}