#include <iostream>
#include "Player.cpp"

using namespace std;

void display_players_num();
void create_obj();

int main()
{
    Player frank;
    Player hero{"Hero", 100, 50}; 
    create_obj(); // 3
    display_players_num(); // 2
    Player hamza(frank);
    display_players_num(); // 3
    {
        Player slayer(hero);
        display_players_num(); // 4
    }
    display_players_num(); // 3
    Player *enemy = new Player("enemy", 330, 500);
    display_players_num(); // 4
    delete enemy; // destructor called
    display_players_num(); // 3

    return 0;
}

void display_players_num()
{
    cout << "Active players : " << Player::get_player_num() << endl;
}

void create_obj()
{
    Player enemy{};
    display_players_num();
    // Destructor is called.
}