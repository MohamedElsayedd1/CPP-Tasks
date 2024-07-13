#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int scores[]{100, 70, 98};
    cout << scores << endl;  // address of first element in the array '100'
    cout << *scores << endl; // 100

    int *scores_ptr{scores};
    cout << scores_ptr << endl;  // address of first element in the array '100'
    cout << *scores_ptr << endl; // 100

    cout << "\n============Pointer subscript notation =============\n\n";

    cout << scores_ptr[0] << endl; // 100
    cout << scores_ptr[1] << endl; // 70
    cout << scores_ptr[2] << endl; // 98

    cout << "\n============Array subscript notation =============\n\n";

    cout << scores[0] << endl; // 100
    cout << scores[1] << endl; // 70
    cout << scores[2] << endl; // 98

    cout << "\n=============Pointer offset notation============\n\n";

    cout << *scores_ptr << endl;       // 100
    cout << *(scores_ptr + 1) << endl; // 70
    cout << *(scores_ptr + 2) << endl; // 98

    cout << "\n=============Array offset notation============\n\n";

    cout << *scores << endl;       // 100
    cout << *(scores + 1) << endl; // 70
    cout << *(scores + 2) << endl; // 98

    cout << "\n=========================\n\n";

    cout << scores_ptr << endl;
    cout << scores_ptr + 1 << endl;
    cout << scores_ptr + 2 << endl;
}