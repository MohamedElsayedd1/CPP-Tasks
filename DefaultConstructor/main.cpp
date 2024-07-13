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

    string get_name()
    {
        return name;
    }

    // Default constructors
    Player(){
        name = "None";
        health = 100;
        xp = 10;
    }

    Player(string nn);

    Player(string n, int hel, int x){
        name = n;
        health = hel;
        xp = x;
    }
};

int main()
{
    Player frank;
    cout << "name : " << frank.get_name() << endl;
    frank.set_name("Frank");
    cout << "name : " << frank.get_name() << endl;

    Player hero("hero", 90, 88);
    cout << "name : " << hero.get_name() << endl;

    return 0;
}