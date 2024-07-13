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

void func(shared_ptr<Test> p){
    cout << "use_count : " << p.use_count() << endl;
}

int main()
{
    shared_ptr<int> p1 {new int(100)};
    shared_ptr<int> p2 {p1}; // copy constructor -> allows shared ownership

    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;

    p1.reset(); // p1 is nulled out, but memory still allocated, only p2 owns the heap object

    cout << p1.use_count() << endl;
    cout << p2.use_count() << endl;

    cout << "====================================\n";

    shared_ptr<Test> ptr = make_shared<Test>(100);
    func(ptr); // here i send a copy of shared ptr to the func function, we can send it by reference to prevent copying 
    cout << "use_count : " << ptr.use_count() << endl;
    {
        shared_ptr<Test> ptr1 {ptr}; // shared ownership
        cout << "use_count : " << ptr1.use_count() << endl;
        {
            shared_ptr<Test> ptr2 {ptr};
            cout << "use_count : " << ptr.use_count() << endl;
            ptr.reset();
            // when goes out of scope, p2 is nulled out and Use_count counts down
        }
        cout << "use_count : " << ptr1.use_count() << endl;
        cout << "Data pointed to : " << *ptr1 << endl;
    }
    cout << "use_count : " << ptr.use_count() << endl;

    cout << "====================================\n";

    // shared_ptr<Account> acc1 = make_shared<Account>("Larry"); // invalid new-expression of abstract class type 'Account'
    shared_ptr<Account> acc1 = make_shared<Savings>("Larry", 1000, 0.05);
    shared_ptr<Account> acc2 = make_shared<CheckingAccount>("Mohamed", 12000, 1.5);
    shared_ptr<Account> acc3 = make_shared<TrustAccount>("Spiderman", 5000, 2.5);

    vector<shared_ptr<Account>> vec;
    // shared pointers are copied into vector now use_count() increase by one
    // vec.push_back(acc1);
    // vec.push_back(acc2);
    // vec.push_back(acc3);
    // to avoid coping we can use move semantic
    vec.push_back(move(acc1));
    vec.push_back(acc2);
    vec.push_back(acc3);

    for(const auto &x : vec){ // can be copied since we are using shared pointers
        cout << *x << endl;
        cout << "use_count : " << x.use_count() << endl;
    }


    return 0;
}