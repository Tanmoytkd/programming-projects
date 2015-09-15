#include <iostream>

using namespace std;

int gcd(int x, int y);

int main()
{
    int x, y, temp;
    cout << "Enter the 1st number: ";
    cin >> x;
    cout << "Enter the 2nd number: ";
    cin >> y;
    if(x==0 || y==0) {
        cout << "It is not possible to calculate GCD if one of the numbers is 0. Please enter the numbers again.\n\n";
        main();
        return 0;
    }
    if(x<y) {
        temp=x;
        x=y;
        y=temp;
    }

    cout << "The greatest common divider is " << gcd(x,y) << endl;
    return 0;
}

int gcd(int x, int y) {
    int rem;
    do {
        rem=x%y;
        x=y;
        y=rem;
    } while(rem!=0);

    return x;
}
