#include <iostream>

using namespace std;

int main()
{
    unsigned long int n;
    cout << "Please enter a number between 1 and 47 : ";
    cin >> n;

    unsigned long int fibo[n];
    fibo[0]=1;
    fibo[1]=1;

    for(unsigned long int m=2; m<n; m++) {
        fibo[m]=fibo[m-1] + fibo[m-2];
    }

    cout << "\nThe " << n << "th number of the fibonacci series is " << fibo[n-1] << endl;

    return 0;
}
