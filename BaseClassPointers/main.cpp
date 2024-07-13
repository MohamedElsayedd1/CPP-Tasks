#include <iostream>
using namespace std;

class Animal {
public:
    void makeSound() const {
        cout << "Animal sound!" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() const {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() const {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* ptr;  // Base class pointer

    Dog myDog;
    Cat myCat;

    ptr = &myDog;  // Pointing to a Dog object
    ptr->makeSound();  // Outputs "Woof!"

    ptr = &myCat;  // Pointing to a Cat object
    ptr->makeSound();  // Outputs "Meow!"

    return 0;
}
