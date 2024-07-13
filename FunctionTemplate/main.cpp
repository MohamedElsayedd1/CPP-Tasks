#include <iostream>
using namespace std;

template <typename T>
T mymax(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
void display(T1 a, T2 b)
{
    cout << a << " " << b << endl;
}

template<typename T>
void myswap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

struct Person
{
    string name;
    int age;
    bool operator>(const Person &obj)
    {
        if (age > obj.age)
            return true;
        else
            return false;
    }
    // friend ostream &operator<<(ostream &os, const Person &obj); we don't a friend here since all members are public
};

ostream &operator<<(ostream &os, const Person &obj)
{
    os << obj.name;
    return os;
}

int main()
{
    int x = 10, y = 20;
    double a = 22.22, b = 50.12;
    Person p1{"Mohamed", 21};
    Person p2{"Khaled", 18};

    cout << mymax(x, y) << endl;
    cout << mymax(15, 33) << endl;
    cout << mymax<double>(7.05, 12) << endl; // must specify template parameter as a double because the compiler won't be able to decude types
    cout << mymax(7.05, 522.02) << endl;
    cout << mymax('A', 'B') << endl;
    cout << mymax(10 * 5 + 1, 12 + 8) << endl;
    cout << mymax(p1, p2) << endl; // this will generate an error : no match for 'operator>' (operand types are 'Person' and 'Person')

    Person p3 = mymax<Person>(p1, p2);

    cout << p3 << endl;
    cout << p3.age << endl;


    string s {"Pro"};
    display('A', 500); // compiler deduce it without indicating template paramters
    display<char, int>('B', 900);
    display(22.90, "Testing");
    display(199.22, 'K');
    display("Iphone 6", s);

    display(p1, p2);


    int m = 500, k = 200;
    cout << m << ", " << k << endl;
    myswap(m, k);
    cout << m << ", " << k << endl;

    string n = "Ibrahim", l = "Abdo";
    cout << n << ", " << l << endl;
    myswap(n, l);
    cout << n << ", " << l << endl;

    return 0;
}
