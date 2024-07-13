#include <iostream>

using namespace std;

class Account{
    friend ostream &operator<<(ostream &os, const Account &obj);
public :
    virtual void withdraw(){
        cout << "Account::withdraw\n";
    }
};

class Savings : public Account{
    friend ostream &operator<<(ostream &os, const Savings &obj);
public :
    virtual void withdraw() override{
        cout << "Savings::withdraw\n";
    }
};


class Checking : public Account{
    friend ostream &operator<<(ostream &os, const Checking &obj);
public :
    virtual void withdraw() override{
        cout << "Checking::withdraw\n";
    }
};

class Trust : public Savings{
    friend ostream &operator<<(ostream &os, const Trust &obj);
public :
    virtual void withdraw() override{
        cout << "Trust::withdraw\n";
    }
};


int main()
{

    cout << "===============Problem================\n";

    Account *ptr1 = new Account();
    cout << *ptr1<< endl;

    Account *ptr2 = new Savings(); 
    cout << *ptr2 << endl; // << is not virtual

    cout << "============Expected output===========\n";

    Account a;
    cout << a << endl;

    Checking c;
    cout << c << endl;

    Savings s;
    cout << s << endl;

    Trust t;
    cout << t << endl;
    
    return 0;
}


ostream &operator<<(ostream &os, const Account &obj){
    os << "Account display.\n";
    return os;
}

ostream &operator<<(ostream &os, const Savings &obj){
    os << "Savings display.\n";
    return os;
}

ostream &operator<<(ostream &os, const Checking &obj){
    os << "Checking display.\n";
    return os;
}

ostream &operator<<(ostream &os, const Trust &obj){
    os << "Trust display.\n";
    return os;
}