#include <iostream>
#include <memory>
using namespace std;
#include "I_Printable.cpp"
#include "Account.cpp"
#include "CheckingAccount.cpp"
#include "Savings.cpp"
#include "TrustAccount.cpp"
#include "Account_Util.cpp"


class Test{
private:
    int data;
public :
    friend ostream &operator<<(ostream &os, const Test &obj);
    Test() : data{0}{ cout << "Test constructor (" << data <<")" << endl;};
    Test(int d) : data{d}{ cout << "Test constructor (" << data <<")" << endl;};
    ~Test(){
        cout << "Test destructor (" << data <<")" << endl;
    }
};

ostream &operator<<(ostream &os, const Test &obj){
    os << obj.data;
    return os;
}

int main()
{

    Test *t = new Test{1000};
    delete t;

    unique_ptr<int> ptr {new int{100}};
    cout << ptr.get() << endl;
    cout << *ptr << endl;

    unique_ptr<Test> p = make_unique<Test>(500);

    unique_ptr<Test> t2;
    // t2 = p;  // smart pointers can't be assigned or copied, but can be moved
    t2 = move(p); // ownership has been tranfered and moved to t2, now p pointer points to nullptr "two or more smart pointer can't point at same storage"

    if(!p){
        cout << "p now is nullptr\n";
    }
    cout << *t2 << endl;

    // unique_ptr<Account> a1 = make_unique<Account>(); // Error Account is an abstract class.

    unique_ptr<Account> a1 = make_unique<CheckingAccount>("Larry", 100);
    cout << *a1 << endl;
    a1->deposit(5000);
    cout << *a1 << endl;

    vector<unique_ptr<Account>> vec;
    // vec.push_back(a1); // ERROR a1 can't be copied because it's smart pointer

    vec.push_back(move(a1)); // moved smart pointers is fine
    vec.push_back(make_unique<Savings>("moe", 4567));
    vec.push_back(make_unique<CheckingAccount>("hala", 254));
    vec.push_back(make_unique<Savings>("cr7", 8899));

    for(auto &x : vec){ // can't copy unique pointers, we have to it by refecerence&
        cout << *x << endl;
    }

    unique_ptr<int> x = make_unique<int>(100);
    unique_ptr<int> y;
    y = move(x);
    cout << *y << endl;


    return 0;
}