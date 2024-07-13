#include <iostream>
#include <vector>
#include "Account.cpp"
#include "Player.cpp"

using namespace std;

int main()
{
    Player p1;
    p1.say_hello();

    Account frank_acc;
    frank_acc.set_name("Frank");
    frank_acc.set_balance(1000.00);
    cout << "Account name : " << frank_acc.get_name() << endl;
    cout << "Account balance : " << frank_acc.get_balance() << endl;
    cout << "==========================\n";
    frank_acc.is_deposited(20.0);
    frank_acc.is_withdrawed(10000);

    return 0;
}
