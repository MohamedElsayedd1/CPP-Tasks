// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;
void swap(int *x, int *y);
void Print_array(int arr[], int size);
void reverse_array(int *arr, int size);

int main() {
    // Write C++ code here
    int arr[] {11, 12, 90, -1, 5, -2, 8};
    cout << "Original array : ";
    Print_array(arr, 7);
    reverse_array(arr, 7);
    cout << "Reverse array : ";
    Print_array(arr, 7);

    return 0;
}

void Print_array(int arr[], int size){
    for(int i = 0; i < size; i++){
       cout << *(arr + i) << " ";
    }
    cout << endl;
}

void reverse_array(int *arr, int size){
    int *s_ptr {nullptr}, *e_ptr {nullptr};
    s_ptr = arr;
    e_ptr = &arr[size-1];
    while(s_ptr < e_ptr){
        swap(s_ptr, e_ptr);
        s_ptr++;
        e_ptr--;
    }
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}