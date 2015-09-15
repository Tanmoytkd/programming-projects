#include <iostream>

using namespace std;

long fibo(long n);

int main()
{
    long n;
    cout << "Enter a number and press enter: ";
    cin >> n;
    cout << "The " << n << "th member of fibonacci series is " << fibo(n);
    return 0;
}


long fibo(long n) {
    long x=1, y=1, res=0;


    switch(n) {
        case 1: return 1;
        case 2: return 1;
        default: {
            for(long m=3; m<=n; m++) {
                res=x+y;
                x=y;
                y=res;
            }
            return res;
        }
    }

}
