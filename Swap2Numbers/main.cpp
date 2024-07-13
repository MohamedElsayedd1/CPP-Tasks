#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

void scale_number(int &num);
void swap_2_numbers(int &num1, int &num2);

int main()
{
    int number1{10}, number2{50};

    cout << "Before swap : " << endl; 
    cout << "number 1 = " << number1 << ", " << "number 2 = " << number2 << endl;
    swap_2_numbers(number1, number2);
    cout << "After swap : " << endl; 
    cout << "number 1 = " << number1 << ", " << "number 2 = " << number2 << endl;

}

void swap_2_numbers(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}