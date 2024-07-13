#include <iostream>
using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    string get_name();
    int get_health();
    int get_xp();
    // Constructor
    Player(string n = "None", int health = 0, int x = 0);
    // Copy constructor
    Player(const Player &src);
    // Destructor
    ~Player()
    {
        cout << "Destructor is called.\n";
    }
};

void display_player(Player p);
Player create_obj();

int main()
{
    Player frank; // None, 0, 0
    display_player(frank);
    Player hero{"Hero"}; // Hero, 0, 0
    Player _obj = create_obj();
    display_player(_obj);
    Player slayer("Slayer", 98); // Slayer, 98, 0
    Player sla_obj{slayer};
    Player villian("Villian", 100, 100); // Villian, 100, 100
    Player vil_obj(villian);

    return 0;
}

Player::Player(string n, int h, int x) : name(n), health{h}, xp{x}
{
    cout << "Three aguments constructor.\n";
}

Player::Player(const Player &src) : name{src.name}, health{src.health}, xp{src.xp}
{
    cout << "Copy constructor made copy of " << src.name << endl;
}

string Player::get_name()
{
    return name;
}

int Player::get_health()
{
    return health;
}

int Player::get_xp()
{
    return xp;
}

void display_player(Player p)
{
    cout << "Name : " << p.get_name() << endl;
    cout << "health : " << p.get_health() << endl;
    cout << "Xp : " << p.get_xp() << endl;
}

Player create_obj(){
    Player obj{"khaled", 99, 10};
    return obj;
}