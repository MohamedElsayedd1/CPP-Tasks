// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;

int main() {
    // Write C++ code here
    int year, month, day;
    int i;
    cin >> i;
    year = i / 365;
    month = abs(i - 365*year) / 30;
    day = abs(i - year*365 - month*30);
    
    cout << year << " years\n";
    cout << month << " months\n";
    cout << day << " days\n";
    
    
    return 0;
}