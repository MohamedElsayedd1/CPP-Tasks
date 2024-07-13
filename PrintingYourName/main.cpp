#include <iostream>
#include <string.h>
#include <cctype>
#include <cstring>
using namespace std;

char first_name[20];
char sec_name[20];
char full_name[50];

int main()
{
    cout << "Enter first name : ";
    cin >> first_name;
    cout << "Enter last name : ";
    cin >> sec_name;
    cout << "Hello, " << first_name << " your first name has " << strlen(first_name) << " characters.\n";
    cout << "and your last name has " << strlen(sec_name) << " characters.\n";
    strcpy(full_name, first_name);
    strcat(full_name, " ");
    strcat(full_name, sec_name);
    cout << "Full name is : " << full_name;
}
