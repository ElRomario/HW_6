#include <iostream>
#include <string>

using namespace std;

class DomesticAnimal
{
protected:
    string name;
    string type;

public:
    DomesticAnimal(const string& animalName, const string& animalType)
        : name(animalName), type(animalType) {}

    virtual void printInfo() { cout << "Имя: " << name << "\nТип: " << type << "\n"; }
};

class Dog : virtual public DomesticAnimal
{
public:
    Dog(const string& dogName) : DomesticAnimal(dogName, "Собака") {}

    void bark() { cout << name << " лает!\n"; }
};

class Cat : virtual public DomesticAnimal
{
public:
    Cat(const string& catName) : DomesticAnimal(catName, "Кот") {}

    void meow() { cout << name << " мяукает!\n"; }
};

class Parrot : virtual public DomesticAnimal
{
public:
    Parrot(const string& parrotName) : DomesticAnimal(parrotName, "Попугай") {}

    void talk() { cout << name << " говорит!\n"; }
};

class DogCatParrot : public Dog, public Cat, public Parrot
{
public:
    DogCatParrot(const string& name)
        : DomesticAnimal(name, "СобакаКотПопугай"), Dog(name), Cat(name), Parrot(name) {}
};

int main()
{
    setlocale(LC_ALL, "ru");
    DogCatParrot myHybrid("Гибрид");

    myHybrid.printInfo();
    myHybrid.bark();
    myHybrid.meow();
    myHybrid.talk();

    return 0;
}