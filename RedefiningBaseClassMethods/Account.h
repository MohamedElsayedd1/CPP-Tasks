#ifndef ACCOUNT_H
#define ACCOUNT_H

#pragma once
#include <iostream>
using namespace std;

class Account
{
protected : 
    double balance;
public:
    Account();
    Account(double);
    ~Account();
    void deposit(double amount);
    void withdraw(double amount);
    friend ostream &operator<<(ostream &os, const Account &rhs);

};

#endif