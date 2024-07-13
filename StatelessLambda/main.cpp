#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Person{
private : 
    string name;
    int age;
public : 
    Person(string n = "None", int a = 0) : name{n}, age{a}{}
    string get_name(void) const { return name; }
    int get_age(void) const { return age;}
    void set_name(string n){ this->name = n; }
    void set_age(int a) { this->age = a; }
    friend ostream &operator<<(ostream &os, const Person &obj);
    ~Person() = default;
};

ostream &operator<<(ostream &os, const Person &obj){
    os << "Person : [ " << obj.name << ", " << obj.age << " ]";
}

void test1(void){
    cout << "Test1 ==========================\n";

    []() { cout << "Hi" << endl; }(); // calling lambda exp.

    [](int x) { cout << x << endl; }(100);

    [](int x, int y){ cout << x + y << endl; }(100, 200);

    [](string name) { cout << name << endl; }("Frank");

    [](const Person &obj) {cout << obj << endl; }(Person("Larry", 17)); // passing by reference -> no copy constructor is called
}

void test2(void){
    cout << "Test2 ==========================\n";

    int num1 {100};
    int num2 {200};
    
    auto l1 = [](int x, int y){ // passing by value -> copy -> main variables are not affected
        cout << x+y << endl;
    };
    l1(num1, num2);
    l1(100, 400);

    auto l2 = [](int x, int y){ // passing by value -> copy -> main variables are not affected
        cout << "x : " << x << " y : " << y << endl;
        x = 1000; 
        y = 2000;
        cout << "x : " << x << " y : " << y << endl;
    };
    l2(num1, num2);
    cout << "x : " << num1 << " y : " << num2 << endl; // not changed since we are passing num1, num2 by value

    cout << "---------------------\n";

    auto l3 = [](int &x, int &y){ // passing by reference, now x and y are aliases -> main variables are affected
        cout << "x : " << x << " y : " << y << endl;
        x = 1000; 
        y = 2000;
        cout << "x : " << x << " y : " << y << endl;
    };
    l3(num1, num2);
    cout << "x : " << num1 << " y : " << num2 << endl; // changed since we are passing num1, num2 by reference
}

void test3(void){
    cout << "Test3 ==========================\n";
    Person p1{"Larry", 18};
    cout << p1 << endl;

    auto l1 = [](Person p){ // passing by value -> copy is made by copy constructor
        cout << p << endl;
    };
    l1(p1);

    auto l2 = [](const Person &p){ // passing by reference -> copy is not made -> copy constructor is not called
        cout << p << endl;
    };
    l2(p1);

    auto l3 = [](Person &p){ // passing by reference -> copy is not made -> copy constructor is not called -> main object is changed
        p.set_name("Frank");
        p.set_age(29);
        cout << p << endl;
    };
    l3(p1);
    cout << p1 << endl; 

}

void filter_vector(const vector<int> &v, auto l){
    cout << "[ ";
    for(auto const & elem : v){
        if(l(elem)){
            cout << elem << " ";
        }
    }
    cout << "]" << endl;
}

void test4(void){
    cout << "Test4 ==========================\n";
    vector<int> myvec {10, 20 , 30 ,40, 50, 60, 70, 80, 90, 100};

    // passing vector of integers and lambda exp to filter_vector function
    filter_vector(myvec, [](int x){ return x > 50; });

    filter_vector(myvec, [](int x){ return x >= 30;});

    filter_vector(myvec, [](int x){ return x <= 20;});
}

auto make_lambda(void){
    return [](){ cout << "This lambda is made by make_lambda function.\n"; };
}

void test5(void){
    cout << "Test5 ==========================\n";
    
    auto l = make_lambda();
    l();
}

void test6(void){
    cout << "Test5 ==========================\n";
    
    auto l = [](auto x, auto y){
        cout << "x : " << x << " y : " << y << endl;
    };
    l(100, 200);
    l(23.4, 'A');
    l('B', "Mohamed");

    l(Person("Ibra", 19), Person("Yoyo", 33)); // must overload the << operator
}

void test7(void){
    cout << "Test7 ==========================\n";

    vector<Person> stooges {{"Moe", 30}, {"Larry", 25}, {"Zain", 15}};
    for_each(stooges.begin(), stooges.end(), [](const Person &obj) { cout << obj << endl; });
    cout << endl;

    sort(stooges.begin(), stooges.end(), [](const Person &lhs, const Person &rhs) { return lhs.get_name() < rhs.get_name();});
    for_each(stooges.begin(), stooges.end(), [](const Person &obj) { cout << obj << endl; });
    cout << endl;

    sort(stooges.begin(), stooges.end(), [](const Person &lhs, const Person &rhs){ return lhs.get_age() < rhs.get_age();});
    for_each(stooges.begin(), stooges.end(), [](const Person &obj) { cout << obj << endl; });
    cout << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    return 0;
}