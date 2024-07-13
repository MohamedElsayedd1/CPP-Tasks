#include <iostream>

using namespace std;

class I_Printable{
public : 
    friend ostream &operator<<(ostream &os, const I_Printable &obj);
    virtual void print(ostream &os) const = 0;
};

class Account{
    friend ostream &operator<<(ostream &os, const Account &obj);
public :
    virtual void withdraw(){
        cout << "Account::withdraw\n";
    }
    virtual void print(ostream &os) const{
        os << "Account diplay." << endl;
    }
};

class Savings : public Account{
public :
    virtual void withdraw() override{
        cout << "Savings::withdraw\n";
    }
    virtual void print(ostream &os) const override{
        os << "Savings diplay." << endl;
    }
};


class Checking : public Account{
public :
    virtual void withdraw() override{
        cout << "Checking::withdraw\n";
    }
    virtual void print(ostream &os) const override{
        os << "Checking diplay" << endl;
    }
};

class Trust : public Savings{
public :
    virtual void withdraw() override{
        cout << "Trust::withdraw\n";
    }
    virtual void print(ostream &os) const override{
        os << "Trust diplay." << endl;
    }
};

void fun1(const Account& obj){
    cout << obj << endl;
}


int main()
{

    cout << "===============Problem solution 1================\n";

    Account *ptr1 = new Account();
    cout << *ptr1<< endl;

    Account *ptr2 = new Savings(); 
    cout << *ptr2 << endl; // << is not virtual

    cout << "===============Problem solution 2================\n\n";

    fun1(*ptr1);
    fun1(*ptr2);

    cout << "============Expected output===========\n\n";

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
    obj.print(os);
    return os;
}


ostream &operator<<(ostream &os, const I_Printable &obj){
    obj.print(os);
    return os;
}