// Online C++ compiler to run C++ program online
#include <iostream>

using namespace std;
void reverse_string(string &s);

int main()
{
    // Write C++ code here
    string str = "Mohamed Elsayed";
    cout << "Original string : " << str << endl;
    reverse_string(str);
    cout << "Reverse string : " << str << endl;

    return 0;
}

void reverse_string(string &s)
{
    int start = 0, end = s.size()-1;
    char temp;
    while(start < end)
    {
        temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}
