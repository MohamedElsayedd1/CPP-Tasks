#include <iostream>
#include <list> 
#include <algorithm>
#include <iterator>
using namespace std;

class Person{
private : 
    string name;
    int age;
public : 
    Person(string n = "None", int a = 0) : name{n}, age{a}{}
    ~Person() = default;
    bool operator==(const Person &rhs){
        return (name == rhs.name && age == rhs.age);
    }
    bool operator<(const Person &rhs){
        return this->age < rhs.age;
    }
    friend ostream &operator<<(ostream &os, const Person &obj);
};

ostream &operator<<(ostream &os, const Person &obj){
    os << "["<< obj.name << ", " << obj.age << "]";
    return os;
}

template<typename T>
void display(const list<T> &deq){
    cout << "List : [ ";
    for_each(deq.begin(), deq.end(), [](T x){ cout << x << " ";});
    cout << "]" << endl;
}

void test1(void){
    cout << "Test1 =========================\n";

    list<int> l {1, 2, 3, 4, 5};
    display(l);
    l.push_back(10);
    l.push_front(20);
    display(l);

    // l[0] = 1000;  -> copile error can't be direct accessed 
    // l.at(1) = 2000;

    list<string> ll {"middle"};
    ll.push_back("back");
    ll.push_front("front");
    display(ll);

    list<int> lll(10, 100);
    display(lll);
}

void test2(void){
    cout << "Test2 =========================\n";

    list<int> l {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    l.resize(5); 
    display(l);

    l.resize(10);
    display(l);

    list<Person> stooges {{"Ahmed", 19}, {"Mohamed", 22}};
    display(stooges);
    stooges.push_back(Person{"Khaled", 23});
    display(stooges);
    stooges.pop_front();
    display(stooges);
}

void test3(void){
    cout << "Test3 =========================\n";

    list<int> l {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    cout << "Size : " << l.size() << endl;
    cout << "Front : " << l.front() << endl;
    cout << "Back : " << l.back() << endl;

    l.clear();
    display(l);
}

void test4(void){
    cout << "Test4 =========================\n";

    list<int> l {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(l);

    auto it = find(l.begin(), l.end(), 5); // iterator points at 5
    if(it != l.end())
        l.insert(it, 100); // insert 100 before 5
    display(l);

    list<int> ll {1000, 2000, 3000};
    l.insert(it, ll.begin(), ll.end()); // insert list ll before 5
    display(l);

    advance(it, -2); // make iterator points at (it - 2) whis is 2000 in that case
    l.erase(it, l.end());
    display(l);
}

void test5(void){
    cout << "Test5 =========================\n";

    list<Person> stooges {{"Larry", 20}
                        , {"Moe", 16}
                        , {"Curly", 30}};
    display(stooges);

    string name;
    int age;
    cout << "Enter name of the next stooge : ";
    cin >> name;
    cout << "Enter the age : ";
    cin >> age;

    auto it = find(stooges.begin(), stooges.end(), Person("Moe", 16));
    stooges.insert(it, Person(name, age)); // insert before ["Moe", 16]
    display(stooges);

    it = find(stooges.begin(), stooges.end(), Person(name, age));
    stooges.insert(it, Person("Ibrahim", 18)); // insert before [name, age]
    display(stooges);
}

void test6(void){
    cout << "Test6 =========================\n";

    list<Person> stooges {{"Larry", 20}
                        , {"Moe", 16}
                        , {"Curly", 30}};
    display(stooges);

    stooges.emplace_back("Khaled", 10);
    stooges.emplace_front("Yassen", 29);

    display(stooges);

    stooges.sort();

    display(stooges);

}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}