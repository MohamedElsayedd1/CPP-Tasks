#include <iostream>
using namespace std;

void double_data(int *int_ptr);

int main()
{
    int data {10};
    int *int_ptr = nullptr;
    cout << "data : " << data << endl;
    double_data(&data);
    cout << "data : " << data << endl;

    cout << endl << "=======================\n\n";

    int_ptr = &data;
    cout << "data : " << data << endl;
    double_data(int_ptr);
    cout << "data : " << data << endl;

    return 0;
}

void double_data(int *int_ptr){
    *int_ptr *= 2;
}