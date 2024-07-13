#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H

#pragma once
#include "Account.h"

class Saving_Account : public Account
{
private : 
    double interest_rate;
public:
    Saving_Account();
    Saving_Account(double amount, double rate);
    ~Saving_Account();
    void deposit(double amount); // deposit base method is overridden
    // withdraw base method is inherited
    friend ostream &operator<<(ostream &os, const Saving_Account &rhs);

};

#endif