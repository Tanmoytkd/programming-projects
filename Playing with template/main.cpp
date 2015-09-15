#include <iostream>

template <class A, class B>

B adder(A x, B y) {
    return x+y;
}

int main()
{
    using namespace std;

    int x=50;
    double y=99.99;

    cout << "The sum of the numbers is : " << adder(x,y) << endl;
    return 0;
}
