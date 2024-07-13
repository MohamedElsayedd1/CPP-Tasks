#include <iostream>
using namespace std;

class Myclass;

class Anotherclass
{
public:
    void display_private_data(Myclass &obj);
};

class Myclass
{
private:
    int privateData;

public:
    // declaring a friend class, it can access private members
    friend void Anotherclass::display_private_data(Myclass &obj);
    // constructor
    Myclass(int d) : privateData{d} {

                     };
};

int main()
{
    Myclass object(20);
    Anotherclass anotherObject;
    anotherObject.display_private_data(object);
    anotherObject.display_private_data(object);

    return 0;
}

void Anotherclass::display_private_data(Myclass &obj)
{
    cout << "Data : " << obj.privateData << endl;
    obj.privateData = 60;
}