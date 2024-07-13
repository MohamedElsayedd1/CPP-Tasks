#include <iostream>
using namespace std;

int main()
{
    float b, h, area;
    cout << "Area Of Traingle \n";
    cout << "Enter the base of a traingle : ";
    cin >> b;
    cout << "Enter the hight of a traingle : ";
    cin >> h;
    area = 0.5*b*h;
    cout << "Area of a traingle : " << area;

    return 0;
}