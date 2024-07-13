#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int random = 0, count = 10, min = 1, max = 10;
    srand(time(nullptr));
    for (size_t i = 0; i < count; i++)
    {
        random = rand() % max + min;
        cout << random << endl;
    }
}