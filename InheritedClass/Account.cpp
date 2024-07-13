#include "Account.h"

Account::Account() : name{"Account"}, balance{0.0}
{
    cout << "Account obj is made.\n";
}

Account::Account(string n, double b) : name{n}, balance{b}{
    cout << "Account obj is made.\n";
}



void Account::deposit(int d){
    balance += d;
    cout << d << "$ is deposited - Account class.\n";
}

void Account::withdraw(int w){
    if(balance >= w){
        balance -= w;
        cout << w << "$ is withdrawn - Account class.\n";
    }
    else{
        cout << "No enough money to withdraw - Account class.\n";
    }
}