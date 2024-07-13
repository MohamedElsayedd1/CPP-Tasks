#include <iostream>
#include <set>
using namespace std;

class Person{
private : 
    string name;
    int age;
public : 
    Person(string n = "None", int a = 0) : name{n}, age{a}{}
    ~Person() = default;
    bool operator==(const Person &rhs) const{
        return (name == rhs.name && age == rhs.age);
    }
    bool operator<(const Person &rhs) const{
        return this->age < rhs.age;
    }
    friend ostream &operator<<(ostream &os, const Person &obj);
};

ostream &operator<<(ostream &os, const Person &obj){
    os << "["<< obj.name << ", " << obj.age << "]";
    return os;
}

template<typename T>
void display(const set<T> &myset){
    cout << "Set : [ ";
    for(auto const &elem : myset){
        cout << elem << " ";
    }
    cout << "]" << endl;
}

void test1(void){
    cout << "Test1 ========================\n";
    set<int> s {1, 2, 3, 4, 5};
    display(s);

    s = {1, 1, 2, 2, 3, 4, 3, 5, 6};
    display(s);

    //s[0], s.at(1), s.back(), s.front() are not allowed

    s.insert(0); // 0 is inerted successfuly because there's no duplicates
    s.insert(10);
    s.insert(6); // couldn't inset 6, because it's already exist
    display(s);

    if(s.count(10))
        cout << "10 is existed in the list.\n";
    else
        cout << "10 is not existed in the list.\n";
    
    set<int>::iterator it = s.find(5);
    if(it != s.end())
        s.erase(it); // erase whateve is it is pointing to
    display(s);
    s.erase(3); // erase 3
    display(s);

    s.clear(); // remove all elements
    display(s);
}


void test2(void){
    cout << "Test2 ========================\n";
    set<Person> stooges {{"Moe", 20}, {"Larry", 30}, {"Curly", 40}};
    display(stooges);

    stooges.emplace("larry", 50); // inserted because not the same age return this->age < rhs.age;
    display(stooges); // notice that the set is sorted.
    stooges.insert(Person{"Ahmed", 30}); // not inserted because it's the same age as larry -> 30, we are comaping ages
    display(stooges); 
    stooges.insert(Person{"Imo", 22});
    display(stooges);

    auto it = stooges.find(Person{"OLI", 40});
    if(it != stooges.end())
        stooges.erase(it); // erased {"Curly", 40} because they have same age
    display(stooges);

}

void test3(void){
    cout << "Test3 ========================\n";
    set<char> s {'A','B', 'C'};
    display(s);

    pair<set<char>::iterator, bool> result = s.insert('D'); // or auto result = s.insert('D');;
    display(s);
    cout << boolalpha;
    cout << "First : " << *(result.first) << endl; // first is an iterator pointing on D
    cout << "Second : " << result.second << endl; // iserted successfuly or not

    result = s.insert('A');
    display(s);
    cout << "First : " << *(result.first) << endl; // first is an iterator pointing on D
    cout << "Second : " << result.second << endl; // iserted successfuly or not
}


int main()
{
    test1();
    test2();
    test3();
    return 0;
}