#include <iostream>
#include <string>
using namespace std;

void reverse_string(string &s);

int main()
{
    string str = "Mohamed Elsayed";
    cout << "Original string : " << str << endl;
    reverse_string(str);
    cout << "Reverse string : " << str << endl;

    return 0;
}

void reverse_string(string &s)
{
    // Get pointers to the beginning and end of the string
    char *begin_ptr = &s[0];
    char *end_ptr = &s[s.size() - 1];

    // Reverse the string using pointers
    while (begin_ptr < end_ptr)
    {
        // Swap characters pointed by begin_ptr and end_ptr
        char temp = *begin_ptr;
        *begin_ptr = *end_ptr;
        *end_ptr = temp;

        // Move pointers towards the center
        begin_ptr++;
        end_ptr--;
    }
}
