#include <iostream>
#include <string>
using namespace std;

class person {
    public:
        person(string n, int a) {
            age=a;
            name=n;
        }
    private:
        int age;
        string name;
    friend string getName(person p);
    friend int getAge(person p);
};

int main()
{
    person tkd("Tanmoy Krishna Das", 17);
    cout << getName(tkd)  << " is " << getAge(tkd)  << " years old. :-)" << endl;
    return 0;
}

string getName(person p) {
    return p.name;
}

int getAge(person p) {
    return p.age;
}
