#include <iostream>
using namespace std;

//----- base class ------
class Animal {
private:
    string name;
    int age;
public:
    Animal(string n, int a) : name(n), age(a) {}

    string GetName() const { return name; }
    int GetAge() const { return age; }

    void Eat(string food) {
        cout << name << " is eating " << food << endl;
    }
    void Sleep() {
        cout << name << " is sleeping..." << endl;
    }
    void MakeNoise() {
        cout << name << " is making noise" << endl;
    }
};

// ------- derived class ------
class Dog : public Animal {
public:
    Dog(string n, int a) : Animal(n, a) {}
};

class Cat : public Animal {
public:
    Cat(string n, int a) : Animal(n, a) {}
};

class Bird : public Animal {
public:
    Bird(string n, int a) : Animal(n, a) {}
};

int main() {
    Dog toob("Toob", 2);
    Cat maw("Maw", 3);
    Bird nok("Nok", 1);

    toob.Eat("pork");
    maw.Eat("tuna");
    nok.Eat("worm");
    nok.Sleep();
}