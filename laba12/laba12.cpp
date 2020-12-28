#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>

using namespace std;

class Veh {
public:
    virtual void Buy() = 0;
    virtual void Drive() = 0;
};

class Auto : public Veh {
protected:
    string brand;
    int power;
    int cost;

public:
    //конструктор без параметров
    Auto() {
        brand = " ";
        power = 0;
        cost = 0;
    }

    //конструктор с 3 параметрами
    Auto(string _brand, int _power, int _cost) {
        brand = " ";
        brand = _brand;
        power = _power;
        cost = _cost;
    }

    virtual void read() { //Ввод данных
        cout << "Enter a brand: ";   cin >> brand;
        cout << "Enter a power: ";   cin >> power;
        cout << "Enter a cost: ";    cin >> cost;
    }

    virtual void display() {
        cout << brand << ", " << power << "л.с. - " << cost << "р" << endl;
    }

    void Drive() override {
        cout << "Человек едет на  " << brand << endl;
    }
    void Buy() override {
        cout << "Человек купил " << brand << endl;
    }

    Auto& operator=(const Auto& a) {
        cout << "___Перегрука оператора присваивания___" << endl;
        brand = a.brand;
        power = a.power;
        cost = a.cost;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Auto& p)
    {
        cout << p.brand  << ", " << p.power << "л.с. - " << p.cost << "р" << endl;
        return os;
    }
};

class Freight_ts : public Auto {
private:
    int lifting_capacity;
public:
    Freight_ts() : Auto() {
        lifting_capacity = 0;
    }
    Freight_ts(string _brand, int _power, int _cost, int lifting_capacity) : Auto(_brand, _power, _cost) {
        this->lifting_capacity = lifting_capacity;
    }

    void read() override {
        Auto::read();
        cout << "Грузоподъемность: ";
        cin >> lifting_capacity;
    }

    void display() override {
        Auto::display();
        cout << "Грузоподъемность: " << lifting_capacity << endl;
    }
};

class Passenger_ts : public Auto {
private:
    int num_of_seats;
    int max_speed;
public:
    Passenger_ts() :Auto() {
        max_speed = 0;
        num_of_seats = 0;
    }
    Passenger_ts(string brand, int power, int cost, int mspeed, int nseats) :Auto(brand, power, cost) {
        max_speed = mspeed;
        num_of_seats = nseats;
    }

    void read() override {
        Auto::read();
        cout << "Макс. скорость: ";         cin >> max_speed;
        cout << "Число посадочных мест:";   cin >> num_of_seats;
    }

    void display() override {
        Auto::display();
        cout << "Макс. скорость: " << max_speed << endl; 
        cout << "Число посадочных мест: " << num_of_seats << endl;
    }
};

class Person {
public:
    Person() {
        cout << "Появялся человек" << endl;
    }
    void toDrive(Veh* veh) {
        veh->Drive();
    }
    void toBuy(Veh* veh) {
        veh->Buy();
    }
};

int main() {
    setlocale(LC_ALL, "rus");


    Freight_ts f_ts("MAN", 800, 3000000, 20);
    Passenger_ts p_ts("Ford", 200, 600000, 200, 5);
    f_ts.display();
    cout << "------------------------" << endl;
    p_ts.display();
    cout << "------------------------" << endl;

    Person guy;
    guy.toBuy(&f_ts);
    guy.toDrive(&f_ts);
    cout << "------------------------" << endl;
    guy.toBuy(&p_ts);
    guy.toDrive(&p_ts);
    cout << "------------------------" << endl;
    Auto car1("Nissan", 130, 200000);
    Auto car2("Lada", 100, 70000);
    cout << car1;
    cout << car2;
    cout << "------------------------" << endl;
    car2 = car1;
    cout << car1;
    cout << car2;
    
    return 0;
}
