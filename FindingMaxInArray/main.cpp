#include <iostream>
using namespace std;

int main()
{
    int arr[] = {11, 22, 8, 45, 87, 90, 3, 2, 1};
    int max = arr[0];
    for(int x : arr){
        if(x > max){
            max = x;
        }
    }
    cout << "Maximum number : " << max;
    return 0;
}