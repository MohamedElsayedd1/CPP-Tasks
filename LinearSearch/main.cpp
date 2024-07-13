#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    int key;
    int index = -1;
    cout << "Enter numbers : ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter a key : ";
    cin >> key;
    for (int i = 0; i < 10; i++)
    {
        if (key == arr[i])
        {
            index = i;
            break;
        }
        else
        {
            index = -1;
        }
    }
    if (index >= 0 && index <= 10)
    {
        cout << "Number has been found at index " << index;
    }
    else
    {
        cout << "Number is not found";
    }
    return 0;
}