#include <iostream>
#include <vector>

using namespace std;

class Player
{
public:
    // attributes
    string name;
    int health;
    int xp;

    // methods
    void talk(string txt)
    {
        cout << name << " says " << txt << "." << endl;
    }
    bool is_dead();
};

class Account
{
public:
    // attributes
    string name{"Account"};
    double balance{0.0};

    // methods
    void is_deposited(double deposit)
    {
        cout << "==========================\n";
        cout << name << " account : \n";
        cout << "In balance : " << balance << endl;
        balance += deposit;
        cout << "Deposited money : " << deposit << endl;
        cout << "Total money after deposit : " << balance << endl;
        cout << "==========================\n";
    }
    void is_withdrawed(double withdraw)
    {
        cout << "==========================\n";
        cout << name << " account : \n";
        cout << "In balance : " << balance << endl;
        balance -= withdraw;
        cout << "Deposited money : " << withdraw << endl;
        cout << "Total money after deposit : " << balance << endl;
        cout << "==========================\n";
    }
};

int main()
{
    Account frank_account;

    frank_account.balance = 50.00;
    frank_account.name = "Frank";
    frank_account.is_deposited(12.00);
    frank_account.is_withdrawed(5.00);

    Account *jim_account = new Account();
    jim_account->balance = 500;
    jim_account->name = "Jim";
    jim_account->is_deposited(100);
    jim_account->is_withdrawed(22);

    Player frank_obj;
    frank_obj.name = "Frank";
    frank_obj.health = 88;
    frank_obj.xp = 12;
    frank_obj.talk("Hi there");

    Player *enemy = new Player();
    (*enemy).name = "enemy";
    (*enemy).health = 100;
    enemy->xp = 10;
    enemy->talk("i will destroy you !");

    return 0;
}