#include <iostream>
#include<vector>

using namespace std;

class Player{
    // attributes
    string name; 
    int health;
    int xp;

    // methods
    void talk(string txt);
    bool is_dead();
};

class Account{
    // attributes 
    string name {"Account"};
    double balance {0.0};

    // methods
    bool is_deposited(double);
    bool is_withdrawed(double);
};

int main()
{
    Account frank_account;
    Account jim_account;

    Player killer;
    Player hero;

    // create an array of objects
    Player players[] {killer, hero};
    Account accounts[] {frank_account, jim_account};


    // create vector of objects
    vector<Player> randomPlayers {hero};
    randomPlayers.push_back(hero);
    vector<Account> randomAccounts {frank_account};
    randomAccounts.pop_back();

    // allocating memory on heap for Player objext
    Player *enemy =  {nullptr};
    enemy = new Player(); 

    delete enemy;


    return 0;
}