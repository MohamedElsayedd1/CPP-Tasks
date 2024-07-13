#include <iostream>
using namespace std;

int main()
{
    int A[2][3], B[2][3], C[2][3];
    cout << "Adding 2 matrix program ...\n";
    cout << "Enter 1st 2x3 matrix elements : ";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "Enter 2nd 2x3 matrix elements : ";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> B[i][j];
        }
    }
    cout << "Sum : \n";
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}