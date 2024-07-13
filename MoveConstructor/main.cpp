#include <iostream>
#include <vector>
using namespace std;

class Move
{
private:
    int *data;

public:
    void set_data(int d)
    {
        *data = d;
    }
    int get_data()
    {
        return *data;
    }
    // constructor
    Move(int d);
    // copy constructor
    Move(const Move &src);
    // move constructor
    Move(Move &&src) noexcept : data{src.data}
    {
        src.data = nullptr;
        cout << "Move constructor is called.\n";
    }
    // destructor
    ~Move()
    {
        if (data != nullptr)
        {
            cout << "Destructor freeing data for " << *data << endl;
        }
        else
        {
            cout << "Destructor freeing data for nullptr\n";
        }
        delete data;
    }
};

int main()
{
    vector<Move> vec;
    vec.push_back(Move(10));
    vec.push_back(Move(20));
    vec.push_back(Move(30));

    return 0;
}

// constructor
Move::Move(int d)
{
    data = new int;
    *data = d;
    cout << "constructor for " << *data << endl;
}

// copy constructor
Move::Move(const Move &src)
{
    data = new int;
    *data = *(src.data);
    cout << "Copy constructor is called.\n";
}
