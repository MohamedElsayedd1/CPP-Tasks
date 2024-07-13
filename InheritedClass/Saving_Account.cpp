#include "Saving_Account.h"

Saving_Account::Saving_Account() : interest_rate{0.0}
{
    
    cout << "Saving account obj is made.\n"; 
}

Saving_Account::~Saving_Account()
{

}

Saving_Account::Saving_Account(double r) : interest_rate(r){
    cout << "Saving account obj is made.\n";
}

double Saving_Account::get_interest_rate(){
    return interest_rate;
}

