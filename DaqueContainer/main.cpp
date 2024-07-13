#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
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
    friend ostream &operator<<(ostream &os, const Person &obj);
};

ostream &operator<<(ostream &os, const Person &obj){
    os << "["<< obj.name << ", " << obj.age << "]";
    return os;
}

template<typename T>
void display(const deque<T> &deq){
    cout << "Deque : [ ";
    for_each(deq.begin(), deq.end(), [](T x){ cout << x << " ";});
    cout << "]" << endl;
}

void test1(){
    cout << "Test1 ========================\n";

    deque<int> d1{1, 2, 3, 4, 5};
    display(d1);

    d1 = {2, 4, 6, 8};
    display(d1);

    deque<int> d2(10, 100); // ten 100s
    display(d2);

    d1[0] = 1000; // no bouds checking
    d1.at(1) = 2000;
    display(d1);
}

void test2(){
    cout << "Test2 ========================\n";

    deque<int> d1{0, 0, 0};
    display(d1);

    d1.push_back(100);
    d1.push_front(20);
    display(d1);

    d1.push_back(200);
    d1.push_front(10);
    display(d1);

    cout << "Front : " << d1.front() << endl;
    cout << "Back : " << d1.back() << endl;
    cout << "Size : " << d1.size() << endl;

    d1.pop_back();
    d1.pop_front();
    display(d1);
}

void test3(){
    cout << "Test3 ========================\n";

    deque<Person> d1{{"Larry", 18}};
    display(d1);

    Person p1 {"Ibra", 22};
    d1.push_back(Person{"Moe", 19});
    d1.push_front(p1);
    display(d1);

    d1.push_back(Person{"Ismail", 33});
    d1.push_front(Person{"Salma", 31});
    display(d1);

    d1.pop_back();
    d1.pop_front();
    display(d1);
}

void test4(){
    cout << "Test4 ========================\n";

    vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> d{0};

    for(auto const &elem : vec){
        if(elem % 2 == 0)
            d.push_back(elem);
        else
            d.push_front(elem);
    }

    display(d);
}

void test5(){
    cout << "Test5 ========================\n";

    vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> d{0};

    display(d);

    for(auto const &elem : vec)
        d.push_front(elem);

    display(d);

    d = {0};

    for(auto const &elem : vec)
        d.push_back(elem);

    display(d);
}

void test6(){
    cout << "Test6 ========================\n";

    vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    deque<int> d{200, 300};

    display(d);

    copy(vec.begin(), vec.end(), back_inserter(d));
    display(d);

    d = {200, 300};

    copy(vec.begin(), vec.end(), front_inserter(d));
    display(d);

    d = {200, 300};

    copy_if(vec.begin(), vec.end(), back_inserter(d), [](int x){ return x % 2 == 0;});
    display(d);

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