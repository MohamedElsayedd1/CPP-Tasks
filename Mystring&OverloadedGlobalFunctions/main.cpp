#include <iostream>
#include "Mystring.cpp"
using namespace std;

int main()
{
    Mystring larry1 = "LARRY";
    Mystring moe {"Moe"};
    larry1.display();

    Mystring larry2 =! larry1;
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

Mystring operator!(const Mystring &lhs){
    Mystring temp;
    size_t i = 0;
    temp.str = new char[strlen(lhs.str) + 1];
    strcpy(temp.str, lhs.str);
    for(i = 0; i < strlen(lhs.str); i++)
        temp.str[i] = tolower(lhs.str[i]);
    temp.str[i] = '\0';
    cout << "Global function operator ! was called.\n";
    return temp;
}

bool operator==(const Mystring &lhs, const Mystring &rhs){
    return (strcmp(lhs.str, rhs.str) == 0);
    cout << "Global function operator == was called.\n";
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs){
    size_t buff_size = strlen(lhs.str) + strlen(rhs.str) + 1;
    Mystring temp;
    temp.str = new char[buff_size + 1];
    strcpy(temp.str, lhs.str);
    strcat(temp.str, rhs.str);
    cout << "Global function operator + was called.\n";
    return temp; 
}

