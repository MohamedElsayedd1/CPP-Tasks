#include "Saving_Account.h"

Saving_Account::Saving_Account() : Account(), interest_rate(0.0)
{

}

Saving_Account::~Saving_Account()
{

}

Saving_Account::Saving_Account(double amount, double rate) : Account(amount), interest_rate{rate}{

}

void Saving_Account::deposit(double amount){
    amount += (amount*interest_rate);
    Account::deposit(amount);
}

ostream &operator<<(ostream &os, const Saving_Account &rhs){
    os << "Account balance : " << rhs.balance << ", Interest rate : " << rhs.interest_rate;
    return os;
}