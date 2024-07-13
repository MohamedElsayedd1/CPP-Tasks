#include <iostream>
using namespace std;

int main()
{
    float arr[100], sum = 0.0f, avg = 0;
    int n;
    cout << "Enter the number of elements in an array : ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << "1. Enter Element #" << i+1 << " : ";
        cin >> arr[i];
        sum += arr[i];
    }
    cout << "=============================" << endl;
    avg = sum / (float)n;
    cout << "Average : " << avg;
    return 0;
}