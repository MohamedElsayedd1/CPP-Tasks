#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    char str[10];
    string s0;
    string s1{"Apple"};
    string s2{"Kiwi"};
    string s3{"apple"};
    string s4{"Banana"};
    string s5{s1};
    string s6{s1, 0, 3};
    string s7(10, 'x');

    /*
    cout << str << endl;         // garbage string
    cout << s0 << endl;          // no garbage "empty"
    cout << s0.length() << endl; // 0 -> no elements
    */

    cout << "=============Intialization===============\n";
    cout << "s1 is intialized to : " << s1 << endl;
    cout << "s2 is intialized to : " << s2 << endl;
    cout << "s3 is intialized to : " << s3 << endl;
    cout << "s4 is intialized to : " << s4 << endl;
    cout << "s5 is intialized to : " << s5 << endl;
    cout << "s6 is intialized to : " << s6 << endl;
    cout << "s7 is intialized to : " << s7 << endl;

    cout << "=============Comparison===============\n";
    cout << boolalpha;
    cout << s1 << " == " << s5 << " : " << (s1 == s5) << endl;
    cout << s1 << " == " << s2 << " : " << (s1 == s2) << endl;
    cout << s1 << " != " << s2 << " : " << (s1 != s2) << endl;
    cout << s1 << " < " << s2 << " : " << (s1 < s2) << endl;
    cout << s2 << " > " << s1 << " : " << (s2 > s1) << endl;
    cout << s4 << " < " << s5 << " : " << (s4 < s5) << endl;
    cout << s3 << " < " << s1 << " : " << (s3 < s1) << endl;
    cout << s1 << " == " << "Apple" << " : " << (s1 == "Apple") << endl;

    cout << "=============Assignment===============\n";
    s1 = "Watermelon";
    cout << "s1 is now : " << s1 << endl;
    s2 = s1;
    cout << "s2 is now : " << s2 << endl;
    s3 = "Frank";
    cout << "s3 is now : " << s3 << endl;
    s3[0] = 'C';
    cout << "s3 after changing 1st letter to 'C' : " << s3 << endl;
    s3.at(0) = 'P';
    cout << "s3 after changing 1st letter to 'P' : " << s3 << endl;

    cout << "=============Concatenation===============\n";
    s1 = s1 + " and " + s4 + " juice.";
    cout << "s1 is now : " << s1 << endl;
    s2 += " juice";
    cout << "s2 is now : " << s2 << endl;
    // s2  = "nice " + "cold " + s2 + " juice";  -> compile error because "nice " and "cold " are c-type strings, we should use strcat() to concatenate them

    cout << "=============Looping===============\n";
    s1 = "Apple";
    cout << "s1 characters : " << endl;
    for (size_t i = 0; i < s1.length(); i++)
        cout << s1.at(i) << " ";
    cout << endl;

    s2 = "Watermelon";
    cout << "s1 characters : " << endl;
    for (char c : s2)
    {
        cout << c << " ";
    }
    cout << endl;

    cout << "=============Substring===============\n";
    s1 = "This is a test";
    cout << "s1 is now : " << s1 << endl;
    cout << s1.substr(0, 5) << endl;
    cout << s1.substr(5, 2) << endl;
    cout << s1.substr(8, 1) << endl;
    cout << s1.substr(10, 4) << endl;

    cout << "=============Erase===============\n";
    s1.erase(0, 5); // Erase this from s1 results in "is a test"
    cout << "s1 is now : " << s1 << endl;

    cout << "=============getline===============\n";
    string full_name;
    cout << "Enter your full name : ";
    getline(cin, full_name);
    cout << "Your name is " << full_name << endl;

    cout << "=============nfind===============\n";
    string secret_word{"secret word is Boo"};
    string key;
    cout << "String is : " << secret_word << endl;
    cout << "Enter word to find : ";
    cin >> key;
    size_t pos = secret_word.find(key);
    if (pos != string::npos)
        cout << "Found " << key << " at position " << pos;
    else
        cout << "Sorry, " << key << " not found. ";
}