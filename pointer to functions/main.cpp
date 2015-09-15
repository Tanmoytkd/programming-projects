#include <iostream>

using namespace std;

class calc {
public:
    int addition(int x, int y) {
        return x+y;
    }

    int subtraction(int x, int y) {
        return x-y;
    }

    int multiplication(int x, int y) {
        return x*y;
    }
    int operation(int x, int y, int (*func)(int, int)) {
        return (*func)(x,y);
    }
};

int addition(int x, int y) {
        return x+y;
    }

    int subtraction(int x, int y) {
        return x-y;
    }

    int multiplication(int x, int y) {
        return x*y;
    }

int main()
{
    int x=9, y=7;
    calc co;
    /*
    int (*add) (int,int) = co.addition;
    int (*minus) (int,int) = co.subtraction;
    int (*multi) (int,int) = co.multiplication;
    */

    int (*add) (int,int) = addition;
    int (*minus) (int,int) = subtraction;
    int (*multi) (int,int) = multiplication;

    cout << co.operation(x,y,add) << endl;
    cout << co.operation(x,y,minus) << endl;
    cout << co.operation(x,y,multi) << endl;
    return 0;
}
