#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

int GetFibonacci(int num){
    if(num <= 1){
        return num;
    }
    else{
        return GetFibonacci(num-2) + GetFibonacci(num-1);
    } 
}

int main()
{
    int fact {0}, num {0};
    cout << "Fibonacci of number : " << endl;
    cout << "Enter a number : ";
    cin >> num;
    fact = GetFibonacci(num);
    cout << "Factorial of " << num << " = " << fact << endl;
}