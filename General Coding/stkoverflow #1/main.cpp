#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
    string m_name;
    string m_speak;

public:
    Animal(string name, string speak = "???"): m_name(name), m_speak(speak){}
    string speak(){return m_name + " speaks " + m_speak;}

};

class Dog: public Animal
{
private:
    string m_dspeak;

public:
    Dog(string name, string speak = "Woof!"): Animal(name), m_dspeak(speak){}
    string speak(){ return m_name + " " + m_speak;}
};

class Cat: public Animal
{
private:
    string m_cspeak;

public:

    Cat(string name, string speak = "Meow!"): Animal(name), m_cspeak(speak){}
    string speak(){ return m_name + " speaks " + m_cspeak;}
};

int main()
{
    Cat Fred("Fred");
    Dog Stuffy("Stuffy");

    Animal *ptr = &Fred;
    cout << ptr->speak() << endl;

    Animal *ptr2 = &Stuffy;
    cout << ptr2->speak() << endl;
}
