#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    cout << "Enter number : ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    cout << "Sum = " << sum << "\n";
    if(2*n == sum){
        cout << n << " is a prefect number\n";
    }
    return 0;
}