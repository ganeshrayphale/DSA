#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string brand;
    int speed;

public:
    Vehicle(string b, int s) {
        brand = b;
        speed = s;
    }

    void startEngine() {
        cout << brand << " engine started." << endl;
    }

    void stopEngine() {
        cout << brand << " engine stopped." << endl;
    }

    void showSpeed() {
        cout << brand << " is moving at " << speed << " km/h." << endl;
    }
};

class Car : public Vehicle {
private:
    int passengers;

public:
    Car(string b, int s, int p) : Vehicle("", 0) { 
        brand = b;
        speed = s;
        passengers = p;
    }

    void displayDetails() {
        cout << "Car Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Passengers: " << passengers << endl;
    }
};

class Truck : public Vehicle {
private:
    int loadCapacity;

public:
    Truck(string b, int s, int capacity) : Vehicle("", 0) {  
        brand = b;
        speed = s;
        loadCapacity = capacity;
    }

    void displayDetails() {
        cout << "Truck Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Load Capacity: " << loadCapacity << " kg" << endl;
    }
};

int main() {
    Car myCar("Toyota", 120, 5);
    myCar.startEngine();
    myCar.showSpeed();
    myCar.displayDetails();
    myCar.stopEngine();

    cout << "-----------------------------" << endl;

    Truck myTruck("Volvo", 80, 10000);
    myTruck.startEngine();
    myTruck.showSpeed();
    myTruck.displayDetails();
    myTruck.stopEngine();

    return 0;
}
