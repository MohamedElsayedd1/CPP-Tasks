#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>

using namespace std;
int func1(int a, int b);
void func2(int &x, int y ,int z);

int main()
{
    int x {10}, y {20}, z {};
    z = func1(x, y);
    cout << z << endl;
}

int func1(int a, int b){
    int result {};
    result = a + b;
    func2(result, a, b);
    return result;
}

void func2(int &x, int y ,int z){
    x += y + z;
}
