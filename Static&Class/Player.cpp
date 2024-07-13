#include "Player.h"

int Player::player_num = 0;

int Player::get_player_num(){
    return player_num;
    
}

Player::Player(string n, int h, int x) : name{n}, health{h}, xp{x}
{
    player_num++;
}

Player::Player(const Player &src) : name{src.name}, health{src.health}, xp{src.xp}
{
    player_num++;
}

Player::~Player()
{
    player_num--;
}

void Player::set_name(string n){
    this->name = n;
}

string Player::get_name(){
    return name;
}

int Player::get_health(){
    return health;
}

int Player::get_xp(){
    return xp;
}