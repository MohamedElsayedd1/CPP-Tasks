#include <iostream>
#include "Mystring.cpp"
using namespace std;

int main()
{
    Mystring moe{"Moe"};
    Mystring larry{"larry"};
    Mystring curly = "curly";
    cout << "Enter first name : ";
    cin >> curly;
    cout << "The three stooges are : " << larry << " ," << moe << " and "<< curly << endl;
    cout << "================================\n";
    cout << "Enter the the three sooge names separated by space : ";
    cin >> larry >> moe >> curly;
    cout << "The three stooges are : " << larry << ", "<< moe << " ,and "<< curly << endl;
    return 0;
}

ostream &operator<<(ostream &os, const Mystring &rhs){
    os << rhs.str; // if declared as a friend
    // os.get_str(); ->> not decared as a friend
    return os;
}

istream &operator>>(istream &is, Mystring &rhs){
    const int max_length = 1000;
    delete[] rhs.str;
    // Read input into temporary buffer (up to max_length characters)
    rhs.str = new char[1000];
    is >> rhs.str;
    return is;
}