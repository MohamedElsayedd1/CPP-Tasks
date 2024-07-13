#include <iostream>
using namespace std;

int n1, n2;

int main()
{
    cout << "Enter 2 numbers : ";
    cin >> n1 >> n2;
    if(n1 > n2){
        cout << "Max number is : " << n1 << ", Min number is : " << n2;
    }
    else if(n2 > n1){
        cout << "Max number is : " << n2 << ", Min number is : " << n1;
    }
    else{
        cout << "both numbers are equal";
    }
}