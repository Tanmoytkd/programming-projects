#include <iostream>

using namespace std;

int diff(int x = 1, int y = 1);

int main()
{
    int x,y;
    cout << "Enter the first number (x):" << endl;
    cin >> x;
    cout << "Enter the second number (y):" << endl;
    cin >> y;
    cout << "\n----------------------------" << endl;
    cout << "\nx-y = " << diff(x,y) << endl;
    cout << "\n----------------------------" << endl;
    return 0;
}

int diff(int x, int y) {
    return x-y;
}
