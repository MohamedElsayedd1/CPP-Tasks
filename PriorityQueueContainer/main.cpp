#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Person{
private : 
    string name;
    int age;
public : 
    Person(string n, int a) : name{n}, age{a}{}
    ~Person() = default;
    bool operator<(const Person &obj) const{
        return (this->age < obj.age);
    }
    bool operator==(const Person &obj) const{
        return (this->name == obj.name && this->age == obj.age);
    }
    friend ostream &operator<<(ostream &os, const Person &obj);
};

ostream &operator<<(ostream &os, const Person &obj){
    os << obj.name << ":" << obj.age << " ";
    return os;
}

template<typename T>
void display(priority_queue<T> pq_copy){
    cout << "Priority queue : [ ";
    while(!pq_copy.empty()){
        cout << pq_copy.top() << " ";
        pq_copy.pop();
    }
    cout << "]\n";
}

void test1(void){
    cout << "Test1 ==========================\n";
    priority_queue<int> pq;

    for(int i : {1,25,3,4,20,6,7}){
        pq.push(i); // greatest element will be on the top -> 7 6 5 4 3 2 1 
    }
    display(pq);
    cout << "Size : " << pq.size() << endl;
    cout << "Top : " << pq.top() << endl;

    pq.pop();
    display(pq);
    cout << "Size : " << pq.size() << endl;
    cout << "Top : " << pq.top() << endl;
}

void test2(void){
    cout << "Test2 ==========================\n";
    priority_queue<Person> pq;
    pq.push(Person{"A",19});
    pq.push(Person{"B",8});
    pq.push(Person{"C",30});
    pq.push(Person{"D",7});
    pq.push(Person{"E",55});
    pq.push(Person{"F",2});

    display(pq); // sort the queue depending on the age -> largest age will be on the top
    cout << "Size : " << pq.size() << endl;
    cout << "Top : " << pq.top() << endl;

    pq.pop(); // it will pop E:55

    display(pq); // sort the queue depending on the age -> C:30 will be on the top
    cout << "Size : " << pq.size() << endl;
    cout << "Top : " << pq.top() << endl;

}

int main()
{
    test1();
    test2();
    return 0;
}