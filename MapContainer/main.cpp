#include <iostream>
#include <set>
#include <map>

using namespace std;

template <typename T1, typename T2>
void display(const map<T1, T2> &my_map)
{
    cout << "[ ";
    for (const auto &elem : my_map)
    {
        cout << elem.first << ":" << elem.second << " ";
    }
    cout << " ]" << endl;
}

template <typename T1>
void display_map_set(const map<T1, set<int>> &my_map)
{
    cout << "[ ";
    for (const auto &elem : my_map)
    {
        cout << elem.first << ":[ ";
        for (const auto &elem_sec : elem.second)
        {
            cout << elem_sec << " ";
        }
        cout << "]  ";
    }
    cout << "]" << endl;
}

void test1(void)
{
    cout << "Test1 ====================================\n";
    map<string, int> m{{"Larry", 12}, {"Moe", 14}, {"Curly", 19}}; // sorting depending on the key
    display(m);

    pair<string, int> p1{"Ibra", 55};
    m.insert(p1);
    display(m);

    m.insert(pair<string, int>{"Khaled", 66});
    display(m);

    m.insert(make_pair("Yoyo", 44.0));
    display(m);

    m["Frank"] = 33; // insert
    display(m);

    m["Frank"] += 99; // update value;
    display(m);

    m.erase("Frank"); // passing the key
    m.erase("Yoyo");
    display(m);

    auto it = m.find("Larry");
    if (it != m.end())
    {
        cout << "Found : " << it->first << ":" << it->second << endl;
    }

    cout << "count for Moe : " << m.count("Moe") << endl;
    cout << "count for Joe : " << m.count("Joe") << endl;

    m.clear();
    display(m);
}

void test2(void)
{
    cout << "Test2 ====================================\n";
    map<string, set<int>> grades{{"Mohamed", {77, 90, 80}}, {"Ahmed", {40, 88, 50}}, {"Salma", {100, 44}}};
    display_map_set(grades);

    grades["Mohamed"].insert(10); // 10 is inserted into the set of the map
    display_map_set(grades);

    grades["Ahmed"].insert(90);
    display_map_set(grades);

    auto it = grades.find("Ahmed");
    if (it != grades.end())
        it->second.insert(30);
    display_map_set(grades);

    grades.erase("Mohamed");
    display_map_set(grades);

    grades["Ibra"] = {20, 30, 40};
    display_map_set(grades);

    pair<string, set<int>> p {"Layla", {33, 55}};
    grades.insert(p);
    display_map_set(grades);

}

int main()
{
    test1();
    test2();
    return 0;
}
