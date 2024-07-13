#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

inline unsigned long long GetFactorial(unsigned long long num){
    if(num == 1){
        return 1;
    }
    else{
        return num * GetFactorial(num-1);
    }
}

int main()
{
    int fact {0}, num {0};
    cout << "Factorial of number " << endl << "=============================\n";
    cout << "Enter a number : ";
    cin >> num;
    fact = GetFactorial(num);
    cout << "Factorial of " << num << " = " << fact << endl;
}
