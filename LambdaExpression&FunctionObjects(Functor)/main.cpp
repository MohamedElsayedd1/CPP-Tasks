#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Square_functor {
    void operator()(int x) const {
        cout << x * x << " ";
    }
};

template<typename T>
struct Displayer {
    void operator()(const T &data) const {
        cout << data << " ";
    }
};

class Multiplier{
private : 
    int num;
public : 
    Multiplier(int n = 10) : num{n}{}
    int operator()(int n){
        return n * num;
    }
    ~Multiplier() = default;
};

void test1() {
    cout << "Test1 ==========================\n";
    Square_functor square; // square is an object
    square(5); // calling square object operator function -> square.operator()(5);

    Displayer<int> d1;
    Displayer<string> d2;
    d1(10); // d1.operator()(10);
    d2("Frank"); // d2.operator()("Frank");

    cout << endl;
}

void test2() {
    cout << "Test2 ==========================\n";
    vector<int> vec1 {1, 2, 3, 4, 5};
    vector<string> vec2 {"Larry", "Moe", "Curly"};

    Square_functor square;
    Displayer<int> d1;
    Displayer<string> d2;

    for_each(vec1.begin(), vec1.end(), d1); // calls d1.operator()(vec elements);
    cout << endl;

    for_each(vec1.begin(), vec1.end(), Displayer<int>()); // creating temporary object and calls Displayer<int>().operator()(vec elements);
    cout << endl;

    for_each(vec2.begin(), vec2.end(), d2); // calls d2.operator()(vec elements);
    cout << endl;

    for_each(vec1.begin(), vec1.end(), Square_functor());
    cout << endl;

    vec1 = {1, 2, 3, 4};
    for_each(vec1.begin(), vec1.end(), square);
    cout << endl;
}

void test3() {
    cout << "Test3 ==========================\n";
    vector<int> vec1 {1, 2, 3, 4, 5};
    vector<string> vec2 {"Larry", "Moe", "Curly"};


    for_each(vec1.begin(), vec1.end(), [](int x) { cout << x << " " ;}); 
    cout << endl;

    for_each(vec2.begin(), vec2.end(), [](string x) { cout << x << " "; }); 
    cout << endl;

    for_each(vec1.begin(), vec1.end(), [](int x) { cout << x*x << " "; });
    cout << endl;
}

void test4(void){
    cout << "Test3 ==========================\n";
    vector<int> vec1 {1, 2, 3, 4, 5};
    Multiplier mult(100); // creating new object of Multipler class

    for_each(vec1.begin(), vec1.end(), Displayer<int>());
    cout << endl;
    transform(vec1.begin(), vec1.end(), vec1.begin(), mult); // calls mult.operator()(100);
    for_each(vec1.begin(), vec1.end(), Displayer<int>());
    cout << endl;

    vec1 = {1, 2, 3, 4, 5};

    for_each(vec1.begin(), vec1.end(), [](int x) { cout << x << " "; });
    cout << endl;
    transform(vec1.begin(), vec1.end(), vec1.begin(), [](int x) { return x*10 ; }); 
    for_each(vec1.begin(), vec1.end(), [](int x) { cout << x << " "; });
    cout << endl;

}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}
