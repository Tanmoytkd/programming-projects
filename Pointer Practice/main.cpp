#include <iostream>

using namespace std;

void ageChanger(int *age);

class person {
    public:
        person(int age) {
            itsage = age;
        }
        int age(int x) {
            itsage = x;
        }
        int age() {
            return itsage;
        }
    private:
        int itsage;
};

int main()
{
    person tanmoy(17);
    person hamid(18);

    cout << "Tanmoy's age is " << tanmoy.age() << endl;
    cout << "Hamid's age is " << hamid.age() << endl;

    int age = tanmoy.age();
    cout << "\n\n\n==================\n\n\n" << "The age was " <<  age << endl;

    ageChanger(&age);

    cout << "\n\n\n==================\n\n\n" << "Now the age is " << age << endl;

    return 0;
}

void ageChanger(int *age) {
    *age = 21;
}
