#include <iostream>
#include <algorithm>
#include <vector>
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
void display(const vector<T> &vec){
    cout << "Vector : [ ";
    for_each(vec.begin(), vec.end(), [](T x){ cout << x << " ";});
    cout << "]" << endl;
}

void test1(void){
    cout << "Test1 ====================================\n";
    vector<int> vec1 {1, 2, 3, 4, 5};
    display(vec1);
    vec1 = {40, 50, 60};
    display(vec1);

    vector<char> vec2(10, 'A'); // size - intialization value
    display(vec2);
}

void test2(void){
    cout << "Test2 ====================================\n";
    vector<int> vec1 {1, 2, 3, 4, 5};

    display(vec1);
    cout << "vec size : " << vec1.size() << endl;
    cout << "vec max size 'How many elements can it hold' : " << vec1.max_size() << endl;
    cout << "vec capacity : " << vec1.capacity() << endl; // it doubles after pushing an element 

    vec1.push_back(10);
    display(vec1);
    cout << "vec size : " << vec1.size() << endl;
    cout << "vec max size 'How many elements can it hold' : " << vec1.max_size() << endl;
    cout << "vec capacity : " << vec1.capacity() << endl << endl; // it doubles after pushing an element 

    vec1.reserve(100); // reserve 100 slots for the capacity
    display(vec1);
    cout << "vec size : " << vec1.size() << endl;
    cout << "vec max size 'How many elements can it hold' : " << vec1.max_size() << endl;
    cout << "vec capacity : " << vec1.capacity() << endl << endl; // it doubles after pushing an element 

    vec1.shrink_to_fit();
    display(vec1);
    cout << "vec size : " << vec1.size() << endl;
    cout << "vec max size 'How many elements can it hold' : " << vec1.max_size() << endl;
    cout << "vec capacity : " << vec1.capacity() << endl << endl; // it doubles after pushing an element 
}

void test3(void){
    cout << "Test3 ====================================\n";
    vector<int> vec1 {1, 2, 3, 4, 5};
    display(vec1);
    
    vec1.at(0) = 1000; // no bounds checking with at() method
    vec1[1] = 5000; // bouds checking with subscript[]

    display(vec1);
}

void test4(void){
    cout << "Test4 ====================================\n";
    vector<Person> stooges;
    display(stooges);

    Person p {"Larry", 18};
    stooges.push_back(p); // using copy constructor
    display(stooges);

    stooges.push_back(Person("Moe", 19)); // using move semantic/constructor
    display(stooges);

    stooges.emplace_back("Curly", 45);
    display(stooges);
}

void test5(void){
    cout << "Test5 ====================================\n";
    vector<Person> stooges{{"Khaled", 13}, {"Mohamed", 19}, {"Ibra", 33}};
    display(stooges);

    cout << "Front : " << stooges.front() << endl;
    cout << "Back : " << stooges.back() << endl;

    stooges.pop_back();
    display(stooges);
}

void test6(void){
    cout << "Test6 ====================================\n";
    vector<int> vec {1, 2, 3, 4, 5};
    display(vec);

    vec.clear();
    display(vec);

    vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    display(vec);
    vec.erase(vec.begin(), vec.begin()+2); // erasing first 2 elements.
    display(vec);

    //erase even numbers
    vector<int>::iterator it = vec.begin();
    while(it != vec.end()){
        if(*it % 2 == 0)
            vec.erase(it);
        else
            it++;
    }
    display(vec);
}

void test7(void){
    cout << "Test7 ====================================\n";
    vector<int> vec1 {1, 2, 3, 4, 5};
    vector<int> vec2{10, 20, 30, 40, 50, 60, 70};
    display(vec1);
    display(vec2);

    vec1.swap(vec2); // must bbe of the same type

    display(vec1);
    display(vec2);
}

void test8(void){
    cout << "Test8 ====================================\n";
    vector<int> vec1 {20, 1, 10, 2, 1, 4, 15, 70};
    display(vec1);

    sort(vec1.begin(), vec1.begin()+5);
    display(vec1);

    sort(vec1.begin(), vec1.end());
    display(vec1);
}

void test9(void){
    cout << "Test9 ====================================\n";
    vector<int> vec1 {1, 2, 3, 4, 5};
    vector<int> vec2 {10, 20, 30};

    display(vec1);
    display(vec2);

    copy(vec1.begin(), vec1.end(), back_inserter(vec2)); // insert all the vec1 after vec2 and store it in vec2
    display(vec1);
    display(vec2);
    
    vector<int> vec3{90, 88, 3};
    copy(vec2.begin(), vec2.end(), back_inserter(vec3));
    display(vec3);
    
    sort(vec3.begin(), vec3.end());
    display(vec3);

    vec1 = {1, 2, 3, 4, 5};
    vec2 = {10, 20, 30};

    display(vec1);
    display(vec2);

    // copy_if -> copy even elements
    copy_if(vec1.begin(), vec1.end(), back_inserter(vec2), [](int x){ return x % 2 == 0;});
    display(vec1);
    display(vec2); // 10 20 2 4
}

void test10(void){
    cout << "Test10 ====================================\n";
    vector<int> vec1 {1, 2, 3, 4, 5};
    vector<int> vec2 {100, 200, 300, 400, 161};

    display(vec1);
    display(vec2);

    auto it = find(vec1.begin(), vec1.end(), 4);
    if(it != vec1.end()){
        cout << "Inserting..\n";
        vec1.insert(it, vec2.begin(), vec2.end()); // inserting before number 4
    }
    else{
        cout << "Couldn't found 4" << endl;
    }
    
    display(vec1);
    display(vec2);
      
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
    test8();
    test9();
    test10();
    return 0;
}