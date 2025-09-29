#include <iostream>
using namespace std;


class Animal {
public:
    void eat() {
        cout << "This animal can eat." << endl;
    }
};


class Dog : public Animal {
public:
    void bark() {
        cout << "The dog barks." << endl;
    }
};

int main() {
    Dog myDog;

    myDog.eat();   
    myDog.bark();  

    return 0;
}
