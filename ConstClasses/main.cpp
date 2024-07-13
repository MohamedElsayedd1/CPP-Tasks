#include <iostream>
using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    // overloaded constructors
    Player() : name{"None"}, health{0}, xp(0)
    {
        cout << "string arg is called" << endl;
    }

    Player(string n, int h, int x);

    string get_name() const;
    void set_name(string name);
};

void diplay_player_name(const Player &p);

int main()
{
    const Player villian{"Villian", 100, 88};
    diplay_player_name(villian);

    // villian.set_name("hero");  -> compiler error trying to modify object's attributes

    return 0;
}

Player::Player(string n, int h, int x) : name{n}, health(h), xp(x)
{
    cout << "three args is called" << endl;
}

string Player::get_name() const
{
    return name;
}

void Player::set_name(string name)
{
    this->name = name;
}

void diplay_player_name(const Player &p)
{
    cout << p.get_name() << endl;
}