#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int score{100};
    int *score_ptr{&score};

    cout << *score_ptr << endl; // 100
    *score_ptr = 500;
    cout << *score_ptr << endl; // 500
    cout << *score_ptr << endl; // 500

    cout << endl
         << "============================" << endl
         << endl;

    double low_temp{27.5}, high_temp{45.88};
    double *temp_ptr{&low_temp};
    cout << *temp_ptr << endl; // 27.5
    temp_ptr = &high_temp;
    cout << *temp_ptr << endl; // 45.88

    cout << endl
         << "============================" << endl
         << endl;

    string name {"Mohamed"};
    string *name_ptr {&name};
    cout << *name_ptr << endl; // Mohamed
    name = "Ahmed";
    cout << *name_ptr << endl; // Ahmed

    cout << endl
         << "============================" << endl
         << endl;
    
    vector<string> tools {"papper", "pen", "book"};
    vector<string> *tools_ptr {&tools};
    cout << "First tool : " << (*tools_ptr).at(0) << endl; // papper
    cout << "All tools : ";
    for(auto i : (*tools_ptr)){
        cout << i << " "; // papper pen book
    }
    cout << endl;
}
