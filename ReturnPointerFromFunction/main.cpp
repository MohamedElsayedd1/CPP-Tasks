#include <iostream>
using namespace std;

int *Largest(int *x, int *y);
int *create_array(int size, int value);
void Display_array(const int *const arr, int size);

int main()
{
    int a = 10, b = 50;
    int *largest_ptr{nullptr};
    largest_ptr = Largest(&a, &b);
    cout << "Address : " << largest_ptr << endl;
    cout << "value : " << *largest_ptr << endl;

    cout << "=========================" << endl;

    int *my_array{nullptr};
    int size{}, value{};
    cout << "Enter how many integers u would like to allocate : ";
    cin >> size;
    cout << "Enter the value u would like to set : ";
    cin >> value;
    my_array = create_array(size, value);
    Display_array(my_array, size);

    return 0;
}

int *Largest(int *x, int *y)
{
    if (*x > *y)
        return x;
    else
        return y;
}

int *create_array(int size, int value)
{
    int *storage = new int[size];
    for (int i = 0; i < size; i++)
    {
        *(storage + i) = value;
    }
    return storage;
}

void Display_array(const int *const arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}