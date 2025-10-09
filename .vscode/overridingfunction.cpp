#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    int id;
public:
    Employee(string n, int i) : name(n), id(i) {}

    
    virtual void showDetails() {
        cout << "Employee Name: " << name << endl;
        cout << "Employee ID: " << id << endl;
    }
};


class Manager : public Employee {
    int teamSize;
public:
    Manager(string n, int i, int t) : Employee(n, i), teamSize(t) {}

    void showDetails() override {
        cout << "Manager Name: " << name << endl;
        cout << "Manager ID: " << id << endl;
        cout << "Team Size: " << teamSize << endl;
    }
};


class Developer : public Employee {
    string programmingLanguage;
public:
    Developer(string n, int i, string lang) : Employee(n, i), programmingLanguage(lang) {}

    void showDetails() override {
        cout << "Developer Name: " << name << endl;
        cout << "Developer ID: " << id << endl;
        cout << "Programming Language: " << programmingLanguage << endl;
    }
};

int main() {
    Employee* e1;  

    Manager m("Kiran", 101, 5);
    Developer d("vedant", 102, "javascript");

    e1 = &m;
    e1->showDetails();   

    cout << endl;

    e1 = &d;
    e1->showDetails();  

    return 0;
}
