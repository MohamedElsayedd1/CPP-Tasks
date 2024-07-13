#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int key;
    int l = 0, h = 9, mid;
    cout << "Enter numbers in ascending order : ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter a key : ";
    cin >> key;
    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == arr[mid])
        {
            cout << "\nKey is found at index " << mid;
            return 0;
        }
        else if (key > arr[mid])
        {
            l = mid + 1;
        }
        else if (key < arr[mid])
        {
            h = mid - 1;
        }
    }
    cout << "Key is not found";
    return 0;
}