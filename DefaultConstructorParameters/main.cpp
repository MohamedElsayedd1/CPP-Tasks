#include <iostream>
using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;

public:
    Player(string n = "None", int h = 0, int x = 0);
};

int main()
{
    Player empty;                       // None, 0, 0
    Player frank("frank");              // frank, 0, 0
    Player hero{"hero", 100};           // hero, 100, 0
    Player villian("villian", 100, 19); // villian, 100, 19

    return 0;
}

Player::Player(string n, int h, int x)
    : name{n}, health{h}, xp{x}
{
    cout << "Three aguments constructor is called.\n";
}