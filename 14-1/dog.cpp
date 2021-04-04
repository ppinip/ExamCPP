#include <iostream>
using namespace std;

class Dog {
private:
    string name;
    int age;
public:
    Dog(string n, int a) : name(n), age(a) {}

    string GetName() const { return name; }
    int GetAge() const { return age; }

    void Eat(string food) {
        cout << name << " is eating " << food << endl;
    }
    void Sleep() {
        cout << name << " is sleeping..." << endl;
    }
    void Woof() {
        cout << name << " is woofing" << endl;
    }
};

class Cat {
private:
    string name;
    int age;
public:
    Cat(string n, int a) : name(n), age(a) {}

    string GetName() const { return name; }
    int GetAge() const { return age; }

    void Eat(string food) {
        cout << name << " is eating " << food << endl;
    }
    void Sleep() {
        cout << name << " is sleeping..." << endl;
    }
    void Meow() {
        cout << name << " is meowing" << endl;
    }
};

class Bird {
private:
    string name;
    int age;
public:
    Bird(string n, int a) : name(n), age(a) {}

    string GetName() const { return name; }
    int GetAge() const { return age; }

    void Eat(string food) {
        cout << name << " is eating " << food << endl;
    }
    void Sleep() {
        cout << name << " is sleeping..." << endl;
    }
    void Chirp() {
        cout << name << " is chirping" << endl;
    }
};

int main() {
    Dog toob("Toob", 2);
    Cat maw("Maw", 3);
    Bird nok("Nok", 1);

    toob.Eat("pork");
    toob.Woof();

    maw.Eat("tuna");
    maw.Meow();

    nok.Eat("worm");
    nok.Chirp();
}