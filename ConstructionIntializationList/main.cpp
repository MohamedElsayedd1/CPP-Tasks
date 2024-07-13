#include <iostream>
using namespace std;

class Account
{
private:
    string name;
    double balance;

public:
    Account();
    Account(string n);
    Account(string n, double b);
};

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    Player();
    Player(string n);
    Player(string n, int h, int x);
};

int main()
{
    Account empty;
    Account frank("frank");
    Account jim("Jim", 109.0);

    Player none;
    Player john("john");
    Player Mohamed("Mohamed", 100, 22);

    return 0;
}

Account::Account() : name{"None"}, balance{0.0}
{
}

Account::Account(string n) : name{n}
{
}

Account::Account(string n, double b) : name{n}, balance{b}
{
}

Player::Player() : name{"None"}, health{0}, xp{0}
{
}

Player::Player(string n) : name{n}, health{0}, xp{0}
{
}

Player::Player(string n, int h, int x) : name{n}, health{h}, xp{x}
{
}