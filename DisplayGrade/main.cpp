#include <iostream>
using namespace std;
typedef int marks;

int main()
{
    marks m1, m2, m3, sum;
    float avg;
    cout << "Enter marks of 3 subjects : ";
    cin >> m1 >> m2 >> m3;
    sum = m1 + m2 + m3;
    avg = sum / 3.0;
    if (avg >= 60)
    {
        cout << "Degree : A";
    }
    else if (avg < 60 && avg > 35)
    {
        cout << "Degree : B";
    }
    else
    {
        cout << "Degree : C";
    }
    return 0;
}