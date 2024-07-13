#ifndef ACCOUNT_H
#define ACCOUNT_H

#pragma once
#include <string>
#include <iostream>
using namespace std;

class Account
{ 
private:
    string name;
    double balance;
public:
    Account();
    Account(string n, double b);
    void deposit(int d);
    void withdraw(int w);

};

#endif