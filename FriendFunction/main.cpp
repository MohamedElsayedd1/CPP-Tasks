#include <iostream>
using namespace std;

class Myclass
{
private:
    int privateData;

public:
    friend void display_private_data(Myclass &obj); // declaring a friend function, it can access private members
    // constructor
    Myclass(int d) : privateData{d} {

                     };
};

int main()
{
    Myclass object(20);
    display_private_data(object);
    display_private_data(object);
    
    return 0;
}

void display_private_data(Myclass &obj)
{
    cout << "Data : " << obj.privateData << endl;
    obj.privateData = 50;
}