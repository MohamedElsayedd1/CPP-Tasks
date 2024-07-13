#include <iostream>
using namespace std;

class Shallow
{
private:
    int *data;

public:
    int get_data()
    {
        return *data;
    }
    void set_data_again(int d)
    {
        *data = d;
        cout << "data is set again to " << d << endl;
    }
    // Overloaded constructors
    Shallow(int d = 1)
    {
        data = new int;
        *data = d;
        cout << "data is set to " << d << endl;
    }
    // Copy constructor
    Shallow(const Shallow &src) : data(src.data)
    {
        cout << "Copy constructor -> shallow copy\n";
    }
    // Destructor
    ~Shallow()
    {
        delete data;
        cout << "Destructor freeing data\n";
    }
};

void display_shallow(Shallow object);

int main()
{
    Shallow obj1(100);
    display_shallow(obj1); // Shallow class destructor is called which deallocate the allocated memory
    // which means the pointer "data" is pointing to unvalid memory

    obj1.set_data_again(1000); // may progam crash happens because we are trying to access invaild memory location

    Shallow obj2(obj1);
    obj2.set_data_again(15000); // changed obj1, obj2 data bacause pointer is pointing to the same memory location in both objects

    return 0;
}

void display_shallow(Shallow object)
{
    cout << "data : " << object.get_data() << endl;
}