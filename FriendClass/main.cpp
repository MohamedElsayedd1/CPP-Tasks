#include <iostream>
using namespace std;

class Myclass
{
private:
    int privateData;

public:
     // declaring a friend class, it can access private members
     friend class Friendclass;

    // constructor
    Myclass(int d) : privateData{d} {

                     };
};

class Friendclass{
    public: 
        void display_private_data(const Myclass &obj);
};

int main()
{
    Myclass object(20);
    Friendclass friendObj;
    friendObj.display_private_data(object);
    
    return 0;
}

void Friendclass::display_private_data(const Myclass &obj){
    cout << "Data : " << obj.privateData;
}