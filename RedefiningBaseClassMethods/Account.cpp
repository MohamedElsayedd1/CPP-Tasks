#include "Account.h"

Account::Account() : balance{0.0}{

}

Account::Account(double b) : balance {b}{

}
Account::~Account(){

}

void Account::deposit(double amount){
    balance += amount;
}

void Account::withdraw(double amount){
    if(amount > balance){
        cout << "No enough money to withdraw.\n";
    }
    else{
        balance -= amount;
    }
}

ostream &operator<<(ostream &os, const Account &rhs){
    os << "Account balance : " << rhs.balance;
    return os;
}