#include <iostream>

using namespace std;

class animal {
    public:
    virtual void Talk()
        {cout << "default animal talk" << endl;}
};

class dog: public animal {
    public:
    void Talk() {cout << "Wof" << endl;}
};

class cat: public animal {
    public:
    void Talk() {cout << "Meow" << endl;}
};

int main()
{
    dog Schnauzer;
    cat Siamese;

    Schnauzer.Talk();
    Siamese.Talk();
    return 0;
}
