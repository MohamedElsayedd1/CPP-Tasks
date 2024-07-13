#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;

void display(int n);
void display(double n);
void display(string s);
void display(string s, string t);
void display(vector<string>);
void display(vector<int>);

int main()
{
    int x = 'B';
    vector<string> names{"Khaled", "Omar", "Ali"};
    vector<int> numbers{11, 22, 44};
    display(10);
    display('A'); // character 'A' is promoted to int
    display(20.00);
    display(20.0f);   // float number is promoted to double
    display("Ahmed"); // C_type string is promoted to C++ string
    display("Ahmed", "Mohmed");
    display(names);
    display(numbers);
}

void display(int n)
{
    cout << n << endl;
}
void display(double n)
{
    cout << n << endl;
}
void display(string s)
{
    cout << s << endl;
}
void display(string s, string t)
{
    cout << s + " " + t << endl;
}
void display(vector<string> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}
void display(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}