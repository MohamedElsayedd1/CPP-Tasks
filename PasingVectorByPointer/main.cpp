#include <iostream>
#include <vector>
using namespace std;

void display_vectors(const vector<string> *const str);
void diplay_array(int *arr, int dest);

int main()
{
    vector<string> stooges{"larry", "Moe", "Curly"};
    int array[]{100, 89, 90, 78, -1};
    display_vectors(&stooges);

    cout << endl
         << "============================\n\n";

    diplay_array(array, -1);

    return 0;
}

void display_vectors(const vector<string> *const str)
{
    for (auto i : *str)
    {
        cout << i << " ";
    }
    cout << endl;
}

void diplay_array(int *arr, int dest)
{
    while (*arr != dest)
        cout << *arr++ << " ";
    cout << endl;
}