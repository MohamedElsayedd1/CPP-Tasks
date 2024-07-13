#include <iostream>
using namespace std;

int main()
{
    float price, discount, rate;
    cout << "Enter the price : ";
    cin >> price;
    cout << "Enter the discount : ";
    cin >> discount;
    rate = (discount / price) * 100;
    cout << "Rate of discount : " << rate << "%";
    return 0;
}