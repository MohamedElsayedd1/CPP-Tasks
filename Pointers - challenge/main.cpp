#include <iostream>
using namespace std;

void printArray(const int *arr, int size);
int *applyAll(const int *arr1, const int *arr2, const int size1, const int size2);

int main()
{
    int *result{nullptr};
    int array1[]{1, 2, 3, 4, 5};
    int array2[]{10, 20, 30};
    cout << "Array 1 : ";
    printArray(array1, 5);
    cout << "Array 2 : ";
    printArray(array2, 3);
    result = applyAll(array1, array2, 5, 3);
    cout << "Result : ";
    printArray(result, 15);

    return 0;
}

void printArray(const int *arr, int size)
{
    cout << " [ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "] ";
    cout << endl;
}

int *applyAll(const int *arr1, const int *arr2, const int size1, const int size2)
{
    int *storage = new int[size1 * size2];
    int index = 0;
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size1; j++)
        {
            *(storage + index) = arr2[i] * arr1[j];
            index++;
        }
    }
    return storage;
}