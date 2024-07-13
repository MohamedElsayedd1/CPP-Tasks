#include <iostream>
using namespace std;

class Deep
{
private:
    int *data;

public:
    void set_data_again(int d);
    int return_data(void);
    // Constructor
    Deep(int d);
    // Deep Copy Constructor
    Deep(const Deep &src);
    // Destructor
    ~Deep();
};

void display_deep(Deep object);

int main()
{
    Deep obj1(100);
    display_deep(obj1);

    Deep obj2(obj1);
    obj2.set_data_again(1000);
    display_deep(obj1);

    return 0;
}

void Deep::set_data_again(int d)
{
    *data = d;
}

int Deep::return_data(void)
{
    return *data;
}

// Constructor
Deep::Deep(int d)
{
    data = new int;
    *data = d;
}

// Deep Copy Constructor
Deep::Deep(const Deep &src)
{
    data = new int;
    *data = *src.data;
    cout << "Copy constructor -> Deep copy\n";
}

// Destructor
Deep::~Deep()
{
    delete data;
    cout << "Destructor freeing data" << endl;
}

void display_deep(Deep object)
{
    cout << "data = " << object.return_data() << endl;
}