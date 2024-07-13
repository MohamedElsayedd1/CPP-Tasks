#include <iostream>
using namespace std;

int main()
{
    int n;
    int i = 1;
    cout << "Enter the number : ";
    cin >> n;

    /* while(i <= n){
        cout << i++ << " ";
    }

    do{
        cout << i++ << " ";
    }while(i <= n);
    */

    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    return 0;
}