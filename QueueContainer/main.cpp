#include <iostream>
#include <queue>

using namespace std;

template <typename T>
void display(queue<T> q)
{
    cout << "Queue : [ ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop(); // don't forget to pop
    }
    cout << "]" << endl;
}

int main()
{
    queue<int> q;
    display(q);

    for (int i = 1; i <= 5; i++)
        q.push(i); // pushes from the back

    display(q);

    cout << "Front : " << q.front() << endl;
    cout << "Back : " << q.back() << endl;
    cout << "Size : " << q.size() << endl;

    q.pop(); // pop from the front
    display(q);

    q.push(200);
    display(q);

    while (!q.empty())
        q.pop(); // pop all elements from the front
    display(q);
    cout << "Size : " << q.size() << endl;

    q.push(100);
    q.push(200);
    q.push(300);
    display(q);

    cout << "Front : " << q.front() << endl;
    cout << "Back : " << q.back() << endl;
    cout << "Size : " << q.size() << endl;

    q.pop();
    display(q);

    cout << "Front : " << q.front() << endl;
    cout << "Back : " << q.back() << endl;
    cout << "Size : " << q.size() << endl;

    return 0;
}