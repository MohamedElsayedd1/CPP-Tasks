#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 7, 11, 32, 8, 16};
    int sum = 0;
    for (int x : arr)
    {
        sum += x;
    }
    cout << "Sum = " << sum << endl;
    return 0;
}