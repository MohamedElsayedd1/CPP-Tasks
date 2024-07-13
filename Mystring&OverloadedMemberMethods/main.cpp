#include <iostream>
#include "Mystring.cpp"
using namespace std;

int main()
{
    Mystring larry1 = "LARRY";
    Mystring moe {"Moe"};
    larry1.display();

    Mystring larry2 =- larry1;
    larry2.display();

    if(larry1 == "LARRY"){
        cout << "are equal.\n";
    }
    else{
        cout << "are not equal.\n";
    }

    if(larry1 == moe){
        cout << "are equal.\n";
    }
    else{
        cout << "are not equal.\n";
    }

    Mystring result;
    result = larry1+moe;
    result.display();
    result = larry2 + "monkey";
    result.display();

    result = moe + " " + larry2 + " donckey " + result;
    result.display();
    return 0;
}