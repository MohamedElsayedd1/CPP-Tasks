#include <iostream>
#include <vector>
#include "Mystring.cpp"

using namespace std;

int main()
{
    Mystring s1; // default constructor
    s1.display();
    s1.get_length();
    cout << "str address : " << (int *)s1.get_str() << endl;
    cout << "=======================\n";
    Mystring s2{"Mohamed"}; // overloaded constructor
    s2.display();
    s2.display();
    cout << "str address : " << (int *)s2.get_str() << endl;
    cout << "=======================\n";
    Mystring s3{s2}; // overloaded copy constructor
    s3.display();
    s3.get_length();
    cout << "str address : " << (int *)s3.get_str() << endl;
    cout << "=======================\n";
    Mystring s4 = "Khaled"; // overloaded copy constructor -> intialization
    s4.display();
    s4.get_length();
    cout << "str address : " << s4.get_str() << endl;

    cout << "=======================\n";
    s1 = s2; // using default assingment opertor method member if we didn't implement our deep copy assignment operator -> shallow copying both s1, s2 are pointing to same memory address
    s2.display();
    s2.display();
    cout << "str address : " << (int *)s1.get_str() << endl;
    cout << "str address : " << (int *)s2.get_str() << endl;

    cout << "=======================\n";
    s3 = "Hi mohamed"; // = assignment overloaded operator -> Move assignment operator
    s3.display();
    s3.get_length();
    cout << "str address : " << (int *)s3.get_str() << endl;

    cout << "=======================\n";
    s1 = s2 = s3; // tool chain assignment
    s1.display();
    s2.display();
    s3.display();

    cout << "========================\n";

    Mystring s5("Kelly");
    s5 = Mystring("Joe");
    s5 = "Yoyo";

    cout << "========================\n";

    Mystring s6;
    s6 = "frank";

    cout << "========================\n";

    vector<Mystring> vec;
    vec.push_back(Mystring("hi"));

    cout << "=========================\n";


    return 0;
}