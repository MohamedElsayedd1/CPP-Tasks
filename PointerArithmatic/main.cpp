#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

int main()
{
    int scores[]{100, 89, 87, 99, -1};
    int *scores_ptr{nullptr};
    scores_ptr = scores;
    cout << scores_ptr << endl;
    while (*scores_ptr != -1)
    {
        cout << *scores_ptr << endl;
        scores_ptr++;
    }
    cout << scores_ptr << endl;

    cout << "\n==============================\n\n";

    scores_ptr = scores;
    while (*scores_ptr != -1)
        cout << *scores_ptr++ << endl;

    cout << "\n==============================\n\n";
    cout << boolalpha;

    string s1{"Frank"};
    string s2{"Frank"};
    string s3{"James"};

    string *p1{&s1};
    string *p2{&s2};
    string *p3{&s1};

    cout << p1 << " == " << p2 << " : " << (p1 == p2) << endl; // false - 0
    cout << p1 << " == " << p3 << " : " << (p1 == p3) << endl; // true - 1

    cout << "\n=========================\n\n";

    cout << *p1 << " == " << *p2 << " : " << (*p1 == *p2) << endl; // true - 1
    cout << *p1 << " == " << *p3 << " : " << (*p1 == *p3) << endl; // true - 1

    p3 = &s3;                                                      // Points to "James"
    cout << *p1 << " == " << *p3 << " : " << (*p1 == *p3) << endl; // false - 0

    cout << "\n=========================\n\n";

    string str{"Frank"};
    char *char_ptr1 = &str[0];
    char *char_ptr2 = &str[3];

    cout << "In the string " << str << ", " << *char_ptr2 << " is " << (char_ptr2 - char_ptr1) << " characters away from " << *char_ptr1;
}