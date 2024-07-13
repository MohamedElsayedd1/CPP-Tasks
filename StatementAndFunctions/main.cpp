#include <iostream>
using namespace std;

int addNumbers(int number1, int number2);

int main()
{
    int sum = addNumbers(10, 2);
    cout << "sum 1 : " << sum << "\n";
    cout << "sum 2 : " << addNumbers(19, 1);

    return 0;
}

int addNumbers(int number1, int number2){
    int sum{number1 + number2};
    return sum;
}