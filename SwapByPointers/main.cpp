#include <iostream>
using namespace std;

void swap(int *x, int *y);

int main()
{
    int num1 = 100, num2 = 500;
    cout << "Before calling swap function : " << endl;
    cout << "number1 = " << num1 << ", num2 = " << num2 << endl << endl;
    swap(&num1, &num2);
    cout << "After calling swap function : " << endl;
    cout << "number1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}