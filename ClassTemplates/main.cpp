#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Item{
private :
    string name;
    T value;
public : 
    Item(string n, T val) : name{n}, value{val}{};
    Item(const Item &obj) : name{obj.name}, value{obj.value}{}
    string get_name() {return name;}
    T get_value() {return value;}
};


template<typename T1, typename T2>
struct My_pair
{
    /* data */
    T1 first;
    T2 second;
};

int main()
{
    Item<int> item1 {"khaled", 20};
    cout << item1.get_name() << " " << item1.get_value() << endl;
    Item<int> item2 (item1);
    cout << item2.get_name() << " " << item2.get_value() << endl;
    Item<double> item3 {"Mohamed", 90.88};
    cout << item3.get_name() << " " << item3.get_value() << endl;
    Item<char> item4{"Ismail", 'B'};
    cout << item4.get_name() << " " << item4.get_value() << endl;

    Item<Item<string>> item5 {"Mohamed", {"is", " student"}};
    cout << item5.get_name() << " "
    << item5.get_value().get_name() 
    << item5.get_value().get_value() << endl;

    cout << "=================================\n";

    vector<Item<double>> vec;
    vec.push_back(item3);
    vec.push_back(Item<double>("Larry", 98.77));
    vec.push_back(Item<double>("curly", 100.71));
    for(auto &item : vec){
        cout << item.get_name() << " " << item.get_value() << endl;
    }

    cout << "=================================\n";

    My_pair<int, double> p1 = {990, 19.2};
    cout << p1.first << " " << p1.second << endl;
    My_pair<char, string> p2 {'B', "Ahmed"};
    cout << p1.first << " " << p1.second << endl;

    return 0;
}