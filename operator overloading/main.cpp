#include <iostream>

using namespace std;

class numberholder {
public:
    int value;
    numberholder() {}

    numberholder(int a, int b) {
        this->a=a;
        this->b=b;
        value=a*b;
    }

    void setA(int a) {
        this->a=a;
    }

    void setB(int b) {
        this->b=b;
    }

    int getA() {
        return a;
    }

    int getB() {
        return b;
    }

    numberholder operator+(numberholder n2) {
        numberholder brandNew;
        brandNew.setA(a+n2.getA());
        brandNew.setB(b+n2.getB());
        brandNew.value=brandNew.getA()*brandNew.getB();
        return brandNew;
    }

    numberholder operator-(numberholder n2) {
        numberholder brandNew;
        brandNew.setA(a-n2.getA());
        brandNew.setB(b-n2.getB());
        brandNew.value=brandNew.getA()*brandNew.getB();
        return brandNew;
    }

    numberholder operator*(numberholder n2) {
        numberholder brandNew;
        brandNew.setA(a*n2.getA());
        brandNew.setB(b*n2.getB());
        brandNew.value=brandNew.getA()*brandNew.getB();
        return brandNew;
    }

    numberholder operator/(numberholder n2) {
        numberholder brandNew;
        brandNew.setA(a/n2.getA());
        brandNew.setB(b/n2.getB());
        brandNew.value=brandNew.getA()*brandNew.getB();
        return brandNew;
    }

    numberholder operator%(numberholder n2) {
        numberholder brandNew;
        brandNew.setA(a%n2.getA());
        brandNew.setB(b%n2.getB());
        brandNew.value=brandNew.getA()*brandNew.getB();
        return brandNew;
    }

private:
    int a,b;
};

int main()
{
    numberholder n1(23,24);
    numberholder n2(32,42);
    numberholder n3=n2+n1;
    cout << "n1.a= " << n1.getA() << "; n1.b=" << n1.getB() << "; n1.value=" << n1.value << endl;
    cout << "n2.a= " << n2.getA() << "; n2.b=" << n2.getB() << "; n2.value=" << n2.value << endl;
    cout << "n3.a= " << n3.getA() << "; n3.b=" << n3.getB() << "; n3.value=" << n3.value << endl;
    return 0;
}
