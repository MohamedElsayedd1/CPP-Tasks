#include <iostream>
#include <string>

using namespace std;

string name;
int age;

string str = "name";

int main()
{
    cout << "what's your name?" << endl;
    cin.ignore();
    std::getline(cin, name);
    cin >> name;

    cout << "what's your age?" << endl;
    cin >> age;

    cout << "my name is " << name << ", and my age is " << age;

    return 0;
}