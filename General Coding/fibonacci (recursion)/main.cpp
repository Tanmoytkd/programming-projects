#include <iostream>

using namespace std;

int fibo(int n);

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "The " << n << "th number of the fibonacci series is " << fibo(n) << endl;
    return 0;
}

int fibo(int n) {
    int res;
    if(n==1 || n==2) return 1;
    else {
        res=fibo(n-1)+fibo(n-2);
        return res;
    }
}
