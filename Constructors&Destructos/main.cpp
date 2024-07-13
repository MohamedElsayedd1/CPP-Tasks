#include <iostream>
using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    void set_name(string n)
    {
        name = n;
    }

    // Overloaded constructors
    Player()
    {
        cout << "No arguments constructor is called.\n";
    }

    Player(string n)
    {
        cout << "String argument constructor is called.\n";
    }

    Player(string n, int health, int xp)
    {
        cout << "Three argument constructor is called.\n";
    }

    // Destructor
    ~Player()
    {
        cout << "Destructor is called for " << name << ".\n";
    }
};

int main()
{
    {
        Player slayer;
        slayer.set_name("slayer");
    }

    {
        Player hero;
        hero.set_name("Hero");
        Player frank("Frank");
        frank.set_name("Frank");
        Player villian("villian", 100, 12);
        villian.set_name("villian");
    }

    Player *enemy = new Player("Enemy", 78, 16);
    enemy->set_name("Enemy");
    Player *boss = new Player("Boss", 88, 100);
    boss->set_name("Boss");

    delete enemy;
    delete boss;

    return 0;
}