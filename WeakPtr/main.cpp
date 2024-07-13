#include <iostream>
#include <memory>
using namespace std;

class B;

class A{
private : 
    shared_ptr<B> b_ptr;
public : 
    A() { cout << "A constructor.\n";};
    ~A() {  cout << "A destructor.\n";};
    void set_ptr(const shared_ptr<B> &ptr){
        b_ptr = ptr;
    }
};

class B{
private : 
    weak_ptr<A> a_ptr; // we have to make it weak_ptr to break the strong circular reference between two objects, and deallocate heap memory properly
public : 
    B() { cout << "B constructor.\n";};
    ~B() {  cout << "B destructor.\n";};
    void set_ptr(const shared_ptr<A> &ptr){
        a_ptr = ptr;
    }
};

int main()
{
    shared_ptr<A> A_obj = make_shared<A>();
    shared_ptr<B> B_obj = make_shared<B>();
    A_obj->set_ptr(B_obj);
    B_obj->set_ptr(A_obj);

    return 0;
}