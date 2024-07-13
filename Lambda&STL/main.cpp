#include <iostream>
#include <vector> 
#include <map>
#include <algorithm>
#include <iterator>
#include <numeric>
using namespace std;

class Person{
private : 
    string name;
    int age;
public : 
    Person(string n = "None", int a = 0) : name{n}, age{a}{}
    ~Person() = default;
    void set_name(string n){ name = n;}
    void set_age(int a){ age = a; }
    string get_name(void) const { return name; }
    int get_age(void) const { return age;}
    friend ostream &operator<<(ostream &os, const Person &obj);
};

ostream &operator<<(ostream &os, const Person &obj){
    os << "["<< obj.name << ", " << obj.age << "]";
    return os;
}

template<typename T>
void display(const vector<T> &vec){
    for(auto const &elem : vec){
        cout << elem << " ";
    }
    cout << endl;
}

void test1(void){
    cout << "Test1 =================================\n";
    vector<int> vec {1, 2, 3, 4, 5}; // Initialize a vector with values 1, 2, 3, 4, 5

    // Use for_each to print each element in the vector
    for_each(vec.begin(), vec.end(), [](int x) {
        cout << x << " "; // Print each element followed by a space
    });
    cout << endl; // Print a newline for better readability

    // Use for_each to print only odd elements in the vector
    for_each(vec.begin(), vec.end(), [](int x) {
        if(x % 2) // Check if the element is odd
            cout << x << " "; // Print the odd element followed by a space
    });
    cout << endl; // Print a newline for better readability
}

void test2(void){
    cout << "Test4 =================================\n";
    vector<int> vec1 {1, 2, 5, 4, 3};
    vector<int> vec2 {5, 4, 3, 2, 1};
    vector<int> vec3 {1, 2, 7, 4, 3};

    if(is_permutation(vec1.begin(), vec1.end(), vec2.begin())){
        cout << "vec1 and vec2 are permutations of each other." << endl;
    } else {
        cout << "vec1 and vec2 are not permutations of each other." << endl;
    }

    if(is_permutation(vec1.begin(), vec1.end(), vec3.begin())){
        cout << "vec1 and vec3 are permutations of each other." << endl;
    } else {
        cout << "vec1 and vec3 are not permutations of each other." << endl;
    }
}

void test3(void) {
    cout << "Test3 =================================\n";
    struct Point {
        int x;
        int y;

        // bool operator==(const Point &obj) const {
        //     return (x == obj.x && y == obj.y);
        // }
    };

    Point p1 {1, 3};
    Point p2 {5, 9};
    Point p3 {8, 10};
    Point p4 {11, 30};

    vector<Point> vec1 {p1, p2, p3};
    vector<Point> vec2 {p4, p1, p3};
    vector<Point> vec3 {p2, p1, p3};

    if (is_permutation(vec1.begin(), vec1.end(), vec2.begin(), [](const Point &lhs, const Point &rhs){ return (lhs.x == rhs.x && rhs.y == rhs.y);})) {
        cout << "vec1 and vec2 are permutations of each other." << endl;
    } else {
        cout << "vec1 and vec2 are not permutations of each other." << endl;
    }

    if (is_permutation(vec1.begin(), vec1.end(), vec3.begin(), [](const Point &lhs, const Point &rhs){ return (lhs.x == rhs.x && rhs.y == rhs.y);} )) {
        cout << "vec1 and vec3 are permutations of each other." << endl;
    } else {
        cout << "vec1 and vec3 are not permutations of each other." << endl;
    }
}

void test4(void){
    cout << "Test4 =================================\n";
    vector<int> vec { 10, 20, 30, 40, 50};
    int bonus_score{50};
    display(vec);

    transform(vec.begin(), vec.end(), vec.begin(), [bonus_score](int score){ score += bonus_score; 
                                                                return score ;});
    display(vec);
}

void test5(void){
    cout << "Test5 =================================\n";
    vector<int> vec { 1, 2, 3, 4, 5};
    int bonus_score{50};
    display(vec);

    vec.erase(remove_if(vec.begin(), vec.end(), [](int x){
        return x % 2 != 0;
        }), vec.end());
    display(vec);
}

void test6(void){
    cout << "Test6 =================================\n";
    Person p1 {"Larry", 18};
    Person p2 {"Hany", 19};
    Person p3 {"Curly", 20};
    vector<Person> vec {p1, p2, p3};
    display(vec);

    sort(vec.begin(), vec.end(), [](const Person &lhs, const Person &rhs){
        return (lhs.get_name() < rhs.get_name());
    });
    display(vec);

    sort(vec.begin(), vec.end(), [](const Person &lhs, const Person &rhs){
        return (lhs.get_age() < rhs.get_age());
    });
    display(vec);
}

bool in_between(const vector<int> &vec, int start, int end){
    bool result{true};
    result = all_of(vec.begin(), vec.end(), [=](int x){
        return (x >= start && x <= end);
    });
    return result;
}

void test7(void) {
    cout << "Test =================================\n";
    vector<int> vec(10); // Create a vector with 10 elements
    iota(vec.begin(), vec.end(), 1); // Fill it with values starting from 1
    display(vec);

    cout << boolalpha;
    cout << in_between(vec, 10, 50) << endl;
    cout << in_between(vec, 7, 10) << endl;
    cout << in_between(vec, 1, 10) << endl;
}

int main(){
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    return 0;
}