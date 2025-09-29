#include <iostream>
using namespace std;


class Animal {
public:
    void eat() {
        cout << "This animal eats food." << endl;
    }
};


class Dog : public Animal {
public:
    void bark() {
        cout << "Dog barks: Woof Woof!" << endl;
    }
};


class Cat : public Animal {
public:
    void meow() {
        cout << "Cat meows: Meow Meow!" << endl;
    }
};

int main() {
    Dog d;
    Cat c;

    cout << "Dog object:" << endl;
    d.eat();
    d.bark();

    cout << "\nCat object:" << endl;
    c.eat();
    c.meow();

    return 0;
}
