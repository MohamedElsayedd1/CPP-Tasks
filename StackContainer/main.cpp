#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <deque>
using namespace std;

template <typename T>
void display(stack<T> s)
{
    cout << "Stack : [ ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "]" << endl;
}

void test(void)
{
    stack<int> s;
    stack<int, vector<int>> s1;
    stack<int, list<int>> s2;
    stack<int, deque<int>> s3;

    display(s);

    s.push(10);
    display(s);
    s.push(20);
    display(s);
    s.push(30);
    display(s);

    cout << "top : " << s.top() << endl;
    s.pop();
    display(s);
    cout << "top : " << s.top() << endl;
    s.pop();
    display(s);
    cout << "top : " << s.top() << endl;

    cout << "Size : " << s.size() << endl;

    s.top() = 100;
    display(s);
    cout << "top : " << s.top() << endl;

    s.push(200);
    display(s);
    cout << "top : " << s.top() << endl;

    while(!s.empty())
        s.pop();

    display(s);
    cout << "size : " << s.size() << endl;
}

int main()
{
    test();
    return 0;
}