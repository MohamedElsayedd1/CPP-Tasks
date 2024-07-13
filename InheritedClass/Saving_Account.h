#ifndef SAVING_ACCOUNT_H
#define SAVING_ACCOUNT_H

#pragma once
#include "Account.h"

class Saving_Account : public Account
{
private:
    double interest_rate;
public:
    Saving_Account();
    Saving_Account(double r);
    ~Saving_Account();
    double get_interest_rate();

};

#endif