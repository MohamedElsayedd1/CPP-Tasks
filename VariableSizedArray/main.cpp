#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n{}, q{};
    int size;
    int i, j;
    cin >> n;
    cin >> q;
    int **arr = (int **)malloc(n*sizeof(int));
    int count = n;
    int l = 0;
    
    while(count){
        cin >> size;
        for(int i = 0; i < size; i++){
            arr[i] = (int*)malloc(size*sizeof(int));

            cin >> arr[l][i];
            cout  << "=======> " << arr[l][i] << endl;
        }
        l++;
        count--;
    }
    for(int i = 0; i < 3; i++){
        cout << arr[0][i] << " ";
    }
    cout << endl; 
    for(int i = 0; i < 5; i++){
        cout << arr[1][i] << " ";
    }
    // cout << "==========================\n\n";
    // for(int k = 0; k < n;k++){
    //         cin >> i;
    //         cin >> j;
    //         cout << endl <<"i : " << i << ", j = " << j << endl;
    //         cout << arr[i][j] << " ";
    // }
    
    // cout << endl << arr[0][2] << endl;
    return 0;
}