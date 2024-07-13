#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float a, b, c, d;
    float root1, root2;
    cout << "Root of quadratic equation \n";
    cout << "Enter a, b, c : ";
    cin >> a >> b >> c;
    d = b * b - 4 * a * c;
    if (d == 0)
    {
        root1 = (-b / (2 * a));
        cout << "roots are real and equal" << endl;
        cout << "root 1 : " << root1 << ", root2 : " << root1;
    }
    else if (d > 0)
    {
        root1 = (-b - sqrt(d)) / (2 * a);
        root2 = (-b + sqrt(d)) / (2 * a);
        cout << "roots are real and not equal" << endl;
        cout << "root 1 : " << root1 << ", root2 : " << root2;
    }
    else
    {
        cout << "Imaginary roots";
    }

    return 0;
}