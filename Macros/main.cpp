#include <iostream>
using namespace std;

#define PI 3.14
#define MAX_SIZE 100

#define SQUARE(a) (a * a) // should be ((a)*(a)) not a*a

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main()
{
    double r;
    cout << "Enter raduis : ";
    cin >> r;
    double area = PI * r * r;
    cout << "Area = " << area << endl;

    int size;
    cout << "Enter size : ";
    cin >> size;
    if (size <= MAX_SIZE)
    {
        cout << "Too small.\n";
    }
    else
    {
        cout << "Too big";
    }

    int n;
    cout << "Enter integer : ";
    cin >> n;
    cout << "Square : " << SQUARE(n) << endl;
    double t;
    cout << "Enter floating point value : ";
    cin >> t;
    cout << "Square root : " << SQUARE(t) << endl;

    cout << 100 / SQUARE(5) << endl; // should be 4 not 100

    int a = 5, b = 10;
    double result2 = SQUARE(a + b); // (a+b*a+b) not right

    cout << result2 << endl; // should be 4 not 100

    int x = 5;
    int y = 10;
    int maxVal = MAX(x++, y++); // x and y are incremented twice   ((x++) > (y++) ? (x++) : (y++))
    cout << "Max : " << maxVal << endl;
    cout << "x : " << x << endl; // should be 6
    cout << "y : " << y << endl; // should be 11 not 12

    return 0;
}