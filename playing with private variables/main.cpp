#include <iostream>
#include <string>
using namespace std;

class person {
    public:
        person(string n, int a) {
            age=a;
            name=n;
        }
        int *getAge() {
            return &age;
        }
        string* getName() {
            return &name;
        }
    private:
        int age;
        string name;
};

int main()
{
    person tkd("Tanmoy Krishna Das", 17);
    person *ptkd = &tkd;
    int* age=tkd.getAge();
    *age=18;
    string *name = ptkd->getName();
    cout << *name << endl;
    cout << *(ptkd->getAge()) << endl;
    return 0;
}
