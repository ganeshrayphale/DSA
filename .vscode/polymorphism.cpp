#include <iostream>
using namespace std;


// Compile-time Polymorphism (Function Overloading)

class Calculator {
public:
    int add(int a, int b) {
        return a + b;
    }

    int add(int a, int b, int c) {
        return a + b + c;
    }

    double add(double a, double b) {
        return a + b;
    }
};

// Run-time Polymorphism (Function Overriding)

class Animal {
public:
    virtual void speak() {   
        cout << "The animal makes a sound." << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {  
        cout << "The dog barks." << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "The cat meows." << endl;
    }
};
int main() {
    
    Calculator calc;
    cout << "Add two ints: " << calc.add(10, 20) << endl;
    cout << "Add three ints: " << calc.add(10, 20, 30) << endl;
    cout << "Add two doubles: " << calc.add(5.5, 6.5) << endl;

    cout << "\n--- Run-time Polymorphism ---" << endl;

    
    Animal* animal;   

    Dog dog;
    Cat cat;

    animal = &dog;
    animal->speak();  

    animal = &cat;
    animal->speak();  

    return 0;
}
