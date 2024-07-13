#include <iostream>
using namespace std;

constexpr int get_value(){
    return 3;
}

int main(int argc, char **argv)
{
    constexpr int value = get_value();
    cout << "value : " << value;
    return 0;
}

