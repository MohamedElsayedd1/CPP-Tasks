#ifndef PLAYER_H
#define PLAYER_H

#pragma once
#include <string>
using namespace std;

class Player
{
private:
    string name;
    int health;
    int xp;
    static int player_num;

public:
    void set_name(string n);
    string get_name();
    int get_health();
    int get_xp();
    static int get_player_num();

    // Overloaded Constructor
    Player(string n = "None", int h = 0, int x = 0);
    // copy constructor
    Player(const Player &src);
    // Destructor
    ~Player();
};

#endif