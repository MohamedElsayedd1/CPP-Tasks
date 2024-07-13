#include <iostream>
#include <memory>
using namespace std;

class Test
{
private:
    int data;

public:
    friend ostream &operator<<(ostream &os, const Test &obj);
    Test() : data{0} { cout << "Test constructor (" << data << ")" << endl; };
    Test(int d) : data{d} { cout << "Test constructor (" << data << ")" << endl; };
    ~Test()
    {
        cout << "Test destructor (" << data << ")" << endl;
    }
};

ostream &operator<<(ostream &os, const Test &obj)
{
    os << obj.data;
    return os;
}

// using function custom deleter
void my_deleter(Test *ptr)
{
    cout << "Hello im a function custom deleter.\n";
    delete ptr;
}

int main()
{

    {
        // using function custom deleter
        shared_ptr<Test> t1{new Test(100), my_deleter};
    }

    {
        // using lambda expression
        shared_ptr<Test>(new Test(1000), [](Test *ptr)
                         {
            cout << "hello im a lambda deleter.\n";
            delete ptr; });
    }

    return 0;
}