#include <iostream>
using namespace std;


class Person {
public:
    void displayPerson() {
        cout << "I am a person." << endl;
    }
};


class Employee : public Person {
public:
    void displayEmployee() {
        cout << "I am an employee."<<endl;
    }
};


class Student {
public:
    void displayStudent() {
        cout << "I am a student." << endl;
    }
};


class Intern : public Employee, public Student {
public:
    void displayIntern() {
        cout << "I am an intern (both employee & student)." << endl;
    }
};

int main() {
    Intern i;

    i.displayPerson();    // from Person
    i.displayEmployee();  // from Employee
    i.displayStudent();   // from Student
    i.displayIntern();    // from Intern

    return 0;
}
